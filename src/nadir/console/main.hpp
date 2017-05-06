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

#include "nadir/console/main_exception.hpp"
#include "nadir/console/io.hpp"
//#include "nadir/base/locked.hpp"

namespace nadir {
namespace console {

//typedef locked maint_implements;
typedef base maint_extends;
///////////////////////////////////////////////////////////////////////
///  Class: maint
///////////////////////////////////////////////////////////////////////
template
<typename TChar = char, typename TEndChar = TChar, TEndChar VEndChar = 0,
 class TImplements = iot<TChar, TEndChar, VEndChar>/*maint_implements*/,
 class TExtends = maint_extends>

class _EXPORT_CLASS maint: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;

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
            main_exception e(main_doesnt_exist);
            throw (e);
        } else {
            the_main() = 0;
        }
    }

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

protected:
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

/*public:
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t outf(const char_t* format, ...) {
        ssize_t count = 0;
        va_list va;
        va_start(va, format);
        if ((format))
        count = outfv(format, va);
        va_end(va);
        return count;
    }
    virtual ssize_t outfv(const char_t* format, va_list va) {
        ssize_t count = outfv(out_std_out(), format, va);
        return count;
    }
    virtual ssize_t outlnl(const char_t* out, ...) {
        ssize_t count = 0, amount = 0;
        va_list va;
        va_start(va, out);
        if ((out)) {
            count = outlv(out, va);
        }
        va_end(va);
        if (0 <= (count)) {
            if (0 <= (amount = outln())) {
                count += amount;
            } else {
                count = amount;
            }
        }
        return count;
    }
    virtual ssize_t outln(const char_t* out, ssize_t length = -1) {
        ssize_t count = this->outln(out_std_out(), out, length);
        return count;
    }
    virtual ssize_t outln() {
        ssize_t count = this->outln(out_std_out());
        return count;
    }
    virtual ssize_t outl(const char_t* out, ...) {
        ssize_t count = 0;
        va_list va;
        va_start(va, out);
        if ((out)) {
            count = outlv(out, va);
        }
        va_end(va);
        return count;
    }
    virtual ssize_t outlv(const char_t* out, va_list va) {
        ssize_t count = outlv(out_std_out(), out, va);
        return count;
    }
    virtual ssize_t out(const char_t* out, ssize_t length = -1) {
        ssize_t count = this->out(out_std_out(), out, length);
        return count;
    }
    virtual ssize_t out_flush() {
        ssize_t count = out_flush(out_std_out());
        return count;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t errf(const char_t* format, ...) {
        ssize_t count = 0;
        va_list va;
        va_start(va, format);
        if ((format))
        count = errfv(format, va);
        va_end(va);
        return count;
    }
    virtual ssize_t errfv(const char_t* format, va_list va) {
        ssize_t count = outfv(out_std_err(), format, va);
        return count;
    }
    virtual ssize_t errlnl(const char_t* out, ...) {
        ssize_t count = 0, amount = 0;
        va_list va;
        va_start(va, out);
        if ((out)) {
            count = errlv(out, va);
        }
        va_end(va);
        if (0 <= (count)) {
            if (0 <= (amount = errln())) {
                count += amount;
            } else {
                count = amount;
            }
        }
        return count;
    }
    virtual ssize_t errln(const char_t* out, ssize_t length = -1) {
        ssize_t count = this->outln(out_std_err(), out, length);
        return count;
    }
    virtual ssize_t errln() {
        ssize_t count = this->outln(out_std_err());
        return count;
    }
    virtual ssize_t errl(const char_t* out, ...) {
        ssize_t count = 0;
        va_list va;
        va_start(va, out);
        if ((out))
        count = errlv(out, va);
        va_end(va);
        return count;
    }
    virtual ssize_t errlv(const char_t* out, va_list va) {
        ssize_t count = outlv(out_std_err(), out, va);
        return count;
    }
    virtual ssize_t err(const char_t* out, ssize_t length = -1) {
        ssize_t count = this->out(out_std_err(), out, length);
        return count;
    }
    virtual ssize_t err_flush() {
        ssize_t count = out_flush(out_std_err());
        return count;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t inf(const char_t* format, ...) {
        ssize_t count = 0;
        va_list va;
        va_start(va, format);
        if ((format))
        count = infv(format, va);
        va_end(va);
        return count;
    }
    virtual ssize_t infv(const char_t* format, va_list va) {
        ssize_t count = infv(in_std_in(), format, va);
        return count;
    }
    virtual ssize_t inln(char_t* in, size_t size) {
        ssize_t count = this->inln(in_std_in(), in, size);
        return count;
    }
    virtual ssize_t in(char_t* in, size_t size) {
        ssize_t count = this->in(in_std_in(), in, size);
        return count;
    }
    virtual ssize_t in_fill() {
        ssize_t count = this->in_fill(in_std_in());
        return count;
    }*/

