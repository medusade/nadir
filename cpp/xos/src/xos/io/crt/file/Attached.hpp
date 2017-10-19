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
///   File: Attached.hpp
///
/// Author: $author$
///   Date: 9/22/2017
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_IO_CRT_FILE_ATTACHED_HPP
#define _XOS_IO_CRT_FILE_ATTACHED_HPP

#include "xos/base/Attached.hpp"
#include "xos/logger/Interface.hpp"

namespace xos {
namespace io {
namespace crt {
namespace file {

typedef FILE* AttachedTo;

///////////////////////////////////////////////////////////////////////
///  Class: AttachT
///////////////////////////////////////////////////////////////////////
template
<class TImplement = ImplementBase,
 class TAttach = xos::AttachT
 <AttachedTo, int, 0, AttachException, TImplement>,
 class TImplements = TAttach>

class _EXPORT_CLASS AttachT: virtual public TImplements {
public:
    typedef TImplements Implements;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t Read(void* what, size_t size, size_t count) {
        FILE* f = 0;

        if ((f = this->AttachedTo()) && (what) && (0 < (size)) && (0 < (count))) {
            ssize_t amount = 0;

            XOS_LOG_TRACE("::fread(what, " << size << ", " << count << ", f)...")
            if ((size*count) > (amount = ::fread(what, size, count, f))) {
                XOS_LOG_ERROR("...failed " << amount << " = ::fread(what, " << size << ", " << count << ", f)")
            } else {
                XOS_LOG_TRACE("..." << amount << " = ::fread(what, " << size << ", " << count << ", f)")
            }
            return amount;
        }
        return 0;
    }
    virtual ssize_t Write(const void* what, size_t size, size_t count) {
        FILE* f = 0;

        if ((f = this->AttachedTo()) && (what) && (0 < (size)) && (0 < (count))) {
            ssize_t amount = 0;

            XOS_LOG_TRACE("::fwrite(what, " << size << ", " << count << ", f)...")
            if ((size*count) > (amount = ::fwrite(what, size, count, f))) {
                XOS_LOG_ERROR("...failed " << amount << " = ::fwrite(what, " << size << ", " << count << ", f)")
            } else {
                XOS_LOG_TRACE("..." << amount << " = ::fwrite(what, " << size << ", " << count << ", f)")
            }
            return amount;
        }
        return 0;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};
typedef AttachT<> Attach;

///////////////////////////////////////////////////////////////////////
///  Class: AttachedT
///////////////////////////////////////////////////////////////////////
template
<class TAttach = Attach,
 class TExtend = Base,
 class TAttached = xos::AttachedT
 <AttachedTo, int, 0, AttachException, TAttach, TExtend>,
 class TImplements = TAttach, class TExtends = TAttached>

class _EXPORT_CLASS AttachedT: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;

    typedef typename Extends::Attached Attached;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    AttachedT(Attached attached = 0): Extends(attached) {
    }
    AttachedT(const AttachedT& copy): Extends(copy) {
    }
    virtual ~AttachedT() {
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};
typedef AttachedT<> Attached;

} // namespace file
} // namespace crt 
} // namespace io 
} // namespace xos 

#endif // _XOS_IO_CRT_FILE_ATTACHED_HPP 
