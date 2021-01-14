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
# Os QtCreator .pri file for nadir
########################################################################
UNAME = $$system(uname)

contains(UNAME,Darwin) {
NADIR_OS = macosx
} else {
contains(UNAME,Linux) {
NADIR_OS = linux
} else {
NADIR_OS = windows
} # contains(UNAME,Linux)
} # contains(UNAME,Darwin)

contains(BUILD_OS,NADIR_OS) {
NADIR_BUILD = $${NADIR_OS}
} else {
NADIR_BUILD = $${BUILD_OS}
} # contains(BUILD_OS,NADIR_OS)

contains(BUILD_CPP_VERSION,10) {
CONFIG += c++0x
} else {
contains(BUILD_CPP_VERSION,98|03|11|14|17) {
CONFIG += c++$${BUILD_CPP_VERSION}
} else {
} # contains(BUILD_CPP_VERSION,98|03|11|14|17)
} # contains(BUILD_CPP_VERSION,10)

contains(NADIR_OS,macosx) {
} else {
contains(NADIR_OS,linux) {
QMAKE_CXXFLAGS += -fpermissive
} else {
contains(NADIR_OS,windows) {
} else {
} # contains(NADIR_OS,windows)
} # contains(NADIR_OS,linux)
} # contains(NADIR_OS,macosx)

########################################################################
# rostra
ROSTRA_THIRDPARTY_PKG_MAKE_BLD = $${ROSTRA_THIRDPARTY_PKG}/build/$${NADIR_BUILD}/$${BUILD_CONFIG}
ROSTRA_THIRDPARTY_PRJ_MAKE_BLD = $${ROSTRA_THIRDPARTY_PRJ}/build/$${NADIR_BUILD}/$${BUILD_CONFIG}
ROSTRA_THIRDPARTY_PKG_BLD = $${ROSTRA_THIRDPARTY_PKG}/build/$${NADIR_BUILD}/QtCreator/$${BUILD_CONFIG}
ROSTRA_THIRDPARTY_PRJ_BLD = $${ROSTRA_THIRDPARTY_PRJ}/build/$${NADIR_BUILD}/QtCreator/$${BUILD_CONFIG}
ROSTRA_PKG_BLD = $${OTHER_BLD}/$${ROSTRA_PKG}/build/$${NADIR_BUILD}/QtCreator/$${BUILD_CONFIG}
ROSTRA_PRJ_BLD = $${OTHER_BLD}/$${ROSTRA_PRJ}/build/$${NADIR_BUILD}/QtCreator/$${BUILD_CONFIG}
#ROSTRA_LIB = $${ROSTRA_THIRDPARTY_PKG_MAKE_BLD}/lib
#ROSTRA_LIB = $${ROSTRA_THIRDPARTY_PRJ_MAKE_BLD}/lib
#ROSTRA_LIB = $${ROSTRA_THIRDPARTY_PKG_BLD}/lib
#ROSTRA_LIB = $${ROSTRA_THIRDPARTY_PRJ_BLD}/lib
#ROSTRA_LIB = $${ROSTRA_PKG_BLD}/lib
ROSTRA_LIB = $${ROSTRA_PRJ_BLD}/lib
#ROSTRA_LIB = $${NADIR_LIB}

# rostra LIBS
#
rostra_LIBS += \
-L$${ROSTRA_LIB}/lib$${ROSTRA_NAME} \
-l$${ROSTRA_NAME} \

########################################################################
# nadir

# nadir OS_LIBS
#
nadir_OS_LIBS += \
$${build_nadir_LIBS} \
-lpthread \
-ldl \

contains(NADIR_OS,linux) {
nadir_OS_LIBS += \
-lrt
} else {
}

# nadir INCLUDEPATH
#
nadir_INCLUDEPATH += \

# nadir DEFINES
#
nadir_DEFINES += \

# nadir LIBS
#
nadir_LIBS += \
$${rostra_LIBS} \
$${nadir_OS_LIBS} \

########################################################################
# nadir SOURCE_INCLUDEPATH
#
nadir_SOURCE_INCLUDEPATH += \

# nadir SOURCE_DEFINES
#
nadir_SOURCE_DEFINES += \

# nadir SOURCE_LIBS
#
nadir_SOURCE_LIBS += \
$${nadir_OS_LIBS} \

########################################################################
# xosnadir INCLUDEPATH
#
xosnadir_INCLUDEPATH += \

# xosnadir DEFINES
#
xosnadir_DEFINES += \

# xosnadir LIBS
#
xosnadir_LIBS += \
$${nadir_OS_LIBS} \

########################################################################
# xosnadir SOURCE_INCLUDEPATH
#
xosnadir_SOURCE_INCLUDEPATH += \

# xosnadir SOURCE_DEFINES
#
xosnadir_SOURCE_DEFINES += \

# xosnadir SOURCE_LIBS
#
xosnadir_SOURCE_LIBS += \
$${nadir_OS_LIBS} \
