%########################################################################
%# Copyright (c) 1988-2014 $organization$
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
%#   File: derived-common-makefile.t
%#
%# Author: $author$
%#   Date: 12/8/2014
%########################################################################
%with(%
%file,%(%else-then(%file%,%(file)%)%)%,%
%File,%(%else-then(%File%,%(%file%)%)%)%,%
%FILE,%(%else-then(%FILE%,%(%toupper(%File%)%)%)%)%,%
%file,%(%else-then(%_File%,%(%tolower(%File%)%)%)%)%,%
%framework,%(%else-then(%framework%,%(framework)%)%)%,%
%Framework,%(%else-then(%Framework%,%(%framework%)%)%)%,%
%FRAMEWORK,%(%else-then(%FRAMEWORK%,%(%toupper(%Framework%)%)%)%)%,%
%framework,%(%else-then(%_Framework%,%(%tolower(%Framework%)%)%)%)%,%
%platform,%(%else-then(%platform%,%(platform)%)%)%,%
%Platform,%(%else-then(%Platform%,%(%platform%)%)%)%,%
%PLATFORM,%(%else-then(%PLATFORM%,%(%toupper(%Platform%)%)%)%)%,%
%platform,%(%else-then(%_Platform%,%(%tolower(%Platform%)%)%)%)%,%
%tools,%(%else-then(%tools%,%(tools)%)%)%,%
%Tools,%(%else-then(%Tools%,%(%tools%)%)%)%,%
%TOOLS,%(%else-then(%TOOLS%,%(%toupper(%Tools%)%)%)%)%,%
%tools,%(%else-then(%_Tools%,%(%tolower(%Tools%)%)%)%)%,%
%target,%(%else-then(%target%,%(target)%)%)%,%
%Target,%(%else-then(%Target%,%(%target%)%)%)%,%
%TARGET,%(%else-then(%TARGET%,%(%toupper(%Target%)%)%)%)%,%
%target,%(%else-then(%_Target%,%(%tolower(%Target%)%)%)%)%,%
%%(%
%
########################################################################
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
# Common %Tools% Makefile for %framework%
########################################################################
%FRAMEWORK%_PKG = ${PKG}
%FRAMEWORK%_SRC = ${%FRAMEWORK%_PKG}/src
%FRAMEWORK%_BLD = ${%FRAMEWORK%_PKG}/${BLD}/${BUILD_TYPE}
%FRAMEWORK%_LIB = ${%FRAMEWORK%_BLD}/lib
%FRAMEWORK%_BIN = ${%FRAMEWORK%_BLD}/bin

########################################################################
# xos
XOS_PKG = ${%FRAMEWORK%_PKG}/../nadir
XOS_SRC = ${XOS_PKG}/src
XOS_BLD = ${XOS_PKG}/${BLD}/${BUILD_TYPE}
XOS_LIB = ${XOS_BLD}/lib
XOS_BIN = ${XOS_BLD}/bin

########################################################################
# %framework%
%framework%_USRDEFINES += \

%framework%_USRINCLUDES += \
-I${%FRAMEWORK%_SRC} \
-I${XOS_SRC} \

%framework%_USRCXXFLAGS += \

%framework%_USRLIBDIRS += \
-L${XOS_LIB} \

%framework%_LIBS += \
-lxosnadir \
%
%)%)%