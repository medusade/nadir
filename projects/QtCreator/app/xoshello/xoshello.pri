########################################################################
# Copyright (c) 1988-2022 $organization$
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
#   File: xoshello.pri
#
# Author: $author$
#   Date: 2/7/2022
#
# generic QtCreator project .pri file for framework xosnadir executable xoshello
########################################################################

########################################################################
# xoshello

# xoshello TARGET
#
xoshello_TARGET = xoshello

# xoshello INCLUDEPATH
#
xoshello_INCLUDEPATH += \
$${xosnadir_INCLUDEPATH} \

# xoshello DEFINES
#
xoshello_DEFINES += \
$${xosnadir_DEFINES} \
DEFAULT_LOGGING_LEVELS_ERROR \
XOS_CONSOLE_MAIN_MAIN \

########################################################################
# xoshello OBJECTIVE_HEADERS
#
#xoshello_OBJECTIVE_HEADERS += \
#$${XOSNADIR_SRC}/xos/app/console/xoshello/main.hh \

# xoshello OBJECTIVE_SOURCES
#
#xoshello_OBJECTIVE_SOURCES += \
#$${XOSNADIR_SRC}/xos/app/console/xoshello/main.mm \

########################################################################
# xoshello HEADERS
#
xoshello_HEADERS += \
$${NADIR_SRC}/xos/app/console/hello/main.hpp \

# xoshello SOURCES
#
xoshello_SOURCES += \
$${NADIR_SRC}/xos/app/console/hello/main.cpp \

########################################################################
# xoshello FRAMEWORKS
#
xoshello_FRAMEWORKS += \
$${xosnadir_FRAMEWORKS} \

# xoshello LIBS
#
xoshello_LIBS += \
$${xosnadir_LIBS} \

########################################################################
# NO Qt
QT -= gui core

