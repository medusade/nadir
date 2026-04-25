########################################################################
# Copyright (c) 1988-2024 $organization$
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
#   File: xosmsg.pri
#
# Author: $author$
#   Date: 2/28/2024
#
# generic QtCreator project file for medusade framework nadir executable xosmsg
########################################################################

########################################################################
# xosmsg

# xosmsg TARGET
#
xosmsg_TARGET = xosmsg

# xosmsg INCLUDEPATH
#
xosmsg_INCLUDEPATH += \
$${xosnadir_INCLUDEPATH} \

# xosmsg DEFINES
#
xosmsg_DEFINES += \
$${xosnadir_DEFINES} \
DEFAULT_LOGGING_LEVELS_ERROR \
XOS_CONSOLE_MAIN_MAIN \

########################################################################
# xosmsg OBJECTIVE_HEADERS
#
#xosmsg_OBJECTIVE_HEADERS += \
#$${NADIR_SRC}/xos/app/console/xosmsg/main.hh \

# xosmsg OBJECTIVE_SOURCES
#
#xosmsg_OBJECTIVE_SOURCES += \
#$${NADIR_SRC}/xos/app/console/xosmsg/main.mm \

########################################################################
# xosmsg HEADERS
#
xosmsg_HEADERS += \
$${NADIR_SRC}/xos/base/main_main.hpp \
$${NADIR_SRC}/xos/app/console/msg/main.hpp \

# xosmsg SOURCES
#
xosmsg_SOURCES += \
$${NADIR_SRC}/xos/base/main_main.cpp \

contains(UNAME,Linux) {
xosmsg_SOURCES += \
$${NADIR_SRC}/xos/app/console/msg/main.cpp 
} else {
} # contains(UNAME,Linux)

########################################################################
# xosmsg FRAMEWORKS
#
xosmsg_FRAMEWORKS += \
$${xosnadir_FRAMEWORKS} \

# xosmsg LIBS
#
xosmsg_LIBS += \
$${xosnadir_LIBS} \

########################################################################
# NO Qt
QT -= gui core
