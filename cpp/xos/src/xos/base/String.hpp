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
///   File: String.hpp
///
/// Author: $author$
///   Date: 8/11/2017
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_BASE_STRING_HPP
#define _XOS_BASE_STRING_HPP

#include "xos/base/std/StringBase.hpp"
#include "xos/base/StringBase.hpp"

namespace xos {

#if defined(USE_XOS_BASE_STRING)
namespace stringns = base;
#else // defined(USE_XOS_BASE_STRING)
namespace stringns = std;
#endif // defined(USE_XOS_BASE_STRING)

///////////////////////////////////////////////////////////////////////
///  Class: StringT
///////////////////////////////////////////////////////////////////////
template
<typename TChar = char,
 typename TEnd = TChar, TEnd VEnd = 0,
 class TChars = CharsBaseT<TChar, TEnd, VEnd>,
 class TString = StringBaseT<TChar, TEnd, VEnd, TChars>,
 class TImplements = TChars, class TExtends = TString>

class _EXPORT_CLASS StringT: virtual public TImplements,public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;

    typedef TChar char_t;
    typedef TEnd end_t;
    static const end_t endof = VEnd;

    typedef typename TString::from_signed from_signed;
    typedef typename TString::from_unsigned from_unsigned;

    ///////////////////////////////////////////////////////////////////////
    /// Constructor: StringT
    ///////////////////////////////////////////////////////////////////////
    StringT(const char_t* chars, size_t length): Extends(chars, length) {
    }
    StringT(const char_t* chars): Extends(chars) {
    }
    StringT(const from_signed& from): Extends(from) {
    }
    StringT(const from_unsigned& from): Extends(from) {
    }
    StringT(const StringT& copy): Extends(copy) {
    }
    StringT() {
    }
    virtual ~StringT() {
    }

    ///////////////////////////////////////////////////////////////////////
    /// Function: Assign/Append Signed/Unsigned
    ///////////////////////////////////////////////////////////////////////
    virtual StringT& AssignSigned(signed from) {
        this->assign_signed(from);
        return *this;
    }
    virtual StringT& AssignUnsigned(unsigned from) {
        this->assign_unsigned(from);
        return *this;
    }
    virtual StringT& AppendSigned(signed from) {
        this->append_signed(from);
        return *this;
    }
    virtual StringT& AppendUnsigned(unsigned from) {
        this->append_unsigned(from);
        return *this;
    }

    ///////////////////////////////////////////////////////////////////////
    /// Function: AssignL/V/AppendL/V
    ///////////////////////////////////////////////////////////////////////
    virtual StringT& AssignL(const char_t* chars, ...) {
        va_list va; va_start(va, chars);
        AssignV(chars, va);
        va_end(va);
        return *this;
    }
    virtual StringT& AssignV(const char_t* chars, va_list va) {
        Clear();
        AppendV(chars, va);
        return *this;
    }
    virtual StringT& AppendL(const char_t* chars, ...) {
        va_list va; va_start(va, chars);
        AppendV(chars, va);
        va_end(va);
        return *this;
    }
    virtual StringT& AppendV(const char_t* chars, va_list va) {
        typedef const char_t* chars_t;
        if ((chars)) {
            do { Append(chars);
            } while ((chars = va_arg(va, chars_t)));
        }
        return *this;
    }

    ///////////////////////////////////////////////////////////////////////
    /// Function: Assign/Append/Clear
    ///////////////////////////////////////////////////////////////////////
    virtual StringT& Assign(const Extends& copy) {
        this->Clear();
        this->Append(copy);
        return *this;
    }
    virtual StringT& Assign(const char_t* chars) {
        this->Clear();
        this->Append(chars);
        return *this;
    }
    virtual StringT& Assign(const char_t* chars, size_t length) {
        this->Clear();
        this->Append(chars, length);
        return *this;
    }
    virtual StringT& Append(const Extends& copy) {
        this->append(copy);
        return *this;
    }
    virtual StringT& Append(const char_t* chars) {
        this->append(chars);
        return *this;
    }
    virtual StringT& Append(const char_t* chars, size_t length) {
        this->append(chars, length);
        return *this;
    }
    virtual StringT& Clear() {
        this->clear();
        return *this;
    }

