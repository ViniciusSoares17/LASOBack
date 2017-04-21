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

#ifndef INCLUDED_IDLC_INC_IDLC_ASTMEMBER_HXX
#define INCLUDED_IDLC_INC_IDLC_ASTMEMBER_HXX

#include "idlc/astdeclaration.hxx"

class AstScope;
class AstType;

class AstMember: public AstDeclaration {
public:
    AstMember(
        AstType const * pType, OString const & name, AstScope * pScope):
        AstDeclaration(NT_member, name, pScope), m_pType(pType) {}

    virtual ~AstMember() {}

    AstType const * getType() const { return m_pType; }

protected:
    AstMember(
        NodeType type, AstType const * pType, OString const & name,
        AstScope * pScope):
        AstDeclaration(type, name, pScope), m_pType(pType) {}

private:
    AstType const * m_pType;
};

#endif

/* vim:set shiftwidth=4 softtabstop=4 expandtab: */
