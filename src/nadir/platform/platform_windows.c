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
///   File: platform_windows.c
///
/// Author: $author$
///   Date: 1/17/2017
///////////////////////////////////////////////////////////////////////
#include "nadir/platform/platform_windows.h"

#if (_MSC_VER < MSC_VER_14)
int vfscanf(FILE* file, const char* format, va_list va) {
    int count = 0;
    return count;
}
#endif // (_MSC_VER < MSC_VER_14)

#if defined(__cplusplus)
namespace nadir {
#endif /*/ defined(__cplusplus)  /*/

#if defined(__cplusplus)
} /*/ namespace nadir /*/
#endif /*/ defined(__cplusplus)  /*/
