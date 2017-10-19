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
///   File: Writer.hpp
///
/// Author: $author$
///   Date: 10/6/2017
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_IO_CRT_FILE_WRITER_HPP
#define _XOS_IO_CRT_FILE_WRITER_HPP

#include "xos/io/crt/file/Opened.hpp"
#include "xos/io/Writer.hpp"

namespace xos {
namespace io {
namespace crt {
namespace file {

///////////////////////////////////////////////////////////////////////
///  Class: WriterT
///////////////////////////////////////////////////////////////////////
template
<class TWriter = io::Writer,
 class TOpened = Opened,
 class TImplements = TWriter, class TExtends = TOpened>

class _EXPORT_CLASS WriterT: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;

    typedef typename TWriter::sized_t sized_t;
    typedef typename TWriter::what_t what_t;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    WriterT(FILE* attached = 0, bool isOpen = false)
    : Extends(attached, isOpen) {
    }
    WriterT(const WriterT& copy): Extends(copy) {
    }
    virtual ~WriterT() {
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    using Extends::Open;
    virtual bool OpenPatterned(const String& name, const String& pattern) {
        const char *nameChars = 0, *patternChars = 0;
        if ((nameChars = name.HasChars())
            && (patternChars = pattern.HasChars())) {
            return this->OpenPatterned(nameChars, patternChars);
        }
        return false;
    }
    virtual bool OpenPatterned(const char* name, const char* pattern) {
        if ((name) && (name[0]) && (pattern) && (pattern[0])) {
            bool success = false;

            XOS_LOG_DEBUG("this->Open(name = \"" << name << "\", file::ModeReadBinary)...");
            if (!(this->Open(name, file::ModeReadBinary))) {
                XOS_LOG_DEBUG("...failed on this->Open(name = \"" << name << "\", file::ModeReadBinary)");
                success = true;
            } else {
                XOS_LOG_DEBUG("this->ReadPattern(pattern = \"" << pattern << "\")...");
                if (0 < (this->ReadPattern(pattern))) {
                    XOS_LOG_DEBUG("...this->ReadPattern(pattern = \"" << pattern << "\")");
                    success = true;
                } else {
                    XOS_LOG_ERROR("...failed on this->ReadPattern(pattern = \"" << pattern << "\")");
                }
                if (!(this->Close())) {
                    success = false;
                }
            }
            if ((success)) {
                return this->Open(name, file::ModeWriteBinary);
            }
        }
        return false;
    }
    virtual bool Open(const char* name) {
        return this->Open(name, this->ModeWriteBinary());
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t ReadPattern(const char* pattern) {
        if ((pattern) && (pattern[0])) {
            ssize_t count = 0, amount = 0;
            sized_t sized = 0;
            char sc = 0;

            for (char c = *(pattern); c; c = *(++pattern)) {
                XOS_LOG_DEBUG("'" << CharToString(c) << "': this->Read(&sized, sizeof(sized_t), 1)...");
                if (0 < (amount = this->Read(&sized, sizeof(sized_t), 1))) {
                    XOS_LOG_DEBUG("...'" << CharToString(c) << "': this->Read(&sized, sizeof(sized_t), 1)");
                    if ((sc = ((char)sized)) == c) {
                        count += amount;
                        continue;
                    } else {
                        XOS_LOG_ERROR("...failed on (sized = '" << CharToString(sc) << "') != (c = '" << CharToString(c) << "')");
                    }
                } else {
                    XOS_LOG_ERROR("...'" << CharToString(c) << "': failed on this->Read(&sized, sizeof(sized_t), 1)");
                }
                return 0;
            }
            return count;
        }
        return 0;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    using Implements::Write;
    using Extends::Write;
    virtual ssize_t Write(const what_t* what, size_t size) {
        return this->Write(what, sizeof(sized_t), size);
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};
typedef WriterT<Writer> Writer;
typedef WriterT<CharWriter> CharWriter;
typedef WriterT<TCharWriter> TCharWriter;
typedef WriterT<WCharWriter> WCharWriter;

} // namespace file
} // namespace crt 
} // namespace io 
} // namespace xos 

#endif // _XOS_IO_CRT_FILE_WRITER_HPP 
