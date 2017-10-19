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
///   File: Os.hpp
///
/// Author: $author$
///   Date: 9/23/2017
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_IO_OS_OS_HPP
#define _XOS_IO_OS_OS_HPP

#include "xos/base/Base.hpp"

namespace xos {
namespace io {
namespace microsoft { namespace windows { namespace crt {} } }
namespace apple { namespace osx { namespace crt {} } }
namespace posix { namespace crt {} }
namespace os {

#if defined(WINDOWS)
namespace os = microsoft::windows;
#elif defined(MACOSX)
namespace os = apple::osx;
#else // defined(WINDOWS)
namespace os = posix;
#endif // defined(WINDOWS)

} // namespace os
} // namespace io 
} // namespace xos 

#endif // _XOS_IO_OS_OS_HPP 
