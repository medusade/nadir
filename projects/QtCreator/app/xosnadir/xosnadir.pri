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
#   File: xosnadir.pri
#
# Author: $author$
#   Date: 3/22/2018
#
# QtCreator .pri file for nadir executable xosnadir
########################################################################

########################################################################
# xosnadir

# xosnadir TARGET
#
xosnadir_exe_TARGET = xosnadir

# xosnadir INCLUDEPATH
#
xosnadir_exe_INCLUDEPATH += \
$${xosnadir_INCLUDEPATH} \

# xosnadir DEFINES
#
xosnadir_exe_DEFINES += \
$${xosnadir_DEFINES} \

########################################################################
# xosnadir OBJECTIVE_HEADERS
#
#xosnadir_exe_OBJECTIVE_HEADERS += \
#$${NADIR_SRC}/nadir/base/Base.hh \

# xosnadir OBJECTIVE_SOURCES
#
#xosnadir_exe_OBJECTIVE_SOURCES += \
#$${NADIR_SRC}/nadir/base/Base.mm \

########################################################################
# xosnadir HEADERS
#
xosnadir_exe_HEADERS += \
$${NADIR_SRC}/xos/console/main_main.hpp \

# xosnadir SOURCES
#
xosnadir_exe_SOURCES += \
$${NADIR_SRC}/xos/console/main_main.cpp \

########################################################################
# xosnadir FRAMEWORKS
#
xosnadir_exe_FRAMEWORKS += \
$${xosnadir_FRAMEWORKS} \

# xosnadir LIBS
#
xosnadir_exe_LIBS += \
$${xosnadir_LIBS} \
