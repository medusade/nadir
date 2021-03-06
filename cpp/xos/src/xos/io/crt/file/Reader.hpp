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
///   File: Reader.hpp
///
/// Author: $author$
///   Date: 9/22/2017
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_IO_CRT_FILE_READER_HPP
#define _XOS_IO_CRT_FILE_READER_HPP

#include "xos/io/crt/file/Opened.hpp"
#include "xos/io/Reader.hpp"

namespace xos {
namespace io {
namespace crt {
namespace file {

///////////////////////////////////////////////////////////////////////
///  Class: ReaderT
///////////////////////////////////////////////////////////////////////
template
<class TReader = io::Reader,
 class TOpened = Opened,
 class TImplements = TReader, class TExtends = TOpened>

class _EXPORT_CLASS ReaderT: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;

    typedef typename TReader::sized_t sized_t;
    typedef typename TReader::what_t what_t;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    ReaderT(FILE* attached = 0, bool isOpen = false)
    : Extends(attached, isOpen) {
    }
    ReaderT(const ReaderT& copy): Extends(copy) {
    }
    virtual ~ReaderT() {
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    using Extends::Open;
    virtual bool Open(const char* name) {
        return this->Open(name, this->ModeReadBinary());
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    using Implements::Read;
    using Extends::Read;
    virtual ssize_t Read(what_t* what, size_t size) {
        return this->Read(what, sizeof(sized_t), size);
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};
typedef ReaderT<Reader> Reader;
typedef ReaderT<CharReader> CharReader;
typedef ReaderT<TCharReader> TCharReader;
typedef ReaderT<WCharReader> WCharReader;

} // namespace file
} // namespace crt 
} // namespace io 
} // namespace xos 

#endif // _XOS_IO_CRT_FILE_READER_HPP 
