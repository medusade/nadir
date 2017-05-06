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
///   Date: 9/18/2016
///////////////////////////////////////////////////////////////////////
#ifndef _NADIR_APP_CONSOLE_HELLO_MAIN_HPP
#define _NADIR_APP_CONSOLE_HELLO_MAIN_HPP

#include "nadir/console/getopt/main.hpp"
#include "nadir/os/fs/directory/path.hpp"
#include "nadir/os/fs/directory/entry.hpp"
#include "nadir/os/fs/entry.hpp"
#include "nadir/mt/os/semaphore.hpp"

namespace nadir {
namespace app {
namespace console {
namespace hello {

class _EXPORT_CLASS main: public nadir::console::getopt::main {
protected:
    int run(int argc, char_t **argv, char_t **env) {
        const char* arg = 0;

        try {
            nadir::mt::os::semaphore s;
            s.release();
            s.timed_wait(2000);
        } catch (const create_exception& e) {
            LOG_ERROR("...caught const create_exception& e.status() = " << e.status());
            return 1;
        }

        nadir::os::fs::entry e;
        if ((optind < argc) && (e.exists((arg = argv[optind])))) {
            std::cout << e.name() << " exists\n";
        }

        nadir::os::fs::directory::path p;
        if ((p.open(arg))) {
            nadir::os::fs::directory::entry *e = 0;

            if ((e = p.get_first_entry())) {
                do {
                    std::cout << e->name() << "\n";
                } while ((e = p.get_next_entry()));
            }
            p.close();
        }
        return 0;
    }
};

} // namespace hello 
} // namespace console 
} // namespace app 
} // namespace nadir 

#endif // _NADIR_APP_CONSOLE_HELLO_MAIN_HPP 
