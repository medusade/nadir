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
#   File: Makefile
#
# Author: $author$
#   Date: 10/17/2018
#
# generic Gcc Makefile for nadir Library libnadir
########################################################################


#
# target
#
libnadir_LIBTARGET = libnadir.${LIBEXT}

########################################################################

#
# user c++ flags
#
libnadir_USRCXXFLAGS += \
${nadir_USRCXXFLAGS} \

#
# user defines
#
libnadir_USRDEFINES += \
${nadir_USRDEFINES} \

#
# user includes
#
libnadir_USRINCLUDES += \
${nadir_USRINCLUDES} \

#
# user libdirs
#
libnadir_USRLIBDIRS += \
${nadir_USRLIBDIRS} \

########################################################################

#
# Library .c sources
#
libnadir_LIB_C_SOURCES += \
${NADIR_SRC}/thirdparty/gnu/glibc/posix/execvpe.c

#
# Library .cc sources
#
#libnadir_LIB_CC_SOURCES += \
#${NADIR_SRC}/nadir/base/Base.cc \

#
# Library .cxx sources
#
#libnadir_LIB_CXX_SOURCES += \
#${NADIR_SRC}/nadir/base/Base.cxx \

#
# Library .cpp sources
#
libnadir_LIB_CPP_SOURCES += \
${NADIR_SRC}/nadir/platform/platform.cpp \
\
${NADIR_SRC}/nadir/base/string.cpp \
${NADIR_SRC}/nadir/base/base.cpp \
\
${NADIR_SRC}/nadir/io/logger.cpp \
${NADIR_SRC}/nadir/io/logger_stdio.cpp \
${NADIR_SRC}/nadir/io/logger_message.cpp \
${NADIR_SRC}/nadir/io/logger_location.cpp \
${NADIR_SRC}/nadir/io/logger_function.cpp \
${NADIR_SRC}/nadir/io/logger_level.cpp \
\
${NADIR_SRC}/nadir/mt/os/process.cpp \
${NADIR_SRC}/nadir/mt/os/pipe.cpp \
${NADIR_SRC}/nadir/mt/os/mutex.cpp \
${NADIR_SRC}/nadir/mt/os/semaphore.cpp \
${NADIR_SRC}/nadir/mt/os/thread.cpp \
${NADIR_SRC}/nadir/mt/posix/timed.cpp \
\
${NADIR_SRC}/nadir/os/posix/file.cpp \
\
${NADIR_SRC}/nadir/lib/nadir/version.cpp \

#
# Library .m sources
#
#libnadir_LIB_M_SOURCES += \
#${NADIR_SRC}/nadir/base/Base.m \

#
# Library .mm sources
#
#libnadir_LIB_MM_SOURCES += \
#${NADIR_SRC}/nadir/base/Base.mm \


########################################################################




