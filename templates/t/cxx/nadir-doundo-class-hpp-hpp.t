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
%#   File: nadir-doundo-class-hpp-hpp.t
%#
%# Author: $author$
%#   Date: 6/14/2017
%########################################################################
%with(%
%do,%(%else-then(%do%,%(Do)%)%)%,%
%Do,%(%else-then(%Do%,%(%do%)%)%)%,%
%DO,%(%else-then(%DO%,%(%toupper(%Do%)%)%)%)%,%
%do,%(%else-then(%_Do%,%(%tolower(%Do%)%)%)%)%,%
%undo,%(%else-then(%undo%,%(Un%Do%)%)%)%,%
%Undo,%(%else-then(%Undo%,%(%undo%)%)%)%,%
%UNDO,%(%else-then(%UNDO%,%(%toupper(%Undo%)%)%)%)%,%
%undo,%(%else-then(%_Undo%,%(%tolower(%Undo%)%)%)%)%,%
%what,%(%else-then(%what%,%(%Do%)%)%)%,%
%What,%(%else-then(%What%,%(%what%)%)%)%,%
%WHAT,%(%else-then(%WHAT%,%(%toupper(%What%)%)%)%)%,%
%what,%(%else-then(%_What%,%(%tolower(%What%)%)%)%)%,%
%class,%(%else-then(%class%,%(%What%ed)%)%)%,%
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
%classt,%(%else-then(%classt%,%(%Class%t)%)%)%,%
%ClassT,%(%else-then(%ClassT%,%(%classt%)%)%)%,%
%CLASST,%(%else-then(%CLASST%,%(%toupper(%ClassT%)%)%)%)%,%
%classt,%(%else-then(%_ClassT%,%(%tolower(%ClassT%)%)%)%)%,%
%%(///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
enum %What%_status {
    %Undo%_success,
    %Do%_success = %Undo%_success,

    %Do%_failed,
    %Do%_busy,
    %Do%_interrupted,
    %Do%_invalid,

    %Undo%_failed,
    %Undo%_busy,
    %Undo%_interrupted,
    %Undo%_invalid
};

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
inline const char* %What%_status_to_chars(%What%_status status) {
    switch (status) {
    case %Do%_success: return "%Do%_success";
    case %Do%_failed: return "%Do%_failed";
    case %Do%_busy: return "%Do%_busy";
    case %Do%_interrupted: return "%Do%_interrupted";
    case %Do%_invalid: return "%Do%_invalid";

    case %Undo%_failed: return "%Undo%_failed";
    case %Undo%_busy: return "%Undo%_busy";
    case %Undo%_interrupted: return "%Undo%_interrupted";
    case %Undo%_invalid: return "%Undo%_invalid";
    }
    return "unknown";
}

typedef exceptiont_implements %What%_exception_implements;
typedef exceptiont<%What%_status> %What%_exception_extends;
///////////////////////////////////////////////////////////////////////
///  Class: %What%_exceptiont
///////////////////////////////////////////////////////////////////////
template
<class TImplements = %What%_exception_implements,
 class TExtends = %What%_exception_extends>

class _EXPORT_CLASS %What%_exceptiont: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    %What%_exceptiont(%What%_status status): Extends(status) {}
    virtual ~%What%_exceptiont() {}
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual const char* status_to_chars() const {
        return %What%_status_to_chars(this->status());
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};
typedef %What%_exceptiont<> %What%_exception;

typedef implement_base %ClassT%_implements;
///////////////////////////////////////////////////////////////////////
///  Class: %ClassT%
///////////////////////////////////////////////////////////////////////
template
<class TException = %What%_exception,
 class TImplements = %ClassT%_implements>

class _EXPORT_CLASS %ClassT%: virtual public TImplements {
public:
    typedef TImplements Implements;
    typedef TException %What%_exception;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool %Do%() { return false; }
    virtual %What%_status try_%Do%() { return %Do%_failed; }
    virtual %What%_status untimed_%Do%() { return %Do%_failed; }
    virtual %What%_status timed_%Do%(mseconds_t milliseconds) { return %Do%_failed; }
    virtual bool %Undo%() { return false; }
    virtual %What%_status try_%Undo%() { return %Undo%_failed; }
    virtual %What%_status untimed_%Undo%() { return %Undo%_failed; }
    virtual %What%_status timed_%Undo%(mseconds_t milliseconds) { return %Undo%_failed; }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};
typedef %ClassT%<> %Class%;

)%)%