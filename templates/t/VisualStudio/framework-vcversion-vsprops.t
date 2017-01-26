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
%#   File: framework-vcversion-vsprops.t
%#
%# Author: $author$
%#   Date: 1/22/2017
%########################################################################
%with(%
%group,%(%else-then(%group%,%()%)%)%,%
%Group,%(%else-then(%Group%,%(%group%)%)%)%,%
%GROUP,%(%else-then(%GROUP%,%(%toupper(%Group%)%)%)%)%,%
%group,%(%else-then(%_Group%,%(%tolower(%Group%)%)%)%)%,%
%framework,%(%else-then(%framework%,%()%)%)%,%
%Framework,%(%else-then(%Framework%,%(%framework%)%)%)%,%
%FRAMEWORK,%(%else-then(%FRAMEWORK%,%(%toupper(%Framework%)%)%)%)%,%
%framework,%(%else-then(%_Framework%,%(%tolower(%Framework%)%)%)%)%,%
%version,%(%else-then(%version%,%()%)%)%,%
%Version,%(%else-then(%Version%,%(%version%)%)%)%,%
%VERSION,%(%else-then(%VERSION%,%(%toupper(%Version%)%)%)%)%,%
%version,%(%else-then(%_Version%,%(%tolower(%Version%)%)%)%)%,%
%%(%
%<?xml version="1.0" encoding="Windows-1252"?>
<!--========================================================================-->
<!-- Copyright (c) 1988-%year()% $organization$                                 -->
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
<!--   File: %if-then(%Framework%,-)%vcversion.vsprops                                       -->
<!--                                                                        -->
<!-- Author: $author$                                                       -->
<!--   Date: %date()%                                                      -->
<!--========================================================================-->
<VisualStudioPropertySheet
    ProjectType="Visual C++"
    Version="8.00"
    Name="%if-then(%Framework%,-)%vcversion">

  <!--===============================================-->

    <UserMacro
      Name="SOURCE_ROOT_DIR"
      Value="../../../../../.."
    />

    <UserMacro
      Name="SOURCE_BUILD_DIR"
      Value="$(SOURCE_ROOT_DIR)"
    />

  <!--===============================================-->

    <UserMacro
        Name="VCVersion"
        Value="vc9"
    />

    <!--===============================================-->

</VisualStudioPropertySheet>
%
%)%)%        
