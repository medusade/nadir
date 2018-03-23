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
#   File: nadir.pri
#
# Author: $author$
#   Date: 1/15/2018
#
# QtCreator .pri file for nadir executable nadir
########################################################################

nadir_exe_TARGET = nadir

########################################################################
nadir_exe_INCLUDEPATH += \
$${neonadir_INCLUDEPATH} \

nadir_exe_DEFINES += \
$${neonadir_DEFINES} \

########################################################################
# nadir
nadir_exe_HEADERS += \
$${NADIR_SRC}/nadir/app/console/nadir/main.hpp \
$${NADIR_SRC}/nadir/app/console/nadir/main_opt.hpp \
$${NADIR_SRC}/nadir/app/console/nadir/thread.hpp \
$${NADIR_SRC}/nadir/console/main_main.hpp \

nadir_exe_SOURCES += \
$${NADIR_SRC}/nadir/app/console/nadir/main.cpp \
$${NADIR_SRC}/nadir/app/console/nadir/main_opt.cpp \
$${NADIR_SRC}/nadir/app/console/nadir/thread.cpp \
$${NADIR_SRC}/nadir/console/main_main.cpp \

########################################################################
# nadir
nadir_exe_HEADERS += \
$${NADIR_SRC}/neo/nadir/console/getopt/main.hpp \
$${NADIR_SRC}/neo/nadir/console/getopt/main_opt.hpp \
$${NADIR_SRC}/neo/nadir/console/main_arg.hpp \

_nadir_exe_SOURCES += \
$${NADIR_SRC}/neo/nadir/console/getopt/main.cpp \
$${NADIR_SRC}/neo/nadir/console/getopt/main_opt.cpp \
$${NADIR_SRC}/neo/nadir/console/main_arg.cpp \

########################################################################
nadir_exe_LIBS += \
$${neonadir_LIBS} \
