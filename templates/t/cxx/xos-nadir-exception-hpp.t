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
%#   File: xos-nadir-exception-hpp.t
%#
%# Author: $author$
%#   Date: 2/12/2018
%########################################################################
%with(%
%%(%
%#ifndef _XOS_BASE_%FILE%_%EXTENSION%
#define _XOS_BASE_%FILE%_%EXTENSION%

#include "xos/base/exception.hpp"

namespace xos {
namespace base {

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
enum %Do%_status {
    %Undo%_success,
    %Do%_success = %Undo%_success,

    %Do%_failed,
    %Undo%_failed
};

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
inline const char* %Do%_status_to_chars(%Do%_status status) {
    switch (status) {
    case %Do%_success: return "%Do%_success";
    case %Do%_failed: return "%Do%_failed";
    case %Undo%_failed: return "%Undo%_failed";
    }
    return "unknown";
}

typedef exceptiont_implements %Do%_exception_implements;
typedef exceptiont<%Do%_status> %Do%_exception_extends;
///////////////////////////////////////////////////////////////////////
///  Class: %Do%_exceptiont
///////////////////////////////////////////////////////////////////////
template
<class TImplements = %Do%_exception_implements,
 class TExtends = %Do%_exception_extends>

class _EXPORT_CLASS %Do%_exceptiont: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    %Do%_exceptiont(%Do%_status status): Extends(status) {}
    virtual ~%Do%_exceptiont() {}
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual const char* status_to_chars() const {
        return %Do%_status_to_chars(this->status());
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};
typedef %Do%_exceptiont<> %Do%_exception;

} // namespace base 
} // namespace xos 

#endif // _XOS_BASE_%FILE%_%EXTENSION%
%
%%)%)%