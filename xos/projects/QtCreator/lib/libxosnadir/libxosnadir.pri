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
#   File: libxosnadir.pri
#
# Author: $author$
#   Date: 3/2/2018
#
# QtCreator .pri file for nadir library libxosnadir
########################################################################

########################################################################
# libxosnadir
libxosnadir_TARGET = xosnadir
libxosnadir_TEMPLATE = lib
libxosnadir_CONFIG += staticlib

libxosnadir_INCLUDEPATH += \
$${nadir_INCLUDEPATH} \

libxosnadir_DEFINES += \
$${nadir_DEFINES} \

########################################################################
libxosnadir_HEADERS += \
$${NADIR_SRC}/xos/base/code.hpp \
$${NADIR_SRC}/xos/base/coded.hpp \
$${NADIR_SRC}/xos/base/coder.hpp \
$${NADIR_SRC}/xos/base/decoded.hpp \
$${NADIR_SRC}/xos/base/decoder.hpp \
$${NADIR_SRC}/xos/base/encoded.hpp \
$${NADIR_SRC}/xos/base/encoder.hpp \
$${NADIR_SRC}/xos/base/plain.hpp \
\
$${NADIR_SRC}/xos/base/constructor.hpp \
$${NADIR_SRC}/xos/base/destructor.hpp \
\
$${NADIR_SRC}/xos/base/collection.hpp \
$${NADIR_SRC}/xos/base/collector.hpp \
$${NADIR_SRC}/xos/base/distribution.hpp \
$${NADIR_SRC}/xos/base/distributor.hpp \
\
$${NADIR_SRC}/xos/base/message.hpp \
$${NADIR_SRC}/xos/base/messenger.hpp \
$${NADIR_SRC}/xos/base/receiver.hpp \
$${NADIR_SRC}/xos/base/router.hpp \
$${NADIR_SRC}/xos/base/sender.hpp \
\
$${NADIR_SRC}/xos/base/deserialized.hpp \
$${NADIR_SRC}/xos/base/deserializer.hpp \
$${NADIR_SRC}/xos/base/serialized.hpp \
$${NADIR_SRC}/xos/base/serializer.hpp \
$${NADIR_SRC}/xos/base/series.hpp \
$${NADIR_SRC}/xos/base/structure.hpp \
\
$${NADIR_SRC}/xos/base/base.hpp \

libxosnadir_SOURCES += \
$${NADIR_SRC}/xos/base/code.cpp \
$${NADIR_SRC}/xos/base/coded.cpp \
$${NADIR_SRC}/xos/base/coder.cpp \
$${NADIR_SRC}/xos/base/decoded.cpp \
$${NADIR_SRC}/xos/base/decoder.cpp \
$${NADIR_SRC}/xos/base/encoded.cpp \
$${NADIR_SRC}/xos/base/encoder.cpp \
$${NADIR_SRC}/xos/base/plain.cpp \
\
$${NADIR_SRC}/xos/base/constructor.cpp \
$${NADIR_SRC}/xos/base/destructor.cpp \
\
$${NADIR_SRC}/xos/base/collection.cpp \
$${NADIR_SRC}/xos/base/collector.cpp \
$${NADIR_SRC}/xos/base/distribution.cpp \
$${NADIR_SRC}/xos/base/distributor.cpp \
\
$${NADIR_SRC}/xos/base/message.cpp \
$${NADIR_SRC}/xos/base/messenger.cpp \
$${NADIR_SRC}/xos/base/receiver.cpp \
$${NADIR_SRC}/xos/base/router.cpp \
$${NADIR_SRC}/xos/base/sender.cpp \
\
$${NADIR_SRC}/xos/base/deserialized.cpp \
$${NADIR_SRC}/xos/base/deserializer.cpp \
$${NADIR_SRC}/xos/base/serialized.cpp \
$${NADIR_SRC}/xos/base/serializer.cpp \
$${NADIR_SRC}/xos/base/series.cpp \
$${NADIR_SRC}/xos/base/structure.cpp \
\
$${NADIR_SRC}/xos/base/base.cpp \

########################################################################

