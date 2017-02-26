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
///   File: to_string.hpp
///
/// Author: $author$
///   Date: 2/18/2017
///////////////////////////////////////////////////////////////////////
#ifndef _NADIR_BASE_TO_STRING_HPP
#define _NADIR_BASE_TO_STRING_HPP

#include "nadir/base/string.hpp"

namespace nadir {

///////////////////////////////////////////////////////////////////////
///  Class: chars_to_stringt
///////////////////////////////////////////////////////////////////////
template
<typename TChar = char,
 class TExtends = char_stringt<TChar> >

class _EXPORT_CLASS chars_to_stringt: public TExtends {
public:
    typedef TExtends Extends;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    chars_to_stringt(const char* chars) {
        if (chars) {
            this->append("\"");
            this->append(chars);
            this->append("\"");
        } else {
            this->append("0");
        }
    }
    chars_to_stringt(const wchar_t* chars) {
        if (chars) {
            this->append("\"");
            this->append(chars);
            this->append("\"");
        } else {
            this->append("0");
        }
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};
typedef chars_to_stringt<char> chars_to_string;
typedef chars_to_stringt<tchar_t> chars_to_tstring;
typedef chars_to_stringt<wchar_t> chars_to_wstring;

} // namespace nadir 

#endif // _NADIR_BASE_TO_STRING_HPP 
