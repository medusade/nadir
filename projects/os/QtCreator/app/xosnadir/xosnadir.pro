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
#   File: xosnadir.pro
#
# Author: $author$
#   Date: 5/12/2018, 1/13/2021
#
# QtCreator .pro file for xosnadir executable xosnadir
########################################################################
include(../../../../../build/QtCreator/xosnadir.pri)
include(../../../../QtCreator/xosnadir.pri)
include(../../xosnadir.pri)
include(../../../../QtCreator/app/xosnadir/xosnadir.pri)

TARGET = $${xosnadir_exe_TARGET}

########################################################################
# INCLUDEPATH
#
INCLUDEPATH += \
$${xosnadir_exe_INCLUDEPATH} \

# DEFINES
# 
DEFINES += \
$${xosnadir_exe_DEFINES} \

########################################################################
# OBJECTIVE_HEADERS
#
OBJECTIVE_HEADERS += \
$${xosnadir_exe_OBJECTIVE_HEADERS} \

# OBJECTIVE_SOURCES
#
OBJECTIVE_SOURCES += \
$${xosnadir_exe_OBJECTIVE_SOURCES} \

########################################################################
# HEADERS
#
HEADERS += \
$${xosnadir_exe_HEADERS} \
$${xosnadir_exe_OBJECTIVE_HEADERS} \

# SOURCES
#
SOURCES += \
$${xosnadir_exe_SOURCES} \

########################################################################
# FRAMEWORKS
#
FRAMEWORKS += \
$${xosnadir_exe_FRAMEWORKS} \

# LIBS
#
LIBS += \
$${xosnadir_exe_LIBS} \
$${FRAMEWORKS} \


