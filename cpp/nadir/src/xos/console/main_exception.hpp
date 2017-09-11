///////////////////////////////////////////////////////////////////////
/// Copyright (c) 1988-2017 $organization$
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
///   File: main_exception.hpp
///
/// Author: $author$
///   Date: 9/9/2017
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_CONSOLE_MAIN_EXCEPTION_HPP
#define _XOS_CONSOLE_MAIN_EXCEPTION_HPP

#include "xos/base/exception.hpp"

namespace xos {
namespace console {

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
enum main_exception_which {
    main_already_exists,
    main_different_exists,
    main_doesnt_exist
};

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
inline const char* main_exception_which_to_chars(main_exception_which which) {
    switch (which) {
    case main_already_exists: return "main_already_exists";
    case main_different_exists: return "main_different_exists";
    case main_doesnt_exist: return "main_doesnt_exist";
    }
    return "unknown";
}

typedef exceptiont_implements main_exception_implements;
typedef exceptiont<main_exception_which> main_exception_extends;
///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
template
<class TImplements = main_exception_implements,
 class TExtends = main_exception_extends>

class _EXPORT_CLASS main_exceptiont: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    main_exceptiont(main_exception_which which): Extends(which) {}
    virtual ~main_exceptiont() {}
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual const char* to_chars() const {
        return main_exception_which_to_chars(this->which());
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};
typedef main_exceptiont<> main_exception;

} // namespace console
} // namespace xos 

#endif // _XOS_CONSOLE_MAIN_EXCEPTION_HPP 
