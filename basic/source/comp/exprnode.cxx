/* -*- Mode: C++; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4 -*- */
/*
 * This file is part of the LibreOffice project.
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 *
 * This file incorporates work covered by the following license notice:
 *
 *   Licensed to the Apache Software Foundation (ASF) under one or more
 *   contributor license agreements. See the NOTICE file distributed
 *   with this work for additional information regarding copyright
 *   ownership. The ASF licenses this file to you under the Apache
 *   License, Version 2.0 (the "License"); you may not use this file
 *   except in compliance with the License. You may obtain a copy of
 *   the License at http://www.apache.org/licenses/LICENSE-2.0 .
 */


#include <math.h>
#include <algorithm>

#include <rtl/math.hxx>
#include "codegen.hxx"
#include "parser.hxx"
#include "expr.hxx"


SbiExprNode::SbiExprNode( SbiExprNode* l, SbiToken t, SbiExprNode* r ) :
    pLeft(l),
    pRight(r),
    pWithParent(nullptr),
    eNodeType(SbxNODE),
    eType(SbxVARIANT), // Nodes are always Variant
    eTok(t),
    bError(false)
{
}

SbiExprNode::SbiExprNode( double n, SbxDataType t ):
    nVal(n),
    pWithParent(nullptr),
    eNodeType(SbxNUMVAL),
    eType(t),
    eTok(NIL),
    bError(false)
{
}

SbiExprNode::SbiExprNode( const OUString& rVal ):
    aStrVal(rVal),
    pWithParent(nullptr),
    eNodeType(SbxSTRVAL),
    eType(SbxSTRING),
    eTok(NIL),
    bError(false)
{
}

SbiExprNode::SbiExprNode( const SbiSymDef& r, SbxDataType t, SbiExprListPtr l ) :
    pWithParent(nullptr),
    eNodeType(SbxVARVAL),
    eTok(NIL),
    bError(false)
{
    eType     = ( t == SbxVARIANT ) ? r.GetType() : t;
    aVar.pDef = const_cast<SbiSymDef*>(&r);
    aVar.pPar = l.release();
    aVar.pvMorePar = nullptr;
    aVar.pNext= nullptr;
}

// #120061 TypeOf
SbiExprNode::SbiExprNode( SbiExprNode* l, sal_uInt16 nId ) :
    nTypeStrId(nId),
    pLeft(l),
    pWithParent(nullptr),
    eNodeType(SbxTYPEOF),
    eType(SbxBOOL),
    eTok(NIL),
    bError(false)
{
}

// new <type>
SbiExprNode::SbiExprNode( sal_uInt16 nId ) :
    nTypeStrId(nId),
    pWithParent(nullptr),
    eNodeType(SbxNEW),
    eType(SbxOBJECT),
    eTok(NIL),
    bError(false)
{
}

SbiExprNode::SbiExprNode() :
    pWithParent(nullptr),
    eNodeType(SbxDUMMY),
    eType(SbxVARIANT),
    eTok(NIL),
    bError(false)
{
}

SbiExprNode::~SbiExprNode()
{
    if( IsVariable() )
    {
        delete aVar.pPar;
        delete aVar.pNext;
        delete aVar.pvMorePar;
    }
}

SbiSymDef* SbiExprNode::GetVar()
{
    if( eNodeType == SbxVARVAL )
        return aVar.pDef;
    else
        return nullptr;
}

SbiSymDef* SbiExprNode::GetRealVar()
{
    SbiExprNode* p = GetRealNode();
    if( p )
        return p->GetVar();
    else
        return nullptr;
}

// From 1995-12-18
SbiExprNode* SbiExprNode::GetRealNode()
{
    if( eNodeType == SbxVARVAL )
    {
        SbiExprNode* p = this;
        while( p->aVar.pNext )
            p = p->aVar.pNext;
        return p;
    }
    else
        return nullptr;
}

// This method transform the type, if it fits into the Integer range

void SbiExprNode::ConvertToIntConstIfPossible()
{
    if( eNodeType == SbxNUMVAL )
    {
        if( eType >= SbxINTEGER && eType <= SbxDOUBLE )
        {
            double n;
            if( nVal >= SbxMININT && nVal <= SbxMAXINT && modf( nVal, &n ) == 0 )
            {
                nVal = (double) (short) nVal;
                eType = SbxINTEGER;
            }
        }
    }
}

bool SbiExprNode::IsNumber()
{
    return eNodeType == SbxNUMVAL;
}

bool SbiExprNode::IsVariable()
{
    return eNodeType == SbxVARVAL;
}

bool SbiExprNode::IsLvalue()
{
    return IsVariable();
}

// Identify of the depth of a tree

short SbiExprNode::GetDepth()
{
    if( IsOperand() ) return 0;
    else
    {
        return std::max(pLeft->GetDepth(), pRight->GetDepth()) + 1;
    }
}


