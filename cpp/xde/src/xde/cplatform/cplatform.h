/**
 **********************************************************************
 * Copyright (c) 1988-2017 $organization$
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
 *   Date: 9/26/2017
 **********************************************************************
 */
#ifndef _XDE_CPLATFORM_CPLATFORM_H
#define _XDE_CPLATFORM_CPLATFORM_H

#include "xos/platform/platform.h"

/**
 **********************************************************************
 **********************************************************************
 */
#define FILE_MODE_READ "r"
#define FILE_MODE_WRITE "w"

#define INVALID_FILEP NULL
typedef FILE* FILEP;

/**
 **********************************************************************
 **********************************************************************
 */
#if defined(WINDOWS)
/* Windows
 */
#define PLATFORM_PATH_SEPARATOR_CHAR ';'
#define FOREIGN_PATH_SEPARATOR_CHAR ':'
#define PATH_SEPARATOR_CHAR PLATFORM_PATH_SEPARATOR_CHAR

#define PLATFORM_VOLUME_SEPARATOR_CHAR ':'
#define FOREIGN_VOLUME_SEPARATOR_CHAR 0
#define VOLUME_SEPARATOR_CHAR PLATFORM_VOLUME_SEPARATOR_CHAR

#define PLATFORM_DIRECTORY_SEPARATOR_CHAR '\\'
#define FOREIGN_DIRECTORY_SEPARATOR_CHAR '/'
#define DIRECTORY_SEPARATOR_CHAR FOREIGN_DIRECTORY_SEPARATOR_CHAR
#else /* defined(WINDOWS) */
/* Unix
 */
#define PLATFORM_PATH_SEPARATOR_CHAR ':'
#define FOREIGN_PATH_SEPARATOR_CHAR ';'
#define PATH_SEPARATOR_CHAR PLATFORM_PATH_SEPARATOR_CHAR

#define PLATFORM_VOLUME_SEPARATOR_CHAR 0
#define FOREIGN_VOLUME_SEPARATOR_CHAR ':'
#define VOLUME_SEPARATOR_CHAR FOREIGN_VOLUME_SEPARATOR_CHAR

#define PLATFORM_DIRECTORY_SEPARATOR_CHAR '/'
#define FOREIGN_DIRECTORY_SEPARATOR_CHAR '\\'
#define DIRECTORY_SEPARATOR_CHAR PLATFORM_DIRECTORY_SEPARATOR_CHAR
/* Unix
 */
#endif /* defined(WINDOWS) */

#define EXTENSION_SEPARATOR_CHAR '.'
#define PLATFORM_EXTENSION_SEPARATOR_CHAR EXTENSION_SEPARATOR_CHAR
#define FOREIGN_EXTENSION_SEPARATOR_CHAR EXTENSION_SEPARATOR_CHAR

#define EXTENSION_SEPARATOR "."
#define PLATFORM_EXTENSION_SEPARATOR EXTENSION_SEPARATOR
#define FOREIGN_EXTENSION_SEPARATOR EXTENSION_SEPARATOR

#define PATH_WILDCARD_CHAR '*'
#define PLATFORM_PATH_WILDCARD_CHAR PATH_WILDCARD_CHAR
#define FOREIGN_PATH_WILDCARD_CHAR PATH_WILDCARD_CHAR

#define PATH_ENV_NAME "PATH"
#define PLATFORM_PATH_ENV_NAME PATH_ENV_NAME
#define FOREIGN_PATH_ENV_NAME PATH_ENV_NAME

/**
 **********************************************************************
 **********************************************************************
 */
#if defined(__cplusplus)
extern "C" {
#endif /* defined(__cplusplus) */

#if defined(__cplusplus)
}
#endif /* defined(__cplusplus) */

#endif /* _XDE_CPLATFORM_CPLATFORM_H */
