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
///   File: Interface.hpp
///
/// Author: $author$
///   Date: 8/11/2017
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_LOGGER_INTERFACE_HPP
#define _XOS_LOGGER_INTERFACE_HPP

#include "xos/base/Base.hpp"

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
#define XOS_STDERR_LOG_LOCATION_FATAL(...)
#define XOS_STDERR_LOG_LOCATION_ERROR(...)
#define XOS_STDERR_LOG_LOCATION_WARN(...)
#define XOS_STDERR_LOG_LOCATION_INFO(...)
#define XOS_STDERR_LOG_LOCATION_DEBUG(...)
#define XOS_STDERR_LOG_LOCATION_TRACE(...)

#define XOS_STDERR_LOG_FUNCTION_FATAL(...)
#define XOS_STDERR_LOG_FUNCTION_ERROR(...)
#define XOS_STDERR_LOG_FUNCTION_WARN(...)
#define XOS_STDERR_LOG_FUNCTION_INFO(...)
#define XOS_STDERR_LOG_FUNCTION_DEBUG(...)
#define XOS_STDERR_LOG_FUNCTION_TRACE(...)

#define XOS_STDERR_LOG_PLAIN_FATAL(...)
#define XOS_STDERR_LOG_PLAIN_ERROR(...)
#define XOS_STDERR_LOG_PLAIN_WARN(...)
#define XOS_STDERR_LOG_PLAIN_INFO(...)
#define XOS_STDERR_LOG_PLAIN_DEBUG(...)
#define XOS_STDERR_LOG_PLAIN_TRACE(...)

#define XOS_STDERR_LOG_FATAL(...)
#define XOS_STDERR_LOG_ERROR(...)
#define XOS_STDERR_LOG_WARN(...)
#define XOS_STDERR_LOG_INFO(...)
#define XOS_STDERR_LOG_DEBUG(...)
#define XOS_STDERR_LOG_TRACE(...)

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
#define XOS_CERR_LOG_LOCATION_FATAL(...)
#define XOS_CERR_LOG_LOCATION_ERROR(...)
#define XOS_CERR_LOG_LOCATION_WARN(...)
#define XOS_CERR_LOG_LOCATION_INFO(...)
#define XOS_CERR_LOG_LOCATION_DEBUG(...)
#define XOS_CERR_LOG_LOCATION_TRACE(...)

#define XOS_CERR_LOG_FUNCTION_FATAL(...)
#define XOS_CERR_LOG_FUNCTION_ERROR(...)
#define XOS_CERR_LOG_FUNCTION_WARN(...)
#define XOS_CERR_LOG_FUNCTION_INFO(...)
#define XOS_CERR_LOG_FUNCTION_DEBUG(...)
#define XOS_CERR_LOG_FUNCTION_TRACE(...)

#define XOS_CERR_LOG_PLAIN_FATAL(...)
#define XOS_CERR_LOG_PLAIN_ERROR(...)
#define XOS_CERR_LOG_PLAIN_WARN(...)
#define XOS_CERR_LOG_PLAIN_INFO(...)
#define XOS_CERR_LOG_PLAIN_DEBUG(...)
#define XOS_CERR_LOG_PLAIN_TRACE(...)

#define XOS_CERR_LOG_FATAL(...)
#define XOS_CERR_LOG_ERROR(...)
#define XOS_CERR_LOG_WARN(...)
#define XOS_CERR_LOG_INFO(...)
#define XOS_CERR_LOG_DEBUG(...)
#define XOS_CERR_LOG_TRACE(...)

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
#define XOS_ERR_LOG_LOCATION_FATAL(...)
#define XOS_ERR_LOG_LOCATION_ERROR(...)
#define XOS_ERR_LOG_LOCATION_WARN(...)
#define XOS_ERR_LOG_LOCATION_INFO(...)
#define XOS_ERR_LOG_LOCATION_DEBUG(...)
#define XOS_ERR_LOG_LOCATION_TRACE(...)

