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

#include "frm_strings.hxx"
#include "property.hxx"

#include "property.hrc"

namespace frm
{

//= PropertyInfoService

PropertyInfoService::PropertyMap PropertyInfoService::s_AllKnownProperties;

sal_Int32 PropertyInfoService::getPropertyId(const OUString& _rName)
{
    initialize();

    sal_Int32 nHandle = -1;
    const auto foundProperty = s_AllKnownProperties.find(_rName);
    if (foundProperty != s_AllKnownProperties.end())
        nHandle = foundProperty->second;
    return nHandle;
}


sal_Int32 ConcreteInfoService::getPreferredPropertyId(const OUString& _rName)
{
    return PropertyInfoService::getPropertyId(_rName);
}


#define EXPAND_PROP_INIT(varname) \
    { PROPERTY_##varname, PROPERTY_ID_##varname }

void PropertyInfoService::initialize()
{
    if (!s_AllKnownProperties.empty())
        return;

    s_AllKnownProperties.insert({
        EXPAND_PROP_INIT(NAME),
        EXPAND_PROP_INIT(TAG),
        EXPAND_PROP_INIT(TABINDEX),
        EXPAND_PROP_INIT(CLASSID),
        EXPAND_PROP_INIT(ALIGN),
        EXPAND_PROP_INIT(FETCHSIZE),
        EXPAND_PROP_INIT(VALUE),
        EXPAND_PROP_INIT(VALUEMIN),
        EXPAND_PROP_INIT(VALUEMAX),
        EXPAND_PROP_INIT(VALUESTEP),
        EXPAND_PROP_INIT(TEXT),
        EXPAND_PROP_INIT(LABEL),
        EXPAND_PROP_INIT(NAVIGATION),
        EXPAND_PROP_INIT(CYCLE),
        EXPAND_PROP_INIT(CONTROLSOURCE),
        EXPAND_PROP_INIT(ENABLED),
        EXPAND_PROP_INIT(ENABLEVISIBLE),
        EXPAND_PROP_INIT(SPIN),
        EXPAND_PROP_INIT(READONLY),
        EXPAND_PROP_INIT(FILTER),
        EXPAND_PROP_INIT(WIDTH),
        EXPAND_PROP_INIT(SEARCHABLE),
        EXPAND_PROP_INIT(MULTILINE),
        EXPAND_PROP_INIT(TARGET_URL),
        EXPAND_PROP_INIT(DEFAULTCONTROL),
        EXPAND_PROP_INIT(MAXTEXTLEN),
        EXPAND_PROP_INIT(SIZE),
        EXPAND_PROP_INIT(DATE),
        EXPAND_PROP_INIT(TIME),
        EXPAND_PROP_INIT(STATE),
        EXPAND_PROP_INIT(TRISTATE),
        EXPAND_PROP_INIT(HIDDEN_VALUE),
        EXPAND_PROP_INIT(TARGET_FRAME),
        EXPAND_PROP_INIT(BUTTONTYPE),
        EXPAND_PROP_INIT(STRINGITEMLIST),
        EXPAND_PROP_INIT(DEFAULT_TEXT),
        EXPAND_PROP_INIT(DEFAULT_STATE),
        EXPAND_PROP_INIT(DEFAULT_DATE),
        EXPAND_PROP_INIT(DEFAULT_TIME),
        EXPAND_PROP_INIT(DEFAULT_VALUE),
        EXPAND_PROP_INIT(FORMATKEY),
        EXPAND_PROP_INIT(FORMATSSUPPLIER),
        EXPAND_PROP_INIT(SUBMIT_ACTION),
        EXPAND_PROP_INIT(SUBMIT_TARGET),
        EXPAND_PROP_INIT(SUBMIT_METHOD),
        EXPAND_PROP_INIT(SUBMIT_ENCODING),
        EXPAND_PROP_INIT(IMAGE_URL),
        EXPAND_PROP_INIT(GRAPHIC),
        EXPAND_PROP_INIT(EMPTY_IS_NULL),
        EXPAND_PROP_INIT(LISTSOURCETYPE),
        EXPAND_PROP_INIT(LISTSOURCE),
        EXPAND_PROP_INIT(SELECT_SEQ),
        EXPAND_PROP_INIT(VALUE_SEQ),
        EXPAND_PROP_INIT(SELECT_VALUE),
        EXPAND_PROP_INIT(SELECT_VALUE_SEQ),
        EXPAND_PROP_INIT(DEFAULT_SELECT_SEQ),
        EXPAND_PROP_INIT(MULTISELECTION),
        EXPAND_PROP_INIT(DECIMAL_ACCURACY),
        EXPAND_PROP_INIT(EDITMASK),
        EXPAND_PROP_INIT(ISREADONLY),
        EXPAND_PROP_INIT(FIELDTYPE),
        EXPAND_PROP_INIT(DECIMALS),
        EXPAND_PROP_INIT(REFVALUE),
        EXPAND_PROP_INIT(STRICTFORMAT),
        EXPAND_PROP_INIT(DATASOURCE),
        EXPAND_PROP_INIT(ALLOWADDITIONS),
        EXPAND_PROP_INIT(ALLOWEDITS),
        EXPAND_PROP_INIT(ALLOWDELETIONS),
        EXPAND_PROP_INIT(MASTERFIELDS),
        EXPAND_PROP_INIT(ISPASSTHROUGH),
        EXPAND_PROP_INIT(QUERY),
        EXPAND_PROP_INIT(LITERALMASK),
        EXPAND_PROP_INIT(SHOWTHOUSANDSEP),
        EXPAND_PROP_INIT(CURRENCYSYMBOL),
        EXPAND_PROP_INIT(DATEFORMAT),
        EXPAND_PROP_INIT(DATEMIN),
        EXPAND_PROP_INIT(DATEMAX),
        EXPAND_PROP_INIT(DATE_SHOW_CENTURY),
        EXPAND_PROP_INIT(TIMEFORMAT),
        EXPAND_PROP_INIT(TIMEMIN),
        EXPAND_PROP_INIT(TIMEMAX),
        EXPAND_PROP_INIT(LINECOUNT),
        EXPAND_PROP_INIT(BOUNDCOLUMN),
        EXPAND_PROP_INIT(HASNAVIGATION),
        EXPAND_PROP_INIT(FONT),
        EXPAND_PROP_INIT(BACKGROUNDCOLOR),
        EXPAND_PROP_INIT(FILLCOLOR),
        EXPAND_PROP_INIT(TEXTCOLOR),
        EXPAND_PROP_INIT(LINECOLOR),
        EXPAND_PROP_INIT(BORDER),
        EXPAND_PROP_INIT(DROPDOWN),
        EXPAND_PROP_INIT(HSCROLL),
        EXPAND_PROP_INIT(VSCROLL),
        EXPAND_PROP_INIT(TABSTOP),
        EXPAND_PROP_INIT(AUTOCOMPLETE),
        EXPAND_PROP_INIT(HARDLINEBREAKS),
        EXPAND_PROP_INIT(PRINTABLE),
        EXPAND_PROP_INIT(ECHO_CHAR),
        EXPAND_PROP_INIT(ROWHEIGHT),
        EXPAND_PROP_INIT(HELPTEXT),
        EXPAND_PROP_INIT(FONT_NAME),
        EXPAND_PROP_INIT(FONT_STYLENAME),
        EXPAND_PROP_INIT(FONT_FAMILY),
        EXPAND_PROP_INIT(FONT_CHARSET),
        EXPAND_PROP_INIT(FONT_HEIGHT),
        EXPAND_PROP_INIT(FONT_WEIGHT),
        EXPAND_PROP_INIT(FONT_SLANT),
        EXPAND_PROP_INIT(FONT_UNDERLINE),
        EXPAND_PROP_INIT(FONT_WORDLINEMODE),
        EXPAND_PROP_INIT(FONT_STRIKEOUT),
        EXPAND_PROP_INIT(TEXTLINECOLOR),
        EXPAND_PROP_INIT(FONTEMPHASISMARK),
        EXPAND_PROP_INIT(FONTRELIEF),
        EXPAND_PROP_INIT(HELPURL),
        EXPAND_PROP_INIT(RECORDMARKER),
        EXPAND_PROP_INIT(BOUNDFIELD),
        EXPAND_PROP_INIT(INPUT_REQUIRED),
        EXPAND_PROP_INIT(TREATASNUMERIC),
        EXPAND_PROP_INIT(EFFECTIVE_VALUE),
        EXPAND_PROP_INIT(EFFECTIVE_DEFAULT),
        EXPAND_PROP_INIT(EFFECTIVE_MIN),
        EXPAND_PROP_INIT(EFFECTIVE_MAX),
        EXPAND_PROP_INIT(HIDDEN),
        EXPAND_PROP_INIT(FILTERPROPOSAL),
        EXPAND_PROP_INIT(FIELDSOURCE),
        EXPAND_PROP_INIT(TABLENAME),
        EXPAND_PROP_INIT(CONTROLLABEL),
        EXPAND_PROP_INIT(CURRSYM_POSITION),
        EXPAND_PROP_INIT(CURSORCOLOR),
        EXPAND_PROP_INIT(ALWAYSSHOWCURSOR),
        EXPAND_PROP_INIT(DISPLAYSYNCHRON),
        EXPAND_PROP_INIT(ISMODIFIED),
        EXPAND_PROP_INIT(ISNEW),
        EXPAND_PROP_INIT(PRIVILEGES),
        EXPAND_PROP_INIT(DETAILFIELDS),
        EXPAND_PROP_INIT(COMMAND),
        EXPAND_PROP_INIT(COMMANDTYPE),
        EXPAND_PROP_INIT(RESULTSET_CONCURRENCY),
        EXPAND_PROP_INIT(INSERTONLY),
        EXPAND_PROP_INIT(RESULTSET_TYPE),
        EXPAND_PROP_INIT(ESCAPE_PROCESSING),
        EXPAND_PROP_INIT(APPLYFILTER),
        EXPAND_PROP_INIT(ISNULLABLE),
        EXPAND_PROP_INIT(ACTIVECOMMAND),
        EXPAND_PROP_INIT(ISCURRENCY),
        EXPAND_PROP_INIT(URL),
        EXPAND_PROP_INIT(TITLE),
        EXPAND_PROP_INIT(ACTIVE_CONNECTION),
        EXPAND_PROP_INIT(SCALE),
        EXPAND_PROP_INIT(SORT),
        EXPAND_PROP_INIT(PERSISTENCE_MAXTEXTLENGTH),
        EXPAND_PROP_INIT(SCROLL_VALUE),
        EXPAND_PROP_INIT(SPIN_VALUE),
        EXPAND_PROP_INIT(DEFAULT_SCROLL_VALUE),
        EXPAND_PROP_INIT(DEFAULT_SPIN_VALUE),
        EXPAND_PROP_INIT( WRITING_MODE ),
        EXPAND_PROP_INIT( CONTEXT_WRITING_MODE ),
        EXPAND_PROP_INIT( GENERATEVBAEVENTS )
    });
}


}
//... namespace frm .......................................................

/* vim:set shiftwidth=4 softtabstop=4 expandtab: */
