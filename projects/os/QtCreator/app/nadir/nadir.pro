########################################################################
# Copyright (c) 1988-2023 $organization$
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
#   File: nadir.pro
#
# Author: $author$
#   Date: 3/4/2023
#
# os specific QtCreator project .pro file for texta framework nadir executable nadir
########################################################################
# Depends: rostra
#
# Debug: nadir/build/os/QtCreator/Debug/bin/nadir
# Release: nadir/build/os/QtCreator/Release/bin/nadir
# Profile: nadir/build/os/QtCreator/Profile/bin/nadir
#
include(../../../../../build/QtCreator/nadir.pri)
include(../../../../QtCreator/nadir.pri)
include(../../nadir.pri)
include(../../../../QtCreator/app/nadir/nadir.pri)

TARGET = $${nadir_exe_TARGET}

########################################################################
# INCLUDEPATH
#
INCLUDEPATH += \
$${nadir_exe_INCLUDEPATH} \

# DEFINES
# 
DEFINES += \
$${nadir_exe_DEFINES} \

########################################################################
# OBJECTIVE_HEADERS
#
OBJECTIVE_HEADERS += \
$${nadir_exe_OBJECTIVE_HEADERS} \

# OBJECTIVE_SOURCES
#
OBJECTIVE_SOURCES += \
$${nadir_exe_OBJECTIVE_SOURCES} \

########################################################################
# HEADERS
#
HEADERS += \
$${nadir_exe_HEADERS} \
$${nadir_exe_OBJECTIVE_HEADERS} \

# SOURCES
#
SOURCES += \
$${nadir_exe_SOURCES} \

########################################################################
# FRAMEWORKS
#
FRAMEWORKS += \
$${nadir_exe_FRAMEWORKS} \

# LIBS
#
LIBS += \
$${nadir_exe_LIBS} \
$${FRAMEWORKS} \

########################################################################
