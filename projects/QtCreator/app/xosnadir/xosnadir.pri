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
#   File: xosnadir.pri
#
# Author: $author$
#   Date: 3/23/2022
#
# generic QtCreator project .pri file for framework xosnadir executable xosnadir
########################################################################

########################################################################
# xosnadir

# xosnadir_exe TARGET
#
xosnadir_exe_TARGET = xosnadir

# xosnadir_exe INCLUDEPATH
#
xosnadir_exe_INCLUDEPATH += \
$${xosnadir_INCLUDEPATH} \

# xosnadir_exe DEFINES
#
xosnadir_exe_DEFINES += \
$${xosnadir_DEFINES} \
DEFAULT_LOGGING_LEVELS_ERROR \
XOS_CONSOLE_MAIN_MAIN \

########################################################################
# xosnadir_exe OBJECTIVE_HEADERS
#
#xosnadir_exe_OBJECTIVE_HEADERS += \
#$${XOSNADIR_SRC}/xos/app/console/xosnadir/main.hh \

# xosnadir_exe OBJECTIVE_SOURCES
#
#xosnadir_exe_OBJECTIVE_SOURCES += \
#$${XOSNADIR_SRC}/xos/app/console/xosnadir/main.mm \

########################################################################
# xosnadir_exe HEADERS
#
xosnadir_exe_HEADERS += \
$${NADIR_SRC}/xos/app/console/nadir/main.hpp \

# xosnadir_exe SOURCES
#
xosnadir_exe_SOURCES += \
$${NADIR_SRC}/xos/app/console/nadir/main.cpp \

########################################################################
# xosnadir_exe FRAMEWORKS
#
xosnadir_exe_FRAMEWORKS += \
$${xosnadir_FRAMEWORKS} \

# xosnadir_exe LIBS
#
xosnadir_exe_LIBS += \
$${xosnadir_LIBS} \

########################################################################
# NO Qt
QT -= gui core

