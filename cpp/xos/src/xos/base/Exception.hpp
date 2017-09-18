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
///   File: Exception.hpp
///
/// Author: $author$
///   Date: 8/6/2017
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_BASE_EXCEPTION_HPP
#define _XOS_BASE_EXCEPTION_HPP

#include "xos/base/String.hpp"

namespace xos {

typedef ImplementBase ExceptionTImplements;
typedef Base ExceptionTExtends;
///////////////////////////////////////////////////////////////////////
///  Class: ExceptionT
///////////////////////////////////////////////////////////////////////
template
<typename TStatus, typename TChar = char,
 class TString = StringT<TChar>,
 class TImplements = ExceptionTImplements,
 class TExtends = ExceptionTExtends>

class _EXPORT_CLASS ExceptionT: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;

    typedef TStatus whict_t;
    typedef TStatus reason_t;
    typedef TStatus status_t;
    typedef TString string_t;
    typedef TChar char_t;

    ///////////////////////////////////////////////////////////////////////
    /// Constructor: ExceptionT
    ///////////////////////////////////////////////////////////////////////
    ExceptionT(status_t status): m_status(status) {
    }
    virtual ~ExceptionT() {
    }

    ///////////////////////////////////////////////////////////////////////
    /// Function: Status
    ///////////////////////////////////////////////////////////////////////
    virtual status_t Status() const {
        return m_status;
    }
    virtual string_t StatusToString() const {
        string_t to(this->StatusToChars());
        return to;
    }
    virtual const char_t* StatusToChars() const {
        return this->ToChars();
    }
    virtual const char_t* ToChars() const {
        static const char_t nullChar = ((char_t)0);
        return &nullChar;
    }
    virtual operator const char_t*() const {
        return this->ToChars();
    }

    ///////////////////////////////////////////////////////////////////////
    /// Function: Reason
    ///////////////////////////////////////////////////////////////////////
    virtual reason_t Reason() const {
        return Status();
    }
    virtual string_t ReasonToString() const {
        string_t to(ReasonToChars());
        return to;
    }
    virtual const char_t* ReasonToChars() const {
        return this->StatusToChars();
    }

    ///////////////////////////////////////////////////////////////////////
    /// Function: Which
    ///////////////////////////////////////////////////////////////////////
    virtual reason_t Which() const {
        return Status();
    }
    virtual string_t WhichToString() const {
        string_t to(WhichToChars());
        return to;
    }
    virtual const char_t* WhichToChars() const {
        return this->StatusToChars();
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    status_t m_status;
};

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
enum ExceptionStatus {
    ExceptionSuccess,
    ExceptionFailed
};

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
inline const char* ExceptionStatusToChars(ExceptionStatus status) {
    switch (status) {
    case ExceptionSuccess: return "ExceptionSuccess";
    case ExceptionFailed: return "ExceptionFailed";
    }
    return "Unknown";
}

typedef ExceptionTImplements ExceptionImplements;
typedef ExceptionT<ExceptionStatus> ExceptionExtends;
///////////////////////////////////////////////////////////////////////
///  Class: Exception
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS Exception
: virtual public ExceptionImplements, public ExceptionExtends {
public:
    typedef ExceptionImplements Implements;
    typedef ExceptionExtends Extends;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    Exception(status_t status): Extends(status) {}

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual const char_t* ToChars() const {
        static const char_t* chars = ExceptionStatusToChars(this->Status());
        return chars;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};

} // namespace xos

#endif // _XOS_BASE_EXCEPTION_HPP 
