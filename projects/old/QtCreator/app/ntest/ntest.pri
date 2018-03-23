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
#   File: xosntest.pri
#
# Author: $author$
#   Date: 1/6/2017
########################################################################

ntest_TARGET = ntest

ntest_INCLUDEPATH += \
$${nadir_INCLUDEPATH} \

ntest_DEFINES += \
$${nadir_DEFINES} \

########################################################################
ntest_HEADERS += \
$${NADIR_SRC}/nadir/io/logger.hpp \
$${NADIR_SRC}/nadir/os/microsoft/windows/time.hpp \
$${NADIR_SRC}/nadir/app/console/test/main.hpp \
$${NADIR_SRC}/nadir/console/main_logger.hpp \

ntest_SOURCES += \
$${NADIR_SRC}/nadir/io/logger.cpp \
$${NADIR_SRC}/nadir/os/microsoft/windows/time.cpp \
$${NADIR_SRC}/nadir/app/console/test/main.cpp \
$${NADIR_SRC}/nadir/console/main_logger.cpp \
$${NADIR_SRC}/nadir/console/main_main.cpp \

########################################################################
ntest_LIBS += \
$${nadir_LIBS} \
