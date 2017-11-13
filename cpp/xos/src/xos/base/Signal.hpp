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
///   File: Signal.hpp
///
/// Author: $author$
///   Date: 11/12/2017
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_BASE_SIGNAL_HPP
#define _XOS_BASE_SIGNAL_HPP

#include "xos/base/Base.hpp"

namespace xos {

typedef ImplementBase SignalTImplements;
typedef Base SignalTExtends;
///////////////////////////////////////////////////////////////////////
///  Class: SignalT
///////////////////////////////////////////////////////////////////////
template
<typename TRaised = bool, 
 TRaised VRaised = true, TRaised VLowered = false,
 class TImplements = SignalTImplements, class TExtends = SignalTExtends>

class _EXPORT_CLASS SignalT: virtual public TImplements {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    SignalT(TRaised& raised): m_raise(VLowered), m_raised(raised) {
    }
    SignalT(): m_raise(VLowered), m_raised(m_raise) {
    }
    virtual ~SignalT() {
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual void operator()(TRaised raised = VRaised) {
        m_raised = raised;
    }
    virtual operator TRaised() {
        return m_raised;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    TRaised m_raise;
    TRaised& m_raised;
};
typedef SignalT<> Signal;

} // namespace xos 

#endif // _XOS_BASE_SIGNAL_HPP 

        

