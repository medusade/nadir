/**
 **********************************************************************
 * Copyright (c) 1988-2017 $organization$
 *
 * This software is provided by the author and contributors ``as is'' 
 * and any express or implied warranties, including, but not limited to, 
 * the implied warranties of merchantability and fitness for a particular 
 * purpose are disclaimed. In no event shall the author or contributors 
 * be liable for any direct, indirect, incidental, special, exemplary, 
 * or consequential damages (including, but not limited to, procurement 
 * of substitute goods or services; loss of use, data, or profits; or 
 * business interruption) however caused and on any theory of liability, 
 * whether in contract, strict liability, or tort (including negligence 
 * or otherwise) arising in any way out of the use of this software, 
 * even if advised of the possibility of such damage.
 *
 *   File: cmain.hxx
 *
 * Author: $author$
 *   Date: 9/27/2017
 **********************************************************************
 */
#ifndef _XDE_CCONSOLE_CMAIN_HXX
#define _XDE_CCONSOLE_CMAIN_HXX

#include "xde/cos/cfile.hxx"
#include "xde/cbase/cstring.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/**
 **********************************************************************
 **********************************************************************
 */

/**
 **********************************************************************
 *  Class: cMainInterfaceT
 *
 * Author: $author$
 *   Date: 1/16/2007
 **********************************************************************
 */
template
<class TChar = CHAR,
 class TImplements = cInterfaceBase>

class c_INSTANCE_CLASS cMainInterfaceT: virtual public TImplements {
public:
    typedef TImplements cImplements;
    typedef cMainInterfaceT cDerives;
    /**
     **********************************************************************
     * Function: Main
     *
     *   Author: $author$
     *     Date: 1/16/2007
     **********************************************************************
     */
    virtual int Main
    (int argc, TChar** argv, TChar** env) = 0;
    virtual int BeforeMain
    (int argc, TChar** argv, TChar** env) = 0;
    virtual int AfterMain
    (int argc, TChar** argv, TChar** env) = 0;
    /**
     **********************************************************************
     * Function: Main
     *
     *   Author: $author$
     *     Date: 1/16/2007
     **********************************************************************
     */
    virtual int Main
    (int argc, const TChar** argv, const TChar** env) = 0;
    virtual int BeforeMain
    (int argc, const TChar** argv, const TChar** env) = 0;
    virtual int AfterMain
    (int argc, const TChar** argv, const TChar** env) = 0;
    /**
     **********************************************************************
     * Function: Run
     *
     *   Author: $author$
     *     Date: 1/16/2007
     **********************************************************************
     */
    virtual int Run
    (int argc, const TChar** argv, const TChar** env) = 0;
    virtual int BeforeRun
    (int argc, const TChar** argv, const TChar** env) = 0;
    virtual int AfterRun
    (int argc, const TChar** argv, const TChar** env) = 0;
    /**
     **********************************************************************
     * Function: Usage
     *
     *   Author: $author$
     *     Date: 1/16/2007
     **********************************************************************
     */
    virtual int Usage
    (int argc, const TChar** argv, const TChar** env) = 0;
    /**
     **********************************************************************
     * Function: SetDidMain
     *
     *   Author: $author$
     *     Date: 3/15/2007
     **********************************************************************
     */
    virtual eError SetDidMain(bool did=true) = 0;
    /**
     **********************************************************************
     * Function: GetDidMain
     *
     *   Author: $author$
     *     Date: 3/15/2007
     **********************************************************************
     */
    virtual bool GetDidMain() const = 0;

    /**
     **********************************************************************
     * Function: TheMain
     *
     *   Author: $author$
     *     Date: 9/29/2017
     **********************************************************************
     */
    static int TheMain(int argc, TChar** argv, TChar** env) {
        int err = 1;
        cDerives* main = 0;

        if ((main = GetMain())) {
            if (!(err = main->BeforeMain(argc, argv, env))) {
                int err2 = 0;

                err = main->Main(argc, argv, env);

                if ((err2 = main->AfterMain(argc, argv, env))) {
                    if (!err) err = err2;
                }
            }
        }
        return err;
    }
    /**
     **********************************************************************
     * Function: GetMain
     *
     *   Author: $author$
     *     Date: 1/18/2008
     **********************************************************************
     */
    static cDerives* GetMain() {
        cDerives* theMain = TheMain();
        return theMain;
    }
protected:
    /**
     **********************************************************************
     * Function: TheMain
     *
     *   Author: $author$
     *     Date: 9/27/2017
     **********************************************************************
     */
    static cDerives*& TheMain() {
        static cDerives* theMain = 0;
        return theMain;
    }
};
/**
 **********************************************************************
 *  Typedef: cMainInterface
 *
 *  Author: $author$
 *    Date: 9/27/2017
 **********************************************************************
 */
typedef cMainInterfaceT<char> cMainInterface;
typedef cMainInterfaceT<TCHAR> cTMainInterface;
typedef cMainInterfaceT<WCHAR> cWMainInterface;

