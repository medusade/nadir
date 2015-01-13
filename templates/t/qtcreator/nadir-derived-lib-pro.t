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
%#   File: nadir-derived-lib-pro.t
%#
%# Author: $author$
%#   Date: 12/15/2014
%########################################################################
%with(%
%_lt_,%(%if(%equal(%content_type%,text/html)%,%(&lt;)%,%(<)%)%)%,%
%_gt_,%(%if(%equal(%content_type%,text/html)%,%(&gt;)%,%(>)%)%)%,%
%framework,%(%else-then(%framework%,%(%else-then(%class%,%(framework)%)%)%)%)%,%
%Framework,%(%else-then(%Framework%,%(%framework%)%)%)%,%
%FRAMEWORK,%(%else-then(%FRAMEWORK%,%(%toupper(%Framework%)%)%)%)%,%
%framework,%(%else-then(%_Framework%,%(%tolower(%Framework%)%)%)%)%,%
%base,%(%else-then(%base%,%(xos)%)%)%,%
%Base,%(%else-then(%Base%,%(%base%)%)%)%,%
%BASE,%(%else-then(%BASE%,%(%toupper(%Base%)%)%)%)%,%
%base,%(%else-then(%_Base%,%(%tolower(%Base%)%)%)%)%,%
%os,%(%else-then(%os%,%(os)%)%)%,%
%Os,%(%else-then(%Os%,%(%os%)%)%)%,%
%OS,%(%else-then(%OS%,%(%toupper(%Os%)%)%)%)%,%
%os,%(%else-then(%_Os%,%(%tolower(%Os%)%)%)%)%,%
%target,%(%else-then(%target%,%(%Framework%)%)%)%,%
%Target,%(%else-then(%Target%,%(%target%)%)%)%,%
%TARGET,%(%else-then(%TARGET%,%(%toupper(%Target%)%)%)%)%,%
%target,%(%else-then(%_Target%,%(%tolower(%Target%)%)%)%)%,%
%filepath,%(%else-then(%filepath%,%(%filepath(%input%)%)%)%)%,%
%file,%(%else-then(%file%,%(%Framework%)%)%)%,%
%File,%(%else-then(%File%,%(%file%)%)%)%,%
%FILE,%(%else-then(%FILE%,%(%toupper(%File%)%)%)%)%,%
%file,%(%else-then(%_File%,%(%tolower(%File%)%)%)%)%,%
%file_base,%(%else-then(%file_base%,%(%filebase(%File%)%)%)%)%,%
%File_base,%(%else-then(%File_base%,%(%file_base%)%)%)%,%
%FILE_BASE,%(%else-then(%FILE_BASE%,%(%toupper(%File_base%)%)%)%)%,%
%file_base,%(%else-then(%_File_base%,%(%tolower(%File_base%)%)%)%)%,%
%file_type,%(%else-then(%file_type%,%(pro)%)%)%,%
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
#   File: lib%File_base%.%File_extension%
#
# Author: $author$
#   Date: %date()%
########################################################################
include(../../../../QtCreator/%Framework%.pri)
include(../../../../QtCreator/lib/lib%Target%/lib%Target%.pri)
include(../../%Framework%.pri)

TARGET = %Target%

TEMPLATE = lib
CONFIG += staticlib

INCLUDEPATH += \
$${lib%Target%_INCLUDEPATH} \

DEFINES += \
$${lib%Target%_DEFINES} \

HEADERS += \
$${lib%Target%_HEADERS} \

SOURCES += \
$${lib%Target%_SOURCES} \

%
%)%)%