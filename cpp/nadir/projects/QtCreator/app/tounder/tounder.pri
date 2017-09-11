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
#   File: tounder.pri
#
# Author: $author$
#   Date: 9/10/2017
#
# QtCreator .pri file for nadir executable tounder
########################################################################

tounder_TARGET = tounder

########################################################################
tounder_INCLUDEPATH += \
$${nadir_INCLUDEPATH} \

tounder_DEFINES += \
$${nadir_DEFINES} \

########################################################################
# nadir
tounder_HEADERS += \
$${NADIR_SRC}/xos/app/console/tounder/main.hpp \
$${NADIR_SRC}/xos/console/main_main.hpp \

tounder_SOURCES += \
$${NADIR_SRC}/xos/app/console/tounder/main.cpp \
$${NADIR_SRC}/xos/console/main_main.cpp \

########################################################################
tounder_LIBS += \
$${nadir_LIBS} \
