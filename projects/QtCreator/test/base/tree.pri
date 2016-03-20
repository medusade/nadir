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
#   File: tree.pri
#
# Author: $author$
#   Date: 3/7/2016
########################################################################

tree_INCLUDEPATH += \
$${libxosnadir_INCLUDEPATH} \

tree_DEFINES += \
$${libxosnadir_DEFINES} \

tree_HEADERS += \
$${XOS_SRC}/xos/base/tree.hpp \
$${XOS_SRC}/xos/base/test/tree.hpp \
$${XOS_SRC}/xos/base/main_main.hpp \
$${XOS_SRC}/xos/base/getopt/main_opt.hpp \

tree_SOURCES += \
$${XOS_SRC}/xos/base/test/tree.cpp \
$${XOS_SRC}/xos/base/main_main.cpp \
$${XOS_SRC}/xos/base/getopt/main_opt.cpp \

tree_LIBS += \
$${libxosnadir_LIBS} \

