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
#   File: xospath.pri
#
# Author: $author$
#   Date: 9/9/2018
#
# QtCreator .pri file for nadir executable xospath
########################################################################

########################################################################
# xospath

# xospath TARGET
#
xospath_TARGET = xosnadir-path

# xospath INCLUDEPATH
#
xospath_INCLUDEPATH += \
$${xosnadir_INCLUDEPATH} \

# xospath DEFINES
#
xospath_DEFINES += \
$${xosnadir_DEFINES} \

########################################################################
# xospath OBJECTIVE_HEADERS
#
#xospath_OBJECTIVE_HEADERS += \
#$${NADIR_SRC}/nadir/base/Base.hh \

# xospath OBJECTIVE_SOURCES
#
#xospath_OBJECTIVE_SOURCES += \
#$${NADIR_SRC}/nadir/base/Base.mm \

########################################################################
# xospath HEADERS
#
xospath_HEADERS += \
$${NADIR_SRC}/xos/fs/path.hpp \
$${NADIR_SRC}/xos/fs/path_separator.hpp \
$${NADIR_SRC}/xos/fs/path_separator_events.hpp \
\
$${NADIR_SRC}/xos/base/main_main.hpp \
$${NADIR_SRC}/xos/app/console/path/main.hpp \

# xospath SOURCES
#
xospath_SOURCES += \
$${NADIR_SRC}/xos/fs/path.cpp \
$${NADIR_SRC}/xos/fs/path_separator.cpp \
$${NADIR_SRC}/xos/fs/path_separator_events.cpp \
\
$${NADIR_SRC}/xos/base/main_main.cpp \
$${NADIR_SRC}/xos/app/console/path/main.cpp \

########################################################################
# xospath FRAMEWORKS
#
xospath_FRAMEWORKS += \
$${xosnadir_FRAMEWORKS} \

# xospath LIBS
#
xospath_LIBS += \
$${xosnadir_LIBS} \


