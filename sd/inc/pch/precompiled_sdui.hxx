/* -*- Mode: C++; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4 -*- */
/*
 * This file is part of the LibreOffice project.
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

/*
 This file has been autogenerated by update_pch.sh. It is possible to edit it
 manually (such as when an include file has been moved/renamed/removed). All such
 manual changes will be rewritten by the next run of update_pch.sh (which presumably
 also fixes all possible problems, so it's usually better to use it).

 Generated on 2016-02-06 12:31:07 using:
 ./bin/update_pch sd sdui --cutoff=4 --exclude:system --include:module --include:local

 If after updating build fails, use the following command to locate conflicting headers:
 ./bin/update_pch_bisect ./sd/inc/pch/precompiled_sdui.hxx "make sd.build" --find-conflicts
*/

#include <algorithm>
#include <cassert>
#include <climits>
#include <config_global.h>
#include <config_typesizes.h>
#include <config_vcl.h>
#include <cstddef>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <float.h>
#include <functional>
#include <iomanip>
#include <limits.h>
#include <limits>
#include <list>
#include <math.h>
#include <memory>
#include <new>
#include <ostream>
#include <set>
#include <sstream>
#include <stack>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <type_traits>
#include <typeinfo>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
#include <boost/intrusive_ptr.hpp>
#include <boost/optional.hpp>
#include <osl/diagnose.h>
#include <osl/diagnose.hxx>
#include <osl/doublecheckedlocking.h>
#include <osl/endian.h>
#include <osl/file.h>
#include <osl/file.hxx>
#include <osl/getglobalmutex.hxx>
#include <osl/interlck.h>
#include <osl/module.h>
#include <osl/module.hxx>
#include <osl/mutex.h>
#include <osl/mutex.hxx>
#include <osl/pipe.h>
#include <osl/process.h>
#include <osl/security.h>
#include <osl/socket.h>
#include <osl/thread.h>
#include <osl/time.h>
#include <rtl/alloc.h>
#include <rtl/byteseq.h>
#include <rtl/character.hxx>
#include <rtl/instance.hxx>
#include <rtl/locale.h>
#include <rtl/math.h>
#include <rtl/math.hxx>
#include <rtl/ref.hxx>
#include <rtl/strbuf.h>
#include <rtl/strbuf.hxx>
#include <rtl/string.h>
#include <rtl/string.hxx>
#include <rtl/stringutils.hxx>
#include <rtl/tencinfo.h>
#include <rtl/textcvt.h>
#include <rtl/textenc.h>
#include <rtl/unload.h>
#include <rtl/ustrbuf.h>
#include <rtl/ustrbuf.hxx>
#include <rtl/ustring.h>
#include <rtl/ustring.hxx>
#include <rtl/uuid.h>
#include <sal/config.h>
#include <sal/detail/log.h>
#include <sal/log.hxx>
#include <sal/macros.h>
#include <sal/mathconf.h>
#include <sal/saldllapi.h>
#include <sal/types.h>
#include <sal/typesizes.h>
#include <salhelper/salhelperdllapi.h>
#include <salhelper/simplereferenceobject.hxx>
#include <vcl/accel.hxx>
#include <vcl/alpha.hxx>
#include <vcl/animate.hxx>
#include <vcl/bitmap.hxx>
#include <vcl/bitmapex.hxx>
#include <vcl/builder.hxx>
#include <vcl/builderfactory.hxx>
#include <vcl/button.hxx>
#include <vcl/cairo.hxx>
#include <vcl/checksum.hxx>
#include <vcl/commandevent.hxx>
#include <vcl/combobox.hxx>
#include <vcl/ctrl.hxx>
#include <vcl/cursor.hxx>
#include <vcl/devicecoordinate.hxx>
#include <vcl/dialog.hxx>
#include <vcl/dllapi.h>
#include <vcl/dndhelp.hxx>
#include <vcl/edit.hxx>
#include <vcl/event.hxx>
#include <vcl/field.hxx>
#include <vcl/fixed.hxx>
#include <vcl/fntstyle.hxx>
#include <vcl/font.hxx>
#include <vcl/gdimtf.hxx>
#include <vcl/gfxlink.hxx>
#include <vcl/gradient.hxx>
#include <vcl/graph.hxx>
#include <vcl/hatch.hxx>
#include <vcl/idle.hxx>
#include <vcl/image.hxx>
#include <vcl/inputctx.hxx>
#include <vcl/inputtypes.hxx>
#include <vcl/jobset.hxx>
#include <vcl/keycod.hxx>
#include <vcl/keycodes.hxx>
#include <vcl/layout.hxx>
#include <vcl/lineinfo.hxx>
#include <vcl/lstbox.hxx>
#include <vcl/mapmod.hxx>
#include <vcl/menu.hxx>
#include <vcl/metaact.hxx>
#include <vcl/metaactiontypes.hxx>
#include <vcl/metric.hxx>
#include <vcl/mnemonicengine.hxx>
#include <vcl/msgbox.hxx>
#include <vcl/outdev.hxx>
#include <vcl/outdevmap.hxx>
#include <vcl/outdevstate.hxx>
#include <vcl/pointr.hxx>
#include <vcl/prntypes.hxx>
#include <vcl/ptrstyle.hxx>
#include <vcl/quickselectionengine.hxx>
#include <vcl/region.hxx>
#include <vcl/salgtype.hxx>
#include <vcl/salnativewidgets.hxx>
#include <vcl/scheduler.hxx>
#include <vcl/scopedbitmapaccess.hxx>
#include <vcl/scrbar.hxx>
#include <vcl/seleng.hxx>
#include <vcl/settings.hxx>
#include <vcl/spinfld.hxx>
#include <vcl/svapp.hxx>
#include <vcl/svgdata.hxx>
#include <vcl/syswin.hxx>
#include <vcl/tabctrl.hxx>
#include <vcl/tabdlg.hxx>
#include <vcl/tabpage.hxx>
#include <vcl/timer.hxx>
#include <vcl/vclenum.hxx>
#include <vcl/vclevent.hxx>
#include <vcl/vclmedit.hxx>
#include <vcl/vclptr.hxx>
#include <vcl/virdev.hxx>
#include <vcl/wall.hxx>
#include <vcl/window.hxx>
#include <basegfx/basegfxdllapi.h>
#include <basegfx/color/bcolor.hxx>
#include <basegfx/color/bcolormodifier.hxx>
#include <basegfx/matrix/b2dhommatrix.hxx>
#include <basegfx/numeric/ftools.hxx>
#include <basegfx/point/b2dpoint.hxx>
#include <basegfx/point/b2ipoint.hxx>
#include <basegfx/polygon/b2dpolygon.hxx>
#include <basegfx/polygon/b2dpolypolygon.hxx>
#include <basegfx/range/b2drange.hxx>
#include <basegfx/range/basicrange.hxx>
#include <basegfx/tuple/b2dtuple.hxx>
#include <basegfx/tuple/b2ituple.hxx>
#include <basegfx/tuple/b3dtuple.hxx>
#include <basegfx/vector/b2dvector.hxx>
#include <basegfx/vector/b2enums.hxx>
#include <basegfx/vector/b2ivector.hxx>
#include <basic/basicdllapi.h>
#include <basic/sbdef.hxx>
#include <basic/sbxcore.hxx>
#include <basic/sbxdef.hxx>
#include <basic/sbxform.hxx>
#include <basic/sbxmeth.hxx>
#include <basic/sbxobj.hxx>
#include <basic/sbxprop.hxx>
#include <basic/sbxvar.hxx>
#include <com/sun/star/accessibility/TextSegment.hpp>
#include <com/sun/star/awt/GradientStyle.hpp>
#include <com/sun/star/awt/Key.hpp>
#include <com/sun/star/awt/KeyGroup.hpp>
#include <com/sun/star/awt/XControlContainer.hpp>
#include <com/sun/star/beans/NamedValue.hpp>
#include <com/sun/star/beans/PropertyState.hpp>
#include <com/sun/star/beans/PropertyValue.hpp>
#include <com/sun/star/beans/XPropertySet.hpp>
#include <com/sun/star/beans/XPropertySetInfo.hpp>
#include <com/sun/star/bridge/oleautomation/Decimal.hpp>
#include <com/sun/star/container/XIndexAccess.hpp>
#include <com/sun/star/container/XNameContainer.hpp>
#include <com/sun/star/datatransfer/DataFlavor.hpp>
#include <com/sun/star/datatransfer/XTransferable2.hpp>
#include <com/sun/star/datatransfer/clipboard/XClipboardOwner.hpp>
#include <com/sun/star/datatransfer/dnd/DNDConstants.hpp>
#include <com/sun/star/datatransfer/dnd/DropTargetDragEvent.hpp>
#include <com/sun/star/datatransfer/dnd/DropTargetDropEvent.hpp>
#include <com/sun/star/datatransfer/dnd/XDragGestureListener.hpp>
#include <com/sun/star/datatransfer/dnd/XDragGestureRecognizer.hpp>
#include <com/sun/star/datatransfer/dnd/XDragSourceListener.hpp>
#include <com/sun/star/datatransfer/dnd/XDropTarget.hpp>
#include <com/sun/star/datatransfer/dnd/XDropTargetListener.hpp>
#include <com/sun/star/drawing/DashStyle.hpp>
#include <com/sun/star/drawing/FillStyle.hpp>
#include <com/sun/star/drawing/HatchStyle.hpp>
#include <com/sun/star/drawing/LineCap.hpp>
#include <com/sun/star/drawing/LineStyle.hpp>
#include <com/sun/star/embed/Aspects.hpp>
#include <com/sun/star/embed/VerbDescriptor.hpp>
#include <com/sun/star/embed/XStorage.hpp>
#include <com/sun/star/frame/FeatureStateEvent.hpp>
#include <com/sun/star/frame/XController2.hpp>
#include <com/sun/star/frame/XFrame.hpp>
#include <com/sun/star/frame/XModel.hpp>
#include <com/sun/star/frame/XTerminateListener.hpp>
#include <com/sun/star/frame/status/Verb.hpp>
#include <com/sun/star/graphic/XPrimitive2D.hpp>
#include <com/sun/star/i18n/Calendar2.hpp>
#include <com/sun/star/i18n/CharacterIteratorMode.hpp>
#include <com/sun/star/i18n/ForbiddenCharacters.hpp>
#include <com/sun/star/i18n/KCharacterType.hpp>
#include <com/sun/star/i18n/KParseTokens.hpp>
#include <com/sun/star/i18n/KParseType.hpp>
#include <com/sun/star/i18n/LocaleItem.hpp>
#include <com/sun/star/i18n/ParseResult.hpp>
#include <com/sun/star/i18n/WordType.hpp>
#include <com/sun/star/i18n/XCharacterClassification.hpp>
#include <com/sun/star/i18n/XCollator.hpp>
#include <com/sun/star/i18n/XExtendedTransliteration.hpp>
#include <com/sun/star/i18n/XLocaleData4.hpp>
#include <com/sun/star/i18n/XNativeNumberSupplier.hpp>
#include <com/sun/star/i18n/reservedWords.hpp>
#include <com/sun/star/io/XInputStream.hpp>
#include <com/sun/star/lang/DisposedException.hpp>
#include <com/sun/star/lang/EventObject.hpp>
#include <com/sun/star/lang/IllegalArgumentException.hpp>
#include <com/sun/star/lang/Locale.hpp>
#include <com/sun/star/lang/XComponent.hpp>
#include <com/sun/star/lang/XMultiServiceFactory.hpp>
#include <com/sun/star/lang/XServiceInfo.hpp>
#include <com/sun/star/lang/XSingleComponentFactory.hpp>
#include <com/sun/star/lang/XSingleServiceFactory.hpp>
#include <com/sun/star/lang/XTypeProvider.hpp>
#include <com/sun/star/lang/XUnoTunnel.hpp>
#include <com/sun/star/registry/XRegistryKey.hpp>
#include <com/sun/star/style/NumberingType.hpp>
#include <com/sun/star/style/XStyle.hpp>
#include <com/sun/star/table/BorderLineStyle.hpp>
#include <com/sun/star/uno/Any.h>
#include <com/sun/star/uno/Any.hxx>
#include <com/sun/star/uno/Exception.hpp>
#include <com/sun/star/uno/Reference.h>
#include <com/sun/star/uno/Reference.hxx>
#include <com/sun/star/uno/RuntimeException.hpp>
#include <com/sun/star/uno/Sequence.h>
#include <com/sun/star/uno/Sequence.hxx>
#include <com/sun/star/uno/Type.h>
#include <com/sun/star/uno/Type.hxx>
#include <com/sun/star/uno/TypeClass.hdl>
#include <com/sun/star/uno/XAggregation.hpp>
#include <com/sun/star/uno/XComponentContext.hpp>
#include <com/sun/star/uno/XInterface.hpp>
#include <com/sun/star/uno/XWeak.hpp>
#include <com/sun/star/uno/genfunc.h>
#include <com/sun/star/uno/genfunc.hxx>
#include <com/sun/star/util/Date.hpp>
#include <com/sun/star/util/DateTime.hpp>
#include <com/sun/star/util/Time.hpp>
#include <com/sun/star/util/URL.hpp>
#include <com/sun/star/view/PrintableState.hpp>
#include <comphelper/broadcasthelper.hxx>
#include <comphelper/comphelperdllapi.h>
#include <comphelper/fileformat.h>
#include <comphelper/namedvaluecollection.hxx>
#include <comphelper/processfactory.hxx>
#include <comphelper/weak.hxx>
#include <cppu/cppudllapi.h>
#include <cppu/unotype.hxx>
#include <cppuhelper/compbase1.hxx>
#include <cppuhelper/compbase_ex.hxx>
#include <cppuhelper/cppuhelperdllapi.h>
#include <cppuhelper/factory.hxx>
#include <cppuhelper/implbase1.hxx>
#include <cppuhelper/implbase2.hxx>
#include <cppuhelper/implbase3.hxx>
#include <cppuhelper/implbase4.hxx>
#include <cppuhelper/implbase_ex.hxx>
#include <cppuhelper/implbase_ex_post.hxx>
#include <cppuhelper/implbase_ex_pre.hxx>
#include <cppuhelper/interfacecontainer.h>
#include <cppuhelper/queryinterface.hxx>
#include <cppuhelper/supportsservice.hxx>
#include <cppuhelper/typeprovider.hxx>
#include <cppuhelper/weak.hxx>
#include <cppuhelper/weakagg.hxx>
#include <cppuhelper/weakref.hxx>
#include <drawdoc.hxx>
#include <drawinglayer/drawinglayerdllapi.h>
#include <drawinglayer/primitive2d/baseprimitive2d.hxx>
#include <editeng/editdata.hxx>
#include <editeng/editeng.hxx>
#include <editeng/editengdllapi.h>
#include <editeng/editstat.hxx>
#include <editeng/eedata.hxx>
#include <editeng/eeitem.hxx>
#include <editeng/forbiddencharacterstable.hxx>
#include <editeng/numdef.hxx>
#include <editeng/numitem.hxx>
#include <editeng/outliner.hxx>
#include <editeng/paragraphdata.hxx>
#include <editeng/svxenum.hxx>
#include <editeng/svxfont.hxx>
#include <i18nlangtag/i18nlangtagdllapi.h>
#include <i18nlangtag/lang.h>
#include <i18nlangtag/languagetag.hxx>
#include <i18nutil/i18nutildllapi.h>
#include <i18nutil/paper.hxx>
#include <o3tl/cow_wrapper.hxx>
#include <o3tl/typed_flags_set.hxx>
#include <rsc/rsc-vcl-shared-types.hxx>
#include <rsc/rscsfx.hxx>
#include <sdattr.hxx>
#include <sdmod.hxx>
#include <sdpage.hxx>
#include <sdresid.hxx>
#include <sfx2/app.hxx>
#include <sfx2/dllapi.h>
#include <sfx2/docfile.hxx>
#include <sfx2/frame.hxx>
#include <sfx2/module.hxx>
#include <sfx2/objsh.hxx>
#include <sfx2/sfxuno.hxx>
#include <sfx2/shell.hxx>
#include <sot/formats.hxx>
#include <sot/sotdllapi.h>
#include <svl/SfxBroadcaster.hxx>
#include <svl/aeitem.hxx>
#include <svl/cenumitm.hxx>
#include <svl/custritm.hxx>
#include <svl/eitem.hxx>
#include <svl/hint.hxx>
#include <svl/intitem.hxx>
#include <svl/itempool.hxx>
#include <svl/itemprop.hxx>
#include <svl/itemset.hxx>
#include <svl/languageoptions.hxx>
#include <svl/lstner.hxx>
#include <svl/metitem.hxx>
#include <svl/poolitem.hxx>
#include <svl/smplhint.hxx>
#include <svl/stritem.hxx>
#include <svl/style.hxx>
#include <svl/stylesheetuser.hxx>
#include <svl/svldllapi.h>
#include <svl/undo.hxx>
#include <svtools/colorcfg.hxx>
#include <svtools/grfmgr.hxx>
#include <svtools/imgdef.hxx>
#include <svtools/miscopt.hxx>
#include <svtools/optionsdrawinglayer.hxx>
#include <svtools/svtdllapi.h>
#include <svtools/transfer.hxx>
#include <svtools/treelist.hxx>
#include <svtools/treelistentries.hxx>
#include <svtools/viewdataentry.hxx>
#include <svx/XPropertyEntry.hxx>
#include <svx/drawitem.hxx>
#include <svx/flagsdef.hxx>
#include <svx/grfcrop.hxx>
#include <svx/ipolypolygoneditorcontroller.hxx>
#include <svx/itextprovider.hxx>
#include <svx/pageitem.hxx>
#include <svx/rectenum.hxx>
#include <svx/sdangitm.hxx>
#include <svx/sdasaitm.hxx>
#include <svx/sdasitm.hxx>
#include <svx/sderitm.hxx>
#include <svx/sdgcoitm.hxx>
#include <svx/sdgcpitm.hxx>
#include <svx/sdggaitm.hxx>
#include <svx/sdginitm.hxx>
#include <svx/sdgluitm.hxx>
#include <svx/sdgmoitm.hxx>
#include <svx/sdgtritm.hxx>
#include <svx/sdmetitm.hxx>
#include <svx/sdooitm.hxx>
#include <svx/sdprcitm.hxx>
#include <svx/sdr/animation/scheduler.hxx>
#include <svx/sdr/overlay/overlayobject.hxx>
#include <svx/sdr/overlay/overlayobjectlist.hxx>
#include <svx/sdrobjectuser.hxx>
#include <svx/sdrpageuser.hxx>
#include <svx/sdshcitm.hxx>
#include <svx/sdshitm.hxx>
#include <svx/sdshtitm.hxx>
#include <svx/sdsxyitm.hxx>
#include <svx/sdtaaitm.hxx>
#include <svx/sdtacitm.hxx>
#include <svx/sdtaditm.hxx>
#include <svx/sdtagitm.hxx>
#include <svx/sdtaiitm.hxx>
#include <svx/sdtaitm.hxx>
#include <svx/sdtakitm.hxx>
#include <svx/sdtayitm.hxx>
#include <svx/sdtcfitm.hxx>
#include <svx/sdtditm.hxx>
#include <svx/sdtfsitm.hxx>
#include <svx/sdtmfitm.hxx>
#include <svx/sdynitm.hxx>
#include <svx/selectioncontroller.hxx>
#include <svx/shapeproperty.hxx>
#include <svx/svdattr.hxx>
#include <svx/svddef.hxx>
#include <svx/svddrag.hxx>
#include <svx/svdedtv.hxx>
#include <svx/svdedxv.hxx>
#include <svx/svdglev.hxx>
#include <svx/svdglue.hxx>
#include <svx/svdhdl.hxx>
#include <svx/svdhlpln.hxx>
#include <svx/svdlayer.hxx>
#include <svx/svdmark.hxx>
#include <svx/svdmodel.hxx>
#include <svx/svdmrkv.hxx>
#include <svx/svdoattr.hxx>
#include <svx/svdobj.hxx>
#include <svx/svdoedge.hxx>
#include <svx/svdorect.hxx>
#include <svx/svdotext.hxx>
#include <svx/svdpagv.hxx>
#include <svx/svdpntv.hxx>
#include <svx/svdpoev.hxx>
#include <svx/svdsnpv.hxx>
#include <svx/svdsob.hxx>
#include <svx/svdtext.hxx>
#include <svx/svdtrans.hxx>
#include <svx/svdtypes.hxx>
#include <svx/svdxcgv.hxx>
#include <svx/svxdlg.hxx>
#include <svx/svxdllapi.h>
#include <svx/xcolit.hxx>
#include <svx/xdash.hxx>
#include <svx/xdef.hxx>
#include <svx/xenum.hxx>
#include <svx/xfillit0.hxx>
#include <svx/xflasit.hxx>
#include <svx/xgrad.hxx>
#include <svx/xhatch.hxx>
#include <svx/xit.hxx>
#include <svx/xlineit0.hxx>
#include <svx/xlnasit.hxx>
#include <svx/xpoly.hxx>
#include <svx/xtable.hxx>
#include <svx/xtextit0.hxx>
#include <tools/color.hxx>
#include <tools/contnr.hxx>
#include <tools/date.hxx>
#include <tools/datetime.hxx>
#include <tools/debug.hxx>
#include <tools/errcode.hxx>
#include <tools/errinf.hxx>
#include <tools/fldunit.hxx>
#include <tools/fontenum.hxx>
#include <tools/fract.hxx>
#include <tools/gen.hxx>
#include <tools/globname.hxx>
#include <tools/lineend.hxx>
#include <tools/link.hxx>
#include <tools/mapunit.hxx>
#include <tools/multisel.hxx>
#include <tools/poly.hxx>
#include <tools/rc.hxx>
#include <tools/ref.hxx>
#include <tools/resid.hxx>
#include <tools/resmgr.hxx>
#include <tools/solar.h>
#include <tools/stream.hxx>
#include <tools/svborder.hxx>
#include <tools/time.hxx>
#include <tools/toolsdllapi.h>
#include <tools/weakbase.h>
#include <tools/weakbase.hxx>
#include <tools/wintypes.hxx>
#include <typelib/typeclass.h>
#include <typelib/typedescription.h>
#include <typelib/uik.h>
#include <uno/any2.h>
#include <uno/data.h>
#include <uno/sequence2.h>
#include <unotools/charclass.hxx>
#include <unotools/configitem.hxx>
#include <unotools/fontcvt.hxx>
#include <unotools/fontdefs.hxx>
#include <unotools/localedatawrapper.hxx>
#include <unotools/options.hxx>
#include <unotools/pathoptions.hxx>
#include <unotools/readwritemutexguard.hxx>
#include <unotools/syslocale.hxx>
#include <unotools/unotoolsdllapi.h>

/* vim:set shiftwidth=4 softtabstop=4 expandtab: */