/**
 **********************************************************************
 **********************************************************************
 */

/**
 **********************************************************************
 *  Class: cMainImplementT
 *
 * Author: $author$
 *   Date: 2/13/2007
 **********************************************************************
 */
template
<class TChar = CHAR,
 class TMainImplements = cMainInterfaceT<TChar>,
 class TImplements = TMainImplements>

class c_IMPLEMENT_CLASS cMainImplementT: virtual public TImplements {
public:
    typedef TImplements cImplements;
    typedef cMainImplementT cDerives;

    /**
     **********************************************************************
     * Function: Main
     *
     *   Author: $author$
     *     Date: 2/13/2007
     **********************************************************************
     */
    virtual int Main
    (int argc, TChar** argv, TChar** env) {
        const TChar** c_argv = (const TChar**)(argv);
        const TChar** c_env = (const TChar**)(env);
        int err = 0;

        if (!(err = BeforeMain(argc, c_argv, c_env))) {
            int err2 = 0;

            err = Main(argc, c_argv, c_env);

            if ((err2 = AfterMain(argc, c_argv, c_env))) {
                if (!err) err = err2;
            }
        }
        return err;
    }
    virtual int BeforeMain
    (int argc, TChar** argv, TChar** env) {
        int err = 0;
        return err;
    }
    virtual int AfterMain
    (int argc, TChar** argv, TChar** env) {
        int err = 0;
        return err;
    }

    /**
     **********************************************************************
     * Function: Main
     *
     *   Author: $author$
     *     Date: 2/13/2007
     **********************************************************************
     */
    virtual int Main
    (int argc, const TChar** argv, const TChar** env) {
        int err = 0;

        if (!(err = BeforeRun(argc, argv, env))) {
            int err2 = 0;

            err = Run(argc, argv, env);

            if ((err2 = AfterRun(argc, argv, env))) {
                if (!err) err = err2;
            }
        }
        return err;
    }
    virtual int BeforeMain
    (int argc, const TChar** argv, const TChar** env) {
        int err = 0;
        return err;
    }
    virtual int AfterMain
    (int argc, const TChar** argv, const TChar** env) {
        int err = 0;
        return err;
    }

    /**
     **********************************************************************
     * Function: Run
     *
     *   Author: $author$
     *     Date: 2/13/2007
     **********************************************************************
     */
    virtual int Run
    (int argc, const TChar** argv, const TChar** env) {
        int err = Usage(argc, argv, env);
        return err;
    }
    virtual int BeforeRun
    (int argc, const TChar** argv, const TChar** env) {
        int err = 0;
        return err;
    }
    virtual int AfterRun
    (int argc, const TChar** argv, const TChar** env) {
        int err = 0;
        return err;
    }

    /**
     **********************************************************************
     * Function: Usage
     *
     *   Author: $author$
     *     Date: 2/13/2007
     **********************************************************************
     */
    virtual int Usage
    (int argc, const TChar** argv, const TChar** env) {
        int err = 0;
        return err;
    }
    /**
     **********************************************************************
     * Function: SetDidMain
     *
     *   Author: $author$
     *     Date: 3/15/2007
     **********************************************************************
     */
    virtual eError SetDidMain(bool did=true) {
        eError error = e_ERROR_NOT_IMPLEMENTED;
        return error;
    }
    /**
     **********************************************************************
     * Function: GetDidMain
     *
     *   Author: $author$
     *     Date: 3/15/2007
     **********************************************************************
     */
    virtual bool GetDidMain() const {
        bool did = false;
        return did;
    }
};
/**
 **********************************************************************
 *  Typedef: cMainImplement
 *
 *  Author: $author$
 *    Date: 1/18/2008
 **********************************************************************
 */
typedef cMainImplementT<char, cMainInterface> cMainImplement;
typedef cMainImplementT<TCHAR, cTMainInterface> cTMainImplement;
typedef cMainImplementT<WCHAR, cWMainInterface> cWMainImplement;

/**
 **********************************************************************
 **********************************************************************
 */

/**
 **********************************************************************
 *  Class: cMainT
 *
 * Author: $author$
 *   Date: 2/13/2007
 **********************************************************************
 */
template
<class TChar = CHAR,
 class TSize = TSIZE,
 class TLength = TLENGTH,
 class TFile = cFile,
 class TString = cString,
 class TStream = cStreamInterface,
 class TMain = cMainInterface,
 class TImplements = cMainImplement,
 class TExtends = cBase>

class c_EXPORT_CLASS cMainT: virtual public TImplements, public TExtends {
public:
    typedef TImplements cImplements;
    typedef TExtends cExtends;
    typedef cMainT cDerives;

    typedef TChar tChar;
    typedef TSize tSize;
    typedef TLength tLength;
    typedef TFile tFile;
    typedef TString tString;
    typedef TStream tStream;

    TMain* m_oldMain;

    bool m_didMainArg;
    bool m_didUsage;

