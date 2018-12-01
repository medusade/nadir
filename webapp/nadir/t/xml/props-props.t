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
%#   File: props-props.t
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
%group,%(%else-then(%group%,%()%)%)%,%
%Group,%(%else-then(%Group%,%(%group%)%)%)%,%
%GROUP,%(%else-then(%GROUP%,%(%toupper(%Group%)%)%)%)%,%
%group,%(%else-then(%_Group%,%(%tolower(%Group%)%)%)%)%,%
%name,%(%else-then(%name%,%(Framework)%)%)%,%
%Name,%(%else-then(%Name%,%(%name%)%)%)%,%
%NAME,%(%else-then(%NAME%,%(%toupper(%Name%)%)%)%)%,%
%name,%(%else-then(%_Name%,%(%tolower(%Name%)%)%)%)%,%
%version,%(%else-then(%version%,%()%)%)%,%
%Version,%(%else-then(%Version%,%(%version%)%)%)%,%
%VERSION,%(%else-then(%VERSION%,%(%toupper(%Version%)%)%)%)%,%
%version,%(%else-then(%_Version%,%(%tolower(%Version%)%)%)%)%,%
%file,%(%else-then(%file%,%(%Name%)%)%)%,%
%File,%(%else-then(%File%,%(%file%)%)%)%,%
%FILE,%(%else-then(%FILE%,%(%toupper(%File%)%)%)%)%,%
%file,%(%else-then(%_File%,%(%tolower(%File%)%)%)%)%,%
%extension,%(%else-then(%fileextension(%File%)%,%(props)%)%)%,%
%Extension,%(%else-then(%Extension%,%(%extension%)%)%)%,%
%EXTENSION,%(%else-then(%EXTENSION%,%(%toupper(%Extension%)%)%)%)%,%
%extension,%(%else-then(%_Extension%,%(%tolower(%Extension%)%)%)%)%,%
%depends,%(%else-then(%depends%,%(Depends)%)%)%,%
%Depends,%(%else-then(%Depends%,%(%depends%)%)%)%,%
%DEPENDS,%(%else-then(%DEPENDS%,%(%toupper(%Depends%)%)%)%)%,%
%depends,%(%else-then(%_Depends%,%(%tolower(%Depends%)%)%)%)%,%
%%(%
%%include(%include_path%/file-xml.t)%%
%<Project
  ToolsVersion="4.0"
  xmlns="http://schemas.microsoft.com/developer/msbuild/2003">

  <!--===============================================-->

  <PropertyGroup Label="UserMacros">
      <%NAME%_GROUP>%if-then(%Group%,/)%</%NAME%_GROUP>
      <%NAME%_NAME>%Name%</%NAME%_NAME>
      <%NAME%_VERSION>%then-if(%Version%,-)%</%NAME%_VERSION>

      <%NAME%_DIR>$(%NAME%_GROUP)$(%NAME%_NAME)$(%NAME%_VERSION)</%NAME%_DIR>
      <%NAME%_SOURCE_DIR>$(SOURCE_ROOT_DIR)/$(%NAME%_DIR)/src</%NAME%_SOURCE_DIR>
      <%NAME%_BUILD_DIR>$(SOURCE_BUILD_DIR)/$(%NAME%_DIR)/build</%NAME%_BUILD_DIR>
      <%NAME%_BUILD>$(%NAME%_BUILD_DIR)/$(PlatformName)/$(VCVersion)/$(Configuration)</%NAME%_BUILD>
      <%NAME%_OBJ>$(%NAME%_BUILD)/obj/$(ProjectName)</%NAME%_OBJ>
      <%NAME%_LIB>$(%NAME%_BUILD)/lib</%NAME%_LIB>
      <%NAME%_BIN>$(%NAME%_BUILD)/bin</%NAME%_BIN>

      <%NAME%_DEFINES></%NAME%_DEFINES>
      <%NAME%_DEBUG_DEFINES>$(%NAME%_DEFINES);$(%DEPENDS%_DEBUG_DEFINES)</%NAME%_DEBUG_DEFINES>
      <%NAME%_RELEASE_DEFINES>$(%NAME%_DEFINES);$(%DEPENDS%_RELEASE_DEFINES)</%NAME%_RELEASE_DEFINES>
      <%NAME%_INCLUDE_DIRS>$(%NAME%_SOURCE_DIR)</%NAME%_INCLUDE_DIRS>
      <VC10_%NAME%_INCLUDE_DIRS>$(%NAME%_INCLUDE_DIRS);$(VC10_%DEPENDS%_INCLUDE_DIRS)</VC10_%NAME%_INCLUDE_DIRS>
      <VC14_%NAME%_INCLUDE_DIRS>$(%NAME%_INCLUDE_DIRS);$(VC14_%DEPENDS%_INCLUDE_DIRS)</VC14_%NAME%_INCLUDE_DIRS>
      <%NAME%_LIB_DIRS>$(%NAME%_LIB);$(%DEPENDS%_LIB_DIRS)</%NAME%_LIB_DIRS>
      <%NAME%_LIBS>lib%Name%.lib;$(%DEPENDS%_LIBS)</%NAME%_LIBS>
  </PropertyGroup>

  <!--===============================================-->

  <ItemGroup>
      <BuildMacro Include="%NAME%_GROUP">
          <Value>$(%NAME%_GROUP)</Value>
      </BuildMacro>
      <BuildMacro Include="%NAME%_NAME">
          <Value>$(%NAME%_NAME)</Value>
      </BuildMacro>
      <BuildMacro Include="%NAME%_VERSION">
          <Value>$(%NAME%_VERSION)</Value>
      </BuildMacro>
      
      <BuildMacro Include="%NAME%_DIR">
          <Value>$(%NAME%_DIR)</Value>
      </BuildMacro>
      <BuildMacro Include="%NAME%_SOURCE_DIR">
          <Value>$(%NAME%_SOURCE_DIR)</Value>
      </BuildMacro>
      <BuildMacro Include="%NAME%_BUILD_DIR">
          <Value>$(%NAME%_BUILD_DIR)</Value>
      </BuildMacro>
      <BuildMacro Include="%NAME%_BUILD">
          <Value>$(%NAME%_BUILD)</Value>
      </BuildMacro>
      <BuildMacro Include="%NAME%_OBJ">
          <Value>$(%NAME%_OBJ)</Value>
      </BuildMacro>
      <BuildMacro Include="%NAME%_LIB">
          <Value>$(%NAME%_LIB)</Value>
      </BuildMacro>
      <BuildMacro Include="%NAME%_BIN">
          <Value>$(%NAME%_BIN)</Value>
      </BuildMacro>
      
      <BuildMacro Include="%NAME%_DEFINES">
          <Value>$(%NAME%_DEFINES)</Value>
      </BuildMacro>
      <BuildMacro Include="%NAME%_DEBUG_DEFINES">
          <Value>$(%NAME%_DEBUG_DEFINES)</Value>
      </BuildMacro>
      <BuildMacro Include="%NAME%_RELEASE_DEFINES">
          <Value>$(%NAME%_RELEASE_DEFINES)</Value>
      </BuildMacro>
      <BuildMacro Include="%NAME%_INCLUDE_DIRS">
          <Value>$(%NAME%_INCLUDE_DIRS)</Value>
      </BuildMacro>
      <BuildMacro Include="VC10_%NAME%_INCLUDE_DIRS">
          <Value>$(VC10_%NAME%_INCLUDE_DIRS)</Value>
      </BuildMacro>
      <BuildMacro Include="VC14_%NAME%_INCLUDE_DIRS">
          <Value>$(VC14_%NAME%_INCLUDE_DIRS)</Value>
      </BuildMacro>
      <BuildMacro Include="%NAME%_LIB_DIRS">
          <Value>$(%NAME%_LIB_DIRS)</Value>
      </BuildMacro>
      <BuildMacro Include="%NAME%_LIBS">
          <Value>$(%NAME%_LIBS)</Value>
      </BuildMacro>
  </ItemGroup>

  <!--===============================================-->

</Project>
)%)%