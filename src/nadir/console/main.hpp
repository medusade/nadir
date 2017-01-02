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
///   Date: 12/31/2016
///////////////////////////////////////////////////////////////////////
#ifndef _NADIR_CONSOLE_MAIN_HPP
#define _NADIR_CONSOLE_MAIN_HPP

#include "nadir/base/locked.hpp"

namespace nadir {
namespace console {

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
enum main_exception_which {
    main_already_exists,
    main_doesnt_exist
};
class _EXPORT_CLASS main_exception {
public:
    main_exception(main_exception_which which): which_(which) {}
    virtual ~main_exception() {}
    virtual main_exception_which which() const { return which_; }
protected:
    main_exception_which which_;
};

typedef locked maint_implements;
typedef base maint_extends;
///////////////////////////////////////////////////////////////////////
///  Class: maint
///////////////////////////////////////////////////////////////////////
template
<typename TChar = char, typename TEndChar = TChar, TEndChar VEndChar = 0,
 class TImplements = maint_implements, class TExtends = maint_extends>

class _EXPORT_CLASS maint: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;

    typedef TChar char_t;
    typedef TEndChar end_char_t;
    enum { end_char = VEndChar };

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    maint(): did_run_(false) {
        if ((the_main())) {
            main_exception e(main_already_exists);
            throw (e);
        } else {
            the_main() = this;
        }
    }
    virtual ~maint() {
        if ((this != the_main())) {
            main_exception e(main_doesnt_exist);
            throw (e);
        } else {
            the_main() = 0;
        }
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    static int main(int argc, char_t** argv, char_t** env) {
        int err = 1;
        maint *main = 0;
        if ((main = the_main())) {
            if (!(err = main->before_run(argc, argv, env))) {
                int err2 = 0;
                err = main->run(argc, argv, env);
                if ((err2 = main->after_run(argc, argv, env)) && (!err)) {
                    err = err2;
                }
            }
        }
        return err;
    }

protected:
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int before_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }

protected:
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    static maint*& the_main() {
        static maint* main = 0;
        return main;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    bool did_run_;
};
typedef maint<char> main;

} // namespace console 
} // namespace nadir 

#endif // _NADIR_CONSOLE_MAIN_HPP 
