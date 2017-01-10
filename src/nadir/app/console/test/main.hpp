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
///   File: main.hpp
///
/// Author: $author$
///   Date: 1/6/2017
///////////////////////////////////////////////////////////////////////
#ifndef _NADIR_APP_CONSOLE_TEST_MAIN_HPP
#define _NADIR_APP_CONSOLE_TEST_MAIN_HPP

#include "nadir/console/main.hpp"
#include "nadir/io/logger.hpp"

namespace nadir {
namespace app {
namespace console {
namespace test {

typedef nadir::console::main_extend main_extends;
///////////////////////////////////////////////////////////////////////
///  Class: main
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS main: public main_extends {
public:
    typedef main_extends Extends;
protected:
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int run(int argc, char** argv, char** env) {
        int err = 0;
        LOG_DEBUGF("... \"%s\"", argv[0]);
        return err;
    }
};

} // namespace test 
} // namespace console 
} // namespace app 
} // namespace nadir 


#endif // _NADIR_APP_CONSOLE_TEST_MAIN_HPP 
        

