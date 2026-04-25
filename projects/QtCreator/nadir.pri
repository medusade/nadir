########################################################################
# Copyright (c) 1988-2023 $organization$
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
#   Date: 3/4/2023, 2/28/2024
#
# generic QtCreator project .pri file for medusade framework nadir
########################################################################
# Depends: rostra

OTHER_RPO = ../../../../../../..
OTHER_PKG = ../../../../../..
OTHER_PRJ = ../../../../..
OTHER_BLD = ..

THIRDPARTY_NAME = thirdparty
THIRDPARTY_PKG = $${OTHER_PKG}/$${THIRDPARTY_NAME}
THIRDPARTY_PRJ = $${OTHER_PRJ}/$${THIRDPARTY_NAME}
THIRDPARTY_SRC = $${OTHER_PRJ}/source/$${THIRDPARTY_NAME}

########################################################################
# rostra
ROSTRA_VERSION_MAJOR = 0
ROSTRA_VERSION_MINOR = 0
ROSTRA_VERSION_RELEASE = 0
ROSTRA_VERSION = $${ROSTRA_VERSION_MAJOR}.$${ROSTRA_VERSION_MINOR}.$${ROSTRA_VERSION_RELEASE}
ROSTRA_NAME = rostra
ROSTRA_GROUP = $${ROSTRA_NAME}
ROSTRA_SOURCE = source
ROSTRA_CREDS = creds
ROSTRA_DIR = $${ROSTRA_GROUP}/$${ROSTRA_NAME}-$${ROSTRA_VERSION}
ROSTRA_PKG_DIR = $${ROSTRA_NAME}
ROSTRA_BUILD_HOME = $${HOME}
ROSTRA_HOME_BUILD = $${ROSTRA_BUILD_HOME}/build/$${ROSTRA_NAME}
ROSTRA_HOME_BUILD_INCLUDE = $${ROSTRA_HOME_BUILD}/include
ROSTRA_HOME_BUILD_LIB = $${ROSTRA_HOME_BUILD}/lib
ROSTRA_THIRDPARTY_PKG = $${THIRDPARTY_PKG}/$${ROSTRA_DIR}
ROSTRA_THIRDPARTY_PRJ = $${THIRDPARTY_PRJ}/$${ROSTRA_DIR}
ROSTRA_THIRDPARTY_SRC = $${THIRDPARTY_SRC}/$${ROSTRA_PKG_DIR}
ROSTRA_THIRDPARTY_SRC_GROUP = $${ROSTRA_GROUP}
ROSTRA_THIRDPARTY_SRC_NAME = $${ROSTRA_NAME}
ROSTRA_THIRDPARTY_SRC_DIR = $${THIRDPARTY_SRC}/$${ROSTRA_THIRDPARTY_SRC_GROUP}/$${ROSTRA_THIRDPARTY_SRC_NAME} 
ROSTRA_PKG = $${OTHER_PKG}/$${ROSTRA_PKG_DIR}
ROSTRA_PRJ = $${OTHER_PRJ}/$${ROSTRA_PKG_DIR}
#ROSTRA_SRC = $${ROSTRA_THIRDPARTY_SRC_DIR}
#ROSTRA_SRC = $${ROSTRA_THIRDPARTY_PKG}/$${ROSTRA_SOURCE}
#ROSTRA_SRC = $${ROSTRA_THIRDPARTY_PRJ}/$${ROSTRA_SOURCE}
ROSTRA_SRC = $${ROSTRA_PKG}/$${ROSTRA_SOURCE}
#ROSTRA_SRC = $${ROSTRA_PRJ}/$${ROSTRA_SOURCE}
ROSTRA_CRD_SRC = $${ROSTRA_PKG}/$${ROSTRA_CREDS}/$${ROSTRA_SOURCE}

# rostra INCLUDEPATH
#
rostra_INCLUDEPATH += \
$${ROSTRA_SRC} \
$${ROSTRA_CRD_SRC} \

# rostra DEFINES
#
rostra_DEFINES += \


########################################################################
# nadir
NADIR_NAME = nadir
NADIR_SOURCE = source
NADIR_CREDS = creds
NADIR_SOURCE_LIBRARY = base

NADIR_PKG = ../../../../..
NADIR_BLD = ../..

NADIR_PRJ = $${NADIR_PKG}
NADIR_BIN = $${NADIR_BLD}/bin
NADIR_LIB = $${NADIR_BLD}/lib
NADIR_SRC = $${NADIR_PKG}/$${NADIR_SOURCE}
NADIR_CRD_SRC = $${NADIR_PKG}/$${NADIR_CREDS}/$${NADIR_SOURCE}
NADIR_SRC_SOURCE = $${NADIR_SRC}/$${NADIR_SOURCE}

# nadir BUILD_CONFIG
#
CONFIG(debug, debug|release) {
BUILD_CONFIG = Debug
nadir_DEFINES += DEBUG_BUILD
} else {
BUILD_CONFIG = Release
nadir_DEFINES += RELEASE_BUILD
}

########################################################################
# nadir INCLUDEPATH
#
nadir_INCLUDEPATH += \
$${NADIR_SRC} \
$${NADIR_CRD_SRC} \
$${rostra_INCLUDEPATH} \
$${build_nadir_INCLUDEPATH} \

# nadir DEFINES
#
nadir_DEFINES += \
$${rostra_DEFINES} \
$${build_nadir_DEFINES} \

# nadir LIBS
#
nadir_LIBS += \
-L$${NADIR_LIB}/lib$${NADIR_NAME} \
-l$${NADIR_NAME} \

########################################################################
# xosnadir INCLUDEPATH
#
xosnadir_INCLUDEPATH += \
$${nadir_INCLUDEPATH} \

# xosnadir DEFINES
#
xosnadir_DEFINES += \
$${nadir_DEFINES} \
NO_USE_NADIR_BASE \
NO_USE_XOS_LOGGER_INTERFACE \

# xosnadir LIBS
#
xosnadir_LIBS += \
-L$${NADIR_LIB}/libxos$${NADIR_NAME} \
-lxos$${NADIR_NAME} \

########################################################################
# nadir SOURCE INCLUDEPATH
#
nadir_SOURCE_INCLUDEPATH += \
$${NADIR_SRC_SOURCE} \
$${nadir_INCLUDEPATH} \

# nadir SOURCE DEFINES
#
nadir_SOURCE_DEFINES += \
$${nadir_DEFINES} \

# nadir SOURCE LIBS
#
nadir_SOURCE_LIBS += \
-L$${NADIR_LIB}/lib$${NADIR_SOURCE_LIBRARY} \
-l$${NADIR_SOURCE_LIBRARY} \

########################################################################
# xosnadir SOURCE INCLUDEPATH
#
xosnadir_SOURCE_INCLUDEPATH += \
$${nadir_SOURCE_INCLUDEPATH} \

# xosnadir SOURCE DEFINES
#
xosnadir_SOURCE_DEFINES += \
$${nadir_SOURCE_DEFINES} \
NO_USE_NADIR_BASE \
NO_USE_XOS_LOGGER_INTERFACE \

# xosnadir SOURCE LIBS
#
xosnadir_SOURCE_LIBS += \
-L$${NADIR_LIB}/libxos$${NADIR_SOURCE_LIBRARY} \
-lxos$${NADIR_SOURCE_LIBRARY} \
