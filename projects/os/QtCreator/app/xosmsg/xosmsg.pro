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
#   File: xosmsg.pro
#
# Author: $author$
#   Date: 9/9/2018, 12/13/2020
#
# QtCreator .pro file for nadir executable xosmsg
########################################################################
include(../../../../../../build/QtCreator/nadir.pri)
include(../../../../../build/QtCreator/nadir.pri)
include(../../../../QtCreator/nadir.pri)
include(../../nadir.pri)
include(../../../../QtCreator/app/xosmsg/xosmsg.pri)

TARGET = $${xosmsg_TARGET}

########################################################################
# INCLUDEPATH
#
INCLUDEPATH += \
$${xosmsg_INCLUDEPATH} \

# DEFINES
# 
DEFINES += \
$${xosmsg_DEFINES} \

########################################################################
# OBJECTIVE_HEADERS
#
OBJECTIVE_HEADERS += \
$${xosmsg_OBJECTIVE_HEADERS} \

# OBJECTIVE_SOURCES
#
OBJECTIVE_SOURCES += \
$${xosmsg_OBJECTIVE_SOURCES} \

########################################################################
# HEADERS
#
HEADERS += \
$${xosmsg_HEADERS} \
$${OBJECTIVE_HEADERS} \

# SOURCES
#
SOURCES += \
$${xosmsg_SOURCES} \

########################################################################
# FRAMEWORKS
#
FRAMEWORKS += \
$${xosmsg_FRAMEWORKS} \

# LIBS
#
LIBS += \
$${xosmsg_LIBS} \
$${FRAMEWORKS} \

