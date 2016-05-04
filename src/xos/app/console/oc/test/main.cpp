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
///   File: main.cpp
///
/// Author: $author$
///   Date: 2/26/2016
///////////////////////////////////////////////////////////////////////
#include "xos/app/console/test/main.hpp"
#include "thirdparty/opencine/OCCore/Log/NadirLoggingAdapter.h"
#include "OCCore/Log/ILogger.h"
#include <iostream>

extern OC::IOurWay& ourWay;
extern OC::ITheirWay& theirWay;
///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
template <class TLogger>
class TestT: public TLogger {
public:
    TestT() {
        if ((ourWay.DoIt().DidIt())) {
            OC_LOG_INFO("...DidIt ourWay");
        } else {
            OC_LOG_ERROR("...Failed to DoIt ourWay");
        }
        if ((theirWay.CanDoIt())) {
            OC_LOG_INFO("...CanDoIt theirWay");
        } else {
            OC_LOG_ERROR("...failed CanDoIt theirWay");
        }
        OC_LOG_INFO("...Having fun");
        OC_LOG_WARNING("...Be careful");
        OC_LOG_ERROR("...Ooops something went wrong");
        OC_LOG_FATAL("...We're done");
    }
};
class Test {
public:
    Test() {
        TestT<OC::Log::Logger>();
        TestT<OC::Log::xos::io::Logger>();
    }
};
OC::MyWay myWay;
OC::NotMyWay notMyWay;
OC::IOurWay& ourWay = myWay;
OC::ITheirWay& theirWay = notMyWay;

namespace xos {
namespace app {
namespace console {
namespace test {

typedef ::xos::io::logger_base logger_extends;
///////////////////////////////////////////////////////////////////////
/// test implementation of ::xos::io::logger
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS logger: public logger_extends {
protected:
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t log(const char_t* chars) {
        ssize_t count = 0;
        if ((chars)) count = fprintf(stderr ,"%s", chars);
        return count;
    }
};

} // namespace test
} // namespace console 
} // namespace app 
} // namespace xos 

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
int main(int argc, char** argv, char **env) {
    xos::app::console::test::logger logger;
    // initialize logger
    //
    XOS_LOGGER_INIT();

    // set logging level to XOS_DEFAULT_LOGGING_LEVELS_ID
    //
    XOS_SET_LOGGING_LEVEL(XOS_LOGGING_LEVELS_DEBUG);

    Test();

    // finalize logger
    //
    XOS_LOGGER_FINI();
    return 0;
}
