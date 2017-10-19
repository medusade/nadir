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
///   File: ReadObserver.hpp
///
/// Author: $author$
///   Date: 10/8/2017
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_IO_READOBSERVER_HPP
#define _XOS_IO_READOBSERVER_HPP

#include "xos/base/String.hpp"

namespace xos {
namespace io {

typedef ImplementBase ReadObserverTImplements;
///////////////////////////////////////////////////////////////////////
///  Class: ReadObserverT
///////////////////////////////////////////////////////////////////////
template
<typename TSized, typename TWhat = TSized,
 class TImplements = ReadObserverTImplements>

class _EXPORT_CLASS ReadObserverT: virtual public TImplements {
public:
    typedef TImplements Implements;

    typedef TSized sized_t;
    typedef TWhat what_t;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual void OnRead(const what_t* what, size_t size) {
    }
    virtual void OnFill(size_t size) {
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};
typedef ReadObserverT<char, void> ReadObserver;

///////////////////////////////////////////////////////////////////////
///  Class: CharReadObserverT
///////////////////////////////////////////////////////////////////////
template
<typename TChar = char, typename TWhat = TChar,
 class TReadObserver = ReadObserverT<TChar, TWhat, ReadObserverTImplements>,
 class TImplements = TReadObserver>

class _EXPORT_CLASS CharReadObserverT: virtual public TImplements {
public:
    typedef TImplements Implements;

    typedef TChar char_t;
    typedef char_t sized_t;
    typedef TWhat what_t;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual void OnReadLn(const what_t* what, size_t size) {
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};
typedef CharReadObserverT<char, void> CharReadObserver;
typedef CharReadObserverT<tchar_t, void> TCharReadObserver;
typedef CharReadObserverT<wchar_t, void> WCharReadObserver;

///////////////////////////////////////////////////////////////////////
///  Class: CharReadObserverToStringT
///////////////////////////////////////////////////////////////////////
template
<typename TChar = char, typename TWhat = TChar,
 class TString = StringT<TChar>,
 class TReadObserver = ReadObserverT<TChar, TWhat, ReadObserverTImplements>,
 class TImplements = TReadObserver, class TExtends = TString>

class _EXPORT_CLASS CharReadObserverToStringT
: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;

    typedef TString string_t;
    typedef TChar char_t;
    typedef char_t sized_t;
    typedef TWhat what_t;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    CharReadObserverToStringT(string_t& string): string_(string) {
    }
    CharReadObserverToStringT(): string_(*this) {
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual void OnRead(const what_t* what, size_t size) {
        const char_t* chars = 0;
        if ((chars = ((const char_t*)what)) && (size)) {
            string_.Append(chars, size);
        }
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    string_t &string_;
};
typedef CharReadObserverToStringT<char, void, String, CharReadObserver> CharReadObserverToString;
typedef CharReadObserverToStringT<tchar_t, void, TString, TCharReadObserver> TCharReadObserverToString;
typedef CharReadObserverToStringT<wchar_t, void, WString, WCharReadObserver> WCharReadObserverToString;

} // namespace io
} // namespace xos 

#endif // _XOS_IO_READOBSERVER_HPP 
