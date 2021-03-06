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
#   File: libnadir.pri
#
# Author: $author$
#   Date: 8/9/2017
########################################################################

libnadir_TARGET = nadir

########################################################################
libnadir_INCLUDEPATH += \
$${nadir_INCLUDEPATH} \

libnadir_DEFINES += \

########################################################################
# rostra
libnadir_HEADERS += \
$${ROSTRA_SRC}/xos/platform/platform.hpp \
$${ROSTRA_SRC}/xos/platform/platform.h \
$${ROSTRA_SRC}/xos/platform/platform_api.h \
$${ROSTRA_SRC}/xos/platform/platform_types.h \
$${ROSTRA_SRC}/xos/platform/platform_defines.h \
$${ROSTRA_SRC}/xos/platform/platform_includes.h \
$${ROSTRA_SRC}/xos/platform/platform_compiler.h \
$${ROSTRA_SRC}/xos/platform/platform_build.h \

libnadir_SOURCES += \
$${ROSTRA_SRC}/xos/platform/platform.cpp \

########################################################################
# nadir
libnadir_HEADERS += \
$${NADIR_SRC}/xos/base/Base.hpp \

libnadir_SOURCES += \
$${NADIR_SRC}/xos/base/Base.cpp \

libnadir_LIBS += \
