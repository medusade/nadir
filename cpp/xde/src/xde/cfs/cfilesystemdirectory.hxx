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
 *   File: cfilesystemdirectory.hxx
 *
 * Author: $author$
 *   Date: 10/3/2017
 **********************************************************************
 */
#ifndef _XDE_CFS_CFILESYSTEMDIRECTORY_HXX
#define _XDE_CFS_CFILESYSTEMDIRECTORY_HXX

#include "xde/cbase/cstring.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/**
 **********************************************************************
 *  Class: cFileSystemDirectoryT
 *
 * Author: $author$
 *   Date: 10/3/2017
 **********************************************************************
 */
template
<class TChar = CHAR,
 class TSize = TSIZE,
 class TLength = TLENGTH,
 TLength VUndefinedLength = UNDEFINED_LENGTH,
 class TNullChar = TChar,
 TNullChar VNullChar = NULL_CHAR,
 class TStringImplement = cStringImplementT<TChar, TSize, TLength, VUndefinedLength, TNullChar, VNullChar>,
 class TString = cStringT<TChar, TSize, TLength, VUndefinedLength, TNullChar, VNullChar>,
 class TImplements = TStringImplement, class TExtends = TString>

class c_EXPORT_CLASS cFileSystemDirectoryT: virtual public TImplements, public TExtends {
public:
    typedef TImplements cImplements;
    typedef TExtends cExtends;
protected:
    char m_cwd[PATH_MAX+1];
public:
    /**
     **********************************************************************
     * Constructor: cFileSystemDirectoryT
     *
     *      Author: $author$
     *        Date: 10/3/2017
     **********************************************************************
     */
    cFileSystemDirectoryT() {
    }
    /**
     **********************************************************************
     * Function: cFileSystemDirectoryT
     *
     *   Author: $author$
     *     Date: 10/3/2017
     **********************************************************************
     */
    virtual eError GetCurrentWorking() {
        eError error = e_ERROR_FAILED;
        const char* cwd = 0;
        TChar c = 0;

        DBF("() getcwd(m_cwd, sizeof(m_cwd)-1)...\n");
        if ((cwd = getcwd(m_cwd, sizeof(m_cwd)-1))) {
            DBF("() ...\"%s\" = getcwd(m_cwd, sizeof(m_cwd)-1)...\n", m_cwd);
            error = 0;
            this->Clear();
            for (char cc = *cwd; (c = (TChar)cc); cc = *++cwd) {
                this->AppendChars(&c, 1);
            }
        } else {
            DBE("() ...failed on getcwd(m_cwd, sizeof(m_cwd)-1)\n");
        }
        return error;
    }
};
typedef cFileSystemDirectoryT<char> cFileSystemDirectory;
typedef cFileSystemDirectoryT<CHAR> cCHARFileSystemDirectory;
typedef cFileSystemDirectoryT<TCHAR> cTCHARFileSystemDirectory;
typedef cFileSystemDirectoryT<WCHAR> cWCHARFileSystemDirectory;

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#endif /* _XDE_CFS_CFILESYSTEMDIRECTORY_HXX */

        

