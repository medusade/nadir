%########################################################################
%# Copyright (c) 1988-2016 $organization$
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
%#   File: signals-cxx.t
%#
%# Author: $author$
%#   Date: 3/14/2016
%########################################################################
%with(%
%file,%(%else-then(%file%,%(File)%)%)%,%
%File,%(%else-then(%File%,%(%file%)%)%)%,%
%FILE,%(%else-then(%FILE%,%(%toupper(%File%)%)%)%)%,%
%file,%(%else-then(%_File%,%(%tolower(%File%)%)%)%)%,%
%file_base,%(%else-then(%file_base%,%(%filebase(%File%)%)%)%)%,%
%File_base,%(%else-then(%File_base%,%(%file_base%)%)%)%,%
%FILE_BASE,%(%else-then(%FILE_BASE%,%(%toupper(%File_base%)%)%)%)%,%
%file_base,%(%else-then(%_File_base%,%(%tolower(%File_base%)%)%)%)%,%
%file_extension,%(%else-then(%file_extension%,%(%fileextension(%File%)%)%)%)%,%
%File_extension,%(%else-then(%File_extension%,%(%file_extension%)%)%)%,%
%FILE_EXTENSION,%(%else-then(%FILE_EXTENSION%,%(%toupper(%File_extension%)%)%)%)%,%
%file_extension,%(%else-then(%_File_extension%,%(%tolower(%File_extension%)%)%)%)%,%
%author,%(%else-then(%author%,%(Author)%)%)%,%
%Author,%(%else-then(%Author%,%(%author%)%)%)%,%
%AUTHOR,%(%else-then(%AUTHOR%,%(%toupper(%Author%)%)%)%)%,%
%author,%(%else-then(%_Author%,%(%tolower(%Author%)%)%)%)%,%
%organization,%(%else-then(%organization%,%(Organization)%)%)%,%
%Organization,%(%else-then(%Organization%,%(%organization%)%)%)%,%
%ORGANIZATION,%(%else-then(%ORGANIZATION%,%(%toupper(%Organization%)%)%)%)%,%
%organization,%(%else-then(%_Organization%,%(%tolower(%Organization%)%)%)%)%,%
%framework,%(%else-then(%framework%,%(Framework)%)%)%,%
%Framework,%(%else-then(%Framework%,%(%framework%)%)%)%,%
%FRAMEWORK,%(%else-then(%FRAMEWORK%,%(%toupper(%Framework%)%)%)%)%,%
%framework,%(%else-then(%_Framework%,%(%tolower(%Framework%)%)%)%)%,%
%namespace,%(%else-then(%namespace%,%(%framework%)%)%)%,%
%Namespace,%(%else-then(%Namespace%,%(%namespace%)%)%)%,%
%NAMESPACE,%(%else-then(%NAMESPACE%,%(%toupper(%Namespace%)%)%)%)%,%
%namespace,%(%else-then(%_Namespace%,%(%tolower(%Namespace%)%)%)%)%,%
%ifndef,%(%else-then(%ifndef%,%(%Namespace%)%)%)%,%
%Ifndef,%(%else-then(%Ifndef%,%(%ifndef%)%)%)%,%
%IFNDEF,%(%else-then(%IFNDEF%,%(%toupper(%Ifndef%)%)%)%)%,%
%ifndef,%(%else-then(%_Ifndef%,%(%tolower(%Ifndef%)%)%)%)%,%
%signals,%(%else-then(%signals%,%(Signals)%)%)%,%
%Signals,%(%else-then(%Signals%,%(%signals%)%)%)%,%
%SIGNALS,%(%else-then(%SIGNALS%,%(%toupper(%Signals%)%)%)%)%,%
%signals,%(%else-then(%_Signals%,%(%tolower(%Signals%)%)%)%)%,%
%signal,%(%else-then(%signal%,%(Signal)%)%)%,%
%Signal,%(%else-then(%Signal%,%(%signal%)%)%)%,%
%SIGNAL,%(%else-then(%SIGNAL%,%(%toupper(%Signal%)%)%)%)%,%
%signal,%(%else-then(%_Signal%,%(%tolower(%Signal%)%)%)%)%,%
%class,%(%else-then(%class%,%(Class)%)%)%,%
%Class,%(%else-then(%Class%,%(%class%)%)%)%,%
%CLASS,%(%else-then(%CLASS%,%(%toupper(%Class%)%)%)%)%,%
%class,%(%else-then(%_Class%,%(%tolower(%Class%)%)%)%)%,%
%implements,%(%else-then(%implements%,%(Implements)%)%)%,%
%Implements,%(%else-then(%Implements%,%(%implements%)%)%)%,%
%IMPLEMENTS,%(%else-then(%IMPLEMENTS%,%(%toupper(%Implements%)%)%)%)%,%
%implements,%(%else-then(%_Implements%,%(%tolower(%Implements%)%)%)%)%,%
%extends,%(%else-then(%extends%,%(Extends)%)%)%,%
%Extends,%(%else-then(%Extends%,%(%extends%)%)%)%,%
%EXTENDS,%(%else-then(%EXTENDS%,%(%toupper(%Extends%)%)%)%)%,%
%extends,%(%else-then(%_Extends%,%(%tolower(%Extends%)%)%)%)%,%
%on,%(%else-then(%on%,%(on_%Class%_)%)%)%,%
%On,%(%else-then(%On%,%(%on%)%)%)%,%
%ON,%(%else-then(%ON%,%(%toupper(%On%)%)%)%)%,%
%on,%(%else-then(%_On%,%(%tolower(%On%)%)%)%)%,%
%parameters,%(%else-then(%parameters%,%(Parameters)%)%)%,%
%Parameters,%(%else-then(%Parameters%,%(%parameters%)%)%)%,%
%PARAMETERS,%(%else-then(%PARAMETERS%,%(%toupper(%Parameters%)%)%)%)%,%
%parameters,%(%else-then(%_Parameters%,%(%tolower(%Parameters%)%)%)%)%,%
%arguments,%(%else-then(%arguments%,%(%parse(%Parameters%,;,,%(;)%,,%(%right(%Parameter%, )%)%,Parameter)%)%)%)%,%
%Arguments,%(%else-then(%Arguments%,%(%arguments%)%)%)%,%
%_Arguments_,%(%else-then(%_Arguments_%,%(%parse(%Arguments%,;,,%( << "," << )% )%)%)%)%,%
%Arguments,%(%else-then(%Arguments_%,%(%parse(%Arguments%,;,,%(,)% )%)%)%)%,%
%ARGUMENTS,%(%else-then(%ARGUMENTS%,%(%toupper(%Arguments%)%)%)%)%,%
%arguments,%(%else-then(%_Arguments%,%(%tolower(%Arguments%)%)%)%)%,%
%return,%(%else-then(%return%,%(void)%)%)%,%
%Return,%(%else-then(%Return%,%(%return%)%)%)%,%
%RETURN,%(%else-then(%RETURN%,%(%toupper(%Return%)%)%)%)%,%
%return,%(%else-then(%_Return%,%(%tolower(%Return%)%)%)%)%,%
%forward_signals_to,%(%else-then(%forward_signals_to%,%(forward_%Class%_to)%)%)%,%
%Forward_signals_to,%(%else-then(%Forward_signals_to%,%(%forward_signals_to%)%)%)%,%
%FORWARD_SIGNALS_TO,%(%else-then(%FORWARD_SIGNALS_TO%,%(%toupper(%Forward_signals_to%)%)%)%)%,%
%forward_signals_to,%(%else-then(%_Forward_signals_to%,%(%tolower(%Forward_signals_to%)%)%)%)%,%
%signals_forward_to,%(%else-then(%signals_forward_to%,%(%Class%_forward_to)%)%)%,%
%Signals_forward_to,%(%else-then(%Signals_forward_to%,%(%signals_forward_to%)%)%)%,%
%SIGNALS_FORWARD_TO,%(%else-then(%SIGNALS_FORWARD_TO%,%(%toupper(%Signals_forward_to%)%)%)%)%,%
%signals_forward_to,%(%else-then(%_Signals_forward_to%,%(%tolower(%Signals_forward_to%)%)%)%)%,%
%%(%
%%if(%File%,%(///////////////////////////////////////////////////////////////////////
/// Copyright (c) 1988-%year()% %Organization%
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
///   File: %File%
///
/// Author: %Author%
///   Date: %date()%
///////////////////////////////////////////////////////////////////////)%)%
%if(%IFNDEF%,%(#if !defined(%parse(%IFNDEF%,/,,,,%(_%IFNDEF%)%,IFNDEF)%_%FILE_BASE%_%FILE_EXTENSION%)
)%)%
%parse(%Namespace%,/,,,,%(namespace %Namespace% {
)%,Namespace)%
typedef %do(%Class_implements%)% %do(%Class%_implements)%;
///////////////////////////////////////////////////////////////////////
///  Class: %do(%Class%)%
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS %do(%Class%)%: virtual public %do(%Class%_implements)% {
public:
    typedef %do(%Class%_implements)% Implements;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
%parse(%Signals%,;,,%(
)%,,%(%
%    virtual %else-then(%left(%Return%, )%,void)% %do(%On%)%%Signal%(%parse(%Parameters%,;,,%(,)% )%) {
        %do(%Class%)%* forward_to = %do(%Signals_forward_to%)%();
        %FRAMEWORK%_LOG_MESSAGE_DEBUG("%do(%On%)%%Signal%(" << %_Arguments_% << ")...");
        if ((forward_to)) {
            %if(%right(%Return%, )%,return )%forward_to->%do(%On%)%%Signal%(%Arguments%);
        }
        %FRAMEWORK%_LOG_MESSAGE_DEBUG("...%do(%On%)%%Signal%(" << %_Arguments_% << ")");%
%%then-if(%if-then(%right(%Return%, )%,;)%,
        return )%
    }%
%)%,Signal)%

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual %do(%Class%)%* %do(%Forward_signals_to%)%(%do(%Class%)%* to) {
        return 0;
    }
    virtual %do(%Class%)%* %do(%Signals_forward_to%)%() const {
        return 0;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};

%reverse-parse(%Namespace%,/,,,,%(} //namespace %Namespace%
)%,Namespace)%
%if(%IFNDEF%,%(#endif // !defined(%parse(%IFNDEF%,/,,,,%(_%IFNDEF%)%,IFNDEF)%_%FILE_BASE%_%FILE_EXTENSION%))%)%
%
%)%)%