protected:
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    /*virtual ssize_t outfv(FILE* f, const char_t* format, va_list va) {
        ssize_t count = 0;
        return count;
    }
    virtual ssize_t outlv(FILE* f, const char_t* out, va_list va) {
        ssize_t count = 0;
        ssize_t amount = 0;
        for (count = 0; out; count += amount) {
            if (0 > (amount = this->out(f, out)))
                return amount;
            out = va_arg(va, const char_t*);
        }
        return count;
    }
    virtual ssize_t outln(FILE* f, const char_t* out, ssize_t length = -1) {
        ssize_t count = 0;
        ssize_t amount;
        if (0 <= (amount = this->out(f, out, length))) {
            count += amount;
            if (0 <= (amount = this->outln(f))) {
                count += amount;
            }
        }
        return count;
    }
    virtual ssize_t outln(FILE* f) {
        const char_t ln = ((char_t)'\n');
        ssize_t count = out(f, &ln, 1);
        return count;
    }*/
    using Implements::out;
    virtual ssize_t out(FILE* f, const char_t* out, ssize_t length = -1) {
        ssize_t count = 0;
        if ((out) && (f)) {
            ssize_t amount;
            if (0 <= (length)) {
                if (0 < (amount = fwrite(out, sizeof(char_t), length, f)))
                    count += amount;
            } else {
                for (; *out; ++out) {
                    if (0 < (amount = fwrite(out, sizeof(char_t), 1, f)))
                        count += amount;
                }
            }
        }
        return count;
    }
    virtual ssize_t out_flush(FILE* f) {
        ssize_t count = 0;
        if ((f)) {
            fflush(f);
        }
        return count;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    /*virtual ssize_t infv(FILE* f, const char_t* format, va_list va) {
        ssize_t count = 0;
        return count;
    }
    virtual ssize_t inln(FILE* f, char_t* in, size_t size) {
        ssize_t count = 0;
        if ((in) && (f) && (0 < (size))) {
            const char_t ln = ((char_t)'\n');
            char_t c;
            ssize_t amount;
            while (0 < (size)) {
                if (0 > (amount = this->in(f, &c, 1))) {
                    count = amount;
                } else {
                    --size;
                    if (ln != c) {
                        *in = c;
                        ++in;
                        continue;
                    }
                }
                break;
            }
        }
        return count;
    }*/
    virtual ssize_t in(FILE* f, char_t* in, size_t size) {
        ssize_t count = 0;
        if ((in) && (f) && (0 < (size))) {
            ssize_t amount;
            if (0 < (amount = fread(in, sizeof(char_t), size, f))) {
                count += amount;
            }
        }
        return count;
    }
    /*virtual ssize_t in_fill(FILE* f) {
        ssize_t count = 0;
        return count;
    }*/

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool set_did_main(bool to = true) {
        return did_main_ = to;
    }
    virtual bool did_main() const {
        return did_main_;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool set_did_run(bool to = true) {
        return did_run_ = to;
    }
    virtual bool did_run() const {
        return did_run_;
    }

    /*///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual FILE* out_std_out() {
        return std_out();
    }
    virtual FILE* out_std_err() {
        return std_err();
    }
    virtual FILE* in_std_in() {
        return std_in();
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
    }*/

public:
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    static maint* get_the_main() {
        return the_main();
    }
protected:
    static maint*& the_main() {
        static maint* main = 0;
        return main;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    bool did_main_, did_run_;
};

typedef maint<char> main;
///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS main_extend: public main {
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
} // namespace nadir 

#endif // _NADIR_CONSOLE_MAIN_HPP 
