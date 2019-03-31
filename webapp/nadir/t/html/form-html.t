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
%#   File: form-html.t
%#
%# Author: $author$
%#   Date: 11/23/2018
%########################################################################
%with(%
%include_path,%(%else-then(%include_path%,%(%filepath(%input%)%)%)%)%,%
%accept-charset,%(%else-then(%accept-charset%,%(UTF-8)%)%)%,%
%Accept-charset,%(%else-then(%Accept-charset%,%(%accept-charset%)%)%)%,%
%ACCEPT-CHARSET,%(%else-then(%ACCEPT-CHARSET%,%(%toupper(%Accept-charset%)%)%)%)%,%
%accept-charset,%(%else-then(%_Accept-charset%,%(%tolower(%Accept-charset%)%)%)%)%,%
%action,%(%else-then(%action%,%(html.t)%)%)%,%
%Action,%(%else-then(%Action%,%(%action%)%)%)%,%
%ACTION,%(%else-then(%ACTION%,%(%toupper(%Action%)%)%)%)%,%
%action,%(%else-then(%_Action%,%(%tolower(%Action%)%)%)%)%,%
%enctype,%(%else-then(%enctype%,%(application/x-www-form-urlencoded)%)%)%,%
%Enctype,%(%else-then(%Enctype%,%(%enctype%)%)%)%,%
%ENCTYPE,%(%else-then(%ENCTYPE%,%(%toupper(%Enctype%)%)%)%)%,%
%enctype,%(%else-then(%_Enctype%,%(%tolower(%Enctype%)%)%)%)%,%
%method,%(%else-then(%method%,%(POST)%)%)%,%
%Method,%(%else-then(%Method%,%(%method%)%)%)%,%
%METHOD,%(%else-then(%METHOD%,%(%toupper(%Method%)%)%)%)%,%
%method,%(%else-then(%_Method%,%(%tolower(%Method%)%)%)%)%,%
%name,%(%else-then(%name%,%(Form)%)%)%,%
%Name,%(%else-then(%Name%,%(%name%)%)%)%,%
%NAME,%(%else-then(%NAME%,%(%toupper(%Name%)%)%)%)%,%
%name,%(%else-then(%_Name%,%(%tolower(%Name%)%)%)%)%,%
%target,%(%else-then(%target%,%()%)%)%,%
%Target,%(%else-then(%Target%,%(%target%)%)%)%,%
%TARGET,%(%else-then(%TARGET%,%(%toupper(%Target%)%)%)%)%,%
%target,%(%else-then(%_Target%,%(%tolower(%Target%)%)%)%)%,%
%onsubmit,%(%else-then(%onsubmit%,%(return setFormSubmit(getFormValue('%Name%Action','%Name%'),getFormValue('%Name%Method','%Name%'),'%Name%');)%)%)%,%
%OnSubmit,%(%else-then(%OnSubmit%,%(%onsubmit%)%)%)%,%
%ONSUBMIT,%(%else-then(%ONSUBMIT%,%(%toupper(%OnSubmit%)%)%)%)%,%
%onsubmit,%(%else-then(%_OnSubmit%,%(%tolower(%OnSubmit%)%)%)%)%,%
%attributes,%(%else-then(%attributes%,%(Name;Target;Action;Method;Enctype;Accept-charset;Accept)%)%)%,%
%Attributes,%(%else-then(%Attributes%,%(%attributes%)%)%)%,%
%ATTRIBUTES,%(%else-then(%ATTRIBUTES%,%(%toupper(%Attributes%)%)%)%)%,%
%attributes,%(%else-then(%_Attributes%,%(%tolower(%Attributes%)%)%)%)%,%
%v5attributes,%(%else-then(%v5attributes%,%(Autocomplete;Novalidate)%)%)%,%
%V5Attributes,%(%else-then(%V5Attributes%,%(%v5attributes%)%)%)%,%
%V5ATTRIBUTES,%(%else-then(%V5ATTRIBUTES%,%(%toupper(%V5Attributes%)%)%)%)%,%
%v5attributes,%(%else-then(%_V5Attributes%,%(%tolower(%V5Attributes%)%)%)%)%,%
%fields,%(%else-then(%fields%,%(%Attributes%;%V5Attributes%;Fields;OnSubmit)%)%)%,%
%Fields,%(%else-then(%Fields%,%(%fields%)%)%)%,%
%FIELDS,%(%else-then(%FIELDS%,%(%toupper(%Fields%)%)%)%)%,%
%fields,%(%else-then(%_Fields%,%(%tolower(%Fields%)%)%)%)%,%
%submit,%(%else-then(%submit%,%(Submit)%)%)%,%
%Submit,%(%else-then(%Submit%,%(%submit%)%)%)%,%
%SUBMIT,%(%else-then(%SUBMIT%,%(%toupper(%Submit%)%)%)%)%,%
%submit,%(%else-then(%_Submit%,%(%tolower(%Submit%)%)%)%)%,%
%%(%
%        <!--========================================================================-->
        <!-- form                                                                   -->
        <!--========================================================================-->
        <form%parse(%Attributes%;%V5Attributes%;OnSubmit,;,,,,%(%if(%do(%%%Attribute%%%)%,%(%(
         )%%Attribute%="%do(%%%Attribute%%%)%")%)%)%,Attribute)%>
            <div class="form"><hr/>
%
%%parse(%Fields%,;,%(
)%,,,%(%
%%with(%
%FieldName,%(%else-then(%left(%Field%,=)%,%(%Field%)%)%)%,%
%FieldValue,%(%else-then(%right(%Field%,=)%,%(%do(%%%Field%%%)%)%)%)%,%
%%(%
%%if-no(%do(%%is_%FieldName%%%)%,,%(%
%%(            )%%FieldName%: <input name="%FieldName%" value="%FieldValue%"></input>
                  <input type="checkbox" name="is_%FieldName%" value="no" unchecked="checked">no</input><br/>%
%)%)%%
%)%)%%
%)%,Field)%%
%%if(%Fields%,%(<br/>
)%)%%
%%if(%Action%%Method%content_type,%(
)%)%%
%%if(%Action%,%(%( 
            )%action = <select name="%Name%Action">
            <option value="%Action%">%Action%</option>
            <option value="/coral-cgi/cgi">/coral-cgi/cgi</option>
            <option value="/xde-cgi/cgi">/xde-cgi/cgi</option>
            <option value=""></option>
            </select><br/>)%)%%
%%if(%Method%,%(%( 
            )%method = <select name="%Name%Method">
            <option value="POST">POST</option>
            <option value="GET">GET</option>
            <option value=""></option>
            </select><br/>)%)%%
%%if(content_type,%(%(
            )%content_type = <select name="content_type">
            <option value="text/plain">text</option>
            <option value="text/html">html</option>
            <option value="text/xml">xml</option>
            <option value=""></option>
            </select><br/>)%)%%
%%if(%Action%%Method%content_type,%(

)%)%%
%            <hr/></div>%if(%Submit%,%(%(
            )%<table cellpadding="0" cellspacing="0" border="0">
            <tr>
            <td><input type="submit" name="%Submit%" value="%do(%%%Submit%%%)%"/></td>
            <td><table cellpadding="0" cellspacing="10" border="0">
                <tr>
                <td><a href="../cpp/nadir-hpp-cpp.html">Create C/C++ File</a></td>
                <td><a href="../xml/vsprops.html">Create VisualStudio props File</a></td>
                <td><a href="../t/t-t.html">Create T File</a></td>
                <td><a href="../..">/nadir/</a></td>
                </tr>
            </table></td>
            </tr>
        </table>)%)%
        </form>
)%)%