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
#   Date: 8/9/2017
########################################################################

NADIR_OS = macosx
QMAKE_CXXFLAGS += -std=c++11

########################################################################
# rostra
ROSTRA_BLD = $${ROSTRA_PKG}/build/$${NADIR_OS}/QtCreator/$${NADIR_CONFIG}
ROSTRA_LIB = $${ROSTRA_BLD}/lib

########################################################################
# nadir
nadir_INCLUDEPATH += \

nadir_DEFINES += \

nadir_LIBS += \
-lpthread \
-ldl \
