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
#   File: Makefile
#
# Author: $author$
#   Date: 11/5/2014
#
# Gcc Makefile for nadir libxosnadir
########################################################################

libxosnadir_USRINCLUDES += \
-I${xos_USRINCLUDES} \

########################################################################
# io
libxosnadir_CPP_SOURCES += \
${XOS_SRC}/xos/io/file/writer.cpp \
${XOS_SRC}/xos/io/main/logger.cpp \
${XOS_SRC}/xos/io/reader.cpp \

########################################################################
# mt
libxosnadir_CPP_SOURCES += \
${XOS_SRC}/xos/mt/main/mutex.cpp \
${XOS_SRC}/xos/mt/acquire.cpp \
${XOS_SRC}/xos/mt/acquirer.cpp \
${XOS_SRC}/xos/mt/releaser.cpp \
${XOS_SRC}/xos/mt/lock.cpp \
${XOS_SRC}/xos/mt/locker.cpp \
${XOS_SRC}/xos/mt/wait.cpp \
${XOS_SRC}/xos/mt/waiter.cpp \

########################################################################
# base
libxosnadir_CPP_SOURCES += \
${XOS_SRC}/xos/base/getopt/main_opt.cpp \
${XOS_SRC}/xos/base/getopt/main.cpp \
${XOS_SRC}/xos/base/string.cpp \
${XOS_SRC}/xos/base/attacher.cpp \
${XOS_SRC}/xos/base/base.cpp \

########################################################################

libxosnadir_LIBS += \
${xos_LIBS} \


