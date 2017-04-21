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

package mod._lnn;

import java.io.PrintWriter;

import lib.TestCase;
import lib.TestEnvironment;
import lib.TestParameters;

import com.sun.star.lang.XMultiServiceFactory;
import com.sun.star.linguistic2.XLinguServiceManager;
import com.sun.star.uno.UnoRuntime;
import com.sun.star.uno.XInterface;

/**
 * Test for object which is represented by service
 * <code>com.sun.star.linguistic2.SpellChecker</code>. <p>
 *
 * Object implements the following interfaces :
 * <ul>
 *  <li> <code>com::sun::star::lang::XInitialization</code></li>
 *  <li> <code>com::sun::star::lang::XComponent</code></li>
 *  <li> <code>com::sun::star::linguistic2::XSupportedLocales</code></li>
 *  <li> <code>com::sun::star::lang::XServiceInfo</code></li>
 *  <li> <code>com::sun::star::linguistic2::XSpellChecker</code></li>
 *  <li> <code>com::sun::star::lang::XServiceDisplayName</code></li>
 *  <li> <code>com::sun::star::linguistic2::XLinguServiceEventBroadcaster</code></li>
 * </ul> <p>
 *
 * This object test <b> is NOT </b> designed to be run in several
 * threads concurrently.
 *
 * @see com.sun.star.lang.XInitialization
 * @see com.sun.star.lang.XComponent
 * @see com.sun.star.linguistic2.XSupportedLocales
 * @see com.sun.star.lang.XServiceInfo
 * @see com.sun.star.linguistic2.XSpellChecker
 * @see com.sun.star.lang.XServiceDisplayName
 * @see com.sun.star.linguistic2.XLinguServiceEventBroadcaster
 * @see ifc.lang._XInitialization
 * @see ifc.lang._XComponent
 * @see ifc.linguistic2._XSupportedLocales
 * @see ifc.lang._XServiceInfo
 * @see ifc.linguistic2._XSpellChecker
 * @see ifc.lang._XServiceDisplayName
 * @see ifc.linguistic2._XLinguServiceEventBroadcaster
 */
public class SpellChecker extends TestCase {

    /**
     * Creating a TestEnvironment for the interfaces to be tested.
     * Creates an instance of the service
     * <code>com.sun.star.linguistic2.SpellChecker</code>.
     */
    @Override
    protected TestEnvironment createTestEnvironment
            (TestParameters tParam, PrintWriter log) throws Exception {
        XMultiServiceFactory xMSF = tParam.getMSF();
        XInterface oObj = (XInterface)xMSF.createInstance
            ("com.sun.star.lingu2.SpellChecker");
        Object LinguServiceManager = xMSF.createInstance
            ("com.sun.star.linguistic2.LinguServiceManager");

        String Iname = util.utils.getImplName(oObj);
        log.println("Implementation Name: "+Iname);
        TestEnvironment tEnv = new TestEnvironment(oObj);

        XLinguServiceManager xLinguServiceManager = UnoRuntime.queryInterface(XLinguServiceManager.class, LinguServiceManager);
        tEnv.addObjRelation("AlternativeChecker",xLinguServiceManager.getSpellChecker());

        return tEnv;
    }

}    // finish class TestCase

