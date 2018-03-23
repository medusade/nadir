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
#   File: xosnmsg.pri
#
# Author: $author$
#   Date: 8/13/2016
########################################################################

########################################################################
# ipc
xosnmsg_HEADERS = \
$${XOS_SRC}/xos/ipc/unix/message_queue.hpp \
$${XOS_SRC}/xos/ipc/os/message_queue.hpp \
$${XOS_SRC}/xos/ipc/message_queue.hpp \
$${XOS_SRC}/xos/ipc/unix/key.hpp \
$${XOS_SRC}/xos/ipc/os/key.hpp \
$${XOS_SRC}/xos/ipc/key.hpp \
$${XOS_SRC}/xos/ipc/os/os.hpp \

xosnmsg_SOURCES = \
$${XOS_SRC}/xos/ipc/os/message_queue.cpp \
$${XOS_SRC}/xos/ipc/os/key.cpp \
$${XOS_SRC}/xos/ipc/os/os.cpp \

########################################################################
xosnmsg_HEADERS += \
$${XOS_SRC}/xos/app/console/msg/main.hpp \

xosnmsg_SOURCES += \
$${XOS_SRC}/xos/app/console/msg/main.cpp \
$${XOS_SRC}/xos/base/main_main.cpp \
