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
#   File: libnadir.pri
#
# Author: $author$
#   Date: 9/17/2016
########################################################################

libnadir_INCLUDEPATH += \
$${NADIR_SRC} \

libnadir_DEFINES += \

########################################################################
# platform
libnadir_HEADERS += \
$${NADIR_SRC}/nadir/platform/platform.hpp \
$${NADIR_SRC}/nadir/platform/platform.h \
$${NADIR_SRC}/nadir/platform/platform_api.h \
$${NADIR_SRC}/nadir/platform/platform_types.h \
$${NADIR_SRC}/nadir/platform/platform_defines.h \
$${NADIR_SRC}/nadir/platform/platform_includes.h \
$${NADIR_SRC}/nadir/platform/platform_compiler.h \
$${NADIR_SRC}/nadir/platform/platform_build.h \

libnadir_SOURCES += \
$${NADIR_SRC}/nadir/platform/platform.cpp \

########################################################################
# base
libnadir_HEADERS += \
$${NADIR_SRC}/nadir/base/string.hpp \
$${NADIR_SRC}/nadir/base/base.hpp \
$${NADIR_SRC}/nadir/base/platform.h \
$${NADIR_SRC}/nadir/base/platform_api.h \
$${NADIR_SRC}/nadir/base/platform_types.h \
$${NADIR_SRC}/nadir/base/platform_defines.h \
$${NADIR_SRC}/nadir/base/platform_includes.h \
$${NADIR_SRC}/nadir/base/platform_compiler.h \
$${NADIR_SRC}/nadir/base/platform_build.h \

libnadir_SOURCES += \
$${NADIR_SRC}/nadir/base/string.cpp \
$${NADIR_SRC}/nadir/base/base.cpp \

########################################################################
# io
libnadir_HEADERS += \
$${NADIR_SRC}/nadir/io/logger.hpp \
$${NADIR_SRC}/nadir/io/logger_stdio.hpp \
$${NADIR_SRC}/nadir/io/logger_message.hpp \
$${NADIR_SRC}/nadir/io/logger_location.hpp \
$${NADIR_SRC}/nadir/io/logger_function.hpp \
$${NADIR_SRC}/nadir/io/logger_level.hpp \

libnadir_SOURCES += \
$${NADIR_SRC}/nadir/io/logger.cpp \
$${NADIR_SRC}/nadir/io/logger_stdio.cpp \
$${NADIR_SRC}/nadir/io/logger_message.cpp \
$${NADIR_SRC}/nadir/io/logger_location.cpp \
$${NADIR_SRC}/nadir/io/logger_function.cpp \
$${NADIR_SRC}/nadir/io/logger_level.cpp \

########################################################################
libnadir_LIBS += \
$${NADIR_LIBS} \
