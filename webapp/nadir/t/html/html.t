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
%#   File: html.t
%#
%# Author: $author$
%#   Date: 11/23/2018
%########################################################################
%with(%
%include_path,%(%else-then(%include_path%,%(%filepath(%input%)%)%)%)%,%
%framework,%(%else-then(%framework%,%(Nadir)%)%)%,%
%Framework,%(%else-then(%Framework%,%(%framework%)%)%)%,%
%FRAMEWORK,%(%else-then(%FRAMEWORK%,%(%toupper(%Framework%)%)%)%)%,%
%framework,%(%else-then(%_Framework%,%(%tolower(%Framework%)%)%)%)%,%
%title,%(%else-then(%title%,%(Create HTML File)%)%)%,%
%Title,%(%else-then(%Title%,%(%title%)%)%)%,%
%TITLE,%(%else-then(%TITLE%,%(%toupper(%Title%)%)%)%)%,%
%title,%(%else-then(%_Title%,%(%tolower(%Title%)%)%)%)%,%
%styletype,%(%else-then(%styletype%,%(text/css)%)%)%,%
%StyleType,%(%else-then(%StyleType%,%(%styletype%)%)%)%,%
%STYLETYPE,%(%else-then(%STYLETYPE%,%(%toupper(%StyleType%)%)%)%)%,%
%styletype,%(%else-then(%_StyleType%,%(%tolower(%StyleType%)%)%)%)%,%
%stylehref,%(%else-then(%stylehref%,%(../css/html-form-css.t)%)%)%,%
%StyleHref,%(%else-then(%StyleHref%,%(%stylehref%)%)%)%,%
%STYLEHREF,%(%else-then(%STYLEHREF%,%(%toupper(%StyleHref%)%)%)%)%,%
%stylehref,%(%else-then(%_StyleHref%,%(%tolower(%StyleHref%)%)%)%)%,%
%scripttype,%(%else-then(%scripttype%,%(text/javascript)%)%)%,%
%ScriptType,%(%else-then(%ScriptType%,%(%scripttype%)%)%)%,%
%SCRIPTTYPE,%(%else-then(%SCRIPTTYPE%,%(%toupper(%ScriptType%)%)%)%)%,%
%scripttype,%(%else-then(%_ScriptType%,%(%tolower(%ScriptType%)%)%)%)%,%
%scriptsrc,%(%else-then(%scriptsrc%,%(../js/html-form-js.t)%)%)%,%
%ScriptSrc,%(%else-then(%ScriptSrc%,%(%scriptsrc%)%)%)%,%
%SCRIPTSRC,%(%else-then(%SCRIPTSRC%,%(%toupper(%ScriptSrc%)%)%)%)%,%
%scriptsrc,%(%else-then(%_ScriptSrc%,%(%tolower(%ScriptSrc%)%)%)%)%,%
%%(%
%%include(%include_path%/file-html.t)%%
%<html>
    <!--========================================================================-->
    <!-- head                                                                   -->
    <!--========================================================================-->
    <head>
        <title>%if-then(%Framework%, - )%%Title%</title>
    
        <!--========================================================================-->
        <!-- style                                                                  -->
        <!--========================================================================-->
        <link rel="stylesheet" type="%StyleType%" href="%StyleHref%"></link>
        <style type="%StyleType%">
        </style>
    
        <!--========================================================================-->
        <!-- script                                                                 -->
        <!--========================================================================-->
        <script type="%ScriptType%" src="%ScriptSrc%"></script>
        <script type="%ScriptType%">
        </script>
    </head>
    
    <!--========================================================================-->
    <!-- body                                                                   -->
    <!--========================================================================-->
    <body>%if(%Title%,%(%(
        )%<a href="%File%"><h3>%Title%</h3></a>
)%)%
%include(%include_path%/form-html.t)%    </body>
</html>
%
%)%)%