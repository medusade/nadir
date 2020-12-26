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
#   File: xosstat.pri
#
# Author: $author$
#   Date: 9/9/2018, 12/13/2020
#
# QtCreator .pri file for nadir executable xosstat
########################################################################

########################################################################
# xosstat

# xosstat TARGET
#
xosstat_TARGET = xosstat

# xosstat INCLUDEPATH
#
xosstat_INCLUDEPATH += \
$${xosnadir_INCLUDEPATH} \

# xosstat DEFINES
#
xosstat_DEFINES += \
$${xosnadir_DEFINES} \
XOS_NO_ERR_LOG_DEBUG \
XOS_NO_ERR_LOG_TRACE \
XOS_LOGGING_LEVELS_DEFAULT=XOS_LOGGING_LEVELS_ERROR \

########################################################################
# xosstat OBJECTIVE_HEADERS
#
#xosstat_OBJECTIVE_HEADERS += \
#$${NADIR_SRC}/nadir/base/Base.hh \

# xosstat OBJECTIVE_SOURCES
#
#xosstat_OBJECTIVE_SOURCES += \
#$${NADIR_SRC}/nadir/base/Base.mm \

########################################################################
# xosstat HEADERS
#
xosstat_HEADERS += \
$${NADIR_SRC}/xos/base/main_main.hpp \
$${NADIR_SRC}/xos/app/console/stat/main.hpp \

# xosstat SOURCES
#
xosstat_SOURCES += \
$${NADIR_SRC}/xos/base/main_main.cpp \
$${NADIR_SRC}/xos/app/console/stat/main.cpp \

########################################################################
# xosstat FRAMEWORKS
#
xosstat_FRAMEWORKS += \
$${xosnadir_FRAMEWORKS} \

# xosstat LIBS
#
xosstat_LIBS += \
$${xosnadir_LIBS} \


