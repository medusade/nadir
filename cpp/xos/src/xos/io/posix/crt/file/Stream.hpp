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
///   Date: 10/7/2017
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_IO_POSIX_CRT_FILE_STREAM_HPP
#define _XOS_IO_POSIX_CRT_FILE_STREAM_HPP

#include "xos/io/crt/file/Stream.hpp"
#include "xos/io/posix/crt/file/Writer.hpp"
#include "xos/io/posix/crt/file/Reader.hpp"
#include "xos/io/posix/crt/file/Opened.hpp"
#include "xos/io/posix/crt/file/Attached.hpp"

namespace xos {
namespace io {
namespace posix {
namespace crt {
namespace file {

typedef io::crt::file::Stream Stream;

} // namespace file 
} // namespace crt 
} // namespace posix 
} // namespace io 
} // namespace xos 

#endif // _XOS_IO_POSIX_CRT_FILE_STREAM_HPP 