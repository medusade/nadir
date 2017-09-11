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
///   File: locked.hpp
///
/// Author: $author$
///   Date: 9/10/2017
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_CONSOLE_LOCKED_HPP
#define _XOS_CONSOLE_LOCKED_HPP

#include "xos/base/locked.hpp"

namespace xos {
namespace console {

///////////////////////////////////////////////////////////////////////
/// class: locked
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS locked: public xos::locked {
public:
    typedef locked Derives;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    locked(xos::locked& _locked): m_locked(_locked) {
        xos::locked*& the_locked = Derives::the_locked();
        if (!(the_locked)) {
            the_locked = this;
        } else {
        }
    }
    locked(): m_locked(m_unlocked) {
        xos::locked*& the_locked = Derives::the_locked();
        if (!(the_locked)) {
            the_locked = this;
        } else {
        }
    }
    virtual ~locked() {
        xos::locked*& the_locked = Derives::the_locked();
        if ((this == the_locked)) {
            the_locked = 0;
        } else {
        }
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool lock() {
        return m_locked.lock();
    }
    virtual bool unlock() {
        return m_locked.unlock();
    }
protected:
    static xos::locked*& the_locked() {
        static xos::locked* the_locked = 0;
        return the_locked;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    xos::unlocked m_unlocked;
    xos::locked &m_locked;
};

} // namespace console
} // namespace xos 

#endif // _XOS_CONSOLE_LOCKED_HPP 
