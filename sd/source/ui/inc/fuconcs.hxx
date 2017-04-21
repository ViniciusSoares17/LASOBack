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

#ifndef INCLUDED_SD_SOURCE_UI_INC_FUCONCS_HXX
#define INCLUDED_SD_SOURCE_UI_INC_FUCONCS_HXX

#include "fuconstr.hxx"

class KeyEvent;
class SdDrawDocument;
class SdrObject;

namespace sd {

class FuConstructCustomShape
    : public FuConstruct
{
public:

    static rtl::Reference<FuPoor> Create( ViewShell* pViewSh, ::sd::Window* pWin, ::sd::View* pView, SdDrawDocument* pDoc, SfxRequest& rReq, bool bPermanent );
    virtual void DoExecute( SfxRequest& rReq ) override;

    // Mouse- & Key-Events
    virtual bool KeyInput(const KeyEvent& rKEvt) override;
    virtual bool MouseMove(const MouseEvent& rMEvt) override;
    virtual bool MouseButtonUp(const MouseEvent& rMEvt) override;
    virtual bool MouseButtonDown(const MouseEvent& rMEvt) override;

    virtual void Activate() override;

    void SetAttributes( SdrObject* pObj );
    const OUString& GetShapeType() const;

    virtual SdrObject* CreateDefaultObject(const sal_uInt16 nID, const Rectangle& rRectangle) override;

    // #i33136#
    virtual bool doConstructOrthogonal() const override;

protected:
    FuConstructCustomShape (
        ViewShell* pViewSh,
        ::sd::Window* pWin,
        ::sd::View* pView,
        SdDrawDocument* pDoc,
        SfxRequest& rReq);

private:
    OUString aCustomShape;
};

} // end of namespace sd

#endif

/* vim:set shiftwidth=4 softtabstop=4 expandtab: */