    ///////////////////////////////////////////////////////////////////////
    /// Function: HasChars/Chars/Length
    ///////////////////////////////////////////////////////////////////////
    virtual const char_t* HasChars(size_t& length) const {
        size_t len = 0;
        if ((len = this->Length())) {
            const char_t* chars = 0;
            if ((chars = this->Chars())) {
                length = len;
                return chars;
            }
        }
        return 0;
    }
    virtual const char_t* HasChars() const {
        if ((this->Length())) {
            return this->Chars();
        }
        return 0;
    }
    virtual const char_t* Chars(size_t& length) const {
        const char_t* chars = 0;
        if ((chars = this->Chars())) {
            length = this->Length();
        }
        return chars;
    }
    virtual const char_t* Chars() const {
        return this->c_str();
    }
    virtual size_t Length() const {
        return this->length();
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};

namespace base {
typedef StringT<char, char, 0, CharsBase, StringBase> String;
typedef StringT<tchar_t, tchar_t, 0, TCharsBase, TStringBase> TString;
typedef StringT<wchar_t, wchar_t, 0, WCharsBase, WStringBase> WString;

typedef String::Implements StringImplements;
typedef TString::Implements TStringImplements;
typedef WString::Implements WStringImplements;
} // namespace base

namespace std {
typedef StringT<char, char, 0, CharsBase, StringBase> String;
typedef StringT<tchar_t, tchar_t, 0, TCharsBase, TStringBase> TString;
typedef StringT<wchar_t, wchar_t, 0, WCharsBase, WStringBase> WString;

typedef String::Implements StringImplements;
typedef TString::Implements TStringImplements;
typedef WString::Implements WStringImplements;
} // namespace std

typedef stringns::String String;
typedef stringns::TString TString;
typedef stringns::WString WString;

typedef stringns::String::Implements StringImplements;
typedef stringns::TString::Implements TStringImplements;
typedef stringns::WString::Implements WStringImplements;

///////////////////////////////////////////////////////////////////////
///  Class: CharToStringT
///////////////////////////////////////////////////////////////////////
template<class TImplements, class TExtends>
class _EXPORT_CLASS CharToStringT: virtual public TImplements, public TExtends {
public:
    typedef typename TExtends::char_t char_t;
    CharToStringT(char_t to) { this->Append(&to, 1); }
};
typedef CharToStringT<StringImplements, String> CharToString;
typedef CharToStringT<TStringImplements, TString> TCharToString;
typedef CharToStringT<WStringImplements, WString> WCharToString;

///////////////////////////////////////////////////////////////////////
///  Class: SignedToStringT
///////////////////////////////////////////////////////////////////////
template<class TImplements, class TExtends>
class _EXPORT_CLASS SignedToStringT: virtual public TImplements, public TExtends {
public:
    SignedToStringT(signed to) { this->AppendSigned(to); }
};
typedef SignedToStringT<StringImplements, String> SignedToString;
typedef SignedToStringT<TStringImplements, TString> TSignedToString;
typedef SignedToStringT<WStringImplements, WString> WSignedToString;

///////////////////////////////////////////////////////////////////////
///  Class: UnsignedToStringT
///////////////////////////////////////////////////////////////////////
template<class TImplements, class TExtends>
class _EXPORT_CLASS UnsignedToStringT: virtual public TImplements, public TExtends {
public:
    UnsignedToStringT(signed to) { this->AppendUnsigned(to); }
};
typedef UnsignedToStringT<StringImplements, String> UnsignedToString;
typedef UnsignedToStringT<TStringImplements, TString> TUnsignedToString;
typedef UnsignedToStringT<WStringImplements, WString> WUnsignedToString;

} // namespace xos

#endif // _XOS_BASE_STRING_HPP 
