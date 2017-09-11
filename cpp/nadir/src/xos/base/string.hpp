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
///   File: string.hpp
///
/// Author: $author$
///   Date: 9/8/2017
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_BASE_STRING_HPP
#define _XOS_BASE_STRING_HPP

#include "xos/base/string_base.hpp"

namespace xos {
namespace nadir {

///////////////////////////////////////////////////////////////////////
///  Class: stringt
///////////////////////////////////////////////////////////////////////
template
<typename TChar = char,
 typename TEndChar = TChar, TEndChar VEndChar = 0,
 class TChars = charst<TChar, TEndChar, VEndChar, implement_base>,
 class TBase = string_baset<TChar, TEndChar, VEndChar, TChars, base>,
 class TImplements = TChars, class TExtends = TBase>

class _EXPORT_CLASS stringt: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;
    typedef stringt Derives;

    typedef TChars chars_t;
    typedef TChar char_t;
    typedef TEndChar end_char_t;
    enum { end_char = VEndChar };

    typedef typename TChars::from_signed from_signed;
    typedef typename TChars::from_unsigned from_unsigned;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    stringt(const char_t* chars, size_t length): Extends(chars, length) {
    }
    stringt(const char_t* chars): Extends(chars) {
    }
    stringt(const from_signed& from): Extends(from) {
    }
    stringt(const from_unsigned& from): Extends(from) {
    }
    stringt(const Derives& copy): Extends(copy) {
    }
    stringt() {
    }
    virtual ~stringt(){
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};

typedef stringt<char, char> string;
typedef stringt<tchar_t, tchar_t> tstring;
typedef stringt<wchar_t, wchar_t> wstring;

} // namespace nadir
} // namespace xos

namespace xos {
namespace std {

///////////////////////////////////////////////////////////////////////
///  Class: stringt
///////////////////////////////////////////////////////////////////////
template
<typename TChar = char,
 typename TEndChar = TChar, TEndChar VEndChar = 0,
 class TChars = charst<TChar, TEndChar, VEndChar, implement_base>,
 class TBase = string_baset<TChar, TEndChar, VEndChar, TChars, base>,
 class TImplements = TChars, class TExtends = TBase>

class _EXPORT_CLASS stringt: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;
    typedef stringt Derives;

    typedef TChars chars_t;
    typedef TChar char_t;
    typedef TEndChar end_char_t;
    enum { end_char = VEndChar };

    typedef typename TChars::from_signed from_signed;
    typedef typename TChars::from_unsigned from_unsigned;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    stringt(const char_t* chars, size_t length): Extends(chars, length) {
    }
    stringt(const char_t* chars): Extends(chars) {
    }
    stringt(const from_signed& from): Extends(from) {
    }
    stringt(const from_unsigned& from): Extends(from) {
    }
    stringt(const Derives& copy): Extends(copy) {
    }
    stringt() {
    }
    virtual ~stringt(){
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};

typedef stringt<char, char> string;
typedef stringt<tchar_t, tchar_t> tstring;
typedef stringt<wchar_t, wchar_t> wstring;

} // namespace std
} // namespace xos

namespace xos {

typedef stringns::string string;
typedef stringns::tstring tstring;
typedef stringns::wstring wstring;

typedef stringns::string::Implements string_implements;
typedef stringns::tstring::Implements tstring_implements;
typedef stringns::wstring::Implements wstring_implements;

} // namespace xos

#endif // _XOS_BASE_STRING_HPP
