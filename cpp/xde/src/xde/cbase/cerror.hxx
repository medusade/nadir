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
 *   File: cerror.hxx
 *
 * Author: $author$
 *   Date: 9/26/2017
 **********************************************************************
 */
#ifndef _XDE_BASE_CERROR_HXX
#define _XDE_BASE_CERROR_HXX

#include "xde/cbase/cerror.h"
#include "xde/cplatform/cplatform.hxx"

#if defined(c_NAMESPACE)
#define c_NAMESPACE_ c_NAMESPACE
#define c_NAMESPACE_BEGIN namespace c_NAMESPACE {
#define c_NAMESPACE_END }
#else /* defined(c_NAMESPACE) */
#define c_NAMESPACE_
#define c_NAMESPACE_BEGIN
#define c_NAMESPACE_END
#endif /* defined(c_NAMESPACE) */

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#endif /* _XDE_BASE_CERROR_HXX */
