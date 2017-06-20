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
#   File: hello.pri
#
# Author: $author$
#   Date: 6/17/2017
########################################################################

hello_TARGET = hello

hello_INCLUDEPATH += \
$${nadir_INCLUDEPATH} \

hello_DEFINES += \
$${nadir_DEFINES} \

########################################################################
hello_HEADERS += \
$${NADIR_SRC}/nadir/base/startup.hpp \
$${NADIR_SRC}/nadir/base/exists.hpp \

hello_SOURCES += \
$${NADIR_SRC}/nadir/base/startup.cpp \
$${NADIR_SRC}/nadir/base/exists.cpp \

########################################################################
hello_HEADERS += \
$${NADIR_SRC}/nadir/network/os/sockets.hpp \
$${NADIR_SRC}/nadir/network/microsoft/windows/sockets.hpp \
$${NADIR_SRC}/nadir/network/apple/osx/sockets.hpp \
$${NADIR_SRC}/nadir/network/posix/sockets.hpp \
$${NADIR_SRC}/nadir/network/sockets.hpp \
$${NADIR_SRC}/nadir/network/os/socket.hpp \
$${NADIR_SRC}/nadir/network/microsoft/windows/socket.hpp \
$${NADIR_SRC}/nadir/network/microsoft/windows/winsock.hpp \
$${NADIR_SRC}/nadir/network/apple/osx/socket.hpp \
$${NADIR_SRC}/nadir/network/posix/socket.hpp \
$${NADIR_SRC}/nadir/network/socket.hpp \
$${NADIR_SRC}/nadir/network/ip/udp/transport.hpp \
$${NADIR_SRC}/nadir/network/ip/tcp/transport.hpp \
$${NADIR_SRC}/nadir/network/ip/transport.hpp \
$${NADIR_SRC}/nadir/network/transport.hpp \
$${NADIR_SRC}/nadir/network/ip/v6/endpoint.hpp \
$${NADIR_SRC}/nadir/network/ip/v4/endpoint.hpp \
$${NADIR_SRC}/nadir/network/ip/endpoint.hpp \
$${NADIR_SRC}/nadir/network/endpoint.hpp \
$${NADIR_SRC}/nadir/network/ip/v6/address.hpp \
$${NADIR_SRC}/nadir/network/ip/v4/address.hpp \
$${NADIR_SRC}/nadir/network/ip/address.hpp \
$${NADIR_SRC}/nadir/network/address.hpp \
$${NADIR_SRC}/nadir/network/os/os.hpp \

hello_SOURCES += \
$${NADIR_SRC}/nadir/network/os/sockets.cpp \
$${NADIR_SRC}/nadir/network/os/socket.cpp \
$${NADIR_SRC}/nadir/network/microsoft/windows/winsock.cpp \
$${NADIR_SRC}/nadir/network/ip/udp/transport.cpp \
$${NADIR_SRC}/nadir/network/ip/v6/endpoint.cpp \
$${NADIR_SRC}/nadir/network/ip/v6/address.cpp \
$${NADIR_SRC}/nadir/network/os/os.cpp \

########################################################################
hello_HEADERS += \
$${NADIR_SRC}/nadir/app/console/network/hello/main.hpp \
$${NADIR_SRC}/nadir/app/console/network/main_opt.hpp \
$${NADIR_SRC}/nadir/console/main_main.hpp \

hello_SOURCES += \
$${NADIR_SRC}/nadir/app/console/network/hello/main.cpp \
$${NADIR_SRC}/nadir/app/console/network/main_opt.cpp \
$${NADIR_SRC}/nadir/console/main_main.cpp \

########################################################################
hello_LIBS += \
$${nadir_LIBS} \
