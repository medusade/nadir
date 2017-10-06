########################################################################
# Copyright (c) 1988-2017 $organization$
#
# This software is provided by the author and contributors ``as is''
# and any express or implied warranties, including, but not limited to,
# the implied warranties of merchantability and fitness for a particular
# purpose are disclaimed. In no event shall the author or contributors
# be liable for any direct, indirect, incidental, special, exemplary,
# or consequential damages (including, but not limited to, procurement
# of substitute goods or services; loss of use, data, or profits; or
# business interruption) however caused and on any theory of liability,
# whether in contract, strict liability, or tort (including negligence
# or otherwise) arising in any way out of the use of this software,
# even if advised of the possibility of such damage.
#
#   File: nadir.pri
#
# Author: $author$
#   Date: 9/26/2017
#
# QtCreator .pri file for nadir executable nadir
########################################################################

nadir_exe_TARGET = nadir

########################################################################
nadir_exe_INCLUDEPATH += \
$${nadir_INCLUDEPATH} \

nadir_exe_DEFINES += \
$${nadir_DEFINES} \
XDE_CAPP_CCONSOLE_CXDE_CMAIN_THE_MAIN \

########################################################################
# patrona
nadir_exe_HEADERS += \
$${PATRONA_SRC}/xde/cbase/cattached.hxx \

nadir_exe_SOURCES += \
$${PATRONA_SRC}/xde/cbase/cattached.cxx \

########################################################################
# crono
nadir_exe_HEADERS += \
$${CRONO_SRC}/xde/cdebug/cdebug.hxx \
$${CRONO_SRC}/xde/cdebug/cdebug.h \

nadir_exe_SOURCES += \
$${CRONO_SRC}/xde/cdebug/cdebug.cxx \

########################################################################
# texta
nadir_exe_HEADERS += \
$${TEXTA_SRC}/xde/capp/cconsole/ct/ctmain.hxx \
$${TEXTA_SRC}/xde/ct/ct.hxx \
$${TEXTA_SRC}/xde/ct/ctbasefunctions.hxx \
$${TEXTA_SRC}/xde/ct/ctblockfunctions.hxx \
$${TEXTA_SRC}/xde/ct/ctcomparefunctions.hxx \
$${TEXTA_SRC}/xde/ct/ctcontrolfunctions.hxx \
$${TEXTA_SRC}/xde/ct/ctconvertfunctions.hxx \
$${TEXTA_SRC}/xde/ct/ctparsefunctions.hxx \
$${TEXTA_SRC}/xde/ct/ctstringfunctions.hxx \
$${TEXTA_SRC}/xde/ct/ctdatefunctions.hxx \
$${TEXTA_SRC}/xde/ct/ctfilefunctions.hxx \
$${TEXTA_SRC}/xde/ct/ctfunctions.hxx \
$${TEXTA_SRC}/xde/ct/ctfunction.hxx \
$${TEXTA_SRC}/xde/ct/ctvariable.hxx \
$${TEXTA_SRC}/xde/ct/ctvalue.hxx \
$${TEXTA_SRC}/xde/ct/ctbase.hxx \

nadir_exe_SOURCES += \
$${TEXTA_SRC}/xde/capp/cconsole/ct/ctmain.cxx \
$${TEXTA_SRC}/xde/ct/ct.cxx \
$${TEXTA_SRC}/xde/ct/ctbasefunctions.cxx \
$${TEXTA_SRC}/xde/ct/ctblockfunctions.cxx \
$${TEXTA_SRC}/xde/ct/ctcomparefunctions.cxx \
$${TEXTA_SRC}/xde/ct/ctcontrolfunctions.cxx \
$${TEXTA_SRC}/xde/ct/ctconvertfunctions.cxx \
$${TEXTA_SRC}/xde/ct/ctparsefunctions.cxx \
$${TEXTA_SRC}/xde/ct/ctstringfunctions.cxx \
$${TEXTA_SRC}/xde/ct/ctdatefunctions.cxx \
$${TEXTA_SRC}/xde/ct/ctfilefunctions.cxx \
$${TEXTA_SRC}/xde/ct/ctfunctions.cxx \
$${TEXTA_SRC}/xde/ct/ctfunction.cxx \
$${TEXTA_SRC}/xde/ct/ctvariable.cxx \
$${TEXTA_SRC}/xde/ct/ctvalue.cxx \
$${TEXTA_SRC}/xde/ct/ctbase.cxx \

########################################################################
# nadir
nadir_exe_HEADERS += \
$${NADIR_SRC}/xde/cbase/cdigitizer.hxx \
$${NADIR_SRC}/xde/cbase/ccomparer.hxx \
$${NADIR_SRC}/xde/cbase/csplitter.hxx \
$${NADIR_SRC}/xde/cbase/cstring.hxx \
$${NADIR_SRC}/xde/cbase/cbuffer.hxx \
$${NADIR_SRC}/xde/cbase/cstream.hxx \
$${NADIR_SRC}/xde/cbase/cbinarytree.hxx \
$${NADIR_SRC}/xde/cbase/clist.hxx \
$${NADIR_SRC}/xde/cbase/cbase.hxx \
$${NADIR_SRC}/xde/cbase/cerror.hxx \
$${NADIR_SRC}/xde/cbase/cerror.h \

nadir_exe_SOURCES += \
$${NADIR_SRC}/xde/cbase/cdigitizer.cxx \
$${NADIR_SRC}/xde/cbase/ccomparer.cxx \
$${NADIR_SRC}/xde/cbase/csplitter.cxx \
$${NADIR_SRC}/xde/cbase/cstring.cxx \
$${NADIR_SRC}/xde/cbase/cbuffer.cxx \
$${NADIR_SRC}/xde/cbase/cstream.cxx \
$${NADIR_SRC}/xde/cbase/cbinarytree.cxx \
$${NADIR_SRC}/xde/cbase/clist.cxx \
$${NADIR_SRC}/xde/cbase/cbase.cxx \
$${NADIR_SRC}/xde/cbase/cerror.cxx \

########################################################################
# nadir
nadir_exe_HEADERS += \
$${NADIR_SRC}/xde/cfs/cfilesystemdirectory.hxx \
$${NADIR_SRC}/xde/cos/cfile.hxx \
$${NADIR_SRC}/xde/cplatform/cplatform.h \

nadir_exe_SOURCES += \
$${NADIR_SRC}/xde/cfs/cfilesystemdirectory.cxx \
$${NADIR_SRC}/xde/cos/cfile.cxx \

########################################################################
# nadir
nadir_exe_HEADERS += \
$${NADIR_SRC}/xde/cconsole/cargmain.hxx \
$${NADIR_SRC}/xde/cconsole/cmainarg.hxx \
$${NADIR_SRC}/xde/cconsole/cmain.hxx \
$${NADIR_SRC}/xde/cconsole/main.hxx \
$${NADIR_SRC}/xde/capp/cconsole/cxde/cmain.hxx \

nadir_exe_SOURCES += \
$${NADIR_SRC}/xde/cconsole/cargmain.cxx \
$${NADIR_SRC}/xde/cconsole/cmainarg.cxx \
$${NADIR_SRC}/xde/cconsole/main.cxx \

########################################################################
nadir_exe_LIBS += \
$${nadir_LIBS} \
