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
///   Date: 9/23/2017
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_IO_MICROSOFT_WINDOWS_CRT_FILE_ATTACHED_HPP
#define _XOS_IO_MICROSOFT_WINDOWS_CRT_FILE_ATTACHED_HPP

#include "xos/io/crt/file/Attached.hpp"

namespace xos {
namespace io {
namespace microsoft {
namespace windows {
namespace crt {
namespace file {

///////////////////////////////////////////////////////////////////////
///  Class: AttachedT
///////////////////////////////////////////////////////////////////////
template
<class TAttach = io::crt::file::Attach,
 class TAttached = io::crt::file::AttachedT<TAttach>,
 class TImplements = TAttach, class TExtends = TAttached>

class _EXPORT_CLASS AttachedT: virtual public TImplements,public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;
    typedef typename Extends::Attached Attached;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    AttachedT(Attached attached = 0, bool isOpen = false)
    : Extends(attached, isOpen) {
    }
    AttachedT(const AttachedT& copy): Extends(copy) {
    }
    virtual ~AttachedT() {
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool SetModeIsBinary(bool to = true) {
        FILE* detached = 0;

        if ((detached = this->AttachedTo())) {
            int fd = -1;

            XOS_LOG_DEBUG("::_fileno(detached)...");
            if (0 <= (fd = ::_fileno(detached))) {
                int mode = (to)?(_O_BINARY):(_O_TEXT);
                int err = 0;

                XOS_LOG_DEBUG("...fd = " << fd << " on ::_fileno(detached)");
                XOS_LOG_DEBUG("::_setmode(fd = " << fd << ", mode = " << mode << ")...");
                if (0 > (err = ::_setmode(fd, mode))) {
                    XOS_LOG_ERROR("...failed errno = " << errno << " on ::_setmode(fd = " << fd << ", mode = " << mode << ")");
                } else {
                    XOS_LOG_DEBUG("...::_setmode(fd = " << fd << ", mode = " << mode << ").");
                    return true;
                }
            } else {
                XOS_LOG_ERROR("...failed fd = " << fd << " on ::_fileno(detached)");
            }
        }
        return false;
    }
    virtual bool ModeIsBinary() const {
        return true;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};
typedef AttachedT<> Attached;

} // namespace file
} // namespace crt 
} // namespace windows 
} // namespace microsoft 
} // namespace io 
} // namespace xos 

#endif // _XOS_IO_MICROSOFT_WINDOWS_CRT_FILE_ATTACHED_HPP 
