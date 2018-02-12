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
%#   File: xos-nadir-exception-hpp-cpp.t
%#
%# Author: $author$
%#   Date: 2/12/2018
%########################################################################
%with(%
%includepath,%(%else-then(%includepath%,%(%filepath(%input%)%)%)%)%,%
%IncludePath,%(%else-then(%IncludePath%,%(%includepath%)%)%)%,%
%INCLUDEPATH,%(%else-then(%INCLUDEPATH%,%(%toupper(%IncludePath%)%)%)%)%,%
%includepath,%(%else-then(%_IncludePath%,%(%tolower(%IncludePath%)%)%)%)%,%
%class,%(%else-then(%class%,%(these)%)%)%,%
%Class,%(%else-then(%Class%,%(%class%)%)%)%,%
%CLASS,%(%else-then(%CLASS%,%(%toupper(%Class%)%)%)%)%,%
%class,%(%else-then(%_Class%,%(%tolower(%Class%)%)%)%)%,%
%do,%(%else-then(%do%,%(%Class%)%)%)%,%
%Do,%(%else-then(%Do%,%(%do%)%)%)%,%
%DO,%(%else-then(%DO%,%(%toupper(%Do%)%)%)%)%,%
%do,%(%else-then(%_Do%,%(%tolower(%Do%)%)%)%)%,%
%undo,%(%else-then(%undo%,%(un%Do%)%)%)%,%
%Undo,%(%else-then(%Undo%,%(%undo%)%)%)%,%
%UNDO,%(%else-then(%UNDO%,%(%toupper(%Undo%)%)%)%)%,%
%undo,%(%else-then(%_Undo%,%(%tolower(%Undo%)%)%)%)%,%
%filetype,%(%else-then(%filetype%,%(hpp)%)%)%,%
%FileType,%(%else-then(%FileType%,%(%filetype%)%)%)%,%
%FILETYPE,%(%else-then(%FILETYPE%,%(%toupper(%FileType%)%)%)%)%,%
%filetype,%(%else-then(%_FileType%,%(%tolower(%FileType%)%)%)%)%,%
%file,%(%else-then(%file%,%(%Class%_exception.%FileType%)%)%)%,%
%File,%(%else-then(%File%,%(%file%)%)%)%,%
%extension,%(%else-then(%extension%,%(%else-then(%fileextension(%File%)%,%(%FileType%)%)%)%)%)%,%
%Extension,%(%else-then(%Extension%,%(%extension%)%)%)%,%
%EXTENSION,%(%else-then(%EXTENSION%,%(%toupper(%Extension%)%)%)%)%,%
%extension,%(%else-then(%_Extension%,%(%tolower(%Extension%)%)%)%)%,%
%File,%(%filebase(%File%)%)%,%
%FILE,%(%else-then(%FILE%,%(%toupper(%File%)%)%)%)%,%
%file,%(%else-then(%_File%,%(%tolower(%File%)%)%)%)%,%
%%(%
%///////////////////////////////////////////////////////////////////////
/// Copyright (c) 1988-%year()% $organization$
///
/// This software is provided by the author and contributors ``as is'' 
/// and any express or implied warranties, including, but not limited to, 
/// the implied warranties of merchantability and fitness for a particular 
/// purpose are disclaimed. In no event shall the author or contributors 
/// be liable for any direct, indirect, incidental, special, exemplary, 
/// or consequential damages (including, but not limited to, procurement 
/// of substitute goods or services; loss of use, data, or profits; or 
/// business interruption) however caused and on any theory of liability, 
/// whether in contract, strict liability, or tort (including negligence 
/// or otherwise) arising in any way out of the use of this software, 
/// even if advised of the possibility of such damage.
///
///   File: %File%.%Extension%
///
/// Author: $author$
///   Date: %date()%
///////////////////////////////////////////////////////////////////////
%
%%include(%IncludePath%/xos-nadir-exception-%FileType%.t)%%
%)%)%