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
#   File: tree.pro
#
# Author: $author$
#   Date: 3/7/2016
########################################################################
include(../../../../QtCreator/lib/libxosnadir.pri)
include(../../../../QtCreator/test/base/tree.pri)

TARGET = xosntest-base-tree

INCLUDEPATH += \
$${tree_INCLUDEPATH} \

DEFINES += \
$${tree_DEFINES} \

HEADERS += \
$${tree_HEADERS} \

SOURCES += \
$${tree_SOURCES} \

LIBS += \
$${tree_LIBS} \
-lpthread \
-ldl \
