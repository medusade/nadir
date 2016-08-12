########################################################################
# Copyright (c) 1988-2014 $organization$
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
#   File: xosnhello.pro
#
# Author: $author$
#   Date: 9/7/2014
########################################################################
include(../../../../QtCreator/lib/libxosnadir.pri)
include(../../../../QtCreator/app/xosnhello.pri)

TARGET = xosnhello

INCLUDEPATH += \
$${libxosnadir_INCLUDEPATH} \

DEFINES += \
$${libxosnadir_DEFINES} \

########################################################################
# mt
HEADERS += \
$${XOS_SRC}/xos/mt/os/semaphore.hpp \
$${XOS_SRC}/xos/mt/macosx/semaphore.hpp \
$${XOS_SRC}/xos/mt/semaphore.hpp \

SOURCES += \
$${XOS_SRC}/xos/mt/os/semaphore.cpp \

########################################################################
# network
HEADERS += \
$${XOS_SRC}/xos/network/ip/v6/address.hpp \
$${XOS_SRC}/xos/network/ip/v4/address.hpp \
$${XOS_SRC}/xos/network/ip/v4/address_string.hpp \
$${XOS_SRC}/xos/network/ip/address.hpp \
$${XOS_SRC}/xos/network/local/address.hpp \
$${XOS_SRC}/xos/network/address.hpp \
$${XOS_SRC}/xos/network/ip/v6/endpoint.hpp \
$${XOS_SRC}/xos/network/ip/v4/endpoint.hpp \
$${XOS_SRC}/xos/network/local/endpoint.hpp \
$${XOS_SRC}/xos/network/ip/endpoint.hpp \
$${XOS_SRC}/xos/network/endpoint.hpp \
$${XOS_SRC}/xos/network/ip/udp/transport.hpp \
$${XOS_SRC}/xos/network/ip/v6/tcp/transport.hpp \
$${XOS_SRC}/xos/network/ip/v6/udp/transport.hpp \
$${XOS_SRC}/xos/network/ip/v4/tcp/transport.hpp \
$${XOS_SRC}/xos/network/ip/v4/udp/transport.hpp \
$${XOS_SRC}/xos/network/ip/tcp/transport.hpp \
$${XOS_SRC}/xos/network/ip/transport.hpp \
$${XOS_SRC}/xos/network/local/dgram/transport.hpp \
$${XOS_SRC}/xos/network/local/stream/transport.hpp \
$${XOS_SRC}/xos/network/local/transport.hpp \
$${XOS_SRC}/xos/network/transport.hpp \
$${XOS_SRC}/xos/network/unix/socket.hpp \
$${XOS_SRC}/xos/network/socket.hpp \

SOURCES += \
$${XOS_SRC}/xos/network/ip/v4/address_string.cpp \
$${XOS_SRC}/xos/network/ip/v6/address.cpp \
$${XOS_SRC}/xos/network/ip/v6/endpoint.cpp \
$${XOS_SRC}/xos/network/ip/v6/udp/transport.cpp \
$${XOS_SRC}/xos/network/unix/socket.cpp \

########################################################################
HEADERS += \
$${xosnhello_HEADERS} \

SOURCES += \
$${xosnhello_SOURCES} \

########################################################################
LIBS += \
$${libxosnadir_LIBS} \
-lpthread \
-ldl \
