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

#ifndef INCLUDED_XMLSECURITY_SOURCE_XMLSEC_NSS_X509CERTIFICATE_NSSIMPL_HXX
#define INCLUDED_XMLSECURITY_SOURCE_XMLSEC_NSS_X509CERTIFICATE_NSSIMPL_HXX

#include <sal/config.h>
#include <rtl/ustring.hxx>
#include <cppuhelper/factory.hxx>
#include <cppuhelper/implbase.hxx>
#include <com/sun/star/uno/Exception.hpp>
#include <com/sun/star/lang/XUnoTunnel.hpp>
#include <com/sun/star/uno/SecurityException.hpp>
#include <com/sun/star/security/XCertificate.hpp>

#include <certificate.hxx>
#include "cert.h"

class X509Certificate_NssImpl : public ::cppu::WeakImplHelper<
    css::security::XCertificate ,
    css::lang::XUnoTunnel > , public xmlsecurity::Certificate
{
    private:
        CERTCertificate* m_pCert ;

    public:
        X509Certificate_NssImpl() ;
        virtual ~X509Certificate_NssImpl() ;

        //Methods from XCertificate
        virtual sal_Int16 SAL_CALL getVersion(  ) throw ( css::uno::RuntimeException, std::exception) override ;

        virtual css::uno::Sequence< sal_Int8 > SAL_CALL getSerialNumber(  ) throw ( css::uno::RuntimeException, std::exception) override ;

        virtual OUString SAL_CALL getIssuerName(  ) throw ( css::uno::RuntimeException, std::exception) override ;
        virtual OUString SAL_CALL getSubjectName(  ) throw ( css::uno::RuntimeException, std::exception) override ;

        virtual css::util::DateTime SAL_CALL getNotValidBefore(  ) throw ( css::uno::RuntimeException, std::exception) override ;
        virtual css::util::DateTime SAL_CALL getNotValidAfter(  ) throw ( css::uno::RuntimeException, std::exception) override ;

        virtual css::uno::Sequence< sal_Int8 > SAL_CALL getIssuerUniqueID(  ) throw ( css::uno::RuntimeException, std::exception) override ;
        virtual css::uno::Sequence< sal_Int8 > SAL_CALL getSubjectUniqueID(  ) throw ( css::uno::RuntimeException, std::exception) override ;

        virtual css::uno::Sequence< css::uno::Reference< css::security::XCertificateExtension > > SAL_CALL getExtensions(  ) throw ( css::uno::RuntimeException, std::exception) override ;

        virtual css::uno::Reference< css::security::XCertificateExtension > SAL_CALL findCertificateExtension( const css::uno::Sequence< sal_Int8 >& oid ) throw (css::uno::RuntimeException, std::exception) override ;

        virtual css::uno::Sequence< sal_Int8 > SAL_CALL getEncoded(  ) throw ( css::uno::RuntimeException, std::exception) override ;

        virtual OUString SAL_CALL getSubjectPublicKeyAlgorithm()
            throw ( css::uno::RuntimeException, std::exception) override ;

        virtual css::uno::Sequence< sal_Int8 > SAL_CALL getSubjectPublicKeyValue()
            throw ( css::uno::RuntimeException, std::exception) override ;

        virtual OUString SAL_CALL getSignatureAlgorithm()
            throw ( css::uno::RuntimeException, std::exception) override ;

        virtual css::uno::Sequence< sal_Int8 > SAL_CALL getSHA1Thumbprint()
            throw ( css::uno::RuntimeException, std::exception) override ;

        virtual css::uno::Sequence< sal_Int8 > SAL_CALL getMD5Thumbprint()
            throw ( css::uno::RuntimeException, std::exception) override ;

        virtual sal_Int32 SAL_CALL getCertificateUsage( ) throw ( css::uno::RuntimeException, std::exception) override ;

        //Methods from XUnoTunnel
        virtual sal_Int64 SAL_CALL getSomething( const css::uno::Sequence< sal_Int8 >& aIdentifier ) throw (css::uno::RuntimeException, std::exception) override;

        /// @see xmlsecurity::Certificate::getSHA256Thumbprint().
        virtual css::uno::Sequence<sal_Int8> getSHA256Thumbprint() throw (css::uno::RuntimeException, std::exception) override;

        static const css::uno::Sequence< sal_Int8 >& getUnoTunnelId() ;

        //Helper methods
        void setCert( CERTCertificate* cert ) ;
        const CERTCertificate* getNssCert() const ;
        void setRawCert( const css::uno::Sequence< sal_Int8 >& rawCert ) throw ( css::uno::RuntimeException) ;
} ;

#endif // INCLUDED_XMLSECURITY_SOURCE_XMLSEC_NSS_X509CERTIFICATE_NSSIMPL_HXX

/* vim:set shiftwidth=4 softtabstop=4 expandtab: */
