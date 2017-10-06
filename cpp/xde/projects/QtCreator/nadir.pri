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
# QtCreator .pri file for nadir
########################################################################

OTHER_PKG = ../../../../../../../..
OTHER_BLD = ..

########################################################################
# rostra
ROSTRA_PKG = $${OTHER_PKG}/rostra/cpp/xos
ROSTRA_PRJ = $${ROSTRA_PKG}
ROSTRA_SRC = $${ROSTRA_PKG}/src

rostra_INCLUDEPATH += \
$${ROSTRA_SRC} \

rostra_DEFINES += \

rostra_LIBS += \

########################################################################
# patrona
PATRONA_PKG = $${OTHER_PKG}/patrona/cpp/xde
PATRONA_PRJ = $${PATRONA_PKG}
PATRONA_SRC = $${PATRONA_PKG}/src

patrona_INCLUDEPATH += \
$${PATRONA_SRC} \

patrona_DEFINES += \

patrona_LIBS += \

########################################################################
# crono
CRONO_PKG = $${OTHER_PKG}/crono/cpp/xde
CRONO_PRJ = $${CRONO_PKG}
CRONO_SRC = $${CRONO_PKG}/src

crono_INCLUDEPATH += \
$${CRONO_SRC} \

crono_DEFINES += \

crono_LIBS += \

########################################################################
# texta
TEXTA_PKG = $${OTHER_PKG}/texta/cpp/xde
TEXTA_PRJ = $${TEXTA_PKG}
TEXTA_SRC = $${TEXTA_PKG}/src

texta_INCLUDEPATH += \
$${TEXTA_SRC} \

texta_DEFINES += \

texta_LIBS += \

########################################################################
# nadir
NADIR_PKG = ../../../../..
NADIR_BLD = ../..

NADIR_PRJ = $${NADIR_PKG}
NADIR_BIN = $${NADIR_BLD}/bin
NADIR_LIB = $${NADIR_BLD}/lib
NADIR_SRC = $${NADIR_PKG}/src

CONFIG(debug, debug|release) {
BUILD_CONFIG = Debug
nadir_DEFINES += DEBUG_BUILD
} else {
BUILD_CONFIG = Release
nadir_DEFINES += RELEASE_BUILD
}

nadir_INCLUDEPATH += \
$${NADIR_SRC} \
$${texta_INCLUDEPATH} \
$${crono_INCLUDEPATH} \
$${patrona_INCLUDEPATH} \
$${rostra_INCLUDEPATH} \
$${build_nadir_INCLUDEPATH} \

nadir_DEFINES += \
$${rostra_DEFINES} \
$${patrona_DEFINES} \
$${crono_DEFINES} \
$${texta_DEFINES} \
$${build_nadir_DEFINES} \

nadir_LIBS += \
-L$${NADIR_LIB}/libnadir \
-lnadir \


