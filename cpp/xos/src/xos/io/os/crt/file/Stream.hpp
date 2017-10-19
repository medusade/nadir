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
#ifndef _XOS_IO_OS_CRT_FILE_STREAM_HPP
#define _XOS_IO_OS_CRT_FILE_STREAM_HPP

#include "xos/io/crt/file/Stream.hpp"
#include "xos/io/os/Os.hpp"

#if defined(WINDOWS)
#include "xos/io/microsoft/windows/crt/file/Stream.hpp"
#elif defined(MACOSX)
#include "xos/io/apple/osx/crt/file/Stream.hpp"
#else // defined(WINDOWS)
#include "xos/io/posix/crt/file/Stream.hpp"
#endif // defined(WINDOWS)

namespace xos {
namespace io {
namespace os {
namespace crt {
namespace file {

typedef os::crt::file::Attached Attached;
typedef os::crt::file::Opened Opened;
typedef os::crt::file::Reader Reader;
typedef os::crt::file::Writer Writer;
typedef os::crt::file::Stream Stream;

} // namespace file 
} // namespace crt 
} // namespace os 
} // namespace io 
} // namespace xos 

#endif // _XOS_IO_OS_CRT_FILE_STREAM_HPP 
