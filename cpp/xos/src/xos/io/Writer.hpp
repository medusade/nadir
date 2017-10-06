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
///   Date: 9/15/2017
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_IO_WRITER_HPP
#define _XOS_IO_WRITER_HPP

#include "xos/base/Base.hpp"

namespace xos {
namespace io {

typedef ImplementBase WriterTImplements;
///////////////////////////////////////////////////////////////////////
///  Class: WriterT
///////////////////////////////////////////////////////////////////////
template
<typename TSized, typename TWhat = TSized,
 class TImplements = WriterTImplements>

class _EXPORT_CLASS WriterT: virtual public TImplements {
public:
    typedef TImplements Implements;

    typedef TSized sized_t;
    typedef TWhat what_t;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t Write(const what_t* what, size_t size) {
        ssize_t count = 0;
        return count;
    }
    virtual ssize_t Write(const what_t* what) {
        ssize_t count = 0, amount = 0;
        const sized_t* sized = 0;

        if ((sized = ((const sized_t*)what))) {
            while ((*sized) != 0) {
                if (0 < (amount = Write(sized, 1))) {
                    count += amount;
                    ++sized;
                } else {
                    return -1;
                }
            }
        }
        return count;
    }
    virtual ssize_t Flush() {
        ssize_t count = 0;
        return count;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};
typedef WriterT<char, void> Writer;
typedef WriterT<byte_t, void> ByteWriter;
typedef WriterT<word_t, void> WordWriter;

///////////////////////////////////////////////////////////////////////
///  Class: CharWriterT
///////////////////////////////////////////////////////////////////////
template
<typename TChar = char, typename TWhat = TChar,
 class TWriter = WriterT<TChar, TWhat, WriterTImplements>,
 class TImplements = TWriter>

class _EXPORT_CLASS CharWriterT: virtual public TImplements {
public:
    typedef TImplements Implements;

    typedef TChar char_t;
    typedef char_t sized_t;
    typedef TWhat what_t;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t WriteLn(const what_t* what, size_t size) {
        ssize_t count = 0, amount = 0;

        if (0 <= (amount = this->Write(what, size))) {
            count += amount;

            if (0 < (amount = this->WriteLn())) {
                count += amount;
            } else {
                return amount;
            }
        } else {
            return amount;
        }
        return count;
    }
    virtual ssize_t WriteLn(const what_t* what) {
        ssize_t count = 0, amount = 0;

        if (0 <= (amount = this->Write(what))) {
            count += amount;

            if (0 < (amount = this->WriteLn())) {
                count += amount;
            } else {
                return amount;
            }
        } else {
            return amount;
        }
        return count;
    }
    virtual ssize_t WriteLn() {
        const char_t cr = ((char_t)'\r');
        const char_t lf = ((char_t)'\n');
        ssize_t count = 0, amount = 0;

        if (0 < (amount = this->Write(&cr, 1))) {
            count += amount;

            if (0 < (amount = this->Write(&lf, 1))) {
                count += amount;
            } else {
                return amount;
            }
        } else {
            return amount;
        }
        return count;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};
typedef CharWriterT<char, void> CharWriter;
typedef CharWriterT<wchar_t, void> WCharWriter;
typedef CharWriterT<tchar_t, void> TCharWriter;

} // namespace io
} // namespace xos 

#endif // _XOS_IO_WRITER_HPP 
