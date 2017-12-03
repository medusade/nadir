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
///   File: StringBase.hpp
///
/// Author: $author$
///   Date: 7/29/2017
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_BASE_STD_STRINGBASE_HPP
#define _XOS_BASE_STD_STRINGBASE_HPP

#include "xos/base/CharsBase.hpp"

#include <sstream>
#include <string>

namespace xos {
namespace std {

///////////////////////////////////////////////////////////////////////
///  Class: StringBaseT
///////////////////////////////////////////////////////////////////////
template
<typename TChar = char,
 typename TEnd = TChar, TEnd VEnd = 0,
 class TChars = CharsBaseT<TChar, TEnd, VEnd>,
 class TSStream = ::std::basic_stringstream<TChar>,
 class TString = ::std::basic_string<TChar>,
 class TImplements = TChars, class TExtends = TString>

class _EXPORT_CLASS StringBaseT: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;

    typedef TSStream sstream_t;
    typedef TString string_t;
    typedef TChar char_t;
    typedef TEnd end_t;
    static const end_t endof = VEnd;

    typedef typename TChars::from_signed from_signed;
    typedef typename TChars::from_unsigned from_unsigned;

    ///////////////////////////////////////////////////////////////////////
    /// Constructor: StringBaseT
    ///////////////////////////////////////////////////////////////////////
    StringBaseT(const char_t* chars, size_t length) {
        if ((chars) && (length)) {
            this->append(chars, length);
        }
    }
    StringBaseT(const char_t* chars) {
        if ((chars)) {
            this->append(chars);
        }
    }
    StringBaseT(const from_signed& from) {
        this->append_signed(from);
    }
    StringBaseT(const from_unsigned& from) {
        this->append_unsigned(from);
    }
    StringBaseT(const StringBaseT& copy) {
        this->append(copy);
    }
    StringBaseT() {
    }
    virtual ~StringBaseT() {
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual StringBaseT& assignl(const char_t* chars, ...) {
        va_list va; va_start(va, chars);
        assignv(chars, va);
        va_end(va);
        return *this;
    }
    virtual StringBaseT& assignv(const char_t* chars, va_list va) {
        this->clear();
        appendv(chars, va);
        return *this;
    }
    virtual StringBaseT& assign_signed(signed from) {
        this->clear();
        append_signed(from);
        return *this;
    }
    virtual StringBaseT& assign_unsigned(unsigned from) {
        this->clear();
        append_unsigned(from);
        return *this;
    }
    virtual StringBaseT& appendl(const char_t* chars, ...) {
        va_list va; va_start(va, chars);
        appendv(chars, va);
        va_end(va);
        return *this;
    }
    virtual StringBaseT& appendv(const char_t* chars, va_list va) {
        if ((chars)) {
            do { this->append(chars);
            } while ((chars = va_arg(va, const char_t*)));
        }
        return *this;
    }
    virtual StringBaseT& append_signed(signed from) {
        sstream_t ss; ss << from;
        this->append(ss.str());
        return *this;
    }
    virtual StringBaseT& append_unsigned(unsigned from) {
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
    virtual char_t* has_buffer(size_t& size) const {
        size_t siz = 0;
        if ((siz = this->size())) {
            char_t* str = 0;
            if ((str = this->str())) {
                size = siz;
            }
            return str;
        }
        return 0;
    }
    virtual char_t* buffer(size_t& size) const {
        char_t* str = 0;
        if ((str = this->str())) {
            size = this->size();
        }
        return str;
    }
    virtual char_t* buffer() const {
        return this->str();
    }
    virtual const char_t* has_chars(size_t& length) const {
        size_t len = 0;
        if ((len = this->length())) {
            const char_t* c_str = 0;
            if ((c_str = this->c_str())) {
                length = len;
            }
            return c_str;
        }
        return 0;
    }
    virtual const char_t* chars(size_t& length) const {
        const char_t* c_str = 0;
        if ((c_str = this->c_str())) {
            length = this->length();
        }
        return c_str;
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
typedef ::std::basic_stringstream<char> StringStream;
typedef ::std::basic_string<char> StringString;
typedef StringBaseT
<char, char, 0, CharsBase, StringStream, StringString> StringBase;

typedef ::std::basic_stringstream<tchar_t> TStringStream;
typedef ::std::basic_string<tchar_t> TStringString;
typedef StringBaseT
<tchar_t, tchar_t, 0, TCharsBase, TStringStream, TStringString> TStringBase;

typedef ::std::basic_stringstream<wchar_t> WStringStream;
typedef ::std::basic_string<wchar_t> WStringString;
typedef StringBaseT
<wchar_t, wchar_t, 0, WCharsBase, WStringStream, WStringString> WStringBase;

typedef ::std::basic_stringstream<byte_t> ByteStringStream;
typedef ::std::basic_string<byte_t> ByteStringString;
typedef StringBaseT
<byte_t, byte_t, 0, BytesBase, 
 ByteStringStream, ByteStringString> ByteStringBase;

} // namespace std
} // namespace xos 

#endif // _XOS_BASE_STD_STRINGBASE_HPP 
