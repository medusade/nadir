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
# QtCreator .pri file for xos executable xos
########################################################################

xos_exe_TARGET = xos

########################################################################
xos_exe_INCLUDEPATH += \
$${xos_INCLUDEPATH} \

xos_exe_DEFINES += \
$${xos_DEFINES} \

########################################################################
# xos
xos_exe_HEADERS += \
$${XOS_SRC}/xos/mt/locked.hpp \
$${XOS_SRC}/xos/io/logger.hpp \
$${XOS_SRC}/xos/console/logger.hpp \
$${XOS_SRC}/xos/console/io.hpp \
$${XOS_SRC}/xos/logger/interface.hpp \
$${XOS_SRC}/xos/logger/output.hpp \
$${XOS_SRC}/xos/logger/message.hpp \
$${XOS_SRC}/xos/logger/level.hpp \
$${XOS_SRC}/xos/app/console/test/main.hpp \
$${XOS_SRC}/xos/console/main_main.hpp \
$${XOS_SRC}/xos/base/main_main.hpp \

xos_exe_SOURCES += \
$${XOS_SRC}/xos/mt/locked.cpp \
$${XOS_SRC}/xos/console/logger.cpp \
$${XOS_SRC}/xos/console/io.cpp \
$${XOS_SRC}/xos/logger/interface.cpp \
$${XOS_SRC}/xos/logger/output.cpp \
$${XOS_SRC}/xos/logger/message.cpp \
$${XOS_SRC}/xos/logger/level.cpp \
$${XOS_SRC}/xos/app/console/test/main.cpp \
$${XOS_SRC}/xos/console/main_main.cpp \

########################################################################
xos_exe_LIBS += \
$${xos_LIBS} \

