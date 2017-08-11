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
///   File: Main.hpp
///
/// Author: $author$
///   Date: 8/6/2017
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_APP_CONSOLE_HELLO_MAIN_HPP
#define _XOS_APP_CONSOLE_HELLO_MAIN_HPP

#include "xos/app/console/hello/MainOpt.hpp"
#include "xos/console/getopt/Main.hpp"

namespace xos {
namespace app {
namespace console {
namespace hello {

typedef xos::console::getopt::MainImplements MainImplements;
typedef xos::console::getopt::Main MainExtends;
///////////////////////////////////////////////////////////////////////
///  Class: Main
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS Main
: virtual public MainOpt, virtual public MainImplements, public MainExtends {
public:
    typedef MainOpt OptImplements;
    typedef MainImplements Implements;
    typedef MainExtends Extends;

    ///////////////////////////////////////////////////////////////////////
    /// Constructor: Main
    ///////////////////////////////////////////////////////////////////////
    Main(): m_message("Hello") {
    }
    virtual ~Main() {
    }

protected:
    ///////////////////////////////////////////////////////////////////////
    /// Function: Run
    ///////////////////////////////////////////////////////////////////////
    virtual int Run(int argc, char_t**argv, char_t** env) {
        int err = 0;
        Out(m_message.Chars());
        if ((optind < argc) && (argv)) {
            const char_t* arg = 0;
            for (int i = optind; i < argc; ++i) {
                if ((arg = argv[i]) && (arg[0])) {
                    OutL(" ", arg, NULL);
                }
            }
        }
        OutLn();
        return err;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int OnMessageOption
    (int optval, const char_t* optarg,
     const char_t* optname, int optind,
     int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
            m_message.Assign(optarg);
        }
        return err;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    String m_message;
};

} // namespace hello
} // namespace console 
} // namespace app 
} // namespace xos 

#endif // _XOS_APP_CONSOLE_HELLO_MAIN_HPP 
