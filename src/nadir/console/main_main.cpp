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
///   File: main_main.cpp
///
/// Author: $author$
///   Date: 12/31/2016
///////////////////////////////////////////////////////////////////////
#include "nadir/console/main_main.hpp"
#include "nadir/mt/os/mutex.hpp"
#include "nadir/io/logger.hpp"

namespace nadir {
namespace console {

typedef nadir::io::logger logger_implements;
///////////////////////////////////////////////////////////////////////
///  Class: logger
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS logger: virtual public logger_implements {
public:
    typedef logger_implements Implements;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    logger(): mutex_(false) {}
    virtual ~logger() {}
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool lock() { return mutex_.lock(); }
    virtual bool unlock() { return mutex_.unlock(); }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    mt::os::mutex mutex_;
};

} // namespace console
} // namespace nadir 

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
int main(int argc, char **argv, char **env) {
    int err = 0;
    nadir::io::logger *old_logger;
    nadir::console::logger logger;
    old_logger = SET_THE_LOGGER(&logger);
    err = nadir::console::main::main(argc, argv, env);
    SET_THE_LOGGER(old_logger);
    return err;
}
