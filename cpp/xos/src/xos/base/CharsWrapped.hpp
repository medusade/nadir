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
///   File: CharsWrapped.hpp
///
/// Author: $author$
///   Date: 9/20/2017
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_BASE_CHARSWRAPPED_HPP
#define _XOS_BASE_CHARSWRAPPED_HPP

#include "xos/base/CharsBase.hpp"
#include "xos/base/Wrapped.hpp"

namespace xos {

///////////////////////////////////////////////////////////////////////
///  Class: CharsWrappedT
///////////////////////////////////////////////////////////////////////
template
<typename TChar,
 typename TEnd = TChar, TEnd VEnd = 0,
 class TChars = CharsBaseT<TChar, TEnd, VEnd, ImplementBase>,
 class TWrapped = WrappedT<const TChar*, int, 0, TChars, Base>,
 class TImplements = TChars, class TExtends = TWrapped>

class _EXPORT_CLASS CharsWrappedT
: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;

    typedef typename Extends::wrapped_t wrapped_t;
    typedef TChars chars_t;
    typedef TChar char_t;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    CharsWrappedT(const char_t* chars): Extends(chars) {
    }
    CharsWrappedT(const CharsWrappedT& copy): Extends(copy) {
    }
    CharsWrappedT(): Extends(0) {
    }
    virtual ~CharsWrappedT() {
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual wrapped_t& SetWrapped(wrapped_t to) {
        this->m_wrapped = to;
        return this->m_wrapped;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};
typedef CharsWrappedT<char> CharsWrapped;

} // namespace xos

#endif // _XOS_BASE_CHARSWRAPPED_HPP 
