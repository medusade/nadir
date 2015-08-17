%########################################################################
%# Copyright (c) 1988-2015 $organization$
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
%#   File: common-pri.t
%#
%# Author: $author$
%#   Date: 4/23/2015
%########################################################################
%with(%
%framework,%(%else-then(%framework%,%(%else-then(%class%,%(Framework)%)%)%)%)%,%
%Framework,%(%else-then(%Framework%,%(%framework%)%)%)%,%
%FRAMEWORK,%(%else-then(%FRAMEWORK%,%(%toupper(%Framework%)%)%)%)%,%
%framework,%(%else-then(%_Framework%,%(%tolower(%Framework%)%)%)%)%,%
%filepath,%(%else-then(%filepath%,%(%filepath(%input%)%)%)%)%,%
%file,%(%else-then(%file%,%(%Framework%)%)%)%,%
%File,%(%else-then(%File%,%(%file%)%)%)%,%
%FILE,%(%else-then(%FILE%,%(%toupper(%File%)%)%)%)%,%
%file,%(%else-then(%_File%,%(%tolower(%File%)%)%)%)%,%
%file_base,%(%else-then(%file_base%,%(%filebase(%File%)%)%)%)%,%
%File_base,%(%else-then(%File_base%,%(%file_base%)%)%)%,%
%FILE_BASE,%(%else-then(%FILE_BASE%,%(%toupper(%File_base%)%)%)%)%,%
%file_base,%(%else-then(%_File_base%,%(%tolower(%File_base%)%)%)%)%,%
%file_type,%(%else-then(%file_type%,%(pri)%)%)%,%
%File_type,%(%else-then(%File_type%,%(%file_type%)%)%)%,%
%FILE_TYPE,%(%else-then(%FILE_TYPE%,%(%toupper(%File_type%)%)%)%)%,%
%file_type,%(%else-then(%_File_type%,%(%tolower(%File_type%)%)%)%)%,%
%file_extension,%(%else-then(%file_extension%,%(%else-then(%fileextension(%File%)%,%(%File_type%)%)%)%)%)%,%
%File_extension,%(%else-then(%File_extension%,%(%file_extension%)%)%)%,%
%FILE_EXTENSION,%(%else-then(%FILE_EXTENSION%,%(%toupper(%File_extension%)%)%)%)%,%
%file_extension,%(%else-then(%_File_extension%,%(%tolower(%File_extension%)%)%)%)%,%
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
#   File: %File_base%.%File_extension%
#
# Author: $author$
#   Date: %date()%
########################################################################
%FRAMEWORK%_PKG = ../../../../..
%FRAMEWORK%_BLD = ../..

%FRAMEWORK%_PRJ = $${%FRAMEWORK%_PKG}
%FRAMEWORK%_BIN = $${%FRAMEWORK%_BLD}/bin
%FRAMEWORK%_LIB = $${%FRAMEWORK%_BLD}/lib
%FRAMEWORK%_SRC = $${%FRAMEWORK%_PKG}/src

%Framework%_INCLUDEPATH += \
$${%Framework%_SRC} \

%Framework%_DEFINES += \

%Framework%_HEADERS += \

%Framework%_SOURCES += \

%Framework%_LIBS += \
-L$${%Framework%_LIB}/lib%Framework%%Library% \
-l%Framework%%Library% \

%)%)%