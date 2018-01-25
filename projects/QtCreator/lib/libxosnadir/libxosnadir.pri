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
#   File: libxosnadir.pri
#
# Author: $author$
#   Date: 1/18/2018
########################################################################

TARGET = xosnadir
TEMPLATE = lib
CONFIG += staticlib

libxosnadir_INCLUDEPATH += \
$${xosnadir_INCLUDEPATH} \

libxosnadir_DEFINES += \
$${xosnadir_DEFINES} \

########################################################################
# base
libxosnadir_HEADERS += \
$${NADIR_SRC}/xos/base/getopt/main_opt.hpp \
$${NADIR_SRC}/xos/base/getopt/main.hpp \
$${NADIR_SRC}/xos/base/main.hpp \
$${NADIR_SRC}/xos/base/string.hpp \
$${NADIR_SRC}/xos/base/created.hpp \
$${NADIR_SRC}/xos/base/creator.hpp \
$${NADIR_SRC}/xos/base/opened.hpp \
$${NADIR_SRC}/xos/base/opener.hpp \
$${NADIR_SRC}/xos/base/attacher.hpp \
$${NADIR_SRC}/xos/base/array.hpp \
$${NADIR_SRC}/xos/base/base.hpp \
$${NADIR_SRC}/xos/base/platform.hpp \
$${NADIR_SRC}/xos/base/platform_types.hpp \
$${NADIR_SRC}/xos/base/platform_defines.hpp \
$${NADIR_SRC}/xos/base/platform_includes.hpp \
$${NADIR_SRC}/xos/base/platform_compiler.hpp \
$${NADIR_SRC}/xos/base/platform_build.hpp \

libxosnadir_SOURCES += \
$${NADIR_SRC}/xos/base/getopt/main_opt.cpp \
$${NADIR_SRC}/xos/base/getopt/main.cpp \
$${NADIR_SRC}/xos/base/string.cpp \
$${NADIR_SRC}/xos/base/created.cpp \
$${NADIR_SRC}/xos/base/creator.cpp \
$${NADIR_SRC}/xos/base/opened.cpp \
$${NADIR_SRC}/xos/base/opener.cpp \
$${NADIR_SRC}/xos/base/attacher.cpp \
$${NADIR_SRC}/xos/base/array.cpp \
$${NADIR_SRC}/xos/base/base.cpp \

########################################################################
# io
libxosnadir_HEADERS += \
$${NADIR_SRC}/xos/io/main/logger.hpp \
$${NADIR_SRC}/xos/io/logger.hpp \
$${NADIR_SRC}/xos/io/file/reader.hpp \
$${NADIR_SRC}/xos/io/reader.hpp \
$${NADIR_SRC}/xos/io/file/writer.hpp \
$${NADIR_SRC}/xos/io/writer.hpp \

libxosnadir_SOURCES += \
$${NADIR_SRC}/xos/io/file/reader.cpp \
$${NADIR_SRC}/xos/io/file/writer.cpp \
$${NADIR_SRC}/xos/io/main/logger.cpp \

########################################################################
# mt
libxosnadir_HEADERS += \
$${NADIR_SRC}/xos/mt/os/semaphore.hpp \
$${NADIR_SRC}/xos/mt/semaphore.hpp \
$${NADIR_SRC}/xos/mt/main/mutex.hpp \
$${NADIR_SRC}/xos/mt/os/mutex.hpp \
$${NADIR_SRC}/xos/mt/mutex.hpp \
$${NADIR_SRC}/xos/mt/os/os.hpp \
$${NADIR_SRC}/xos/mt/acquire.hpp \
$${NADIR_SRC}/xos/mt/acquirer.hpp \
$${NADIR_SRC}/xos/mt/releaser.hpp \
$${NADIR_SRC}/xos/mt/lock.hpp \
$${NADIR_SRC}/xos/mt/locker.hpp \
$${NADIR_SRC}/xos/mt/wait.hpp \
$${NADIR_SRC}/xos/mt/waiter.hpp \

libxosnadir_SOURCES += \
$${NADIR_SRC}/xos/mt/acquire.cpp \
$${NADIR_SRC}/xos/mt/acquirer.cpp \
$${NADIR_SRC}/xos/mt/releaser.cpp \
$${NADIR_SRC}/xos/mt/lock.cpp \
$${NADIR_SRC}/xos/mt/locker.cpp \
$${NADIR_SRC}/xos/mt/wait.cpp \
$${NADIR_SRC}/xos/mt/waiter.cpp \

########################################################################
