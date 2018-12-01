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
%#   File: vcversion-props.t
%#
%# Author: $author$
%#   Date: 11/26/2018
%########################################################################
%with(%
%include_path,%(%else-then(%include_path%,%(%filepath(%input%)%)%)%)%,%
%xmlencoding,%(%else-then(%xmlencoding%,%(Windows-1252)%)%)%,%
%XmlEncoding,%(%else-then(%XmlEncoding%,%(%xmlencoding%)%)%)%,%
%XMLENCODING,%(%else-then(%XMLENCODING%,%(%toupper(%XmlEncoding%)%)%)%)%,%
%xmlencoding,%(%else-then(%_XmlEncoding%,%(%tolower(%XmlEncoding%)%)%)%)%,%
%vcversion,%(%else-then(%vcversion%,%(vc10)%)%)%,%
%VCVersion,%(%else-then(%VCVersion%,%(%vcversion%)%)%)%,%
%VCVERSION,%(%else-then(%VCVERSION%,%(%toupper(%VCVersion%)%)%)%)%,%
%vcversion,%(%else-then(%_VCVersion%,%(%tolower(%VCVersion%)%)%)%)%,%
%file,%(%else-then(%file%,%(vcversion)%)%)%,%
%File,%(%else-then(%File%,%(%file%)%)%)%,%
%FILE,%(%else-then(%FILE%,%(%toupper(%File%)%)%)%)%,%
%file,%(%else-then(%_File%,%(%tolower(%File%)%)%)%)%,%
%base,%(%else-then(%filebase(%File%)%,%(%File%)%)%)%,%
%Base,%(%else-then(%Base%,%(%base%)%)%)%,%
%BASE,%(%else-then(%BASE%,%(%toupper(%Base%)%)%)%)%,%
%base,%(%else-then(%_Base%,%(%tolower(%Base%)%)%)%)%,%
%extension,%(%else-then(%fileextension(%File%)%,%(props)%)%)%,%
%Extension,%(%else-then(%Extension%,%(%extension%)%)%)%,%
%EXTENSION,%(%else-then(%EXTENSION%,%(%toupper(%Extension%)%)%)%)%,%
%extension,%(%else-then(%_Extension%,%(%tolower(%Extension%)%)%)%)%,%
%%(%
%%include(%include_path%/file-xml.t)%%
%<Project
  ToolsVersion="4.0"
  xmlns="http://schemas.microsoft.com/developer/msbuild/2003">

  <!--===============================================-->

  <PropertyGroup Label="UserMacros">
      <VCVersion>%VCVersion%</VCVersion>
  </PropertyGroup>

  <!--===============================================-->

  <ItemGroup>
      <BuildMacro Include="VCVersion">
          <Value>$(VCVersion)</Value>
      </BuildMacro>
  </ItemGroup>

  <!--===============================================-->

</Project>)%)%