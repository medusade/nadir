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

#include "xos/io/crt/file/Mode.hpp"
#include "xos/base/Opened.hpp"
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
<class TImplement = Open,
 class TAttach = xos::AttachT
 <AttachedTo, int, 0, AttachException, TImplement>,
 class TImplements = TAttach>

class _EXPORT_CLASS AttachT: virtual public TImplements {
public:
    typedef TImplements Implements;
};
typedef AttachT<> Attach;

///////////////////////////////////////////////////////////////////////
///  Class: AttachedT
///////////////////////////////////////////////////////////////////////
template
<class TAttach = Attach,
 class TAttached = xos::AttachedT
 <AttachedTo, int, 0, AttachException, TAttach, Base>,
 class TOpened = xos::OpenedT
 <AttachedTo, int, 0, OpenException, TAttach, TAttached>,
 class TImplements = TAttach, class TExtends = TOpened>

class _EXPORT_CLASS AttachedT: virtual public TImplements, public TExtends {
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
        if (!(this->Closed())) {
            OpenException e(CloseFailed);
            throw (e);
        }
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool SetModeIsBinary(bool to = true) {
        return true;
    }
    virtual bool ModeIsBinary() const {
        return true;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool Open(const String& name, const file::Mode& mode) {
        const char* chars = 0;
        if ((chars = name.HasChars())) {
            return Open(chars, mode);
        }
        return false;
    }
    virtual bool Open(const char* name, const file::Mode& mode) {
        return Open(name, Mode(mode));
    }
    virtual bool Open(const char* name, const char* mode) {
        FILE* detached = 0;
        if ((detached = OpenAttached(name, mode))) {
            this->SetIsOpen();
            return true;
        }
        return false;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual FILE* OpenAttached(const char* name, const file::Mode& mode) {
        return OpenAttached(name, Mode(mode));
    }
    virtual FILE* OpenAttached(const char* name, const char* mode) {
        if ((this->Closed())) {
            FILE* detached = 0;
            if ((detached = OpenDetached(name, mode))) {
                this->Attach(detached);
            }
            return detached;
        }
        return 0;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual FILE* OpenDetached(const char* name, const file::Mode& mode) const {
        return OpenDetached(name, Mode(mode));
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
    virtual const char* Mode(const file::Mode& mode) const {
        switch (mode) {
        case file::ModeRead: return this->ModeRead();
        case file::ModeWrite: return this->ModeWrite();
        case file::ModeAppend: return this->ModeAppend();
        case file::ModeReadBinary: return this->ModeReadBinary();
        case file::ModeWriteBinary: return this->ModeWriteBinary();
        case file::ModeAppendBinary: return this->ModeAppendBinary();
        }
        return 0;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual const char* ModeRead() const {
        const char* mode = XOS_IO_CRT_FILE_MODE_READ;
        return mode;
    }
    virtual const char* ModeWrite() const {
        const char* mode = XOS_IO_CRT_FILE_MODE_WRITE;
        return mode;
    }
    virtual const char* ModeAppend() const {
        const char* mode = XOS_IO_CRT_FILE_MODE_WRITE_APPEND;
        return mode;
    }
    ///////////////////////////////////////////////////////////////////////
    virtual const char* ModeReadBinary() const {
        const char* mode = XOS_IO_CRT_FILE_MODE_READ_BINARY;
        return mode;
    }
    virtual const char* ModeWriteBinary() const {
        const char* mode = XOS_IO_CRT_FILE_MODE_WRITE_BINARY;
        return mode;
    }
    virtual const char* ModeAppendBinary() const {
        const char* mode = XOS_IO_CRT_FILE_MODE_WRITE_BINARY_APPEND;
        return mode;
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
