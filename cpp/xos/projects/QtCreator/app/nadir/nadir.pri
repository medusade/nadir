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
#   File: nadir.pri
#
# Author: $author$
#   Date: 9/15/2017
#
# QtCreator .pri file for nadir executable nadir
########################################################################

nadir_exe_TARGET = nadir

########################################################################
nadir_exe_INCLUDEPATH += \
$${nadir_INCLUDEPATH} \

nadir_exe_DEFINES += \
$${nadir_DEFINES} \
XOS_APP_CONSOLE_NADIR_THE_MAIN \

########################################################################
# nadir
nadir_exe_HEADERS += \
$${NADIR_SRC}/xos/app/console/nadir/Main.hpp \
$${NADIR_SRC}/xos/app/console/nadir/MainOpt.hpp \
$${NADIR_SRC}/xos/console/Main_main.hpp \

nadir_exe_SOURCES += \
$${NADIR_SRC}/xos/app/console/nadir/Main.cpp \
$${NADIR_SRC}/xos/app/console/nadir/MainOpt.cpp \
$${NADIR_SRC}/xos/console/Main_main.cpp \

########################################################################
nadir_exe_LIBS += \
$${nadir_LIBS} \



