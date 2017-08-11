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
#ifndef _XOS_BASE_STD_STRING_HPP
#define _XOS_BASE_STD_STRING_HPP

#include "xos/base/std/StringBase.hpp"
#include "xos/base/String.hpp"

namespace xos {
namespace std {

typedef StringT<char, char, 0, CharsBase, StringBase> String;
typedef StringT<tchar_t, tchar_t, 0, TCharsBase, TStringBase> TString;
typedef StringT<wchar_t, wchar_t, 0, WCharsBase, WStringBase> WString;

typedef String::Implements StringImplements;
typedef TString::Implements TStringImplements;
typedef WString::Implements WStringImplements;

} // namespace std
} // namespace xos 

#endif // _XOS_BASE_STD_STRING_HPP 

        

