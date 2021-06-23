########################################################################
# Copyright (c) 1988-2021 $organization$
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
#   File: xosnadir.pri
#
# Author: $author$
#   Date: 6/13/2021
#
# Os specific QtCreator .pri file for xosnadir
########################################################################
UNAME = $$system(uname)

contains(UNAME,Darwin) {
XOSNADIR_OS = macosx
} else {
contains(UNAME,Linux) {
XOSNADIR_OS = linux
} else {
XOSNADIR_OS = windows
} # contains(UNAME,Linux)
} # contains(UNAME,Darwin)

contains(BUILD_OS,XOSNADIR_OS) {
XOSNADIR_BUILD = $${XOSNADIR_OS}
} else {
XOSNADIR_BUILD = $${BUILD_OS}
} # contains(BUILD_OS,XOSNADIR_OS)

contains(BUILD_CPP_VERSION,10) {
CONFIG += c++0x
} else {
contains(BUILD_CPP_VERSION,98|03|11|14|17) {
CONFIG += c++$${BUILD_CPP_VERSION}
} else {
} # contains(BUILD_CPP_VERSION,98|03|11|14|17)
} # contains(BUILD_CPP_VERSION,10)

contains(XOSNADIR_OS,macosx) {
} else {
contains(XOSNADIR_OS,linux) {
QMAKE_CXXFLAGS += -fpermissive
} else {
contains(XOSNADIR_OS,windows) {
} else {
} # contains(XOSNADIR_OS,windows)
} # contains(XOSNADIR_OS,linux)
} # contains(XOSNADIR_OS,macosx)

########################################################################
# xosrostra
XOSROSTRA_THIRDPARTY_PKG_MAKE_BLD = $${XOSROSTRA_THIRDPARTY_PKG}/build/$${XOSNADIR_BUILD}/$${BUILD_CONFIG}
XOSROSTRA_THIRDPARTY_PRJ_MAKE_BLD = $${OTHER_BLD}/$${XOSROSTRA_THIRDPARTY_PRJ}/build/$${XOSNADIR_BUILD}/$${BUILD_CONFIG}
XOSROSTRA_THIRDPARTY_PKG_BLD = $${XOSROSTRA_THIRDPARTY_PKG}/build/$${XOSNADIR_BUILD}/QtCreator/$${BUILD_CONFIG}
XOSROSTRA_THIRDPARTY_PRJ_BLD = $${OTHER_BLD}/$${XOSROSTRA_THIRDPARTY_PRJ}/build/$${XOSNADIR_BUILD}/QtCreator/$${BUILD_CONFIG}
XOSROSTRA_PKG_BLD = $${OTHER_BLD}/$${XOSROSTRA_PKG}/build/$${XOSNADIR_BUILD}/QtCreator/$${BUILD_CONFIG}
XOSROSTRA_PRJ_BLD = $${OTHER_BLD}/$${XOSROSTRA_PRJ}/build/$${XOSNADIR_BUILD}/QtCreator/$${BUILD_CONFIG}
#XOSROSTRA_LIB = $${XOSROSTRA_THIRDPARTY_PKG_MAKE_BLD}/lib
#XOSROSTRA_LIB = $${XOSROSTRA_THIRDPARTY_PRJ_MAKE_BLD}/lib
#XOSROSTRA_LIB = $${XOSROSTRA_THIRDPARTY_PKG_BLD}/lib
#XOSROSTRA_LIB = $${XOSROSTRA_THIRDPARTY_PRJ_BLD}/lib
XOSROSTRA_LIB = $${XOSROSTRA_PKG_BLD}/lib
#XOSROSTRA_LIB = $${XOSROSTRA_PRJ_BLD}/lib
#XOSROSTRA_LIB = $${XOSNADIR_LIB}

XOSROSTRA_LIB_NAME = xos$${XOSROSTRA_NAME}

# xosrostra LIBS
#
xosrostra_LIBS += \
-L$${XOSROSTRA_LIB}/lib$${XOSROSTRA_LIB_NAME} \
-l$${XOSROSTRA_LIB_NAME} \

########################################################################
# xosnadir

# xosnadir INCLUDEPATH
#
xosnadir_INCLUDEPATH += \

# xosnadir DEFINES
#
xosnadir_DEFINES += \

# xosnadir LIBS
#
xosnadir_LIBS += \
$${xosrostra_LIBS} \
$${build_xosnadir_LIBS} \

contains(XOSNADIR_OS,macosx|linux) {
xosnadir_LIBS += \
-lpthread \
-ldl
} else {
} # contains(XOSNADIR_OS,macosx|linux)

contains(XOSNADIR_OS,linux) {
xosnadir_LIBS += \
-lrt
} else {
} # contains(XOSNADIR_OS,linux)


