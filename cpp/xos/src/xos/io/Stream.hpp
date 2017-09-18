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
///   File: Stream.hpp
///
/// Author: $author$
///   Date: 9/15/2017
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_IO_STREAM_HPP
#define _XOS_IO_STREAM_HPP

#include "xos/io/Reader.hpp"
#include "xos/io/Writer.hpp"

namespace xos {
namespace io {

typedef ImplementBase StreamTImplements;
///////////////////////////////////////////////////////////////////////
///  Class: StreamT
///////////////////////////////////////////////////////////////////////
template
<typename TSized, typename TWhat = TSized,
 class TReader = ReaderT<TSized, TWhat>,
 class TWriter = WriterT<TSized, TWhat>,
 class TReaderImplements = TReader, class TWriterImplements = TWriter>

class _EXPORT_CLASS StreamT
: virtual public TReaderImplements, virtual public TWriterImplements {
public:
    typedef TReaderImplements ReaderImplements;
    typedef TWriterImplements WriterImplements;
    typedef TSized sized_t;
    typedef TWhat what_t;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};
typedef StreamT<char, void, Reader, Writer> Stream;

///////////////////////////////////////////////////////////////////////
///  Class: CharStreamT
///////////////////////////////////////////////////////////////////////
template
<typename TChar = char, typename TWhat = TChar,
 class TReader = CharReaderT<TChar, TWhat>,
 class TWriter = CharWriterT<TChar, TWhat>,
 class TReaderImplements = TReader, class TWriterImplements = TWriter>

class _EXPORT_CLASS CharStreamT
: virtual public TReaderImplements, virtual public TWriterImplements {
public:
    typedef TReaderImplements ReaderImplements;
    typedef TWriterImplements WriterImplements;

    typedef TChar char_t;
    typedef char_t sized_t;
    typedef TWhat what_t;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};
typedef CharStreamT<char, void, CharReader, CharWriter> CharStream;
typedef CharStreamT<tchar_t, void, TCharReader, TCharWriter> TCharStream;
typedef CharStreamT<wchar_t, void, WCharReader, WCharWriter> WCharStream;

} // namespace io
} // namespace xos 

#endif // _XOS_IO_STREAM_HPP 
