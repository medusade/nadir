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
///   File: Main.hpp
///
/// Author: $author$
///   Date: 8/5/2017
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_CONSOLE_MAIN_HPP
#define _XOS_CONSOLE_MAIN_HPP

#include "xos/console/IO.hpp"
#include "xos/console/MainArg.hpp"

namespace xos {
namespace console {

typedef ImplementBase MainTImplements;
typedef Base MainTExtends;
///////////////////////////////////////////////////////////////////////
///  Class: MainT
///////////////////////////////////////////////////////////////////////
template
<typename TChar = char, typename TEndChar = TChar, TEndChar VEndChar = 0,
 class TArg = MainArgT<TChar, TEndChar, VEndChar, MainTImplements>,
 class TIO = IOT<TChar, TEndChar, VEndChar, MainTImplements>,
 class TMain = MainTExtends,
 class TArgImplements = TArg, class TImplements = TIO, class TExtends = TMain>

class _EXPORT_CLASS MainT
: virtual public TArgImplements, virtual public TImplements, public TExtends {
public:
    typedef TArgImplements ArgImplements;
    typedef TImplements Implements;
    typedef TExtends Extends;

    typedef TChar char_t;
    typedef TEndChar endchar_t;
    static const TEndChar endchar = VEndChar;

    ///////////////////////////////////////////////////////////////////////
    /// Class: Exception
    ///////////////////////////////////////////////////////////////////////
    class _EXPORT_CLASS Exception: public Base {
    public:
        typedef int Reason;
        enum { MainAlreadyExists, MainDifferentExists, MainShouldExist };
        Exception(Reason which): m_which(which) {}
        virtual Reason Which() { return m_which; }
    protected:
        Reason m_which;
    };

    ///////////////////////////////////////////////////////////////////////
    /// Constructor: MainT
    ///////////////////////////////////////////////////////////////////////
    MainT(): m_didMain(false), m_didRun(false), m_didUsage(false) {
        if ((TheMain())) {
            Exception e(Exception::MainAlreadyExists);
            throw (e);
        } else {
            TheMain() = this;
        }
    }
    virtual ~MainT() {
        MainT* theMain = TheMain();
        if ((theMain)) {
            if ((theMain != this)) {
                Exception e(Exception::MainDifferentExists);
                throw (e);
            } else {
                TheMain() = 0;
            }
        } else {
            Exception e(Exception::MainShouldExist);
            throw (e);
        }
    }

protected:
    ///////////////////////////////////////////////////////////////////////
    /// Function: Run
    ///////////////////////////////////////////////////////////////////////
    virtual int Run(int argc, char_t**argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int BeforeRun(int argc, char_t**argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int AfterRun(int argc, char_t**argv, char_t** env) {
        int err = 0;
        return err;
    }

    ///////////////////////////////////////////////////////////////////////
    /// Function: Main
    ///////////////////////////////////////////////////////////////////////
    virtual int Main(int argc, char_t**argv, char_t** env) {
        int err = 0;
        if (!(err = this->BeforeRun(argc, argv, env))) {
            int err2 = 0;
            if (!(DidRun())) {
                err = this->Run(argc, argv, env);
            }
            if ((err2 = this->AfterRun(argc, argv, env))) {
                if (!err) err = err2;
            }
        }
        return err;
    }
    virtual int BeforeMain(int argc, char_t**argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int AfterMain(int argc, char_t**argv, char_t** env) {
        int err = 0;
        return err;
    }

    ///////////////////////////////////////////////////////////////////////
    /// Operator: ()
    ///////////////////////////////////////////////////////////////////////
    virtual int operator()(int argc, char_t**argv, char_t** env) {
        int err = 0;
        if (!(err = this->BeforeMain(argc, argv, env))) {
            int err2 = 0;
            if (!(DidMain())) {
                err = this->Main(argc, argv, env);
            }
            if ((err2 = this->AfterMain(argc, argv, env))) {
                if (!err) err = err2;
            }
        }
        return err;
    }

public:
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    static int TheMain(int argc, char_t**argv, char_t** env) {
        int err = 1;
        MainT* theMain = 0;
        if ((theMain = TheMain())) {
            err = (*theMain)(argc, argv, env);
        }
        return err;
    }
protected:
    static MainT*& TheMain() {
        static MainT* theMain = 0;
        return theMain;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool SetDidMain(bool to = true) {
        return m_didMain = to;
    }
    virtual bool DidMain() const {
        return m_didMain;
    }
    virtual bool SetDidRun(bool to = true) {
        return m_didRun = to;
    }
    virtual bool DidRun() const {
        return m_didRun;
    }
    virtual bool SetDidUsage(bool to = true) {
        m_didRun = to;
        return m_didUsage = to;
    }
    virtual bool DidUsage() const {
        return m_didUsage;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    bool m_didMain, m_didRun, m_didUsage;
};
typedef IO MainIO;
typedef MainIO MainImplements;
typedef MainTExtends MainExtends;
typedef MainT<char, char, 0, MainArg, MainIO, MainExtends> Main;

typedef MainT<tchar_t> TMain;
typedef MainT<wchar_t> WMain;

} // namespace console
} // namespace xos 

#endif // _XOS_CONSOLE_MAIN_HPP 
