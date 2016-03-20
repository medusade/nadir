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

#include "xos/io/logger_base.hpp"

#ifndef OC_EXPORT
#define OC_EXPORT
#endif // ndef OC_EXPORT

namespace OC {

class OC_EXPORT IOurWay {
public:
    virtual IOurWay& DoIt() = 0;
    virtual bool DidIt() const = 0;
};
class OC_EXPORT MyWay: virtual public IOurWay {
public:
    MyWay(): _didIt(false) {}
    virtual ~MyWay() {}
    virtual IOurWay& DoIt() {
        _didIt = true;
        return *this;
    }
    virtual bool DidIt() const {
        return _didIt;
    }
protected:
    bool _didIt;
};
class OC_EXPORT ITheirWay {
public:
    virtual bool CanDoIt() const = 0;
};
class OC_EXPORT NotMyWay: virtual public ITheirWay, public MyWay {
public:
    NotMyWay() {}
    virtual ~NotMyWay() {}
    virtual IOurWay& DoIt() {
        _didIt = CanDoIt();
        return *this;
    }
    virtual bool CanDoIt() const {
        return false;
    }
};

} // namespace OC

namespace xos {
namespace app {
namespace console {
namespace test {

} // namespace test
} // namespace console 
} // namespace app 
} // namespace xos 

#endif // _XOS_APP_CONSOLE_TEST_MAIN_HPP 
