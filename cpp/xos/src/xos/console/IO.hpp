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
///   File: IO.hpp
///
/// Author: $author$
///   Date: 8/5/2017
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_CONSOLE_IO_HPP
#define _XOS_CONSOLE_IO_HPP

#include "xos/base/Base.hpp"

namespace xos {
namespace console {

typedef ImplementBase IOTImplements;
///////////////////////////////////////////////////////////////////////
///  Class: IOT
///////////////////////////////////////////////////////////////////////
template
<typename TChar = char,
 typename TEndChar = TChar, TEndChar VEndChar = 0,
 class TImplements = IOTImplements>

class _EXPORT_CLASS IOT: virtual public TImplements {
public:
    typedef TImplements Implements;

    typedef TChar char_t;
    typedef TEndChar endchar_t;
    static const TEndChar endchar = VEndChar;
    typedef const char_t* const_chars_t;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t OutLn(const char_t* chars, size_t length) {
        ssize_t count = this->OutLn(this->OutStdOut(), chars, length);
        return count;
    }
    virtual ssize_t OutLn(const char_t* chars) {
        ssize_t count = this->OutLn(this->OutStdOut(), chars);
        return count;
    }
    virtual ssize_t OutLn() {
        ssize_t count = this->OutLn(this->OutStdOut());
        return count;
    }
    virtual ssize_t OutF(const char_t* chars, ...) {
        ssize_t count = 0;
        va_list va;
        va_start(va, chars);
        count = OutFV(chars, va);
        va_end(va);
        return count;
    }
    virtual ssize_t OutFV(const char_t* chars, va_list va) {
        ssize_t count = this->OutFV(this->OutStdOut(), chars, va);
        return count;
    }
    virtual ssize_t OutL(const char_t* chars, ...) {
        ssize_t count = 0;
        va_list va;
        va_start(va, chars);
        count = OutV(chars, va);
        va_end(va);
        return count;
    }
    virtual ssize_t OutV(const char_t* chars, va_list va) {
        ssize_t count = this->OutV(this->OutStdOut(), chars, va);
        return count;
    }
    virtual ssize_t Out(const char_t* chars, size_t length) {
        ssize_t count = this->Out(this->OutStdOut(), chars, length);
        return count;
    }
    virtual ssize_t Out(const char_t* chars) {
        ssize_t count = this->Out(this->OutStdOut(), chars);
        return count;
    }
    virtual ssize_t OutFlush() {
        ssize_t count = this->OutFlush(this->OutStdOut());
        return count;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t ErrLn(const char_t* chars, size_t length) {
        ssize_t count = this->OutLn(this->OutStdErr(), chars, length);
        return count;
    }
    virtual ssize_t ErrLn(const char_t* chars) {
        ssize_t count = this->OutLn(this->OutStdErr(), chars);
        return count;
    }
    virtual ssize_t ErrLn() {
        ssize_t count = this->OutLn(this->OutStdErr());
        return count;
    }
    virtual ssize_t ErrF(const char_t* chars, ...) {
        ssize_t count = 0;
        va_list va;
        va_start(va, chars);
        count = ErrFV(chars, va);
        va_end(va);
        return count;
    }
    virtual ssize_t ErrFV(const char_t* chars, va_list va) {
        ssize_t count = this->OutFV(this->OutStdErr(), chars, va);
        return count;
    }
    virtual ssize_t ErrL(const char_t* chars, ...) {
        ssize_t count = 0;
        va_list va;
        va_start(va, chars);
        count = ErrV(chars, va);
        va_end(va);
        return count;
    }
    virtual ssize_t ErrV(const char_t* chars, va_list va) {
        ssize_t count = this->OutV(this->OutStdErr(), chars, va);
        return count;
    }
    virtual ssize_t Err(const char_t* chars, size_t length) {
        ssize_t count = this->Out(this->OutStdErr(), chars, length);
        return count;
    }
    virtual ssize_t Err(const char_t* chars) {
        ssize_t count = this->Out(this->OutStdErr(), chars);
        return count;
    }
    virtual ssize_t ErrFlush() {
        ssize_t count = this->OutFlush(this->OutStdErr());
        return count;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t InLn(char_t* chars, size_t size) {
        ssize_t count = this->InLn(this->InStdIn(), chars, size);
        return count;
    }
    virtual ssize_t InLn() {
        ssize_t count = this->InLn(this->InStdIn());
        return count;
    }
    virtual ssize_t InF(char_t* chars, ...) {
        ssize_t count = 0;
        va_list va;
        va_start(va, chars);
        count = InFV(chars, va);
        va_end(va);
        return count;
    }
    virtual ssize_t InFV(char_t* chars, va_list va) {
        ssize_t count = this->InFV(this->InStdIn(), chars, va);
        return count;
    }
    virtual ssize_t In(char_t* chars, size_t size) {
        ssize_t count = this->In(this->InStdIn(), chars, size);
        return count;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t OutF(FILE* out, const char_t* chars, ...) {
        ssize_t count = 0;
        va_list va;
        va_start(va, chars);
        count = OutFV(out, chars, va);
        va_end(va);
        return count;
    }
    virtual ssize_t OutFV(FILE* out, const char_t* chars, va_list va) {
        ssize_t count = 0;
        return count;
    }
    virtual ssize_t OutL(FILE* out, const char_t* chars, ...) {
        ssize_t count = 0;
        va_list va;
        va_start(va, chars);
        count = OutV(out, chars, va);
        va_end(va);
        return count;
    }
    virtual ssize_t OutV(FILE* out, const char_t* chars, va_list va) {
        ssize_t count = 0, amount = 0;
        for (count = 0; chars; count += amount) {
            if (0 > (amount = this->Out(out, chars))) {
                return amount;
            }
            chars = va_arg(va, const_chars_t);
        }
        return count;
    }
    virtual ssize_t Out(FILE* out, const char_t* chars) {
        ssize_t count = 0;
        if ((out) && (chars) && (chars[0] != endchar)) {
            ssize_t amount = 0;
            char_t c = endchar;
            for (c = *(chars); c != endchar; c = *(++chars)) {
                if (0 < (amount = ::fwrite(&c, sizeof(char_t), 1, out))) {
                    count += amount;
                } else {
                    return amount;
                }
            }
        }
        return count;
    }
    virtual ssize_t Out(FILE* out, const char_t* chars, size_t length) {
        ssize_t count = 0;
        if ((out) && (chars) && (length)) {
            ssize_t amount = 0;
            if (0 < (amount = ::fwrite(chars, sizeof(char_t), length, out))) {
                count += amount;
            } else {
                return amount;
            }
        }
        return count;
    }
    virtual ssize_t OutLn(FILE* out, const char_t* chars, size_t length) {
        ssize_t count = 0;
        if (0 <= (count = this->Out(out, chars, length))) {
            ssize_t amount = 0;
            if (0 < (amount = this->OutLn(out))) {
                count += amount;
            } else {
                return amount;
            }
        }
        return count;
    }
    virtual ssize_t OutLn(FILE* out, const char_t* chars) {
        ssize_t count = 0;
        if (0 <= (count = this->Out(out, chars))) {
            ssize_t amount = 0;
            if (0 < (amount = this->OutLn(out))) {
                count += amount;
            } else {
                return amount;
            }
        }
        return count;
    }
    virtual ssize_t OutLn(FILE* out) {
        char_t ln = ((char_t)'\n');
        ssize_t count = Out(out, &ln, 1);
        return count;
    }
    virtual ssize_t OutFlush(FILE* out) {
        ssize_t count = 0;
        if ((out)) {
            int err = 0;
            err = ::fflush(out);
        }
        return count;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t InF(FILE* in, char_t* chars, ...) {
        ssize_t count = 0;
        va_list va;
        va_start(va, chars);
        count = InFV(in, chars, va);
        va_end(va);
        return count;
    }
    virtual ssize_t InFV(FILE* in, char_t* chars, va_list va) {
        ssize_t count = 0;
        return count;
    }
    virtual ssize_t InLn(FILE* in, char_t* chars, size_t size) {
        ssize_t count = 0;
        return count;
    }
    virtual ssize_t InLn(FILE* in) {
        ssize_t count = 0;
        return count;
    }
    virtual ssize_t In(FILE* in, char_t* chars, size_t size) {
        ssize_t count = 0;
        if ((in) && (chars) && (size)) {
            ssize_t amount = 0;
            if ((amount = ::fread(chars, sizeof(char_t), size, in))) {
                count += amount;
            } else {
                return amount;
            }
        }
        return count;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual FILE* OutStdErr() {
        return this->StdErr();
    }
    virtual FILE* OutStdOut() {
        return this->StdOut();
    }
    virtual FILE* InStdIn() {
        return this->StdIn();
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual FILE* StdErr() const {
        return stderr;
    }
    virtual FILE* StdOut() const {
        return stdout;
    }
    virtual FILE* StdIn() const {
        return stdin;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};
typedef IOT<char, char, 0> IOImplements;
///////////////////////////////////////////////////////////////////////
///  Class: IO
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS IO: virtual public IOImplements {
public:
    typedef IOImplements Implements;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t OutFV(FILE* out, const char_t* chars, va_list va) {
        ssize_t count = 0;
        if ((out) && (chars) && (chars[0])) {
            count = ::vfprintf(out, chars, va);
        }
        return count;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};
typedef IOT<tchar_t, tchar_t, 0> TIO;
typedef IOT<wchar_t, wchar_t, 0> WIO;

} // namespace console 
} // namespace xos 

#endif // _XOS_CONSOLE_IO_HPP 
