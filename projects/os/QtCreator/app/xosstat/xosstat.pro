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
#   File: xosstat.pro
#
# Author: $author$
#   Date: 9/9/2018, 12/13/2020
#
# QtCreator .pro file for nadir executable xosstat
########################################################################
include(../../../../../../build/QtCreator/nadir.pri)
include(../../../../../build/QtCreator/nadir.pri)
include(../../../../QtCreator/nadir.pri)
include(../../nadir.pri)
include(../../../../QtCreator/app/xosstat/xosstat.pri)

TARGET = $${xosstat_TARGET}

########################################################################
# INCLUDEPATH
#
INCLUDEPATH += \
$${xosstat_INCLUDEPATH} \

# DEFINES
# 
DEFINES += \
$${xosstat_DEFINES} \

########################################################################
# OBJECTIVE_HEADERS
#
OBJECTIVE_HEADERS += \
$${xosstat_OBJECTIVE_HEADERS} \

# OBJECTIVE_SOURCES
#
OBJECTIVE_SOURCES += \
$${xosstat_OBJECTIVE_SOURCES} \

########################################################################
# HEADERS
#
HEADERS += \
$${xosstat_HEADERS} \
$${OBJECTIVE_HEADERS} \

# SOURCES
#
SOURCES += \
$${xosstat_SOURCES} \

########################################################################
# FRAMEWORKS
#
FRAMEWORKS += \
$${xosstat_FRAMEWORKS} \

# LIBS
#
LIBS += \
$${xosstat_LIBS} \
$${FRAMEWORKS} \


