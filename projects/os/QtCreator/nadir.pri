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
#   Date: 3/4/2023, 2/26/2024
#
# os specific QtCreator project file for medusade framework nadir
########################################################################
# Depends: rostra

UNAME = $$system(uname)

contains(UNAME,Darwin) {
DARWIN_VERSION = $$system(sw_vers -productVersion)
} else {
contains(UNAME,Linux) {
LINUX_VERSION = $$system(uname -r)
} else {
contains(UNAME,Windows) {
WINDOWS_VERSION = $$system(ver)
} else {
} # contains(UNAME,Windows)
} # contains(UNAME,Linux)
} # contains(UNAME,Darwin)

contains(UNAME,Darwin) {
DARWIN_VERSION_NUMBER = $$system(echo $${DARWIN_VERSION} | cut -d'.' -f1)
contains(DARWIN_VERSION_NUMBER,15) {
DARWIN_VERSION_NAME = Sequoia
} else {
contains(DARWIN_VERSION_NUMBER,14) {
DARWIN_VERSION_NAME = Sonoma
} else {
contains(DARWIN_VERSION_NUMBER,13) {
DARWIN_VERSION_NAME = Ventura
} else {
contains(DARWIN_VERSION_NUMBER,12) {
DARWIN_VERSION_NAME = Monterey
} else {
contains(DARWIN_VERSION_NUMBER,11) {
DARWIN_VERSION_NAME = Bigsur
} else {
contains(DARWIN_VERSION_NUMBER,10) {
DARWIN_VERSION_NAME = Sierra
} else {
DARWIN_VERSION_NAME = Mavricks
} # contains(DARWIN_VERSION,10)
} # contains(DARWIN_VERSION,11)
} # contains(DARWIN_VERSION,12)
} # contains(DARWIN_VERSION,13)
} # contains(DARWIN_VERSION,14)
} # contains(DARWIN_VERSION,15)
} # contains(UNAME,Darwin)

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
contains(DARWIN_VERSION_NUMBER,15) {
#QMAKE_CXXFLAGS += -Werror -Wno-error=register
QMAKE_CXXFLAGS += -Wno-register
} else {
} # contains(DARWIN_VERSION_NUMBER,15)
contains(DARWIN_VERSION_NUMBER,14) {
QMAKE_CXXFLAGS += -Wno-dynamic-exception-spec
} else {
} # contains(DARWIN_VERSION_NUMBER,14)
contains(DARWIN_VERSION_NUMBER,11|12|13|14|15) {
QMAKE_CFLAGS += -Wno-implicit-function-declaration
} else {
} # contains(DARWIN_VERSION_NUMBER,11|12|13|14|15)
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
ROSTRA_THIRDPARTY_PRJ_MAKE_BLD = $${OTHER_BLD}/$${ROSTRA_THIRDPARTY_PRJ}/build/$${NADIR_BUILD}/$${BUILD_CONFIG}
ROSTRA_THIRDPARTY_PKG_BLD = $${ROSTRA_THIRDPARTY_PKG}/build/$${NADIR_BUILD}/QtCreator/$${BUILD_CONFIG}
ROSTRA_THIRDPARTY_PRJ_BLD = $${OTHER_BLD}/$${ROSTRA_THIRDPARTY_PRJ}/build/$${NADIR_BUILD}/QtCreator/$${BUILD_CONFIG}
ROSTRA_PKG_BLD = $${OTHER_BLD}/$${ROSTRA_PKG}/build/$${NADIR_BUILD}/QtCreator/$${BUILD_CONFIG}
ROSTRA_PRJ_BLD = $${OTHER_BLD}/$${ROSTRA_PRJ}/build/$${NADIR_BUILD}/QtCreator/$${BUILD_CONFIG}
#ROSTRA_LIB = $${ROSTRA_THIRDPARTY_PKG_MAKE_BLD}/lib
#ROSTRA_LIB = $${ROSTRA_THIRDPARTY_PRJ_MAKE_BLD}/lib
#ROSTRA_LIB = $${ROSTRA_THIRDPARTY_PKG_BLD}/lib
#ROSTRA_LIB = $${ROSTRA_THIRDPARTY_PRJ_BLD}/lib
ROSTRA_LIB = $${ROSTRA_PKG_BLD}/lib
#ROSTRA_LIB = $${ROSTRA_PRJ_BLD}/lib
#ROSTRA_LIB = $${NADIR_LIB}
ROSTRA_LIB_NAME = $${ROSTRA_NAME}

# rostra LIBS
#
rostra_LIBS += \
-L$${ROSTRA_LIB}/lib$${ROSTRA_LIB_NAME} \
-l$${ROSTRA_LIB_NAME} \

########################################################################
# nadir

# nadir INCLUDEPATH
#
nadir_INCLUDEPATH += \

# nadir DEFINES
#
nadir_DEFINES += \

# nadir os LIBS
#
contains(NADIR_OS,macosx|linux) {
nadir_os_LIBS += \
-lpthread \
-ldl
} else {
} # contains(NADIR_OS,macosx|linux)

contains(NADIR_OS,linux) {
nadir_os_LIBS += \
-lrt
} else {
} # contains(NADIR_OS,linux)


# nadir base LIBS
#
nadir_base_LIBS += \
$${rostra_LIBS} \


# nadir LIBS
#
nadir_LIBS += \
$${nadir_base_LIBS} \
$${build_nadir_LIBS} \
$${nadir_os_LIBS} \

########################################################################
