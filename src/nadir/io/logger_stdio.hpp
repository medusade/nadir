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
///   File: logger_stdio.hpp
///
/// Author: $author$
///   Date: 5/20/2017
///////////////////////////////////////////////////////////////////////
#ifndef _NADIR_IO_LOGGER_STDIO_HPP
#define _NADIR_IO_LOGGER_STDIO_HPP

#include "nadir/io/logger_message.hpp"
#include <iostream>

namespace nadir {
namespace io {

} // namespace io 
} // namespace nadir 

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
#if !defined(STDERR_LOG)
#define STDERR_LOG(__message__) \
    ::std::cerr << __FILE__ << "[" << __LINE__ << "] " << __FUNCTION__ << " " << __message__ << "\n"
#endif // !defined(STDERR_LOG)

#if !defined(STDERR_LOG_DEBUG)
#if defined(DEBUG_BUILD)
#define STDERR_LOG_DEBUG(__message__) STDERR_LOG(__message__)
#else // defined(DEBUG_BUILD)
#define STDERR_LOG_DEBUG(__message__)
#endif // defined(DEBUG_BUILD)
#endif // !defined(STDERR_LOG_DEBUG)

#if !defined(STDERR_LOG_ERROR)
#define STDERR_LOG_ERROR(__message__) STDERR_LOG(__message__)
#endif // !defined(STDERR_LOG_ERROR)

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
#if !defined(LOG_DEBUG)
#define LOG_DEBUG(__message__) STDERR_LOG_DEBUG(__message__)
#endif // !defined(LOG_DEBUG)

#if !defined(LOG_ERROR)
#define LOG_ERROR(__message__) STDERR_LOG_ERROR(__message__)
#endif // !defined(LOG_ERROR)

#endif // _NADIR_IO_LOGGER_STDIO_HPP
