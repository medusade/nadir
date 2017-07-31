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
#   File: test.pri
#
# Author: $author$
#   Date: 8/29/2017
########################################################################

test_TARGET = test

test_INCLUDEPATH += \
$${nadir_cpp_xos_INCLUDEPATH} \

test_DEFINES += \
$${nadir_cpp_xos_DEFINES} \

########################################################################
test_HEADERS += \
$${NADIR_CPP_XOS_SRC}/xos/base/std/StringBase.hpp \
$${NADIR_CPP_XOS_SRC}/xos/base/StringBase.hpp \
$${NADIR_CPP_XOS_SRC}/xos/base/CharsBase.hpp \
$${NADIR_CPP_XOS_SRC}/xos/base/Base.hpp \
$${NADIR_CPP_XOS_SRC}/xos/console/Main_main.hpp \

test_SOURCES += \
$${NADIR_CPP_XOS_SRC}/xos/base/StringBase.cpp \
$${NADIR_CPP_XOS_SRC}/xos/base/CharsBase.cpp \
$${NADIR_CPP_XOS_SRC}/xos/base/Base.cpp \
$${NADIR_CPP_XOS_SRC}/xos/console/Main_main.cpp \

########################################################################
test_LIBS += \
$${nadir_cpp_xos_LIBS} \
