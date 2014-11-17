########################################################################
# Copyright (c) 1988-2014 $organization$
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
#   File: libxosnadir.pro
#
# Author: $author$
#   Date: 8/17/2014
########################################################################
include(../../../../QtCreator/lib/libxosnadir.pri)

TARGET = xosnadir
TEMPLATE = lib
CONFIG += staticlib

INCLUDEPATH += \
$${libxosnadir_INCLUDEPATH} \

DEFINES += \
$${libxosnadir_DEFINES} \

HEADERS += \
$${libxosnadir_HEADERS} \
$${XOS_SRC}/xos/mt/unix/mutex.hpp \
$${XOS_SRC}/xos/mt/macosx/mutex.hpp \
$${XOS_SRC}/xos/mt/unix/process.hpp \
$${XOS_SRC}/xos/mt/macosx/process.hpp \
$${XOS_SRC}/thirdparty/gnu/glibc/posix/execvpe.h \

SOURCES += \
$${libxosnadir_SOURCES} \
$${XOS_SRC}/xos/mt/macosx/mutex.cpp \
$${XOS_SRC}/xos/mt/macosx/process.cpp \
$${XOS_SRC}/thirdparty/gnu/glibc/posix/execvpe.c \


