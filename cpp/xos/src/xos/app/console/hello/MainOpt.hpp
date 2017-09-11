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
///   File: MainOpt.hpp
///
/// Author: $author$
///   Date: 8/10/2017
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_APP_CONSOLE_HELLO_MAINOPT_HPP
#define _XOS_APP_CONSOLE_HELLO_MAINOPT_HPP

#include "nadir/app/console/hello/MainOpt.hpp"
#include "xos/console/getopt/MainOpt.hpp"

namespace xos {
namespace app {
namespace console {
namespace hello {

typedef nadir::app::console::hello::MainOpt MainOptImplements;
///////////////////////////////////////////////////////////////////////
///  Class: MainOptT
///////////////////////////////////////////////////////////////////////
template <class TImplements = MainOptImplements>

class _EXPORT_CLASS MainOptT: virtual public TImplements {
public:
    typedef TImplements Implements;
    typedef typename Implements::char_t char_t;
    typedef typename Implements::endchar_t endchar_t;
    static const endchar_t endchar = Implements::endchar;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};
typedef MainOptT<> MainOpt;

} // namespace hello 
} // namespace console 
} // namespace app 
} // namespace xos 

#endif // _XOS_APP_CONSOLE_HELLO_MAINOPT_HPP 

        

