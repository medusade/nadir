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
#   Date: 10/10/2017
#
# Linux QtCreator .pri file for nadir
########################################################################
NADIR_OS = linux
#QMAKE_CXXFLAGS += -std=c++11
#QMAKE_CXXFLAGS += -std=c++0x

########################################################################
# rostra
ROSTRA_BLD = $${OTHER_BLD}/$${ROSTRA_PKG}/build/$${NADIR_OS}/QtCreator/$${BUILD_CONFIG}
ROSTRA_LIB = $${ROSTRA_BLD}/lib

rostra_LIBS += \
-L$${ROSTRA_LIB}/librostra \
-lrostra \

########################################################################
# crono
CRONO_BLD = $${OTHER_BLD}/$${CRONO_PKG}/build/$${NADIR_OS}/QtCreator/$${BUILD_CONFIG}
CRONO_LIB = $${CRONO_BLD}/lib

crono_LIBS += \
-L$${CRONO_LIB}/libcrono \
-lcrono \

########################################################################
# nadir
nadir_INCLUDEPATH += \

nadir_DEFINES += \

nadir_LIBS += \
$${build_nadir_LIBS} \
-lpthread \
-ldl \
-lrt \

