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
#ifndef _XOS_IO_APPLE_OSX_CRT_FILE_STREAM_HPP
#define _XOS_IO_APPLE_OSX_CRT_FILE_STREAM_HPP

#include "xos/io/posix/crt/file/Stream.hpp"

namespace xos {
namespace io {
namespace apple {
namespace osx {
namespace crt {
namespace file {

typedef posix::crt::file::Attached Attached;
typedef posix::crt::file::Opened Opened;
typedef posix::crt::file::Reader Reader;
typedef posix::crt::file::Writer Writer;
typedef posix::crt::file::Stream Stream;

} // namespace file
} // namespace crt 
} // namespace osx 
} // namespace apple 
} // namespace io 
} // namespace xos 

#endif // _XOS_IO_APPLE_OSX_CRT_FILE_STREAM_HPP 
