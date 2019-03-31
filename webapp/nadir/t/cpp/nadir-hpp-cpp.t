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
%#   File: nadir-hpp-cpp.t
%#
%# Author: $author$
%#   Date: 11/20/2018
%########################################################################
%with(%
%include_path,%(%else-then(%include_path%,%(%filepath(%input%)%)%)%)%,%
%file,%(%else-then(%file%,%(name)%)%)%,%
%File,%(%else-then(%File%,%(%file%)%)%)%,%
%FILE,%(%else-then(%FILE%,%(%toupper(%File%)%)%)%)%,%
%file,%(%else-then(%_File%,%(%tolower(%File%)%)%)%)%,%
%name,%(%else-then(%name%,%(%filebase(%File%)%)%)%)%,%
%Name,%(%else-then(%Name%,%(%name%)%)%)%,%
%NAME,%(%else-then(%NAME%,%(%toupper(%Name%)%)%)%)%,%
%name,%(%else-then(%_Name%,%(%tolower(%Name%)%)%)%)%,%
%namet,%(%else-then(%namet%,%(%Name%%if-no(%is_template%,,t)%)%)%)%,%
%NameT,%(%else-then(%NameT%,%(%namet%)%)%)%,%
%NAMET,%(%else-then(%NAMET%,%(%toupper(%NameT%)%)%)%)%,%
%namet,%(%else-then(%_NameT%,%(%tolower(%NameT%)%)%)%)%,%
%extension,%(%else-then(%extension%,%(%if-no(%extension%,,%fileextension(%File%)%)%)%)%)%,%
%Extension,%(%else-then(%Extension%,%(%extension%)%)%)%,%
%EXTENSION,%(%else-then(%EXTENSION%,%(%toupper(%Extension%)%)%)%)%,%
%extension,%(%else-then(%_Extension%,%(%tolower(%Extension%)%)%)%)%,%
%nadir,%(%else-then(%nadir%,%(nadir)%)%)%,%
%Nadir,%(%else-then(%Nadir%,%(%nadir%)%)%)%,%
%NADIR,%(%else-then(%NADIR%,%(%toupper(%Nadir%)%)%)%)%,%
%nadir,%(%else-then(%_Nadir%,%(%tolower(%Nadir%)%)%)%)%,%
%namespace,%(%else-then(%namespace%,%(%Nadir%)%)%)%,%
%Namespace,%(%else-then(%Namespace%,%(%namespace%)%)%)%,%
%NAMESPACE,%(%else-then(%NAMESPACE%,%(%toupper(%Namespace%)%)%)%)%,%
%namespace,%(%else-then(%_Namespace%,%(%tolower(%Namespace%)%)%)%)%,%
%namespace_begin,%(%else-then(%namespace_begin%,%(%parse(%Namespace%,/,,,,%(namespace %ns% {
)%,ns)%)%)%)%,%
%Namespace_begin,%(%else-then(%Namespace_begin%,%(%namespace_begin%)%)%)%,%
%NAMESPACE_BEGIN,%(%else-then(%NAMESPACE_BEGIN%,%(%toupper(%Namespace_begin%)%)%)%)%,%
%namespace_begin,%(%else-then(%_Namespace_begin%,%(%tolower(%Namespace_begin%)%)%)%)%,%
%namespace_end,%(%else-then(%namespace_end%,%(%reverse-parse(%Namespace%,/,,,,%(} /// namespace %ns%
)%,ns)%)%)%)%,%
%Namespace_end,%(%else-then(%Namespace_end%,%(%namespace_end%)%)%)%,%
%NAMESPACE_END,%(%else-then(%NAMESPACE_END%,%(%toupper(%Namespace_end%)%)%)%)%,%
%namespace_end,%(%else-then(%_Namespace_end%,%(%tolower(%Namespace_end%)%)%)%)%,%
%ifndef_directory,%(%else-then(%ifndef_directory%,%(%Namespace%)%)%)%,%
%Ifndef_directory,%(%else-then(%Ifndef_directory%,%(%ifndef_directory%)%)%)%,%
%IFNDEF_DIRECTORY,%(%else-then(%IFNDEF_DIRECTORY%,%(%toupper(%Ifndef_directory%)%)%)%)%,%
%ifndef_directory,%(%else-then(%_Ifndef_directory%,%(%tolower(%Ifndef_directory%)%)%)%)%,%
%header,%(%else-then(%header%,%(%ifndef_directory%/%Name%.hpp)%)%)%,%
%Header,%(%else-then(%Header%,%(%header%)%)%)%,%
%HEADER,%(%else-then(%HEADER%,%(%toupper(%Header%)%)%)%)%,%
%header,%(%else-then(%_Header%,%(%tolower(%Header%)%)%)%)%,%
%%(%
%%include(%include_path%/nadir-file-hpp-cpp.t)%%
%%include(%include_path%/nadir-%Extension%.t)%%
%)%)%