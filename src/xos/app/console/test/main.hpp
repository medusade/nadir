///////////////////////////////////////////////////////////////////////
/// Copyright (c) 1988-2016 $organization$
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
///   File: main.hpp
///
/// Author: $author$
///   Date: 2/26/2016
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_APP_CONSOLE_TEST_MAIN_HPP
#define _XOS_APP_CONSOLE_TEST_MAIN_HPP

#include "xos/base/getopt/main.hpp"

namespace xos {
namespace app {
namespace console {
namespace test {

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS main: public base::getopt::main {
public:
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    int run(int argc, char** argv, char** env) {
        int err = 0;
        return err;
    }
};

} // namespace test
} // namespace console 
} // namespace app 
} // namespace xos 

#endif // _XOS_APP_CONSOLE_TEST_MAIN_HPP 
