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
%#   File: nadir-derived-template-class-cpp.t
%#
%# Author: $author$
%#   Date: 1/3/2015
%########################################################################
%with(%
%_lt_,%(%if(%equal(%content_type%,text/html)%,%(&lt;)%,%(<)%)%)%,%
%_gt_,%(%if(%equal(%content_type%,text/html)%,%(&gt;)%,%(>)%)%)%,%
%filepath,%(%else-then(%filepath%,%(%filepath(%input%)%)%)%)%,%
%file,%(%else-then(%file%,%(base)%)%)%,%
%File,%(%else-then(%File%,%(%file%)%)%)%,%
%FILE,%(%else-then(%FILE%,%(%toupper(%File%)%)%)%)%,%
%file,%(%else-then(%_File%,%(%tolower(%File%)%)%)%)%,%
%file_base,%(%else-then(%file_base%,%(%filebase(%File%)%)%)%)%,%
%File_base,%(%else-then(%File_base%,%(%file_base%)%)%)%,%
%FILE_BASE,%(%else-then(%FILE_BASE%,%(%toupper(%File_base%)%)%)%)%,%
%file_base,%(%else-then(%_File_base%,%(%tolower(%File_base%)%)%)%)%,%
%file_type,%(%else-then(%file_type%,%(hpp)%)%)%,%
%File_type,%(%else-then(%File_type%,%(%file_type%)%)%)%,%
%FILE_TYPE,%(%else-then(%FILE_TYPE%,%(%toupper(%File_type%)%)%)%)%,%
%file_type,%(%else-then(%_File_type%,%(%tolower(%File_type%)%)%)%)%,%
%file_extension,%(%else-then(%file_extension%,%(%File_type%)%)%)%,%
%File_extension,%(%else-then(%File_extension%,%(%file_extension%)%)%)%,%
%FILE_EXTENSION,%(%else-then(%FILE_EXTENSION%,%(%toupper(%File_extension%)%)%)%)%,%
%file_extension,%(%else-then(%_File_extension%,%(%tolower(%File_extension%)%)%)%)%,%
%framework,%(%else-then(%framework%,%(%else-then(%class%,%(framework)%)%)%)%)%,%
%Framework,%(%else-then(%Framework%,%(%framework%)%)%)%,%
%FRAMEWORK,%(%else-then(%FRAMEWORK%,%(%toupper(%Framework%)%)%)%)%,%
%framework,%(%else-then(%_Framework%,%(%tolower(%Framework%)%)%)%)%,%
%base,%(%else-then(%base%,%(base)%)%)%,%
%Base,%(%else-then(%Base%,%(%base%)%)%)%,%
%BASE,%(%else-then(%BASE%,%(%toupper(%Base%)%)%)%)%,%
%base,%(%else-then(%_Base%,%(%tolower(%Base%)%)%)%)%,%
%class,%(%else-then(%class%,%(derives)%)%)%,%
%Class,%(%else-then(%Class%,%(%class%)%)%)%,%
%CLASS,%(%else-then(%CLASS%,%(%toupper(%Class%)%)%)%)%,%
%class,%(%else-then(%_Class%,%(%tolower(%Class%)%)%)%)%,%
%extends,%(%else-then(%extends%,%(%Class%_extends)%)%)%,%
%Extends,%(%else-then(%Extends%,%(%extends%)%)%)%,%
%EXTENDS,%(%else-then(%EXTENDS%,%(%toupper(%Extends%)%)%)%)%,%
%extends,%(%else-then(%_Extends%,%(%tolower(%Extends%)%)%)%)%,%
%implements,%(%else-then(%implements%,%(%Class%_implements)%)%)%,%
%Implements,%(%else-then(%Implements%,%(%implements%)%)%)%,%
%IMPLEMENTS,%(%else-then(%IMPLEMENTS%,%(%toupper(%Implements%)%)%)%)%,%
%implements,%(%else-then(%_Implements%,%(%tolower(%Implements%)%)%)%)%,%
%%(%
%
///////////////////////////////////////////////////////////////////////
/// %Class%
///////////////////////////////////////////////////////////////////////
#if !defined(CPP_11)
#error Requires C++11
#else // !defined(CPP_11)
template
<class TExtends = %Framework%::%Base%::%Extends%,
 class TImplements = %Framework%::%Base%::%Implements%>

using %Class% = typename %Framework%::%Base%::%Class%
<TExtends, TImplements>;
#endif // !defined(CPP_11)
%
%)%)%