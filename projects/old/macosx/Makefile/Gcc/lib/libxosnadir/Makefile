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
# MacOSX Gcc Makefile for nadir libxosnadir Static Library
########################################################################
PKG = $(PWD)/../../../../../..

MAK = projects/Makefile/Gcc
PRJ = projects/macosx/Makefile/Gcc
SRC = src

include $(PKG)/$(MAK)/Makedefines
include $(PKG)/$(PRJ)/Makedefines
include $(PKG)/$(MAK)/Makefile
include $(PKG)/$(MAK)/lib/libxosnadir/Makefile

#
# user includes
#
USRINCLUDES = \
${libxosnadir_USRINCLUDES} \
-I${XOS_SRC}/thirdparty/gnu/glibc/posix \

#
# user defines
#
USRDEFINES = \

#
# user c++ flags
#
USRCXXFLAGS = \

#
# user c flags
#
USRCFLAGS = \

#
# user ld flags
#
USRLDFLAGS = \

#
# user libdirs
#
USRLIBDIRS = \

#
# target
#
LIBTARGET = libxosnadir.$(LIBEXT)

#
# Static Library C sources
#
LIB_C_SOURCES = \
${XOS_SRC}/thirdparty/gnu/glibc/posix/execvpe.c \

#
# Static Library C++ .cc sources
#
LIB_CC_SOURCES = \

#
# Static Library C++ .cxx sources
#
LIB_CXX_SOURCES = \

#
# Static Library C++ .cpp sources
#
LIB_CPP_SOURCES = \
${libxosnadir_CPP_SOURCES} \
${XOS_SRC}/xos/mt/macosx/mutex.cpp \
${XOS_SRC}/xos/mt/macosx/process.cpp \

#
# Static Library Objective C .m sources
#
LIB_M_SOURCES = \

#
# Static Library Objective C++ .mm sources
#
LIB_MM_SOURCES = \

#
# Static Library libs
#
#LIBS = \
#-lsomelib
#
LIBS = \

#
# Static Library depends
#
#LIBDEP = \
#$(PKG)/$(BLD)/libsomelib \
#
LIBDEP = \

#
# Static Library depend dirs
#
#LIBDEP_DIRS = \
#../libsomelib
#
LIBDEP_DIRS = \

include $(PKG)/$(PRJ)/Makerules

#
# Static Library depend rules
#
#$(PKG)/$(BLD)/libsomelib.a:
#	@(echo Building libsomelib.a ...;\
#	  pushd ../libsomelib;\
#	  ((make) || (exit 1));\
#	  popd)
#
