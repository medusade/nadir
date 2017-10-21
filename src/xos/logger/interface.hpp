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
///   File: interface.hpp
///
/// Author: $author$
///   Date: 10/21/2017
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_NADIR_LOGGER_INTERFACE_HPP
#define _XOS_NADIR_LOGGER_INTERFACE_HPP

#include "xos/logger/output.hpp"
#include "xos/mt/locker.hpp"

namespace xos {
namespace logger {

typedef mt::locker interface_implements;
///////////////////////////////////////////////////////////////////////
///  Class: interface
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS interface: virtual public interface_implements {
public:
    typedef interface_implements Implements;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool init() { 
        return true; 
    }
    virtual bool fini() { 
        return true; 
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual void log
    (const level& _level, const location& _location, const message& _message) {
    }
    virtual void logf
    (const level& _level, const location& _location, const char* format, ...) {
    }
    virtual void logfv
    (const level& _level, const location& _location, const char* format, va_list va) {
    }
    virtual void logfv
    (const level& _level, const location& _location,
     const message& _message, const char* format, va_list va) {
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual void log
    (const level& _level, const message& _message) {
    }
    virtual void logf
    (const level& _level, const char* format, ...) {
    }
    virtual void logfv
    (const level& _level, const char* format, va_list va) {
    }
    virtual void logfv
    (const level& _level, const message& _message, const char* format, va_list va) {
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual void enable_for(const level& _level) {
    }
    virtual level enabled_for() const { 
        return enabled_for_default(); 
    }
    virtual bool is_enabled_for(const level& _level) const { 
        level::enable enabled = _level, enabled_for = this->enabled_for();
        return ((enabled_for & enabled) == enabled);
    }
    virtual level enabled_for_default() const { 
        return level(XOS_LOGGING_LEVELS_DEFAULT); 
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};

} // namespace logger 
} // namespace xos 

#endif // _XOS_NADIR_LOGGER_INTERFACE_HPP 
