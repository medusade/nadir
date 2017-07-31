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

    ///////////////////////////////////////////////////////////////////////
    /// Constructor: StringBaseT
    ///////////////////////////////////////////////////////////////////////
    StringBaseT(const char_t* chars, size_t length) {
        this->append(chars, length);
    }
    StringBaseT(const char_t* chars) {
        this->append(chars);
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
    virtual StringBaseT& appendl(const char_t* chars, ...) {
        va_list va; va_start(va, chars);
        appendv(chars, va);
        va_end(va);
        return *this;
    }
    virtual StringBaseT& appendv(const char_t* chars, va_list va) {
        if ((chars)) {
            do { append(chars);
            } while ((chars = va_arg(va, const char_t*)));
        }
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
    virtual float to_float() const {
        sstream_t ss(*this);
        float to = 0;
        ss >> to;
        return to;
    }
    virtual double to_double() const {
        sstream_t ss(*this);
        double to = 0;
        ss >> to;
        return to;
    }
    virtual bool to_bool() const {
        sstream_t ss(*this);
        bool to = 0;
        ss >> to;
        return to;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};

} // namespace std 
} // namespace xos 

#endif // _XOS_BASE_STD_STRINGBASE_HPP 
