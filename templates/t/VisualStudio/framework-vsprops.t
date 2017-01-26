%########################################################################
%# Copyright (c) 1988-2017 $organization$
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
%#   File: framework-vsprops.t
%#
%# Author: $author$
%#   Date: 1/20/2017
%########################################################################
%with(%
%group,%(%else-then(%group%,%(Group)%)%)%,%
%Group,%(%else-then(%Group%,%(%group%)%)%)%,%
%GROUP,%(%else-then(%GROUP%,%(%toupper(%Group%)%)%)%)%,%
%group,%(%else-then(%_Group%,%(%tolower(%Group%)%)%)%)%,%
%framework,%(%else-then(%framework%,%(Framework)%)%)%,%
%Framework,%(%else-then(%Framework%,%(%framework%)%)%)%,%
%FRAMEWORK,%(%else-then(%FRAMEWORK%,%(%toupper(%Framework%)%)%)%)%,%
%framework,%(%else-then(%_Framework%,%(%tolower(%Framework%)%)%)%)%,%
%version,%(%else-then(%version%,%(Version)%)%)%,%
%Version,%(%else-then(%Version%,%(%version%)%)%)%,%
%VERSION,%(%else-then(%VERSION%,%(%toupper(%Version%)%)%)%)%,%
%version,%(%else-then(%_Version%,%(%tolower(%Version%)%)%)%)%,%
%%(%
%<?xml version="1.0" encoding="Windows-1252"?>
<!--========================================================================-->
<!-- Copyright (c) 1988-%year()% $organization$                             -->
<!--                                                                        -->
<!-- This software is provided by the author and contributors ``as is''     -->
<!-- and any express or implied warranties, including, but not limited to,  -->
<!-- the implied warranties of merchantability and fitness for a particular -->
<!-- purpose are disclaimed. In no event shall the author or contributors   -->
<!-- be liable for any direct, indirect, incidental, special, exemplary,    -->
<!-- or consequential damages (including, but not limited to, procurement   -->
<!-- of substitute goods or services; loss of use, data, or profits; or     -->
<!-- business interruption) however caused and on any theory of liability,  -->
<!-- whether in contract, strict liability, or tort (including negligence   -->
<!-- or otherwise) arising in any way out of the use of this software,      -->
<!-- even if advised of the possibility of such damage.                     -->
<!--                                                                        -->
<!--   File: %Framework%.vsprops                                            -->
<!--                                                                        -->
<!-- Author: $author$                                                       -->
<!--   Date: %date()%                                                       -->
<!--========================================================================-->
<VisualStudioPropertySheet
    ProjectType="Visual C++"
    Version="8.00"
    Name="%Framework%">

    <!--===============================================-->

    <UserMacro
        Name="%FRAMEWORK%_GROUP"
        Value=""
    />
    <UserMacro
        Name="%FRAMEWORK%_NAME"
        Value="%Framework%"
    />
    <UserMacro
        Name="%FRAMEWORK%_VERSION"
        Value=""
    />
    <UserMacro
        Name="%FRAMEWORK%_DIR"
        Value="$(%FRAMEWORK%_GROUP)$(%FRAMEWORK%_NAME)$(%FRAMEWORK%_VERSION)"
    />
    <UserMacro
        Name="%FRAMEWORK%_SOURCE_DIR"
        Value="$(SOURCE_ROOT_DIR)/$(%FRAMEWORK%_DIR)/src"
    />
    <UserMacro
        Name="%FRAMEWORK%_BUILD_DIR"
        Value="$(SOURCE_BUILD_DIR)/$(%FRAMEWORK%_DIR)/build"
    />

    <!--===============================================-->

    <UserMacro
        Name="%FRAMEWORK%_BUILD"
        Value="$(%FRAMEWORK%_BUILD_DIR)/$(PlatformName)/$(VCVersion)/$(ConfigurationName)"
    />
    <UserMacro
        Name="%FRAMEWORK%_OBJ"
        Value="$(%FRAMEWORK%_BUILD)/obj/$(ProjectName)"
    />
    <UserMacro
        Name="%FRAMEWORK%_LIB"
        Value="$(%FRAMEWORK%_BUILD)/lib"
    />
    <UserMacro
        Name="%FRAMEWORK%_BIN"
        Value="$(%FRAMEWORK%_BUILD)/bin"
    />

  <!--===============================================-->

    <UserMacro
        Name="%FRAMEWORK%_DEFINES"
        Value="$(NADIR_DEFINES)"
    />
    <UserMacro
      Name="XOS%FRAMEWORK%_DEFINES"
      Value="$(XOSNADIR_DEFINES)"
    />

    <UserMacro
        Name="%FRAMEWORK%_INCLUDE_DIRS"
        Value="$(%FRAMEWORK%_SOURCE_DIR);$(NADIR_INCLUDE_DIRS)"
    />
    <UserMacro
        Name="%FRAMEWORK%_LIB_DIRS"
        Value="$(%FRAMEWORK%_LIB);$(NADIR_LIB_DIRS)"
    />

    <UserMacro
        Name="%FRAMEWORK%_LIBS"
        Value="lib%Framework%.lib $(NADIR_LIBS)"
    />
    <UserMacro
      Name="XOS%FRAMEWORK%_LIBS"
      Value="libxos%Framework%.lib $(XOSNADIR_LIBS)"
    />

  <!--===============================================-->

</VisualStudioPropertySheet>
%
%)%)%