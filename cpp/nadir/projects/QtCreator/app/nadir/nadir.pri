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
#   Date: 9/7/2017
#
# QtCreator .pri file for nadir executable nadir
########################################################################

nadir_exe_TARGET = nadir

########################################################################
nadir_exe_INCLUDEPATH += \
$${nadir_INCLUDEPATH} \

nadir_exe_DEFINES += \
$${nadir_DEFINES} \

########################################################################
# patrona
nadir_exe_HEADERS += \
$${PATRONA_SRC}/xos/base/locked.hpp \

nadir_exe_SOURCES += \
$${PATRONA_SRC}/xos/base/locked.cpp \

########################################################################
# nadir
nadir_exe_HEADERS += \
$${NADIR_SRC}/xos/base/exception.hpp \
$${NADIR_SRC}/xos/base/string.hpp \
$${NADIR_SRC}/xos/base/string_base.hpp \
$${NADIR_SRC}/xos/base/chars.hpp \
$${NADIR_SRC}/xos/base/append.hpp \

nadir_exe_SOURCES += \
$${NADIR_SRC}/xos/base/exception.cpp \
$${NADIR_SRC}/xos/base/string.cpp \
$${NADIR_SRC}/xos/base/string_base.cpp \
$${NADIR_SRC}/xos/base/chars.cpp \
$${NADIR_SRC}/xos/base/append.cpp \

nadir_exe_HEADERS += \
$${NADIR_SRC}/xos/console/io.hpp \
$${NADIR_SRC}/xos/console/getopt/main.hpp \
$${NADIR_SRC}/xos/console/getopt/main_base.hpp \
$${NADIR_SRC}/xos/console/getopt/main_opt.hpp \
$${NADIR_SRC}/xos/console/main.hpp \
$${NADIR_SRC}/xos/console/main_arg.hpp \
$${NADIR_SRC}/xos/console/main_exception.hpp \
$${NADIR_SRC}/xos/console/main_main.hpp \

nadir_exe_SOURCES += \
$${NADIR_SRC}/xos/console/io.cpp \
$${NADIR_SRC}/xos/console/getopt/main.cpp \
$${NADIR_SRC}/xos/console/getopt/main_base.cpp \
$${NADIR_SRC}/xos/console/getopt/main_opt.cpp \
$${NADIR_SRC}/xos/console/main_arg.cpp \
$${NADIR_SRC}/xos/console/main_exception.cpp \
$${NADIR_SRC}/xos/console/main_main.cpp \

########################################################################
nadir_exe_LIBS += \
$${nadir_LIBS} \