    TFile m_stdIn;
    TFile m_stdOut;
    TFile m_stdErr;

    TStream* m_in;
    TStream* m_out;
    TStream* m_err;

    /**
     **********************************************************************
     * Constructor: cMainT
     *
     *      Author: $author$
     *        Date: 3/15/2007
     **********************************************************************
     */
    cMainT()
    : m_oldMain(cDerives::TheMain()),
      m_didMainArg(false), m_didUsage(false),
      m_in(&m_stdIn), m_out(&m_stdOut), m_err(&m_stdErr) {
        TMain*& theMain = cDerives::TheMain();
        theMain = this;
    }
    /**
     **********************************************************************
     *  Destructor: ~cMainT
     *
     *      Author: $author$
     *        Date: 3/15/2007
     **********************************************************************
     */
    virtual ~cMainT() {
        TMain*& theMain = cDerives::TheMain();
        if (this == theMain) {
            theMain = m_oldMain;
        }
    }

    /**
     **********************************************************************
     * Function: Main
     *
     *   Author: $author$
     *     Date: 3/7/2008
     **********************************************************************
     */
    virtual int BeforeMain
    (int argc, const TChar** argv, const TChar** env) {
        int err = 1;
        eError error = 0;
        if (!(error = StdAttach())) {
            err = 0;
        }
        return err;
    }
    virtual int AfterMain
    (int argc, const TChar** argv, const TChar** env) {
        int err = 1;
        eError error = 0;
        if (!(error = StdDetach())) {
            err = 0;
        }
        return err;
    }

    /**
     **********************************************************************
     * Function: StdAttach
     *
     *   Author: $author$
     *     Date: 3/7/2008
     **********************************************************************
     */
    virtual eError StdAttach() {
        eError error;
        FILE* file;
        if (!(error = m_stdIn.Attach(stdin)))
        {
            if (!(error = m_stdOut.Attach(stdout)))
            {
                if (!(error = m_stdErr.Attach(stderr)))
                    return error;
                m_stdOut.Detach(file);
            }
            m_stdIn.Detach(file);
        }
        return error;
    }
    /**
     **********************************************************************
     * Function: StdDetach
     *
     *   Author: $author$
     *     Date: 3/7/2008
     **********************************************************************
     */
    virtual eError StdDetach() {
        eError error;
        eError error2;
        FILE* file;
        error = m_stdErr.Detach(file);
        if ((error2 = m_stdOut.Detach(file)) && !error)
            error = error2;
        if ((error2 = m_stdIn.Detach(file)) && !error)
            error = error2;
        return error;
    }

    /**
     **********************************************************************
     * Function: Err
     *
     *   Author: $author$
     *     Date: 3/6/2008
     **********************************************************************
     */
    virtual TLength Err
    (const TChar* chars, TLength length=-1)
    {
        TLength count = 0;
        if (m_err)
            count = m_err->Write(chars, length);
        return count;
    }
    /**
     **********************************************************************
     * Function: Out
     *
     *   Author: $author$
     *     Date: 3/6/2008
     **********************************************************************
     */
    virtual TLength Out
    (const TChar* chars, TLength length=-1)
    {
        TLength count = 0;
        if (m_out)
            count = m_out->Write(chars, length);
        return count;
    }
    /**
     **********************************************************************
     * Function: In
     *
     *   Author: $author$
     *     Date: 3/6/2008
     **********************************************************************
     */
    virtual TLength In
    (TChar* chars, TSize size)
    {
        TLength count = 0;
        if (m_in)
            count = m_in->Read(chars, size);
        return count;
    }
    /**
     **********************************************************************
     * Function: SetDidUsage
     *
     *   Author: $author$
     *     Date: 3/17/2007
     **********************************************************************
     */
    virtual eError SetDidUsage(bool did=true)
    {
        eError error = e_ERROR_NONE;
        m_didUsage = did;
        return error;
    }
    /**
     **********************************************************************
     * Function: GetDidUsage
     *
     *   Author: $author$
     *     Date: 3/17/2007
     **********************************************************************
     */
    virtual bool GetDidUsage() const
    {
        return m_didUsage;
    }
    /**
     **********************************************************************
     * Function: SetDidMainArg
     *
     *   Author: $author$
     *     Date: 3/15/2007
     **********************************************************************
     */
    virtual eError SetDidMainArg(bool did=true)
    {
        eError error = e_ERROR_NONE;
        m_didMainArg = did;
        return error;
    }
    /**
     **********************************************************************
     * Function: GetDidMainArg
     *
     *   Author: $author$
     *     Date: 3/15/2007
     **********************************************************************
     */
    virtual bool GetDidMainArg() const
    {
        return m_didMainArg;
    }
};
/**
 **********************************************************************
 * Typedef: cMain
 *
 *  Author: $author$
 *    Date: 9/29/2017
 **********************************************************************
 */
typedef cMainT<char> cMain;
typedef cMainImplement cMainImplements;

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#endif /* _XDE_CCONSOLE_CMAIN_HXX */
