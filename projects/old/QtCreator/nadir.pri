########################################################################
# Copyright (c) 1988-2016 $organization$
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
#   Date: 9/17/2016
########################################################################

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

nadir_DEFINES += \
BUILD_CONFIG=$${BUILD_CONFIG} \
WINSOCK_2 \

nadir_LIBS += \
-L$${NADIR_LIB}/libnadir \
-lnadir \

########################################################################
# neonadir
neonadir_INCLUDEPATH += \
$${NADIR_SRC}/neo \
$${NADIR_SRC} \

neonadir_DEFINES += \
$${nadir_DEFINES} \

neonadir_LIBS += \
-L$${NADIR_LIB}/libneonadir \
-lneonadir \

########################################################################
# xosnadir
xosnadir_INCLUDEPATH += \
$${NADIR_SRC} \

xosnadir_DEFINES += \
$${nadir_DEFINES} \
NO_USE_XOS_LOGGER_INTERFACE \

xosnadir_LIBS += \
-L$${NADIR_LIB}/libxosnadir \
-lxosnadir \

########################################################################
# rostra
ROSTRA_CPP_XOS_PKG = $${NADIR_PKG}/../rostra/cpp/xos
ROSTRA_CPP_XOS_PRJ = $${ROSTRA_CPP_XOS_PKG}
ROSTRA_CPP_XOS_SRC = $${ROSTRA_CPP_XOS_PKG}/src

rostra_cpp_xos_INCLUDEPATH += \
$${ROSTRA_CPP_XOS_SRC} \

rostra_cpp_xos_DEFINES += \

rostra_cpp_xos_LIBS += \

########################################################################
# nadir/cpp/xos
NADIR_CPP_XOS_PKG = $${NADIR_PKG}/cpp/xos
NADIR_CPP_XOS_PRJ = $${NADIR_CPP_XOS_PKG}
NADIR_CPP_XOS_SRC = $${NADIR_CPP_XOS_PKG}/src

nadir_cpp_xos_INCLUDEPATH += \
$${NADIR_CPP_XOS_SRC} \
$${rostra_cpp_xos_INCLUDEPATH} \
$${nadir_INCLUDEPATH} \

nadir_cpp_xos_DEFINES += \
$${nadir_DEFINES} \

nadir_cpp_xos_LIBS += \
