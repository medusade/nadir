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
///   File: string_base.hpp
///
/// Author: $author$
///   Date: 9/7/2017
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_BASE_STRING_BASE_HPP
#define _XOS_BASE_STRING_BASE_HPP

#include "xos/base/chars.hpp"
#include "xos/base/append.hpp"

namespace xos {

///////////////////////////////////////////////////////////////////////
///  Class: string_implementt
///////////////////////////////////////////////////////////////////////
template
<typename TChar = char,
 typename TEndChar = TChar, TEndChar VEndChar = 0,
 class TChars = charst<TChar, TEndChar, VEndChar, implement_base>,
 class TImplements = TChars>

class _EXPORT_CLASS string_implementt: virtual public TImplements {
public:
    typedef TImplements Implements;
    typedef string_implementt Derives;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual Derives& assignl(const char_t* chars, ...) {
        va_list va; va_start(va, chars);
        this->assignv(chars, va);
        va_end(va);
        return *this;
    }
    virtual Derives& assignv(const char_t* chars, va_list va) {
        this->clear();
        this->appendv(chars, va);
        return *this;
    }
    virtual Derives& assign_signed(signed from) {
        this->clear();
        this->append_signed(from);
        return *this;
    }
    virtual Derives& assign_unsigned(unsigned from) {
        this->clear();
        this->append_unsigned(from);
        return *this;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual Derives& appendl(const char_t* chars, ...) {
        va_list va; va_start(va, chars);
        this->appendv(chars, va);
        va_end(va);
        return *this;
    }
    virtual Derives& appendv(const char_t* chars, va_list va) {
        if ((chars)) {
            do { this->append(chars);
            } while ((chars = va_arg(va, const char_t*)));
        }
        return *this;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual char_t* buffer(size_t& size, size_t& length) const {
        size = this->size();
        length = this->length();
        return this->buffer();
    }
    virtual char_t* buffer(size_t& size) const {
        size = this->size();
        return this->buffer();
    }
    virtual const char_t* has_chars(size_t& length) const {
        if (0 < (length = this->length())) {
            return this->chars();
        }
        return 0;
    }
    virtual const char_t* chars(size_t& length) const {
        length = this->length();
        return this->chars();
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};

} // namespace xos

namespace xos {
namespace nadir {

///////////////////////////////////////////////////////////////////////
///  Class: string_baset
///////////////////////////////////////////////////////////////////////
template
<typename TChar = char,
 typename TEndChar = TChar, TEndChar VEndChar = 0,
 class TChars = charst<TChar, TEndChar, VEndChar, implement_base>,
 class TString = string_implementt<TChar, TEndChar, VEndChar, TChars>,
 class TBase = base, size_t VDefaultSize = 128,
 class TImplements = TString, class TExtends = TBase>

class _EXPORT_CLASS string_baset
: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;
    typedef string_baset Derives;

    typedef TChars chars_t;
    typedef TChar char_t;
    typedef TEndChar end_char_t;
    enum { end_char = VEndChar };
    enum { default_size = VDefaultSize };

    typedef typename TChars::from_signed from_signed;
    typedef typename TChars::from_unsigned from_unsigned;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    string_baset(const char_t* chars, size_t length) {
        _construct();
        append(chars, length);
    }
    string_baset(const char_t* chars) {
        _construct();
        append(chars);
    }
    string_baset(const Derives& copy) {
        _construct();
        append(copy.c_str(), copy.length());
    }
    string_baset(const from_signed& from) {
        _construct();
        this->append_signed(from);
    }
    string_baset(const from_unsigned& from) {
        _construct();
        this->append_unsigned(from);
    }
    virtual ~string_baset(){
        if ((_writeBuffer != _defaultBuffer)) {
            if ((_writeBuffer) && (_freeBuffer)) {
                _free_buffer(_writeBuffer);
            }
        }
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual Derives& append_signed(signed from) {
        append_signedt<Derives, TChar, signed>(*this, from);
        return *this;
    }
    virtual Derives& append_unsigned(unsigned from) {
        append_unsignedt<Derives, TChar, unsigned>(*this, from);
        return *this;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    Derives& assign(const Derives& copy) {
        clear();
        return append(copy.c_str(), copy.length());
    }
    Derives& assign(const char_t* chars, size_t length) {
        clear();
        return append(chars, length);
    }
    Derives& assign(const char_t* chars) {
        clear();
        return append(chars);
    }
    Derives& append(const Derives& copy) {
        return append(copy.c_str(), copy.length());
    }
    Derives& append(const char_t* chars, size_t length) {
        if ((chars) && (0 < length)) {
            size_t newSize = (_tell+length);
            if (_size <= newSize) {
                if (_fixedSize)
                    length = _size-_tell;
                else
                if (!(_adjust_to_size(_new_size_of(newSize))))
                    length = 0;
            }
            if (length) {
                _copy_to(_writeBuffer+_tell, chars, length);
                if ((_tell += length) > _length)
                if ((_length = _tell) < _size)
                    _writeBuffer[_tell] = ((char_t)end_char);
            }
        }
        return *this;
    }
    Derives& append(const char_t* chars) {
        return append(chars, _length_of(chars));
    }
    Derives& clear() {
        if ((_writeBuffer)) {
            if (_size > (_length = (_tell = 0))) {
                _writeBuffer[_tell] = ((char_t)end_char);
            }
        }
        return *this;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int compare(const Derives& to) const {
        return compare(to.c_str(), to.length());
    }
    virtual int compare_cased(const Derives& to) const {
        return compare_cased(to.c_str(), to.length());
    }
    virtual int compare_uncased(const Derives& to) const {
        return compare_uncased(to.c_str(), to.length());
    }
    virtual int compare(const char_t* toChars, size_t toLength) const {
        return Implements::compare
        (this->chars(), this->length(), toChars, toLength);
    }
    virtual int compare_cased(const char_t* toChars, size_t toLength) const {
        return Implements::compare_cased
        (this->chars(), this->length(), toChars, toLength);
    }
    virtual int compare_uncased(const char_t* toChars, size_t toLength) const {
        return Implements::compare_uncased
        (this->chars(), this->length(), toChars, toLength);
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool operator < (const Derives& to) const {
        int unequal = compare(to.c_str(), to.length());
        return (unequal < 0);
    }
    virtual bool operator > (const Derives& to) const {
        int unequal = compare(to.c_str(), to.length());
        return (unequal > 0);
    }
    virtual bool operator <= (const Derives& to) const {
        int unequal = compare(to.c_str(), to.length());
        return (unequal <= 0);
    }
    virtual bool operator >= (const Derives& to) const {
        int unequal = compare(to.c_str(), to.length());
        return (unequal >= 0);
    }
    virtual bool operator == (const Derives& to) const {
        int unequal = compare(to.c_str(), to.length());
        return (unequal == 0);
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    using Implements::buffer;
    virtual char_t* buffer() const {
        return this->str();
    }
    using Implements::chars;
    virtual const char_t* chars() const {
        return this->c_str();
    }
    virtual char_t* str() const {
        return _writeBuffer;
    }
    virtual const char_t* c_str() const {
        return _readBuffer;
    }
    virtual size_t length() const {
        return _length;
    }
    virtual size_t size() const {
        return _size;
    }
protected:
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual void _construct() {
        _freeBuffer = _fixedSize = false;
        _size = default_size;
        _length = _tell = 0;
        _readBuffer = _writeBuffer = _defaultBuffer;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual size_t _adjust_size(size_t newSize) {
        if (_writeBuffer) {
            if (_size < (newSize)) {
                if (!_fixedSize) {
                    if (0 < (_adjust_to_size(_new_size_of(newSize)))) {
                        return _size;
                    }
                }
            } else {
                return _size;
            }
        }
        return 0;
    }
    virtual size_t _adjust_to_size(size_t size) {
        if (_writeBuffer) {
            if (size > _size) {
                bool freeBuffer = false;
                char_t* buffer = 0;

                if (!(freeBuffer = _freeBuffer)) {
                    _freeBuffer = true;
                }
                if ((buffer = _alloc_buffer(size))) {
                    if (_length > 0) {
                        _copy_to(buffer, _writeBuffer, _length);
                    }
                    if ((_writeBuffer != _defaultBuffer) && (freeBuffer)) {
                        _free_buffer(_writeBuffer);
                    }
                    _readBuffer = _writeBuffer = buffer;
                    _size = size;
                    return _size;
                } else {
                    _freeBuffer = freeBuffer;
                }
            } else {
                return _size;
            }
        }
        return 0;
    }
    virtual size_t _new_size_of(size_t size) const {
        // Lets increase the buffer size by default buffer
        // sized chunks. Note the desired new size is always
        // needed size + 1. The size in chunks is calculated
        // as (new size + (chunk size - 1)) / chunk size.
        // since new size = needed size + 1 then we have
        // chunks = (needed size + chunk size) / chunk size.
        // Finally we need bytes which is chunks * chunk size
        // which can be reduced to
        // ((needed size / chunk size) + 1) * chunk size
        //
        return ((size / default_size) + 1) * default_size;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual size_t _copy_to(char_t* to, const char_t* from, size_t size) const {
        size_t length = 0;

        for (length = size; size; --size) {
            (*to++) = (*from++);
        }
        return length;
    }
    virtual size_t _length_of(const char_t* chars) const {
        const char_t endChar(((char_t)end_char));
        size_t length = 0;

        for (length = 0; ((*chars) != endChar); chars++) {
            length++;
        }
        return length;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual char_t* _alloc_buffer(size_t size) const {
        char_t* chars = new char_t[size];
        return chars;
    }
    virtual void _free_buffer(char_t* buffer) const {
        delete[] buffer;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    bool _freeBuffer, _fixedSize;
    size_t _size, _length, _tell;
    const char_t* _readBuffer;
    char_t* _writeBuffer;
    char_t _defaultBuffer[default_size];
};

typedef string_baset<char, char> string_base;
typedef string_baset<tchar_t, tchar_t> tstring_base;
typedef string_baset<wchar_t, wchar_t> wstring_base;

} // namespace nadir
} // namespace xos

#include <sstream>
#include <string>

namespace xos {
namespace std {

///////////////////////////////////////////////////////////////////////
///  Class: string_baset
///////////////////////////////////////////////////////////////////////
template
<typename TChar = char,
 typename TEndChar = TChar, TEndChar VEndChar = 0,
 class TChars = charst<TChar, TEndChar, VEndChar, implement_base>,
 class TString = string_implementt<TChar, TEndChar, VEndChar, TChars>,
 class TSStream = ::std::basic_stringstream<TChar>,
 class TBase = ::std::basic_string<TChar>,
 class TImplements = TChars, class TExtends = TBase>

class _EXPORT_CLASS string_baset
: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;
    typedef string_baset Derives;

    typedef TSStream sstream_t;
    typedef TChars chars_t;
    typedef TChar char_t;
    typedef TEndChar end_char_t;
    enum { end_char = VEndChar };

    typedef typename TChars::from_signed from_signed;
    typedef typename TChars::from_unsigned from_unsigned;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    string_baset(const char_t* chars, size_t length) {
        this->append(chars, length);
    }
    string_baset(const char_t* chars) {
        this->append(chars);
    }
    string_baset(const from_signed& from) {
        this->append_signed(from);
    }
    string_baset(const from_unsigned& from) {
        this->append_unsigned(from);
    }
    string_baset(const Derives& copy) {
        this->append(copy.c_str(), copy.length());
    }
    string_baset() {
    }
    virtual ~string_baset(){
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual Derives& append_signed(signed from) {
        sstream_t ss; ss << from;
        this->append(ss.str());
        return *this;
    }
    virtual Derives& append_unsigned(unsigned from) {
        sstream_t ss; ss << from;
        this->append(ss.str());
        return *this;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual signed to_signed() const {
        sstream_t ss(*this);
        signed to = 0;
        ss >> to;
        return to;
    }
    virtual unsigned to_unsigned() const {
        sstream_t ss(*this);
        unsigned to = 0;
        ss >> to;
        return to;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual char_t* buffer() const {
        return this->str();
    }
    virtual const char_t* chars() const {
        return this->c_str();
    }
    virtual char_t* str() const {
        return 0;
    }
    virtual size_t size() const {
        return 0;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};

typedef string_baset<char, char> string_base;
typedef string_baset<tchar_t, tchar_t> tstring_base;
typedef string_baset<wchar_t, wchar_t> wstring_base;

} // namespace std
} // namespace xos

namespace xos {

#if defined(USE_XOS_NADIR_STRING)
namespace stringns = nadir;
#else // defined(USE_XOS_NADIR_STRING)
namespace stringns = std;
#endif // defined(USE_XOS_NADIR_STRING)

typedef stringns::string_base string_base;
typedef stringns::tstring_base tstring_base;
typedef stringns::wstring_base wstring_base;

} // namespace xos

#endif // _XOS_BASE_STRING_BASE_HPP
