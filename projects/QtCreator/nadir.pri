########################################################################
# Copyright (c) 1988-2018 $organization$
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
#   Date: 5/10/2018, 1/12/2021
#
# QtCreator .pri file for nadir
########################################################################

OTHER_PKG = ../../../../../../..
OTHER_PRJ = ../../../../../..
OTHER_BLD = ..

THIRDPARTY_NAME = thirdparty
THIRDPARTY_PKG = $${OTHER_PKG}/$${THIRDPARTY_NAME}
THIRDPARTY_PRJ = $${OTHER_PRJ}/$${THIRDPARTY_NAME}
THIRDPARTY_SRC = $${OTHER_PRJ}/src/$${THIRDPARTY_NAME}

########################################################################
# rostra
ROSTRA_VERSION_MAJOR = 0
ROSTRA_VERSION_MINOR = 0
ROSTRA_VERSION_RELEASE = 0
ROSTRA_VERSION = $${ROSTRA_VERSION_MAJOR}.$${ROSTRA_VERSION_MINOR}.$${ROSTRA_VERSION_RELEASE}
ROSTRA_NAME = rostra
ROSTRA_GROUP = $${ROSTRA_NAME}
ROSTRA_SOURCE = src
ROSTRA_DIR = $${ROSTRA_GROUP}/$${ROSTRA_NAME}-$${ROSTRA_VERSION}
ROSTRA_PKG_DIR = $${ROSTRA_NAME}
ROSTRA_HOME_BUILD = $${HOME}/build/$${ROSTRA_NAME}
ROSTRA_HOME_BUILD_INCLUDE = $${ROSTRA_HOME_BUILD}/include
ROSTRA_HOME_BUILD_LIB = $${ROSTRA_HOME_BUILD}/lib
ROSTRA_THIRDPARTY_PKG = $${THIRDPARTY_PKG}/$${ROSTRA_DIR}
ROSTRA_THIRDPARTY_PRJ = $${THIRDPARTY_PRJ}/$${ROSTRA_DIR}
ROSTRA_THIRDPARTY_SRC = $${THIRDPARTY_SRC}/$${ROSTRA_PKG_DIR}
ROSTRA_THIRDPARTY_SRC_GROUP = $${ROSTRA_NAME}
ROSTRA_THIRDPARTY_SRC_NAME = $${ROSTRA_NAME}
ROSTRA_THIRDPARTY_SRC_DIR = $${THIRDPARTY_SRC}/$${ROSTRA_THIRDPARTY_SRC_GROUP}/$${ROSTRA_THIRDPARTY_SRC_NAME} 
ROSTRA_PKG = $${OTHER_PKG}/$${ROSTRA_PKG_DIR}
ROSTRA_PRJ = $${OTHER_PRJ}/$${ROSTRA_PKG_DIR}
#ROSTRA_SRC = $${ROSTRA_THIRDPARTY_SRC_DIR}
#ROSTRA_SRC = $${ROSTRA_THIRDPARTY_PKG}/$${ROSTRA_SOURCE}
#ROSTRA_SRC = $${ROSTRA_THIRDPARTY_PRJ}/$${ROSTRA_SOURCE}
#ROSTRA_SRC = $${ROSTRA_PKG}/$${ROSTRA_SOURCE}
ROSTRA_SRC = $${ROSTRA_PRJ}/$${ROSTRA_SOURCE}

# rostra INCLUDEPATH
#
#rostra_INCLUDEPATH += \
#$${ROSTRA_HOME_BUILD_INCLUDE} \

rostra_INCLUDEPATH += \
$${ROSTRA_SRC} \

# rostra DEFINES
#
rostra_DEFINES += \

########################################################################
# nadir
FRAMEWORK_NAME = nadir
FRAMEWORK_SRC = src
FRAMEWORK_LIBRARY_NAME = nadir
FRAMEWORK_SOURCE = source
FRAMEWORK_SOURCE_LIBRARY_NAME = base

NADIR_PKG = ../../../../..
NADIR_BLD = ../..

NADIR_PRJ = $${NADIR_PKG}
NADIR_BIN = $${NADIR_BLD}/bin
NADIR_LIB = $${NADIR_BLD}/lib
NADIR_SRC = $${NADIR_PKG}/$${FRAMEWORK_SRC}
NADIR_SOURCE = $${NADIR_PKG}/$${FRAMEWORK_SOURCE}

# nadir BUILD_CONFIG
#
CONFIG(debug, debug|release) {
BUILD_CONFIG = Debug
nadir_DEFINES += DEBUG_BUILD
} else {
BUILD_CONFIG = Release
nadir_DEFINES += RELEASE_BUILD
}

# nadir INCLUDEPATH
#
nadir_INCLUDEPATH += \
$${NADIR_SRC} \
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
-L$${NADIR_LIB}/lib$${FRAMEWORK_LIBRARY_NAME} \
-l$${FRAMEWORK_LIBRARY_NAME} \

########################################################################
# nadir SOURCE_INCLUDEPATH
#
nadir_SOURCE_INCLUDEPATH += \
$${NADIR_SOURCE} \
$${nadir_INCLUDEPATH} \

# nadir SOURCE_DEFINES
#
nadir_SOURCE_DEFINES += \
$${nadir_DEFINES} \

# nadir SOURCE_LIBS
#
nadir_SOURCE_LIBS += \
-L$${NADIR_LIB}/lib$${FRAMEWORK_SOURCE_LIBRARY_NAME} \
-l$${FRAMEWORK_SOURCE_LIBRARY_NAME} \

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
-L$${NADIR_LIB}/libxos$${FRAMEWORK_LIBRARY_NAME} \
-lxos$${FRAMEWORK_LIBRARY_NAME} \

########################################################################
# xosnadir SOURCE_INCLUDEPATH
#
xosnadir_SOURCE_INCLUDEPATH += \
$${nadir_SOURCE_INCLUDEPATH} \

# xosnadir SOURCE_DEFINES
#
xosnadir_SOURCE_DEFINES += \
$${nadir_SOURCE_DEFINES} \
NO_USE_NADIR_BASE \
NO_USE_XOS_LOGGER_INTERFACE \

# xosnadir SOURCE_LIBS
#
xosnadir_SOURCE_LIBS += \
-L$${NADIR_LIB}/libxos$${FRAMEWORK_SOURCE_LIBRARY_NAME} \
-lxos$${FRAMEWORK_SOURCE_LIBRARY_NAME} \

########################################################################