// Adjustment of a tree:
// 1. Constant Folding
// 2. Type-Adjustment
// 3. Conversion of the operands into Strings
// 4. Lifting of the composite- and error-bits

void SbiExprNode::Optimize(SbiParser* pParser)
{
    FoldConstants(pParser);
    CollectBits();
}

// Lifting of the error-bits

void SbiExprNode::CollectBits()
{
    if( pLeft )
    {
        pLeft->CollectBits();
        bError = bError || pLeft->bError;
    }
    if( pRight )
    {
        pRight->CollectBits();
        bError = bError || pRight->bError;
    }
}

// If a twig can be converted, True will be returned. In this case
// the result is in the left twig.
void SbiExprNode::FoldConstants(SbiParser* pParser)
{
    if( IsOperand() || eTok == LIKE ) return;

    if (IsUnary())
        FoldConstantsUnaryNode(pParser);
    else if (IsBinary())
        FoldConstantsBinaryNode(pParser);

    if( eNodeType == SbxNUMVAL )
    {
        // Potentially convolve in INTEGER (because of better opcode)?
        if( eType == SbxSINGLE || eType == SbxDOUBLE )
        {
            double x;
            if( nVal >= SbxMINLNG && nVal <= SbxMAXLNG
            && !modf( nVal, &x ) )
                eType = SbxLONG;
        }
        if( eType == SbxLONG && nVal >= SbxMININT && nVal <= SbxMAXINT )
            eType = SbxINTEGER;
    }
}

