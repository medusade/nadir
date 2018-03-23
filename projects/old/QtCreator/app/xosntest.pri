########################################################################
# Copyright (c) 1988-2015 $organization$
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
#   File: xosntest.pri
#
# Author: $author$
#   Date: 3/25/2015
########################################################################

xosntest_INCLUDEPATH += \
$${libxosnadir_INCLUDEPATH} \

xosntest_DEFINES += \
$${libxosnadir_DEFINES} \

########################################################################
xosntest_HEADERS += \
$${XOS_SRC}/xos/app/console/test/main.hpp \

xosntest_SOURCES += \
$${XOS_SRC}/xos/app/console/test/main.cpp \
$${XOS_SRC}/xos/base/main_main.cpp \

########################################################################
xosntest_LIBS += \
$${libxosnadir_LIBS} \
