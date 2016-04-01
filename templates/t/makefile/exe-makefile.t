%########################################################################
%# Copyright (c) 1988-2016 $organization$
%#
%# This software is provided by the author and contributors ``as is'' 
%# and any express or implied warranties, including, but not limited to, 
%# the implied warranties of merchantability and fitness for a particular 
%# purpose are disclaimed. In no event shall the author or contributors 
%# be liable for any direct, indirect, incidental, special, exemplary, 
%# or consequential damages (including, but not limited to, procurement 
%# of substitute goods or services; loss of use, data, or profits; or 
%# business interruption) however caused and on any theory of liability, 
%# whether in contract, strict liability, or tort (including negligence 
%# or otherwise) arising in any way out of the use of this software, 
%# even if advised of the possibility of such damage.
%#
%#   File: exe-makefile.t
%#
%# Author: $author$
%#   Date: 3/23/2016
%########################################################################
%with(%
%file,%(%else-then(%file%,%(File)%)%)%,%
%File,%(%else-then(%File%,%(%file%)%)%)%,%
%FILE,%(%else-then(%FILE%,%(%toupper(%File%)%)%)%)%,%
%file,%(%else-then(%_File%,%(%tolower(%File%)%)%)%)%,%
%base,%(%else-then(%base%,%(Base)%)%)%,%
%Base,%(%else-then(%Base%,%(%base%)%)%)%,%
%BASE,%(%else-then(%BASE%,%(%toupper(%Base%)%)%)%)%,%
%base,%(%else-then(%_Base%,%(%tolower(%Base%)%)%)%)%,%
%baselib,%(%else-then(%baselib%,%(%Base%lib)%)%)%,%
%Baselib,%(%else-then(%Baselib%,%(%baselib%)%)%)%,%
%BASELIB,%(%else-then(%BASELIB%,%(%toupper(%Baselib%)%)%)%)%,%
%baselib,%(%else-then(%_Baselib%,%(%tolower(%Baselib%)%)%)%)%,%
%framework,%(%else-then(%framework%,%(Framework)%)%)%,%
%Framework,%(%else-then(%Framework%,%(%framework%)%)%)%,%
%FRAMEWORK,%(%else-then(%FRAMEWORK%,%(%toupper(%Framework%)%)%)%)%,%
%framework,%(%else-then(%_Framework%,%(%tolower(%Framework%)%)%)%)%,%
%frameworklib,%(%else-then(%frameworklib%,%(lib%Framework%)%)%)%,%
%Frameworklib,%(%else-then(%Frameworklib%,%(%frameworklib%)%)%)%,%
%FRAMEWORKLIB,%(%else-then(%FRAMEWORKLIB%,%(%toupper(%Frameworklib%)%)%)%)%,%
%frameworklib,%(%else-then(%_Frameworklib%,%(%tolower(%Frameworklib%)%)%)%)%,%
%platform,%(%else-then(%platform%,%(Platform)%)%)%,%
%Platform,%(%else-then(%Platform%,%(%platform%)%)%)%,%
%PLATFORM,%(%else-then(%PLATFORM%,%(%toupper(%Platform%)%)%)%)%,%
%platform,%(%else-then(%_Platform%,%(%tolower(%Platform%)%)%)%)%,%
%tools,%(%else-then(%tools%,%(Tools)%)%)%,%
%Tools,%(%else-then(%Tools%,%(%tools%)%)%)%,%
%TOOLS,%(%else-then(%TOOLS%,%(%toupper(%Tools%)%)%)%)%,%
%tools,%(%else-then(%_Tools%,%(%tolower(%Tools%)%)%)%)%,%
%target,%(%else-then(%target%,%(Target)%)%)%,%
%Target,%(%else-then(%Target%,%(%target%)%)%)%,%
%TARGET,%(%else-then(%TARGET%,%(%toupper(%Target%)%)%)%)%,%
%target,%(%else-then(%_Target%,%(%tolower(%Target%)%)%)%)%,%
%%(%
%########################################################################
# Copyright (c) 1988-%year()% $organization$
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
#   File: %File%
#
# Author: $author$
#   Date: %date()%
#
# %Platform% %Tools% Makefile for %Framework% executable %Target%
########################################################################
PKG = ../../../../../..
OS = %Platform%

BMK = build/Makefile/%Tools%
MAK = projects/Makefile/%Tools%
PRJ = projects/$(OS)/Makefile/%Tools%
SRC = src

include $(PKG)/$(MAK)/Makedefines
include $(PKG)/$(PRJ)/Makedefines
include $(PKG)/$(BMK)/Makefile
include $(PKG)/$(MAK)/Makefile
include $(PKG)/$(MAK)/lib/%Frameworklib%/Makefile
include $(PKG)/$(MAK)/app/%Target%/Makefile

#
# target
#
EXETARGET = %Target%

#
# user defines
#
USRDEFINES = \
${%Frameworklib%_USRDEFINES} \

#
# user includes
#
USRINCLUDES = \
${%Frameworklib%_USRINCLUDES} \

#
# user libdirs
#
USRLIBDIRS = \
${%Frameworklib%_USRLIBDIRS} \

#
# user c++ flags
#
USRCXXFLAGS = \
${%Frameworklib%_USRCXXFLAGS} \

#
# user c flags
#
USRCFLAGS = \
${%Frameworklib%_USRCFLAGS} \

#
# user ld flags
#
USRLDFLAGS = \
${%Frameworklib%_USRLDFLAGS} \

#
# Executable C sources
#
EXE_C_SOURCES = \
${%Target%_EXE_C_SOURCES} \

#
# Executable C++ .cc sources
#
EXE_CC_SOURCES = \
${%Target%_EXE_CC_SOURCES} \

#
# Executable C++ .cxx sources
#
EXE_CXX_SOURCES = \
${%Target%_EXE_CXX_SOURCES} \

#
# Executable C++ .cpp sources
#
EXE_CPP_SOURCES = \
${%Target%_EXE_CPP_SOURCES} \

#
# Executable Objective C .m sources
#
EXE_M_SOURCES = \
${%Target%_EXE_M_SOURCES} \

#
# Executable Objective C++ .mm sources
#
EXE_MM_SOURCES = \
${%Target%_EXE_MM_SOURCES} \

#
# Executable libs
#
#LIBS = \
#-lsomelib
#
LIBS = \
${%Frameworklib%_LIBS} \

#
# Executable depends
#
#EXEDEP = \
#$(PKG)/$(BLD)/libsomelib \
#
EXEDEP = \

#
# Executable depend dirs
#
#EXEDEP_DIRS = \
#../libsomelib
#
EXEDEP_DIRS = \

include $(PKG)/$(PRJ)/Makerules

#
# Executable depend rules
#
#$(PKG)/$(BLD)/libsomelib.a:
#	@(echo Building libsomelib.a ...;\
#	  pushd ../libsomelib;\
#	  ((make) || (exit 1));\
#	  popd)
#
%
%)%)%