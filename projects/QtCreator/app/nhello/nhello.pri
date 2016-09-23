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
#   File: nhello.pri
#
# Author: $author$
#   Date: 9/18/2016
########################################################################

nhello_INCLUDEPATH += \
$${nadir_INCLUDEPATH} \
$${crono_INCLUDEPATH} \

nhello_DEFINES += \
$${nadir_DEFINES} \

########################################################################
nhello_HEADERS += \
$${CRONO_SRC}/crono/mt/posix/Mutex.hpp \
$${CRONO_SRC}/crono/mt/Mutex.hpp \
$${CRONO_SRC}/crono/base/Locked.hpp \
$${CRONO_SRC}/crono/base/Created.hpp \
$${CRONO_SRC}/crono/base/Attached.hpp \
$${CRONO_SRC}/crono/base/Base.hpp \

nhello_SOURCES += \
$${CRONO_SRC}/crono/mt/posix/Mutex.cpp \
$${CRONO_SRC}/crono/base/Locked.cpp \
$${CRONO_SRC}/crono/base/Created.cpp \
$${CRONO_SRC}/crono/base/Attached.cpp \
$${CRONO_SRC}/crono/base/Base.cpp \

########################################################################
nhello_HEADERS += \
$${NADIR_SRC}/nadir/base/locked.hpp \
$${NADIR_SRC}/nadir/base/waited.hpp \

nhello_SOURCES += \
$${NADIR_SRC}/nadir/base/waited.cpp \

########################################################################
nhello_HEADERS += \
$${NADIR_SRC}/nadir/app/console/hello/main.hpp \

nhello_SOURCES += \
$${NADIR_SRC}/nadir/app/console/hello/main.cpp \

########################################################################
nhello_LIBS += \
$${nadir_LIBS} \

