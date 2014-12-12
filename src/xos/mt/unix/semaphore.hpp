///////////////////////////////////////////////////////////////////////
/// Copyright (c) 1988-2014 $organization$
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
///   File: semaphore.hpp
///
/// Author: $author$
///   Date: 12/11/2014
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_NADIR_XOS_MT_UNIX_SEMAPHORE_HPP
#define _XOS_NADIR_XOS_MT_UNIX_SEMAPHORE_HPP
#include "xos/mt/semaphore.hpp"

namespace xos {
namespace mt {
namespace unix {


///////////////////////////////////////////////////////////////////////
///  Class: semaphoret
///////////////////////////////////////////////////////////////////////
template
<class TImplements = semaphoret_implemets, class TExtends = semaphoret_extends>
class _EXPORT_CLASS semaphoret: virtual public TImplements,public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;
    semaphoret() {
    }
    virtual ~semaphoret() {
    }
};


} // namespace unix 
} // namespace mt 
} // namespace xos 


#endif // _XOS_NADIR_XOS_MT_UNIX_SEMAPHORE_HPP 
        

