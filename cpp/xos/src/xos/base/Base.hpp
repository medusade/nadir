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
///   File: Base.hpp
///
/// Author: $author$
///   Date: 7/29/2017
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_BASE_BASE_HPP
#define _XOS_BASE_BASE_HPP

#include "xos/platform/Platform.hpp"

namespace xos {

///////////////////////////////////////////////////////////////////////
///  Class: ImplementBase
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS ImplementBase {
public:
    ///////////////////////////////////////////////////////////////////////
    /// Destructor: ~ImplementBase
    ///////////////////////////////////////////////////////////////////////
    virtual ~ImplementBase() {
    }
};

///////////////////////////////////////////////////////////////////////
///  Class: Base
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS Base: virtual public ImplementBase {
public:
    typedef ImplementBase Implements;
    ///////////////////////////////////////////////////////////////////////
    /// Constructor: Base
    ///////////////////////////////////////////////////////////////////////
    Base() {
    }
    virtual ~Base() {
    }
};

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
inline seconds_t mseconds_seconds
(mseconds_t mseconds) { return mseconds / 1000; }

inline mseconds_t mseconds_mseconds
(mseconds_t mseconds) { return mseconds % 1000; }

inline useconds_t mseconds_useconds
(mseconds_t mseconds) { return mseconds_mseconds(mseconds) * 1000; }

inline nseconds_t mseconds_nseconds
(mseconds_t mseconds) { return mseconds_useconds(mseconds) * 1000; }

} // namespace xos

#endif // _XOS_BASE_BASE_HPP 