#define XOS_ERR_LOG_FUNCTION_FATAL(...)
#define XOS_ERR_LOG_FUNCTION_ERROR(...)
#define XOS_ERR_LOG_FUNCTION_WARN(...)
#define XOS_ERR_LOG_FUNCTION_INFO(...)
#define XOS_ERR_LOG_FUNCTION_DEBUG(...)
#define XOS_ERR_LOG_FUNCTION_TRACE(...)

#define XOS_ERR_LOG_PLAIN_FATAL(...)
#define XOS_ERR_LOG_PLAIN_ERROR(...)
#define XOS_ERR_LOG_PLAIN_WARN(...)
#define XOS_ERR_LOG_PLAIN_INFO(...)
#define XOS_ERR_LOG_PLAIN_DEBUG(...)
#define XOS_ERR_LOG_PLAIN_TRACE(...)

#define XOS_ERR_LOG_FATAL(...)
#define XOS_ERR_LOG_ERROR(...)
#define XOS_ERR_LOG_WARN(...)
#define XOS_ERR_LOG_INFO(...)
#define XOS_ERR_LOG_DEBUG(...)
#define XOS_ERR_LOG_TRACE(...)

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
#define XOS_LOG_LOCATION_FATAL(...)
#define XOS_LOG_LOCATION_ERROR(...)
#define XOS_LOG_LOCATION_WARN(...)
#define XOS_LOG_LOCATION_INFO(...)
#define XOS_LOG_LOCATION_DEBUG(...)
#define XOS_LOG_LOCATION_TRACE(...)

#define XOS_LOG_FUNCTION_FATAL(...)
#define XOS_LOG_FUNCTION_ERROR(...)
#define XOS_LOG_FUNCTION_WARN(...)
#define XOS_LOG_FUNCTION_INFO(...)
#define XOS_LOG_FUNCTION_DEBUG(...)
#define XOS_LOG_FUNCTION_TRACE(...)

#define XOS_LOG_PLAIN_FATAL(...)
#define XOS_LOG_PLAIN_ERROR(...)
#define XOS_LOG_PLAIN_WARN(...)
#define XOS_LOG_PLAIN_INFO(...)
#define XOS_LOG_PLAIN_DEBUG(...)
#define XOS_LOG_PLAIN_TRACE(...)

#define XOS_LOG_FATAL(...)
#define XOS_LOG_ERROR(...)
#define XOS_LOG_WARN(...)
#define XOS_LOG_INFO(...)
#define XOS_LOG_DEBUG(...)
#define XOS_LOG_TRACE(...)

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
#define XOS_IF_LOG_LOCATION_FATAL(...)
#define XOS_IF_LOG_LOCATION_ERROR(...)
#define XOS_IF_LOG_LOCATION_WARN(...)
#define XOS_IF_LOG_LOCATION_INFO(...)
#define XOS_IF_LOG_LOCATION_DEBUG(...)
#define XOS_IF_LOG_LOCATION_TRACE(...)

#define XOS_IF_LOG_FUNCTION_FATAL(...)
#define XOS_IF_LOG_FUNCTION_ERROR(...)
#define XOS_IF_LOG_FUNCTION_WARN(...)
#define XOS_IF_LOG_FUNCTION_INFO(...)
#define XOS_IF_LOG_FUNCTION_DEBUG(...)
#define XOS_IF_LOG_FUNCTION_TRACE(...)

#define XOS_IF_LOG_PLAIN_FATAL(...)
#define XOS_IF_LOG_PLAIN_ERROR(...)
#define XOS_IF_LOG_PLAIN_WARN(...)
#define XOS_IF_LOG_PLAIN_INFO(...)
#define XOS_IF_LOG_PLAIN_DEBUG(...)
#define XOS_IF_LOG_PLAIN_TRACE(...)

#define XOS_IF_LOG_FATAL(...)
#define XOS_IF_LOG_ERROR(...)
#define XOS_IF_LOG_WARN(...)
#define XOS_IF_LOG_INFO(...)
#define XOS_IF_LOG_DEBUG(...)
#define XOS_IF_LOG_TRACE(...)

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////

namespace xos {
namespace logger {

} // namespace logger 
} // namespace xos 

#endif // _XOS_LOGGER_INTERFACE_HPP 
