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
#   File: xosls.pri
#
# Author: $author$
#   Date: 9/1/2018
#
# QtCreator .pri file for nadir executable xosls
########################################################################

########################################################################
# xosls

# xosls TARGET
#
xosls_TARGET = xosls

# xosls INCLUDEPATH
#
xosls_INCLUDEPATH += \
$${xosnadir_INCLUDEPATH} \

# xosls DEFINES
#
xosls_DEFINES += \
$${xosnadir_DEFINES} \

########################################################################
# xosls OBJECTIVE_HEADERS
#
#xosls_OBJECTIVE_HEADERS += \
#$${NADIR_SRC}/nadir/base/Base.hh \

# xosls OBJECTIVE_SOURCES
#
#xosls_OBJECTIVE_SOURCES += \
#$${NADIR_SRC}/nadir/base/Base.mm \

########################################################################
# xosls HEADERS
#
xosls_HEADERS += \
$${NADIR_SRC}/xos/base/main_main.hpp \
$${NADIR_SRC}/xos/app/console/ls/main.hpp \

# xosls SOURCES
#
xosls_SOURCES += \
$${NADIR_SRC}/xos/base/main_main.cpp \
$${NADIR_SRC}/xos/app/console/ls/main.cpp \

########################################################################
# xosls FRAMEWORKS
#
xosls_FRAMEWORKS += \
$${xosnadir_FRAMEWORKS} \

# xosls LIBS
#
xosls_LIBS += \
$${xosnadir_LIBS} \


