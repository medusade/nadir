///////////////////////////////////////////////////////////////////////
/// Copyright (c) 1988-2018 $organization$
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
///   File: process.hpp
///
/// Author: $author$
///   Date: 9/30/2018
///////////////////////////////////////////////////////////////////////
#ifndef _NADIR_MT_MICROSOFT_WINDOWS_PROCESS_HPP
#define _NADIR_MT_MICROSOFT_WINDOWS_PROCESS_HPP

#include "nadir/mt/process.hpp"

namespace nadir {
namespace mt {
namespace microsoft {
namespace windows {

///////////////////////////////////////////////////////////////////////
///  Class: processt
///////////////////////////////////////////////////////////////////////
template 
<class TImplements = implement_base, class TExtends = base>
class _EXPORT_CLASS processt: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;

    processt(const processt &copy) {
    }
    processt() {
    }
    virtual ~processt() {
    }
};
typedef processt<> process;

} /// namespace windows
} /// namespace microsoft
} /// namespace mt
} /// namespace nadir

#endif /// _NADIR_MT_MICROSOFT_WINDOWS_PROCESS_HPP 
