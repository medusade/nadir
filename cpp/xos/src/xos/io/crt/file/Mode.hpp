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
///   File: Mode.hpp
///
/// Author: $author$
///   Date: 9/22/2017
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_IO_CRT_FILE_MODE_HPP
#define _XOS_IO_CRT_FILE_MODE_HPP

#include "xos/base/Base.hpp"

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
#define XOS_IO_CRT_FILE_MODE_READ "r"
#define XOS_IO_CRT_FILE_MODE_WRITE "w"

#define XOS_IO_CRT_FILE_MODE_BINARY "b"
#define XOS_IO_CRT_FILE_MODE_APPEND "+"

///////////////////////////////////////////////////////////////////////
#define XOS_IO_CRT_FILE_MODE_READ_APPEND \
    XOS_IO_CRT_FILE_MODE_READ \
    XOS_IO_CRT_FILE_MODE_APPEND

#define XOS_IO_CRT_FILE_MODE_WRITE_APPEND \
    XOS_IO_CRT_FILE_MODE_WRITE \
    XOS_IO_CRT_FILE_MODE_APPEND

///////////////////////////////////////////////////////////////////////
#define XOS_IO_CRT_FILE_MODE_READ_BINARY \
    XOS_IO_CRT_FILE_MODE_READ \
    XOS_IO_CRT_FILE_MODE_BINARY

#define XOS_IO_CRT_FILE_MODE_WRITE_BINARY \
    XOS_IO_CRT_FILE_MODE_WRITE \
    XOS_IO_CRT_FILE_MODE_BINARY

#define XOS_IO_CRT_FILE_MODE_READ_BINARY_APPEND \
    XOS_IO_CRT_FILE_MODE_READ \
    XOS_IO_CRT_FILE_MODE_BINARY \
    XOS_IO_CRT_FILE_MODE_APPEND

#define XOS_IO_CRT_FILE_MODE_WRITE_BINARY_APPEND \
    XOS_IO_CRT_FILE_MODE_WRITE \
    XOS_IO_CRT_FILE_MODE_BINARY \
    XOS_IO_CRT_FILE_MODE_APPEND

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////

namespace xos {
namespace io {
namespace crt {
namespace file {

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
enum ModeWhich {
    ModeRead   = 0,
    ModeWrite  = 1,
    ModeAppend = 3,
    ModeBinary = 4,
    ModeReadBinary = (ModeRead | ModeBinary),
    ModeWriteBinary = (ModeWrite | ModeBinary),
    ModeAppendBinary = (ModeAppend | ModeBinary)
};

typedef ImplementBase ModeTImplements;
///////////////////////////////////////////////////////////////////////
///  Class: ModeT
///////////////////////////////////////////////////////////////////////
template<class TImplements = ModeTImplements>

class _EXPORT_CLASS ModeT: virtual public TImplements {
public:
    typedef TImplements Implements;

    typedef ModeWhich mode_which_t;

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
    virtual const char* Mode(const mode_which_t& mode) const {
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
typedef ModeT<> Mode;

} // namespace file
} // namespace crt 
} // namespace io 
} // namespace xos 

#endif // _XOS_IO_CRT_FILE_MODE_HPP 
