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
#   File: xosbase.pri
#
# Author: $author$
#   Date: 2/28/2024
#
# generic QtCreator project file for medusade framework nadir executable xosbase
########################################################################

########################################################################
# xosbase

# xosbase TARGET
#
xosbase_TARGET = xosbase

# xosbase INCLUDEPATH
#
xosbase_INCLUDEPATH += \
$${xosnadir_SOURCE_INCLUDEPATH} \

# xosbase DEFINES
#
xosbase_DEFINES += \
$${xosnadir_SOURCE_DEFINES} \
DEFAULT_LOGGING_LEVELS_ERROR \
XOS_CONSOLE_MAIN_MAIN \

########################################################################
# xosbase OBJECTIVE_HEADERS
#
#xosbase_OBJECTIVE_HEADERS += \
#$${NADIR_SRC}/xos/app/console/xosbase/main.hh \

# xosbase OBJECTIVE_SOURCES
#
#xosbase_OBJECTIVE_SOURCES += \
#$${NADIR_SRC}/xos/app/console/xosbase/main.mm \

########################################################################
# xosbase HEADERS
#
xosbase_HEADERS += \
$${NADIR_SRC}/xos/app/console/nadir/main.hpp \

# xosbase SOURCES
#
xosbase_SOURCES += \
$${NADIR_SRC}/xos/app/console/nadir/main.cpp \

########################################################################
# xosbase FRAMEWORKS
#
xosbase_FRAMEWORKS += \
$${xosnadir_SOURCE_FRAMEWORKS} \

# xosbase LIBS
#
xosbase_LIBS += \
$${xosnadir_SOURCE_LIBS} \

########################################################################
# NO Qt
QT -= gui core
