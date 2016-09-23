///////////////////////////////////////////////////////////////////////
/// Copyright (c) 1988-2016 $organization$
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
///   File: waited.hpp
///
/// Author: $author$
///   Date: 9/20/2016
///////////////////////////////////////////////////////////////////////
#ifndef _NADIR_BASE_WAITED_HPP
#define _NADIR_BASE_WAITED_HPP

#include "nadir/base/base.hpp"

namespace nadir {

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
enum wait_length {
    wait_forever = -1,
    wait_none = 0
};
///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
enum wait_status {
    wait_success,
    wait_failed,
    wait_busy,
    wait_interrupted,
    wait_invalid
};

typedef implement_base wait_exception_implements;
typedef base wait_exception_extends;
///////////////////////////////////////////////////////////////////////
///  Class: wait_exceptiont
///////////////////////////////////////////////////////////////////////
template
<class TImplements = wait_exception_implements,
 class TExtends = wait_exception_extends>

class _EXPORT_CLASS wait_exceptiont: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    wait_exceptiont(wait_status status): status_(status) {}
    virtual ~wait_exceptiont() {}
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual wait_status status() const { return status_; }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    wait_status status_;
};
typedef wait_exceptiont<> wait_exception;

typedef implement_base waitedt_implements;
///////////////////////////////////////////////////////////////////////
///  Class: waitedt
///////////////////////////////////////////////////////////////////////
template
<class TWaitException = wait_exception,
 class TImplements = waitedt_implements>

class _EXPORT_CLASS waitedt: virtual public TImplements {
public:
    typedef TImplements Implements;
    typedef TWaitException wait_exception;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool wait() { return false; }
    virtual wait_status try_wait() { return wait_failed; }
    virtual wait_status timed_wait(mseconds_t milliseconds) { return wait_failed; }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};
typedef waitedt<> waited;

typedef implement_base waitert_implements;
typedef base waitert_extends;
///////////////////////////////////////////////////////////////////////
///  Class: waitert
///////////////////////////////////////////////////////////////////////
template
<class TWaited = waited,
 class TWaitException = wait_exception,
 class TImplements = waitert_implements,
 class TExtends = waitert_extends>

class _EXPORT_CLASS waitert: virtual public TImplements,public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;
    typedef TWaited waited;
    typedef TWaitException wait_exception;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    waitert(waited& _waited): waited_(_waited) {
        if (!(waited_.wait())) {
            wait_exception e(wait_failed);
            throw (e);
        }
    }
    virtual ~waitert() {}
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    waited& waited_;
};

} // namespace nadir

#endif // _NADIR_BASE_WAITED_HPP 
