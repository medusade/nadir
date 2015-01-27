/**
 **********************************************************************
 * Copyright (c) 1988-2015 $organization$
 *
 * This software is provided by the author and contributors ``as is'' 
 * and any express or implied warranties, including, but not limited to, 
 * the implied warranties of merchantability and fitness for a particular 
 * purpose are disclaimed. In no event shall the author or contributors 
 * be liable for any direct, indirect, incidental, special, exemplary, 
 * or consequential damages (including, but not limited to, procurement 
 * of substitute goods or services; loss of use, data, or profits; or 
 * business interruption) however caused and on any theory of liability, 
 * whether in contract, strict liability, or tort (including negligence 
 * or otherwise) arising in any way out of the use of this software, 
 * even if advised of the possibility of such damage.
 *
 *   File: cplatform.h
 *
 * Author: $author$
 *   Date: 1/22/2015
 **********************************************************************
 */
#ifndef _XOS_NADIR_THIRDPARTY_XDE_CLIB_COS_CPLATFORM_H
#define _XOS_NADIR_THIRDPARTY_XDE_CLIB_COS_CPLATFORM_H
#define _CPLATFORM_H

#if defined(__cplusplus)
#include "xos/base/platform.hpp"
#endif /* defined(__cplusplus) */

#include <stdarg.h>

#if !defined(DB_PRINTF)
#define DB_PRINTF platform_db_printf
#endif /* !defined(DB_PRINTF) */

#if defined(__cplusplus)
extern "C" {
#endif /* defined(__cplusplus) */

extern int platform_db_printf(const char* format, ...);
extern int platform_db_vprintf(const char* format, va_list va);

#if defined(__cplusplus)
}
#endif /* defined(__cplusplus) */

#endif /* _XOS_NADIR_THIRDPARTY_XDE_CLIB_COS_CPLATFORM_H */
        

