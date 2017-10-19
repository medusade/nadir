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
///   File: Opened.hpp
///
/// Author: $author$
///   Date: 10/15/2017
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_IO_CRT_FILE_OPENED_HPP
#define _XOS_IO_CRT_FILE_OPENED_HPP

#include "xos/io/crt/file/Attached.hpp"
#include "xos/io/crt/file/Mode.hpp"
#include "xos/base/Opened.hpp"

namespace xos {
namespace io {
namespace crt {
namespace file {

///////////////////////////////////////////////////////////////////////
///  Class: OpenT
///////////////////////////////////////////////////////////////////////
template
<class TAttach = AttachT<Mode>,
 class TOpen = xos::OpenT<OpenException, TAttach>,
 class TImplements = TOpen>

class _EXPORT_CLASS OpenT: virtual public TImplements {
public:
    typedef TImplements Implements;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    using Implements::Open;
    virtual bool Open(const String& name, const ModeWhich& mode) {
        const char* chars = 0;
        if ((chars = name.HasChars())) {
            return this->Open(chars, mode);
        }
        return false;
    }
    virtual bool Open(const char* name, const ModeWhich& mode) {
        return this->Open(name, this->Mode(mode));
    }
    virtual bool Open(const String& name) {
        const char* chars = 0;
        if ((chars = name.HasChars())) {
            return this->Open(chars);
        }
        return false;
    }
    virtual bool Open(const char* name, const char* mode) {
        FILE* detached = 0;
        if ((detached = this->OpenAttached(name, mode))) {
            this->SetIsOpen();
            return true;
        }
        return false;
    }
    virtual bool Open(const char* name) {
        return this->Open(name, ModeReadBinary);
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual FILE* OpenAttached(const char* name, const ModeWhich& mode) {
        return OpenAttached(name, this->Mode(mode));
    }
    virtual FILE* OpenAttached(const char* name, const char* mode) {
        if ((this->Closed())) {
            FILE* detached = 0;
            if ((detached = this->OpenDetached(name, mode))) {
                this->Attach(detached);
            }
            return detached;
        }
        return 0;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual FILE* OpenDetached(const char* name, const ModeWhich& mode) const {
        return OpenDetached(name, this->Mode(mode));
    }
    virtual FILE* OpenDetached(const char* name, const char* mode) const {
        if ((name) && (name[0]) && (mode) && (mode[0])) {
            FILE* detached = 0;
            XOS_LOG_DEBUG("::fopen(name = \"" << name << "\", mode = \"" << mode << "\")...");
            if ((detached = fopen(name, mode))) {
                XOS_LOG_DEBUG("...::fopen(name = \"" << name << "\", mode = \"" << mode << "\")");
                return detached;
            } else {
                XOS_LOG_DEBUG("...failed errno = " << errno << " on ::fopen(name = \"" << name << "\", mode = \"" << mode << "\")");
            }
        }
        return 0;
    }
    virtual bool CloseDetached(FILE* detached) const {
        if ((detached)) {
            int err = 0;
            XOS_LOG_DEBUG("::fclose(detached)...");
            if (!(err = ::fclose(detached))) {
                XOS_LOG_DEBUG("...::fclose(detached)");
                return true;
            } else {
                XOS_LOG_ERROR("...failed errno = " << errno << " on ::fclose(detached)");
            }
        }
        return false;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};
typedef OpenT<> Open;

///////////////////////////////////////////////////////////////////////
///  Class: OpenedT
///////////////////////////////////////////////////////////////////////
template
<class TOpen = Open,
 class TAttached = AttachedT<TOpen>,
 class TOpened = xos::OpenedT
 <AttachedTo, int, 0, OpenException, TOpen, TAttached>,
 class TImplements = TOpen, class TExtends = TOpened>

class _EXPORT_CLASS OpenedT: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    OpenedT(AttachedTo attached = 0, bool isOpen = false)
    : Extends(attached, isOpen) {
    }
    OpenedT(const OpenedT& copy): Extends(copy) {
    }
    virtual ~OpenedT() {
        if (!(this->Closed())) {
            OpenException e(CloseFailed);
            throw (e);
        }
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    using Implements::Open;
    virtual bool CloseDetached(FILE* detached) const {
        return Implements::CloseDetached(detached);
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};
typedef OpenedT<> Opened;

} // namespace file
} // namespace crt 
} // namespace io 
} // namespace xos 

#endif // _XOS_IO_CRT_FILE_OPENED_HPP 
