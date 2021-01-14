########################################################################
# Copyright (c) 1988-2021 $organization$
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
#   File: libxosbase.pro
#
# Author: $author$
#   Date: 1/12/2021
#
# QtCreator .pro file for nadir library libxosbase
########################################################################
include(../../../../../../build/QtCreator/nadir.pri)
include(../../../../../build/QtCreator/nadir.pri)
include(../../../../QtCreator/nadir.pri)
include(../../nadir.pri)
include(../../../../QtCreator/lib/libxosbase/libxosbase.pri)

TARGET = $${libxosbase_TARGET}
TEMPLATE = $${libxosbase_TEMPLATE}
CONFIG += $${libxosbase_CONFIG}

########################################################################
# INCLUDEPATH
#
INCLUDEPATH += \
$${libxosbase_INCLUDEPATH} \

# DEFINES
# 
DEFINES += \
$${libxosbase_DEFINES} \

########################################################################
# OBJECTIVE_HEADERS
#
OBJECTIVE_HEADERS += \
$${libxosbase_OBJECTIVE_HEADERS} \

# OBJECTIVE_SOURCES
#
OBJECTIVE_SOURCES += \
$${libxosbase_OBJECTIVE_SOURCES} \

########################################################################
# HEADERS
#
HEADERS += \
$${libxosbase_HEADERS} \
$${libxosbase_OBJECTIVE_HEADERS} \

# SOURCES
#
SOURCES += \
$${libxosbase_SOURCES} \

########################################################################


