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
#   File: xoshello.pri
#
# Author: $author$
#   Date: 9/1/2018, 12/13/2020
#
# QtCreator .pri file for nadir executable xoshello
########################################################################

########################################################################
# xoshello

# xoshello TARGET
#
xoshello_TARGET = xoshello

# xoshello INCLUDEPATH
#
xoshello_INCLUDEPATH += \
$${xosnadir_INCLUDEPATH} \

# xoshello DEFINES
#
xoshello_DEFINES += \
$${xosnadir_DEFINES} \
XOS_NO_ERR_LOG_DEBUG \
XOS_NO_ERR_LOG_TRACE \
XOS_LOGGING_LEVELS_DEFAULT=XOS_LOGGING_LEVELS_ERROR \

########################################################################
# xoshello OBJECTIVE_HEADERS
#
#xoshello_OBJECTIVE_HEADERS += \
#$${NADIR_SRC}/nadir/base/Base.hh \

# xoshello OBJECTIVE_SOURCES
#
#xoshello_OBJECTIVE_SOURCES += \
#$${NADIR_SRC}/nadir/base/Base.mm \

########################################################################
# xoshello HEADERS
#
xoshello_HEADERS += \
$${NADIR_SRC}/xos/app/console/hello/main.hpp \

# xoshello SOURCES
#
xoshello_SOURCES += \
$${NADIR_SRC}/xos/app/console/hello/main.cpp \

########################################################################
# xoshello FRAMEWORKS
#
xoshello_FRAMEWORKS += \
$${xosnadir_FRAMEWORKS} \

# xoshello LIBS
#
xoshello_LIBS += \
$${xosnadir_LIBS} \


