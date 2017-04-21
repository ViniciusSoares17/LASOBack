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

#include <sfx2/docfile.hxx>
#include <unotools/pathoptions.hxx>

#include "sdpage.hxx"
#include "Outliner.hxx"
#include "res_bmp.hrc"

#include <vcl/svapp.hxx>
#include <vcl/builderfactory.hxx>
#include <o3tl/make_unique.hxx>
#include "svtools/svlbitm.hxx"
#include "svtools/treelistentry.hxx"

#include "dlgassim.hxx"

SdPageListControl::SdPageListControl(
    vcl::Window* pParent,
    const WinBits nStyle )
    : SvTreeListBox(pParent, nStyle)
{
    // add lines to tree listbox
    SetStyle( GetStyle() | WB_TABSTOP | WB_BORDER | WB_HASLINES |
                            WB_HASBUTTONS |  WB_HASLINESATROOT |
                            WB_HSCROLL |
                            WB_HASBUTTONSATROOT );

    SetNodeDefaultImages ();
    m_pCheckButton = new SvLBoxButtonData(this);
    EnableCheckButton (m_pCheckButton);

    SetCheckButtonHdl( LINK(this,SdPageListControl,CheckButtonClickHdl) );
}

VCL_BUILDER_DECL_FACTORY(SdPageListControl)
{
    WinBits nWinStyle = WB_TABSTOP;
    OString sBorder = VclBuilder::extractCustomProperty(rMap);
    if (!sBorder.isEmpty())
        nWinStyle |= WB_BORDER;
    rRet = VclPtr<SdPageListControl>::Create(pParent, nWinStyle);
}

IMPL_LINK_NOARG_TYPED(SdPageListControl, CheckButtonClickHdl, SvTreeListBox*, void)
{
    SvTreeList* pTreeModel = GetModel();
    SvTreeListEntry* pEntry = pTreeModel->First();

    while( pEntry )
    {
        if(pTreeModel->IsAtRootDepth(pEntry) && GetCheckButtonState( pEntry ) == SvButtonState::Checked )
            return;
        pEntry = pTreeModel->Next( pEntry );
    }

    pEntry = pTreeModel->First();
    SetCheckButtonState( pEntry, SvButtonState::Checked );
}

SdPageListControl::~SdPageListControl()
{
    disposeOnce();
}

void SdPageListControl::dispose()
{
    delete m_pCheckButton;
    SvTreeListBox::dispose();
}

void SdPageListControl::Clear()
{
    SvTreeListBox::Clear();
}

SvTreeListEntry* SdPageListControl::InsertPage( const OUString& rPageName )
{
    SvTreeListEntry* pEntry = new SvTreeListEntry;

    pEntry->AddItem(o3tl::make_unique<SvLBoxButton>(SvLBoxButtonKind::EnabledCheckbox, m_pCheckButton));
    pEntry->AddItem(o3tl::make_unique<SvLBoxContextBmp>(Image(), Image(), false));    // otherwise boom!
    pEntry->AddItem(o3tl::make_unique<SvLBoxString>(rPageName));

    GetModel()->Insert( pEntry );

    return pEntry;
}

void SdPageListControl::InsertTitle( SvTreeListEntry* pParent, const OUString& rTitle )
{
    SvTreeListEntry* pEntry = new SvTreeListEntry;
    pEntry->AddItem(o3tl::make_unique<SvLBoxString>(OUString()));
    pEntry->AddItem(o3tl::make_unique<SvLBoxContextBmp>(Image(), Image(), false));    // otherwise boom!
    pEntry->AddItem(o3tl::make_unique<SvLBoxString>(rTitle));
    GetModel()->Insert( pEntry,pParent );
}

void SdPageListControl::Fill( SdDrawDocument* pDoc )
{
    Outliner* pOutliner = pDoc->GetInternalOutliner();

    sal_uInt16 nPage = 0;
    const sal_uInt16 nMaxPages = pDoc->GetPageCount();
    while( nPage < nMaxPages )
    {
        SdPage* pPage = static_cast<SdPage*>( pDoc->GetPage( nPage ) );
        if( pPage->GetPageKind() == PK_STANDARD )
        {
            SvTreeListEntry* pEntry = InsertPage( pPage->GetName() );
            SetCheckButtonState(pEntry, SvButtonState( SvButtonState::Checked ) );

            SdrTextObj* pTO = static_cast<SdrTextObj*>(pPage->GetPresObj(PRESOBJ_TEXT));
            if(!pTO)
            {
                // determines the SdrTextObject with the layout text of this page
                const size_t nObjectCount = pPage->GetObjCount();
                for (size_t nObject = 0; nObject < nObjectCount; ++nObject)
                {
                    SdrObject* pObject = pPage->GetObj(nObject);
                    if (pObject->GetObjInventor() == SdrInventor && pObject->GetObjIdentifier() == OBJ_OUTLINETEXT)
                    {
                        pTO = static_cast<SdrTextObj*>(pObject);
                        break;
                    }
                }
            }

            if (pTO && !pTO->IsEmptyPresObj())
            {
                OutlinerParaObject* pOPO = pTO->GetOutlinerParaObject();
                if (pOPO)
                {
                    pOutliner->Clear();
                    pOutliner->SetText( *pOPO );

                    sal_Int32 nCount = pOutliner->GetParagraphCount();


                    for (sal_Int32 nPara = 0; nPara < nCount; nPara++)
                    {
                        Paragraph* pPara = pOutliner->GetParagraph(nPara);
                        if(pPara && pOutliner->GetDepth( nPara ) == 0 )
                        {
                            OUString aParaText = pOutliner->GetText(pPara);
                            if (!aParaText.isEmpty())
                                InsertTitle( pEntry, aParaText );
                        }
                    }
                }
            }
        }
        nPage++;
    }

    pOutliner->Clear();
}

sal_uInt16 SdPageListControl::GetSelectedPage()
{
    SvTreeListEntry* pSelEntry = GetCurEntry();
    sal_uInt16 nPage = 0;

    if ( pSelEntry )
    {
        SvTreeList* pTreeModel = GetModel();
        SvTreeListEntry* pEntry = pTreeModel->First();

        while( pEntry && pEntry != pSelEntry )
        {
            if(pTreeModel->IsAtRootDepth(pEntry))
                nPage++;
            pEntry = pTreeModel->Next( pEntry );
        }

        if(!pTreeModel->IsAtRootDepth(pSelEntry))
            nPage--;
    }
    return nPage;
}

bool SdPageListControl::IsPageChecked( sal_uInt16 nPage )
{
    SvTreeListEntry* pEntry = GetModel()->GetEntry(nPage);
    return pEntry && (GetCheckButtonState( pEntry ) == SvButtonState::Checked);
}

void SdPageListControl::DataChanged( const DataChangedEvent& rDCEvt )
{
    SvTreeListBox::DataChanged( rDCEvt );
}

/* vim:set shiftwidth=4 softtabstop=4 expandtab: */
