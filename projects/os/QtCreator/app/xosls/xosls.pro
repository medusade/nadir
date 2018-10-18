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
#   File: xosls.pro
#
# Author: $author$
#   Date: 9/1/2018
#
# QtCreator .pro file for nadir executable xosls
########################################################################
include(../../../../../build/QtCreator/nadir.pri)
include(../../../../QtCreator/nadir.pri)
include(../../nadir.pri)
include(../../../../QtCreator/app/xosls/xosls.pri)

TARGET = $${xosls_TARGET}

########################################################################
# INCLUDEPATH
#
INCLUDEPATH += \
$${xosls_INCLUDEPATH} \

# DEFINES
# 
DEFINES += \
$${xosls_DEFINES} \

########################################################################
# OBJECTIVE_HEADERS
#
OBJECTIVE_HEADERS += \
$${xosls_OBJECTIVE_HEADERS} \

# OBJECTIVE_SOURCES
#
OBJECTIVE_SOURCES += \
$${xosls_OBJECTIVE_SOURCES} \

########################################################################
# HEADERS
#
HEADERS += \
$${xosls_HEADERS} \
$${OBJECTIVE_HEADERS} \

# SOURCES
#
SOURCES += \
$${xosls_SOURCES} \

########################################################################
# FRAMEWORKS
#
FRAMEWORKS += \
$${xosls_FRAMEWORKS} \

# LIBS
#
LIBS += \
$${xosls_LIBS} \
$${FRAMEWORKS} \