void SbiExprNode::FoldConstantsBinaryNode(SbiParser* pParser)
{
    pLeft->FoldConstants(pParser);
    pRight->FoldConstants(pParser);
    if( pLeft->IsConstant() && pRight->IsConstant()
        && pLeft->eNodeType == pRight->eNodeType )
    {
        CollectBits();
        if( eTok == CAT )
            // CAT affiliate also two numbers!
            eType = SbxSTRING;
        if( pLeft->eType == SbxSTRING )
            // No Type Mismatch!
            eType = SbxSTRING;
        if( eType == SbxSTRING )
        {
            OUString rl( pLeft->GetString() );
            OUString rr( pRight->GetString() );
            pLeft.reset();
            pRight.reset();
            if( eTok == PLUS || eTok == CAT )
            {
                eTok = CAT;
                // Linking:
                aStrVal = rl;
                aStrVal += rr;
                eType = SbxSTRING;
                eNodeType = SbxSTRVAL;
            }
            else
            {
                eType = SbxDOUBLE;
                eNodeType = SbxNUMVAL;
                int eRes = rr.compareTo( rl );
                switch( eTok )
                {
                case EQ:
                    nVal = ( eRes == 0 ) ? SbxTRUE : SbxFALSE;
                    break;
                case NE:
                    nVal = ( eRes != 0 ) ? SbxTRUE : SbxFALSE;
                    break;
                case LT:
                    nVal = ( eRes < 0 ) ? SbxTRUE : SbxFALSE;
                    break;
                case GT:
                    nVal = ( eRes > 0 ) ? SbxTRUE : SbxFALSE;
                    break;
                case LE:
                    nVal = ( eRes <= 0 ) ? SbxTRUE : SbxFALSE;
                    break;
                case GE:
                    nVal = ( eRes >= 0 ) ? SbxTRUE : SbxFALSE;
                    break;
                default:
                    pParser->Error( ERRCODE_BASIC_CONVERSION );
                    bError = true;
                    break;
                }
            }
        }
        else
        {
            double nl = pLeft->nVal;
            double nr = pRight->nVal;
            long ll = 0, lr = 0;
            long llMod = 0, lrMod = 0;
            if( ( eTok >= AND && eTok <= IMP )
               || eTok == IDIV || eTok == MOD )
            {
                // Integer operations
                bool bErr = false;
                if( nl > SbxMAXLNG )
                {
                    bErr = true;
                    nl = SbxMAXLNG;
                }
                else if( nl < SbxMINLNG )
                {
                    bErr = true;
                    nl = SbxMINLNG;
                }
                if( nr > SbxMAXLNG )
                {
                    bErr = true;
                    nr = SbxMAXLNG;
                }
                else if( nr < SbxMINLNG )
                {
                    bErr = true;
                    nr = SbxMINLNG;
                }
                ll = static_cast<long>(nl); lr = static_cast<long>(nr);
                llMod = static_cast<long>(nl);
                lrMod = static_cast<long>(nr);
                if( bErr )
                {
                    pParser->Error( ERRCODE_BASIC_MATH_OVERFLOW );
                    bError = true;
                }
            }
            bool bBothInt = ( pLeft->eType < SbxSINGLE
                               && pRight->eType < SbxSINGLE );
            pLeft.reset();
            pRight.reset();
            nVal = 0;
            eType = SbxDOUBLE;
            eNodeType = SbxNUMVAL;
            bool bCheckType = false;
            switch( eTok )
            {
                case EXPON:
                    nVal = pow( nl, nr ); break;
                case MUL:
                    bCheckType = true;
                    nVal = nl * nr; break;
                case DIV:
                    if( !nr )
                    {
                        pParser->Error( ERRCODE_BASIC_ZERODIV ); nVal = HUGE_VAL;
                        bError = true;
                    } else nVal = nl / nr;
                    break;
                case PLUS:
                    bCheckType = true;
                    nVal = nl + nr; break;
                case MINUS:
                    bCheckType = true;
                    nVal = nl - nr; break;
                case EQ:
                    nVal = ( nl == nr ) ? SbxTRUE : SbxFALSE;
                    eType = SbxINTEGER; break;
                case NE:
                    nVal = ( nl != nr ) ? SbxTRUE : SbxFALSE;
                    eType = SbxINTEGER; break;
                case LT:
                    nVal = ( nl <  nr ) ? SbxTRUE : SbxFALSE;
                    eType = SbxINTEGER; break;
                case GT:
                    nVal = ( nl >  nr ) ? SbxTRUE : SbxFALSE;
                    eType = SbxINTEGER; break;
                case LE:
                    nVal = ( nl <= nr ) ? SbxTRUE : SbxFALSE;
                    eType = SbxINTEGER; break;
                case GE:
                    nVal = ( nl >= nr ) ? SbxTRUE : SbxFALSE;
                    eType = SbxINTEGER; break;
                case IDIV:
                    if( !lr )
                    {
                        pParser->Error( ERRCODE_BASIC_ZERODIV ); nVal = HUGE_VAL;
                        bError = true;
                    } else nVal = ll / lr;
                    eType = SbxLONG; break;
                case MOD:
                    if( !lr )
                    {
                        pParser->Error( ERRCODE_BASIC_ZERODIV ); nVal = HUGE_VAL;
                        bError = true;
                    } else nVal = llMod - lrMod * (llMod/lrMod);
                    eType = SbxLONG; break;
                case AND:
                    nVal = (double) ( ll & lr ); eType = SbxLONG; break;
                case OR:
                    nVal = (double) ( ll | lr ); eType = SbxLONG; break;
                case XOR:
                    nVal = (double) ( ll ^ lr ); eType = SbxLONG; break;
                case EQV:
                    nVal = (double) ( ~ll ^ lr ); eType = SbxLONG; break;
                case IMP:
                    nVal = (double) ( ~ll | lr ); eType = SbxLONG; break;
                default: break;
            }

            if( !::rtl::math::isFinite( nVal ) )
                pParser->Error( ERRCODE_BASIC_MATH_OVERFLOW );

            // Recover the data type to kill rounding error
            if( bCheckType && bBothInt
             && nVal >= SbxMINLNG && nVal <= SbxMAXLNG )
            {
                // Decimal place away
                long n = (long) nVal;
                nVal = n;
                eType = ( n >= SbxMININT && n <= SbxMAXINT )
                      ? SbxINTEGER : SbxLONG;
            }
        }
    }

}
void SbiExprNode::FoldConstantsUnaryNode(SbiParser* pParser)
{
    pLeft->FoldConstants(pParser);
    if (pLeft->IsNumber())
    {
        nVal = pLeft->nVal;
        pLeft.reset();
        eType = SbxDOUBLE;
        eNodeType = SbxNUMVAL;
        switch( eTok )
        {
            case NEG:
                nVal = -nVal; break;
            case NOT: {
                // Integer operation!
                bool bErr = false;
                if( nVal > SbxMAXLNG )
                {
                    bErr = true;
                    nVal = SbxMAXLNG;
                }
                else if( nVal < SbxMINLNG )
                {
                    bErr = true;
                    nVal = SbxMINLNG;
                }
                if( bErr )
                {
                    pParser->Error( ERRCODE_BASIC_MATH_OVERFLOW );
                    bError = true;
                }
                nVal = (double) ~((long) nVal);
                eType = SbxLONG;
                } break;
            default: break;
        }
    }
    if( eNodeType == SbxNUMVAL )
    {
        // Potentially convolve in INTEGER (because of better opcode)?
        if( eType == SbxSINGLE || eType == SbxDOUBLE )
        {
            double x;
            if( nVal >= SbxMINLNG && nVal <= SbxMAXLNG
            && !modf( nVal, &x ) )
                eType = SbxLONG;
        }
        if( eType == SbxLONG && nVal >= SbxMININT && nVal <= SbxMAXINT )
            eType = SbxINTEGER;
    }
}


/* vim:set shiftwidth=4 softtabstop=4 expandtab: */
