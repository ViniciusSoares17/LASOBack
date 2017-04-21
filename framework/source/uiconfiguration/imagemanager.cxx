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

#include <uiconfiguration/imagemanager.hxx>
#include <xml/imagesconfiguration.hxx>
#include <uiconfiguration/graphicnameaccess.hxx>
#include "imagemanagerimpl.hxx"

#include "properties.h"

#include <com/sun/star/lang/DisposedException.hpp>
#include <com/sun/star/beans/XPropertySet.hpp>
#include <com/sun/star/beans/PropertyValue.hpp>
#include <com/sun/star/embed/ElementModes.hpp>
#include <com/sun/star/io/XStream.hpp>

#include <vcl/svapp.hxx>
#include <rtl/ref.hxx>
#include <rtl/ustrbuf.hxx>
#include <osl/mutex.hxx>
#include <comphelper/sequence.hxx>
#include <unotools/ucbstreamhelper.hxx>
#include <vcl/pngread.hxx>
#include <vcl/pngwrite.hxx>

using ::com::sun::star::uno::Sequence;
using ::com::sun::star::uno::XInterface;
using ::com::sun::star::uno::Exception;
using ::com::sun::star::uno::RuntimeException;
using ::com::sun::star::uno::Any;
using ::com::sun::star::graphic::XGraphic;
using namespace ::com::sun::star;
using namespace ::com::sun::star::io;
using namespace ::com::sun::star::embed;
using namespace ::com::sun::star::lang;
using namespace ::com::sun::star::container;
using namespace ::com::sun::star::beans;

namespace framework
{

ImageManager::ImageManager( const uno::Reference< uno::XComponentContext >& rxContext ) :
    m_pImpl( new ImageManagerImpl(rxContext, this, false) )
{
}

ImageManager::~ImageManager()
{
    m_pImpl->clear();
}

// XComponent
void SAL_CALL ImageManager::dispose() throw (css::uno::RuntimeException, std::exception)
{
    m_pImpl->dispose();
}

void SAL_CALL ImageManager::addEventListener( const uno::Reference< XEventListener >& xListener ) throw (css::uno::RuntimeException, std::exception)
{
    m_pImpl->addEventListener(xListener);
}

void SAL_CALL ImageManager::removeEventListener( const uno::Reference< XEventListener >& xListener ) throw (css::uno::RuntimeException, std::exception)
{
    /* SAFE AREA ----------------------------------------------------------------------------------------------- */
    m_pImpl->removeEventListener(xListener);
}

// Non-UNO methods
void ImageManager::setStorage( const uno::Reference< XStorage >& Storage )
throw (css::uno::RuntimeException)
{
    SolarMutexGuard g;

    m_pImpl->m_xUserConfigStorage = Storage;
    m_pImpl->implts_initialize();
}

// XInitialization
void SAL_CALL ImageManager::initialize( const Sequence< Any >& aArguments ) throw ( Exception, RuntimeException, std::exception )
{
    m_pImpl->initialize(aArguments);
}

// XImageManager
void SAL_CALL ImageManager::reset()
    throw (css::lang::IllegalAccessException,
           css::uno::RuntimeException,
           std::exception)
{
    /* SAFE AREA ----------------------------------------------------------------------------------------------- */
    m_pImpl->reset();
}

Sequence< OUString > SAL_CALL ImageManager::getAllImageNames( ::sal_Int16 nImageType )
throw (css::uno::RuntimeException, std::exception)
{
    return m_pImpl->getAllImageNames( nImageType );
}

sal_Bool SAL_CALL ImageManager::hasImage( ::sal_Int16 nImageType, const OUString& aCommandURL )
throw (css::lang::IllegalArgumentException, css::uno::RuntimeException, std::exception)
{
    return m_pImpl->hasImage(nImageType,aCommandURL);
}

Sequence< uno::Reference< XGraphic > > SAL_CALL ImageManager::getImages(
    ::sal_Int16 nImageType,
    const Sequence< OUString >& aCommandURLSequence )
throw ( css::lang::IllegalArgumentException, css::uno::RuntimeException, std::exception )
{
    return m_pImpl->getImages(nImageType,aCommandURLSequence);
}

void SAL_CALL ImageManager::replaceImages(
    ::sal_Int16 nImageType,
    const Sequence< OUString >& aCommandURLSequence,
    const Sequence< uno::Reference< XGraphic > >& aGraphicsSequence )
throw ( css::lang::IllegalArgumentException,
        css::lang::IllegalAccessException,
        css::uno::RuntimeException, std::exception)
{
    m_pImpl->replaceImages(nImageType,aCommandURLSequence,aGraphicsSequence);
}

void SAL_CALL ImageManager::removeImages( ::sal_Int16 nImageType, const Sequence< OUString >& aCommandURLSequence )
throw ( css::lang::IllegalArgumentException,
        css::lang::IllegalAccessException,
        css::uno::RuntimeException, std::exception)
{
    m_pImpl->removeImages(nImageType,aCommandURLSequence);
}

void SAL_CALL ImageManager::insertImages( ::sal_Int16 nImageType, const Sequence< OUString >& aCommandURLSequence, const Sequence< uno::Reference< XGraphic > >& aGraphicSequence )
throw ( css::container::ElementExistException,
        css::lang::IllegalArgumentException,
        css::lang::IllegalAccessException,
        css::uno::RuntimeException, std::exception)
{
    m_pImpl->insertImages(nImageType,aCommandURLSequence,aGraphicSequence);
}

// XUIConfiguration
void SAL_CALL ImageManager::addConfigurationListener( const uno::Reference< css::ui::XUIConfigurationListener >& xListener )
throw (css::uno::RuntimeException, std::exception)
{
    m_pImpl->addConfigurationListener(xListener);
}

void SAL_CALL ImageManager::removeConfigurationListener( const uno::Reference< css::ui::XUIConfigurationListener >& xListener )
throw (css::uno::RuntimeException, std::exception)
{
    /* SAFE AREA ----------------------------------------------------------------------------------------------- */
    m_pImpl->removeConfigurationListener(xListener);
}

// XUIConfigurationPersistence
void SAL_CALL ImageManager::reload()
throw ( css::uno::Exception,
        css::uno::RuntimeException, std::exception )
{
    m_pImpl->reload();
}

void SAL_CALL ImageManager::store()
throw (css::uno::Exception, css::uno::RuntimeException, std::exception)
{
    m_pImpl->store();
}

void SAL_CALL ImageManager::storeToStorage( const uno::Reference< XStorage >& Storage )
throw (css::uno::Exception, css::uno::RuntimeException, std::exception)
{
    m_pImpl->storeToStorage(Storage);
}

sal_Bool SAL_CALL ImageManager::isModified()
throw (css::uno::RuntimeException, std::exception)
{
    return m_pImpl->isModified();
}

sal_Bool SAL_CALL ImageManager::isReadOnly() throw (css::uno::RuntimeException, std::exception)
{
    return m_pImpl->isReadOnly();
}

} // namespace framework

extern "C" SAL_DLLPUBLIC_EXPORT css::uno::XInterface * SAL_CALL
com_sun_star_comp_framework_ImageManager_get_implementation(
    css::uno::XComponentContext *context,
    css::uno::Sequence<css::uno::Any> const &)
{
    return cppu::acquire(new framework::ImageManager(context));
}

/* vim:set shiftwidth=4 softtabstop=4 expandtab: */
