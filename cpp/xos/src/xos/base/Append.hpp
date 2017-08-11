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
///   File: Append.hpp
///
/// Author: $author$
///   Date: 8/11/2017
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_BASE_APPEND_HPP
#define _XOS_BASE_APPEND_HPP

#include "xos/base/Base.hpp"

namespace xos {

///////////////////////////////////////////////////////////////////////
/// Function: AppendSignedT
///////////////////////////////////////////////////////////////////////
template
<typename TString, typename TChar = char, typename TSigned = signed>
TString& AppendSignedT(TString& thiss, TSigned value) {
    TChar c = ((TChar)('0'));
    TChar s = ((TChar)('-'));
    size_t digits = 0;
    TSigned msdValue = 0;

    if (0 != value) {
        if (0 > value) {
            thiss.append(&s, 1);
            value = -value;
        }
        for (digits = 0, msdValue = 0;
             value; value /= 10, digits++) {
            msdValue = (msdValue*10) + (value%10);
        }
        for (; msdValue; msdValue /= 10, --digits) {
            TChar d = c + (TChar)(msdValue%10);
            thiss.append(&d, 1);
        }
        for (; digits; --digits)
            thiss.append(&c, 1);
    } else {
        thiss.append(&c, 1);
    }
    return thiss;
}

///////////////////////////////////////////////////////////////////////
/// Function: AppendUnsignedT
///////////////////////////////////////////////////////////////////////
template
<typename TString, typename TChar = char, typename TUnsigned = signed>
TString& AppendUnsignedT(TString& thiss, TUnsigned value) {
    TChar c = ((TChar)('0'));
    size_t digits = 0;
    TUnsigned msdValue = 0;

    if (0 != value) {
        for (digits = 0, msdValue = 0;
             value; value /= 10, digits++) {
            msdValue = (msdValue*10) + (value%10);
        }
        for (; msdValue; msdValue /= 10, --digits) {
            TChar d = c + (TChar)(msdValue%10);
            thiss.append(&d, 1);
        }
        for (; digits; --digits)
            thiss.append(&c, 1);
    } else {
        thiss.append(&c, 1);
    }
    return thiss;
}

} // namespace xos

#endif // _XOS_BASE_APPEND_HPP 
