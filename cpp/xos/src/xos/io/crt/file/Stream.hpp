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
///   Date: 10/6/2017
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_IO_CRT_FILE_STREAM_HPP
#define _XOS_IO_CRT_FILE_STREAM_HPP

#include "xos/io/Stream.hpp"
#include "xos/io/crt/file/Writer.hpp"
#include "xos/io/crt/file/Reader.hpp"
#include "xos/io/crt/file/Attached.hpp"

namespace xos {
namespace io {
namespace crt {
namespace file {

///////////////////////////////////////////////////////////////////////
///  Class: StreamAttachT
///////////////////////////////////////////////////////////////////////
template
<class TStream = io::Stream,
 class TOpen = OpenT<OpenException, TStream>,
 class TAttach = AttachT<TOpen>,
 class TImplements = TAttach>

class _EXPORT_CLASS StreamAttachT: virtual public TImplements {
public:
    typedef TImplements Implements;

    typedef typename TStream::sized_t sized_t;
    typedef typename TStream::what_t what_t;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};
typedef StreamAttachT<io::Stream> StreamAttach;
typedef StreamAttachT<io::CharStream> CharStreamAttach;
typedef StreamAttachT<io::TCharStream> TCharStreamAttach;
typedef StreamAttachT<io::WCharStream> WCharStreamAttach;

///////////////////////////////////////////////////////////////////////
///  Class: StreamT
///////////////////////////////////////////////////////////////////////
template
<class TStream = io::Stream,
 class TAttach = StreamAttachT<TStream>,
 class TAttached = AttachedT<TAttach>,
 class TImplements = TAttach, class TExtends = TAttached>

class _EXPORT_CLASS StreamT: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;

    typedef typename TStream::sized_t sized_t;
    typedef typename TStream::what_t what_t;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    StreamT(FILE* attached = 0): Extends(attached) {
    }
    virtual ~StreamT() {
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};
typedef StreamT<Stream> Stream;
typedef StreamT<CharStream> CharStream;
typedef StreamT<TCharStream> TCharStream;
typedef StreamT<WCharStream> WCharStream;

} // namespace file
} // namespace crt 
} // namespace io 
} // namespace xos 

#endif // _XOS_IO_CRT_FILE_STREAM_HPP 
