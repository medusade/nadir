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
# Linux QtCreator .pri file for xos
########################################################################
XOS_OS = linux
#QMAKE_CXXFLAGS += -std=c++11
#QMAKE_CXXFLAGS += -std=c++0x

########################################################################
# rostra
ROSTRA_BLD = $${OTHER_BLD}/$${ROSTRA_PKG}/build/$${XOS_OS}/QtCreator/$${BUILD_CONFIG}
ROSTRA_LIB = $${ROSTRA_BLD}/lib

rostra_LIBS += \
-L$${ROSTRA_LIB}/librostra \
-lrostra \

########################################################################
# xos
xos_INCLUDEPATH += \

xos_DEFINES += \

xos_LIBS += \
$${rostra_LIBS} \
$${build_xos_LIBS} \
-lpthread \
-ldl \
-lrt \

