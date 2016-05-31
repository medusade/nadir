########################################################################
# Copyright (c) 1988-2016 $organization$
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
#   File: xosnpath.pri
#
# Author: $author$
#   Date: 5/27/2016
########################################################################

xosnpath_INCLUDEPATH += \
$${libxosnadir_INCLUDEPATH} \

xosnpath_DEFINES += \
$${libxosnadir_DEFINES} \

########################################################################
xosnpath_HEADERS += \
$${XOS_SRC}/xos/app/console/path/main.hpp \
$${XOS_SRC}/xos/fs/path.hpp \
$${XOS_SRC}/xos/fs/path_separator.hpp \
$${XOS_SRC}/xos/fs/path_separator_events.hpp \
$${XOS_SRC}/xos/base/string.hpp \
$${XOS_SRC}/xos/base/getopt/main.hpp \
$${XOS_SRC}/xos/base/getopt/main_opt.hpp \
$${XOS_SRC}/xos/base/main.hpp \

xosnpath_SOURCES += \
$${XOS_SRC}/xos/app/console/path/main.cpp \
$${XOS_SRC}/xos/fs/path.cpp \
$${XOS_SRC}/xos/fs/path_separator.cpp \
$${XOS_SRC}/xos/fs/path_separator_events.cpp \
$${XOS_SRC}/xos/base/string.cpp \
$${XOS_SRC}/xos/base/getopt/main_opt.cpp \
$${XOS_SRC}/xos/base/main_main.cpp \

########################################################################

xosnpath_LIBS += \
$${libxosnadir_LIBS} \

