///////////////////////////////////////////////////////////////////////
/// Copyright (c) 1988-2015 $organization$
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
///   Date: 3/23/2015
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_NADIR_XOS_APP_CONSOLE_LS_MAIN_HPP
#define _XOS_NADIR_XOS_APP_CONSOLE_LS_MAIN_HPP

#include "xos/base/getopt/main.hpp"
#include "xos/os/fs/directory/path.hpp"
#include "xos/os/fs/directory/entry.hpp"
#include "xos/os/fs/entry.hpp"

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
#define XOS_APP_CONSOLE_LS_MAIN_PATH_ARG "[path]"
#define XOS_APP_CONSOLE_LS_MAIN_PATH_ARG_USE "File path"
#define XOS_APP_CONSOLE_LS_MAIN_PATH_ARGV \
    XOS_APP_CONSOLE_LS_MAIN_PATH_ARG " - " \
    XOS_APP_CONSOLE_LS_MAIN_PATH_ARG_USE \

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
#define XOS_APP_CONSOLE_LS_MAIN_ARGV \
    XOS_APP_CONSOLE_LS_MAIN_PATH_ARGV , \

#define XOS_APP_CONSOLE_LS_MAIN_ARGS \
    XOS_APP_CONSOLE_LS_MAIN_PATH_ARG " " \

namespace xos {
namespace app {
namespace console {
namespace ls {

typedef base::getopt::main_implement main_implement;
typedef base::getopt::main main_extend;
///////////////////////////////////////////////////////////////////////
///  Class: main
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS main: virtual public main_implement, public main_extend {
public:
    typedef main_implement Implements;
    typedef main_extend Extends;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    main() {
    }
    virtual ~main() {
    }

protected:
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        const char_t* path = 0;
        if ((optind < (argc)) && ((path = argv[optind])) && ((path[0]))) {
            os::fs::directory::path d;
            if ((d.open(path))) {
                os::fs::directory::entry* e = 0;
                if ((e = d.get_first_entry())) {
                    do {
                        outln(e->name());
                    } while ((e = d.get_next_entry()));
                }
            } else {
                outl("Unable to find \"", path, "\"", 0);
                outln();
            }
        } else {
            err = usage(argc, argv, env);
        }
        return err;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual const char* arguments(const char**& args) {
        static const char* argv[] = {
            XOS_APP_CONSOLE_LS_MAIN_ARGV
            0};
        args = argv;
        return XOS_APP_CONSOLE_LS_MAIN_ARGS;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
};

} // namespace ls 
} // namespace console 
} // namespace app 
} // namespace xos 

#endif // _XOS_NADIR_XOS_APP_CONSOLE_LS_MAIN_HPP 
