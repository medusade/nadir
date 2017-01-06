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

nhello_DEFINES += \
$${nadir_DEFINES} \

########################################################################
nhello_HEADERS += \
$${NADIR_SRC}/nadir/os/fs/directory/path.hpp \
$${NADIR_SRC}/nadir/os/fs/directory/entry.hpp \
$${NADIR_SRC}/nadir/os/microsoft/windows/fs/directory/path.hpp \
$${NADIR_SRC}/nadir/os/microsoft/windows/fs/directory/entry.hpp \
$${NADIR_SRC}/nadir/os/microsoft/windows/fs/entry.hpp \
$${NADIR_SRC}/nadir/os/apple/osx/fs/directory/path.hpp \
$${NADIR_SRC}/nadir/os/apple/osx/fs/directory/entry.hpp \
$${NADIR_SRC}/nadir/os/apple/osx/fs/entry.hpp \
$${NADIR_SRC}/nadir/os/fs/entry.hpp \
$${NADIR_SRC}/nadir/os/posix/fs/directory/path.hpp \
$${NADIR_SRC}/nadir/os/posix/fs/directory/entry.hpp \
$${NADIR_SRC}/nadir/os/posix/fs/entry.hpp \
$${NADIR_SRC}/nadir/os/fs.hpp \
$${NADIR_SRC}/nadir/os/os.hpp \
$${NADIR_SRC}/nadir/fs/directory/path.hpp \
$${NADIR_SRC}/nadir/fs/directory/entry.hpp \
$${NADIR_SRC}/nadir/fs/path.hpp \
$${NADIR_SRC}/nadir/fs/path_separator.hpp \
$${NADIR_SRC}/nadir/fs/entry.hpp \
$${NADIR_SRC}/nadir/fs/time.hpp \
$${NADIR_SRC}/nadir/io/logger.hpp \
$${NADIR_SRC}/nadir/base/date.hpp \
$${NADIR_SRC}/nadir/base/time.hpp \
$${NADIR_SRC}/nadir/base/timezone.hpp \
$${NADIR_SRC}/nadir/base/string.hpp \
$${NADIR_SRC}/nadir/base/created.hpp \
$${NADIR_SRC}/nadir/base/opened.hpp \
$${NADIR_SRC}/nadir/base/attached.hpp \
$${NADIR_SRC}/nadir/base/acquired.hpp \
$${NADIR_SRC}/nadir/base/locked.hpp \
$${NADIR_SRC}/nadir/base/waited.hpp \
$${NADIR_SRC}/nadir/base/chars.hpp \

nhello_SOURCES += \
$${NADIR_SRC}/nadir/os/fs/directory/path.cpp \
$${NADIR_SRC}/nadir/os/fs/entry.cpp \
$${NADIR_SRC}/nadir/os/fs.cpp \
$${NADIR_SRC}/nadir/os/os.cpp \
$${NADIR_SRC}/nadir/fs/path_separator.cpp \
$${NADIR_SRC}/nadir/fs/time.cpp \
$${NADIR_SRC}/nadir/io/logger.cpp \
$${NADIR_SRC}/nadir/base/date.cpp \
$${NADIR_SRC}/nadir/base/timezone.cpp \
$${NADIR_SRC}/nadir/base/string.cpp \
$${NADIR_SRC}/nadir/base/created.cpp \
$${NADIR_SRC}/nadir/base/opened.cpp \
$${NADIR_SRC}/nadir/base/attached.cpp \
$${NADIR_SRC}/nadir/base/acquired.cpp \
$${NADIR_SRC}/nadir/base/locked.cpp \
$${NADIR_SRC}/nadir/base/waited.cpp \
$${NADIR_SRC}/nadir/base/chars.cpp \

########################################################################
nhello_HEADERS += \
$${NADIR_SRC}/nadir/mt/os/semaphore.hpp \
$${NADIR_SRC}/nadir/mt/microsoft/windows/semaphore.hpp \
$${NADIR_SRC}/nadir/mt/apple/osx/semaphore.hpp \
$${NADIR_SRC}/nadir/mt/apple/mach/semaphore.hpp \
$${NADIR_SRC}/nadir/mt/posix/semaphore.hpp \
$${NADIR_SRC}/nadir/mt/semaphore.hpp \
$${NADIR_SRC}/nadir/mt/os/mutex.hpp \
$${NADIR_SRC}/nadir/mt/microsoft/windows/mutex.hpp \
$${NADIR_SRC}/nadir/mt/apple/osx/mutex.hpp \
$${NADIR_SRC}/nadir/mt/posix/mutex.hpp \
$${NADIR_SRC}/nadir/mt/mutex.hpp \
$${NADIR_SRC}/nadir/mt/os/os.hpp \

nhello_SOURCES += \
$${NADIR_SRC}/nadir/mt/os/semaphore.cpp \
$${NADIR_SRC}/nadir/mt/os/mutex.cpp \

########################################################################
nhello_HEADERS += \
$${NADIR_SRC}/nadir/console/main_main.hpp \
$${NADIR_SRC}/nadir/app/console/hello/main.hpp \

nhello_SOURCES += \
$${NADIR_SRC}/nadir/console/main_main.cpp \
$${NADIR_SRC}/nadir/app/console/hello/main.cpp \

########################################################################
nhello_LIBS += \
$${nadir_LIBS} \
