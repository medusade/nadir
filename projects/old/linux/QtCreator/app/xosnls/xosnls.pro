########################################################################
# Copyright (c) 1988-2015 $organization$
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
#   File: xosnls.pro
#
# Author: $author$
#   Date: 3/26/2015
########################################################################
include(../../../../QtCreator/lib/libxosnadir.pri)
include(../../../../QtCreator/app/xosnls.pri)

TARGET = xosnls

INCLUDEPATH += \
$${xosnls_INCLUDEPATH} \

DEFINES += \
$${xosnls_DEFINES} \

HEADERS += \
$${xosnls_HEADERS} \
$${XOS_SRC}/xos/os/macosx/fs/directory/entry.hpp \
$${XOS_SRC}/xos/os/macosx/fs/directory/path.hpp \

SOURCES += \
$${xosnls_SOURCES} \
$${XOS_SRC}/xos/os/macosx/fs/directory/entry.cpp \
$${XOS_SRC}/xos/os/macosx/fs/directory/path.cpp \

LIBS += \
$${xosnls_LIBS} \
-lpthread \
-ldl \
-lrt \
