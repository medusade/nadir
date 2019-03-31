%########################################################################
%# Copyright (c) 1988-2019 $organization$
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
%#   File: nadir-class-hpp.t
%#
%# Author: $author$
%#   Date: 3/13/2019
%########################################################################
%with(%
%include_path,%(%else-then(%include_path%,%(%filepath(%input%)%)%)%)%,%
%implements,%(%else-then(%implements%,%(%if-no(%is_implements%,,::%Nadir%::implement_base)%)%)%)%,%
%Implements,%(%else-then(%Implements%,%(%implements%)%)%)%,%
%IMPLEMENTS,%(%else-then(%IMPLEMENTS%,%(%toupper(%Implements%)%)%)%)%,%
%implements,%(%else-then(%_Implements%,%(%tolower(%Implements%)%)%)%)%,%
%extends,%(%else-then(%extends%,%(%if-no(%is_extends%,,::%Nadir%::base)%)%)%)%,%
%Extends,%(%else-then(%Extends%,%(%extends%)%)%)%,%
%EXTENDS,%(%else-then(%EXTENDS%,%(%toupper(%Extends%)%)%)%)%,%
%extends,%(%else-then(%_Extends%,%(%tolower(%Extends%)%)%)%)%,%
%implementst,%(%else-then(%implementst%,%(ImplementsT)%)%)%,%
%ImplementsT,%(%else-then(%ImplementsT%,%(%implementst%)%)%)%,%
%IMPLEMENTST,%(%else-then(%IMPLEMENTST%,%(%toupper(%ImplementsT%)%)%)%)%,%
%implementst,%(%else-then(%_ImplementsT%,%(%tolower(%ImplementsT%)%)%)%)%,%
%extendst,%(%else-then(%extendst%,%(ExtendsT)%)%)%,%
%ExtendsT,%(%else-then(%ExtendsT%,%(%extendst%)%)%)%,%
%EXTENDST,%(%else-then(%EXTENDST%,%(%toupper(%ExtendsT%)%)%)%)%,%
%extendst,%(%else-then(%_ExtendsT%,%(%tolower(%ExtendsT%)%)%)%)%,%
%timplements,%(%else-then(%timplements%,%(%if-no(%is_template%,%NameT%_implements,TImplements)%)%)%)%,%
%TImplements,%(%else-then(%TImplements%,%(%timplements%)%)%)%,%
%TIMPLEMENTS,%(%else-then(%TIMPLEMENTS%,%(%toupper(%TImplements%)%)%)%)%,%
%timplements,%(%else-then(%_TImplements%,%(%tolower(%TImplements%)%)%)%)%,%
%textends,%(%else-then(%textends%,%(%if-no(%is_template%,%NameT%_extends,TExtends)%)%)%)%,%
%TExtends,%(%else-then(%TExtends%,%(%textends%)%)%)%,%
%TEXTENDS,%(%else-then(%TEXTENDS%,%(%toupper(%TExtends%)%)%)%)%,%
%textends,%(%else-then(%_TExtends%,%(%tolower(%TExtends%)%)%)%)%,%
%%(%
%
%if-no(%is_name%,,%(%if(%Implements%,%(typedef %Implements% %NameT%_implements;
)%)%%if(%Extends%,%(typedef %Extends% %NameT%_extends;
)%)%///////////////////////////////////////////////////////////////////////
///  Class: %NameT%
///////////////////////////////////////////////////////////////////////
%if-no(%is_template%,,%(template <class TImplements = %NameT%_implements, class TExtends = %NameT%_extends>
)%)%class _EXPORT_CLASS %NameT%%if(%Implements%%Extends%,: )%%if(%Implements%,virtual public %TImplements%)%%if(%and(%Implements%,%Extends%)%,%(, )%)%%if(%Extends%,public %TExtends%)% {
public:
    %if(%Implements%,typedef %TImplements% Implements;
    )%%if(%Extends%,typedef %TExtends% Extends;
    )%typedef %NameT% Derives;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    %NameT%(const %NameT%& copy) {
    }
    %NameT%() {
    }
    virtual ~%NameT%() {
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
}; /// class _EXPORT_CLASS %NameT%
)%)%%
%)%)%