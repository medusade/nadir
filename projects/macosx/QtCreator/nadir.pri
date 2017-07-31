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

NADIR_OS = macosx

########################################################################
# nadir
nadir_INCLUDEPATH += \

nadir_DEFINES += \

nadir_LIBS += \
-lpthread \
-ldl \

########################################################################
# rostra
ROSTRA_CPP_XOS_BLD = $${ROSTRA_CPP_XOS_PKG}/build/$${NADIR_OS}/QtCreator/$${NADIR_CONFIG}
ROSTRA_CPP_XOS_LIB = $${ROSTRA_CPP_XOS_BLD}/lib

########################################################################
# nadir/cpp/xos
NADIR_CPP_XOS_BLD = $${NADIR_CPP_XOS_PKG}/build/$${NADIR_OS}/QtCreator/$${NADIR_CONFIG}
NADIR_CPP_XOS_LIB = $${NADIR_CPP_XOS_BLD}/lib

