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
%#   File: common-exe-makefile.t
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
# Common %Tools% Makefile for %Framework% executable %Target%
########################################################################

#
# Executable C sources
#
%Target%_EXE_C_SOURCES += \

#
# Executable C++ .cxx sources
#
%Target%_EXE_CXX_SOURCES += \

#
# Executable C++ .cpp sources
#
%Target%_EXE_CPP_SOURCES += \
${%FRAMEWORK%_SRC}/%Framework%/console/main_opt.cpp \
${%FRAMEWORK%_SRC}/%Framework%/console/main_main.cpp \

#
# Executable Objective C sources
#
%Target%_EXE_M_SOURCES += \

#
# Executable Objective C++ sources
#
%Target%_EXE_MM_SOURCES += \

%
%)%)%