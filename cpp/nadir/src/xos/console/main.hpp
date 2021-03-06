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
///   Date: 9/9/2017
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_CONSOLE_MAIN_HPP
#define _XOS_CONSOLE_MAIN_HPP

#include "xos/console/main_exception.hpp"
#include "xos/console/main_arg.hpp"
#include "xos/console/io.hpp"

namespace xos {
namespace console {

///////////////////////////////////////////////////////////////////////
///  Class: maint
///////////////////////////////////////////////////////////////////////
template
<typename TChar = char,
 typename TEndChar = TChar, TEndChar VEndChar = 0,
 class TArg = main_argt<TChar, TEndChar, VEndChar>,
 class TIo = iot<TChar, TEndChar, VEndChar>,
 class TMain = base,
 class TArgImplements = TArg, class TImplements = TIo, class TExtends = TMain>

class _EXPORT_CLASS maint
: virtual public TArgImplements, virtual public TImplements, public TExtends {
public:
    typedef TArgImplements ArgImplements;
    typedef TImplements Implements;
    typedef TExtends Extends;
    typedef maint Derives;

    typedef main_exception exception;
    typedef TChar char_t;
    typedef TEndChar end_char_t;
    enum { end_char = VEndChar };

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    maint(): did_main_(false), did_run_(false) {
        if ((the_main())) {
            main_exception e(main_already_exists);
            throw (e);
        } else {
            the_main() = this;
        }
    }
    virtual ~maint() {
        if ((this != the_main())) {
            if ((the_main())) {
                main_exception e(main_different_exists);
                throw (e);
            } else {
                main_exception e(main_doesnt_exist);
                throw (e);
            }
        } else {
            the_main() = 0;
        }
    }

protected:
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int operator()(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_main(argc, argv, env))) {
            int err2 = 0;
            if (!(did_main())) {
                err = main(argc, argv, env);
            }
            if ((err2 = after_main(argc, argv, env)) && (!err)) {
                err = err2;
            }
        }
        return err;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int main(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_run(argc, argv, env))) {
            int err2 = 0;
            if (!(did_run())) {
                err = run(argc, argv, env);
            }
            if ((err2 = after_run(argc, argv, env)) && (!err)) {
                err = err2;
            }
        }
        return err;
    }
    virtual int before_main(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_main(int argc, char_t** argv, char_t** env) {
        int err = 0;
        set_did_main();
        return err;
    }

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
        set_did_run();
        return err;
    }

public:
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    static int the_main(int argc, char_t** argv, char_t** env) {
        int err = 1;
        Derives* main = 0;
        if ((main = the_main())) {
            err = (*main)(argc, argv, env);
        }
        return err;
    }
protected:
    static Derives*& the_main() {
        static Derives* main = 0;
        return main;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool set_did_main(bool to = true) {
        return did_main_ = to;
    }
    virtual bool did_main() const {
        return did_main_;
    }
    virtual bool set_did_run(bool to = true) {
        return did_run_ = to;
    }
    virtual bool did_run() const {
        return did_run_;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    using Implements::out;
    virtual ssize_t out(FILE* f, const char_t* out, ssize_t length = -1) {
        ssize_t count = 0;
        if ((out) && (f)) {
            ssize_t amount;
            if (0 <= (length)) {
                if (0 <= (amount = fwrite(out, sizeof(char_t), length, f))) {
                    count += amount;
                } else {
                    count = amount;
                }
            } else {
                for (; *out; ++out) {
                    if (0 <= (amount = fwrite(out, sizeof(char_t), 1, f))) {
                        count += amount;
                    } else {
                        count = amount;
                        break;
                    }
                }
            }
        }
        return count;
    }
    using Implements::out_flush;
    virtual ssize_t out_flush(FILE* f) {
        ssize_t count = 0;
        if ((f)) {
            fflush(f);
        }
        return count;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    using Implements::in;
    virtual ssize_t in(FILE* f, char_t* in, size_t size) {
        ssize_t count = 0;
        if ((in) && (f) && (0 < (size))) {
            ssize_t amount = 0;
            if (0 <= (amount = fread(in, sizeof(char_t), size, f))) {
                count += amount;
            } else {
                count = amount;
            }
        }
        return count;
    }
    virtual ssize_t in_fill(FILE* f) {
        ssize_t count = 0;
        return count;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual FILE* std_out() const {
        return stdout;
    }
    virtual FILE* std_err() const {
        return stderr;
    }
    virtual FILE* std_in() const {
        return stdin;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    bool did_main_, did_run_;
};

typedef maint<char> main_extends;
///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS main: public main_extends {
public:
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t outfv(FILE* f, const char_t* format, va_list va) {
        ssize_t count = 0;
        count = vfprintf(f, format, va);
        return count;
    }
    virtual ssize_t infv(FILE* f, const char_t* format, va_list va) {
        ssize_t count = 0;
        count = vfscanf(f, format, va);
        return count;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};

} // namespace console
} // namespace xos 

#endif // _XOS_CONSOLE_MAIN_HPP 
