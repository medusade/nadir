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
///   Date: 9/10/2017
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_APP_CONSOLE_TOUNDER_MAIN_HPP
#define _XOS_APP_CONSOLE_TOUNDER_MAIN_HPP

#include "xos/console/getopt/main.hpp"

namespace xos {
namespace app {
namespace console {
namespace tounder {

typedef xos::console::getopt::main_implements main_implements;
typedef xos::console::getopt::main main_extends;
///////////////////////////////////////////////////////////////////////
///  Class: main
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS main: virtual public main_implements,public main_extends {
public:
    typedef main_implements Implements;
    typedef main_extends Extends;
    typedef main Derives;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    main(): on_(0), lower_c(0), upper_c(0) {
    }
    virtual ~main() {
    }

protected:
    void (Derives::*on_)(char c);
    char lower_c, upper_c;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int run(int argc, char** argv, char** env) {
        int err = 0;
        char c = 0;
        while (0 < (this->in(&c, 1))) {
            on(c);
            this->out_flush();
        }
        return err;
    }
    virtual void on(char c) {
        if ((on_)) {
            (this->*on_)(c);
        } else {
            if ((c >= 'A') && (c <= 'Z')) {
                on_ = &Derives::first_upper_on;
                lower_c = ::tolower(c);
                upper_c = c;
            } else {
                if ((c >= 'a') && (c <= 'z')) {
                    on_ = &Derives::lower_on;
                    this->out(&c, 1);
                } else {
                    if ((c >= '_') && (c <= '_')) {
                        on_ = &Derives::under_on;
                        this->out(&c, 1);
                    } else {
                        this->out(&c, 1);
                    }
                }
            }
        }
    }
    virtual void under_on(char c) {
        if ((c >= 'A') && (c <= 'Z')) {
            on_ = &Derives::upper_on;
            this->out(&c, 1);
        } else {
            if ((c >= 'a') && (c <= 'z')) {
                on_ = &Derives::lower_on;
                this->out(&c, 1);
            } else {
                if ((c >= '_') && (c <= '_')) {
                    this->out(&c, 1);
                } else {
                    on_ = 0;
                    this->out(&c, 1);
                }
            }
        }
    }
    virtual void lower_on(char c) {
        if ((c >= 'A') && (c <= 'Z')) {
            on_ = &Derives::lower_upper_on;
            lower_c = ::tolower(c);
        } else {
            if ((c >= 'a') && (c <= 'z')) {
                this->out(&c, 1);
            } else {
                if ((c >= '_') && (c <= '_')) {
                    on_ = &Derives::under_on;
                    this->out(&c, 1);
                } else {
                    on_ = 0;
                    this->out(&c, 1);
                }
            }
        }
    }
    virtual void lower_upper_on(char c) {
        if ((c >= 'A') && (c <= 'Z')) {
            on_ = &Derives::upper_on;
            this->out("_");
            this->out(&lower_c, 1);
            this->out(&c, 1);
        } else {
            if ((c >= 'a') && (c <= 'z')) {
                on_ = &Derives::lower_on;
                this->out("_");
                this->out(&lower_c, 1);
                this->out(&c, 1);
            } else {
                if ((c >= '_') && (c <= '_')) {
                    on_ = &Derives::under_on;
                    this->out("_");
                    this->out(&lower_c, 1);
                    this->out(&c, 1);
                } else {
                    on_ = 0;
                    this->out(&lower_c, 1);
                    this->out(&c, 1);
                }
            }
        }
    }
    virtual void first_upper_on(char c) {
        if ((c >= 'A') && (c <= 'Z')) {
            on_ = &Derives::upper_on;
            this->out(&upper_c, 1);
            this->out(&c, 1);
        } else {
            if ((c >= 'a') && (c <= 'z')) {
                on_ = &Derives::lower_on;
                this->out(&lower_c, 1);
                this->out(&c, 1);
            } else {
                if ((c >= '_') && (c <= '_')) {
                    on_ = &Derives::under_on;
                    this->out(&upper_c, 1);
                    this->out(&c, 1);
                } else {
                    on_ = 0;
                    this->out(&upper_c, 1);
                    this->out(&c, 1);
                }
            }
        }
    }
    virtual void upper_on(char c) {
        if ((c >= 'A') && (c <= 'Z')) {
            this->out(&c, 1);
        } else {
            if ((c >= 'a') && (c <= 'z')) {
                on_ = &Derives::lower_on;
                this->out(&c, 1);
            } else {
                if ((c >= '_') && (c <= '_')) {
                    on_ = &Derives::under_on;
                    this->out(&c, 1);
                } else {
                    on_ = 0;
                    this->out(&c, 1);
                }
            }
        }
    }
};

} // namespace tounder 
} // namespace console 
} // namespace app 
} // namespace xos 

#endif // _XOS_APP_CONSOLE_TOUNDER_MAIN_HPP 
