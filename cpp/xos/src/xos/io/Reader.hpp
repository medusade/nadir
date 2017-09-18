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
///   Date: 9/15/2017
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_IO_READER_HPP
#define _XOS_IO_READER_HPP

#include "xos/base/Base.hpp"

namespace xos {
namespace io {

typedef ImplementBase ReaderTImplements;
///////////////////////////////////////////////////////////////////////
///  Class: ReaderT
///////////////////////////////////////////////////////////////////////
template
<typename TSized, typename TWhat = TSized,
 class TImplements = ReaderTImplements>

class _EXPORT_CLASS ReaderT: virtual public TImplements {
public:
    typedef TImplements Implements;

    typedef TSized sized_t;
    typedef TWhat what_t;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t Read(what_t* what, size_t size) {
        ssize_t count = 0;
        return count;
    }
    virtual ssize_t Fill() {
        ssize_t count = 0;
        return count;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};
typedef ReaderT<char, void> Reader;

///////////////////////////////////////////////////////////////////////
///  Class: CharReaderT
///////////////////////////////////////////////////////////////////////
template
<typename TChar = char, typename TWhat = TChar,
 class TReader = ReaderT<TChar, TWhat, ReaderTImplements>,
 class TImplements = TReader>

class _EXPORT_CLASS CharReaderT: virtual public TImplements {
public:
    typedef TImplements Implements;

    typedef TChar char_t;
    typedef char_t sized_t;
    typedef TWhat what_t;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t ReadLn() {
        const char_t lf = (char_t)'\n';
        ssize_t count = 0, amount = 0;
        sized_t sized = 0;

        do {
            if (0 < (amount = this->Read(&sized, 1))) {
                count += amount;

                if (!(sized != (lf))) {
                    break;
                }
            }
        } while (0 < (amount));
        return count;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};
typedef CharReaderT<char, void> CharReader;
typedef CharReaderT<tchar_t, void> TCharReader;
typedef CharReaderT<wchar_t, void> WCharReader;

} // namespace io
} // namespace xos 

#endif // _XOS_IO_READER_HPP 
