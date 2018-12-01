%########################################################################
%# Copyright (c) 1988-2018 $organization$
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
%#   File: nadir-hpp.t
%#
%# Author: $author$
%#   Date: 11/20/2018
%########################################################################
%with(%
%include_path,%(%else-then(%include_path%,%(%filepath(%input%)%)%)%)%,%
%ifndef,%(%else-then(%ifndef%,%(_%parse(%Ifndef_directory%,/,,_)%_%Name%_%Extension%)%)%)%,%
%Ifndef,%(%else-then(%Ifndef%,%(%ifndef%)%)%)%,%
%IFNDEF,%(%else-then(%IFNDEF%,%(%toupper(%Ifndef%)%)%)%)%,%
%ifndef,%(%else-then(%_Ifndef%,%(%tolower(%Ifndef%)%)%)%)%,%
%ifndef_begin,%(%else-then(%ifndef_begin%,%(#ifndef %IFNDEF%
#define %IFNDEF%

)%)%)%,%
%Ifndef_begin,%(%else-then(%Ifndef_begin%,%(%ifndef_begin%)%)%)%,%
%IFNDEF_BEGIN,%(%else-then(%IFNDEF_BEGIN%,%(%toupper(%Ifndef_begin%)%)%)%)%,%
%ifndef_begin,%(%else-then(%_Ifndef_begin%,%(%tolower(%Ifndef_begin%)%)%)%)%,%
%ifndef_end,%(%else-then(%ifndef_end%,%(
#endif /// ndef %IFNDEF%
)%)%)%,%
%Ifndef_end,%(%else-then(%Ifndef_end%,%(%ifndef_end%)%)%)%,%
%IFNDEF_END,%(%else-then(%IFNDEF_END%,%(%toupper(%Ifndef_end%)%)%)%)%,%
%ifndef_end,%(%else-then(%_Ifndef_end%,%(%tolower(%Ifndef_end%)%)%)%)%,%
%include,%(%else-then(%include%,%(xos/base/base.hpp)%)%)%,%
%Include,%(%else-then(%Include%,%(%include%)%)%)%,%
%Include,%(%parse(%Include%,;,,,,%(#include "%include%"
)%,include)%)%,%
%INCLUDE,%(%else-then(%INCLUDE%,%(%toupper(%Include%)%)%)%)%,%
%include,%(%else-then(%_Include%,%(%tolower(%Include%)%)%)%)%,%
%sysinclude,%(%else-then(%sysinclude%,%(%sys_include%)%)%)%,%
%SysInclude,%(%else-then(%SysInclude%,%(%sysinclude%)%)%)%,%
%SysInclude,%(%parse(%SysInclude%,;,,,,%(#include <%include%>
)%,include)%)%,%
%SYSINCLUDE,%(%else-then(%SYSINCLUDE%,%(%toupper(%SysInclude%)%)%)%)%,%
%sysinclude,%(%else-then(%_SysInclude%,%(%tolower(%SysInclude%)%)%)%)%,%
%%(%
%%Ifndef_begin%%
%%include(%include_path%/nadir-%Extension%-%Extension%.t)%%
%%Ifndef_end%%
%)%)%