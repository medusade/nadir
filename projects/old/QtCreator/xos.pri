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
#   File: xos.pri
#
# Author: $author$
#   Date: 10/20/2017
#
# QtCreator .pri file for xos
########################################################################
OTHER_PKG = ../../../../../..
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
# xos
XOS_PKG = ../../../../..
XOS_BLD = ../..

XOS_PRJ = $${XOS_PKG}
XOS_BIN = $${XOS_BLD}/bin
XOS_LIB = $${XOS_BLD}/lib
XOS_SRC = $${XOS_PKG}/src

CONFIG(debug, debug|release) {
BUILD_CONFIG = Debug
xos_DEFINES += DEBUG_BUILD
} else {
BUILD_CONFIG = Release
xos_DEFINES += RELEASE_BUILD
}

xos_INCLUDEPATH += \
$${XOS_SRC} \
$${rostra_INCLUDEPATH} \
$${build_xos_INCLUDEPATH} \

xos_DEFINES += \
$${rostra_DEFINES} \
$${build_xos_DEFINES} \

xos_LIBS += \
-L$${XOS_LIB}/libxosnadir \
-lxosnadir \

########################################################################
