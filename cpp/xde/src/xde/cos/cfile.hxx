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
 *   File: cfile.hxx
 *
 * Author: $author$
 *   Date: 9/28/2017
 **********************************************************************
 */
#ifndef _XDE_COS_CFILE_HXX
#define _XDE_COS_CFILE_HXX

#include "xde/cbase/cstream.hxx"
#include "xde/cbase/cattached.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/**
 **********************************************************************
 *  Class: cFILEAttachInterfaceT
 *
 * Author: $author$
 *   Date: 3/6/2008
 **********************************************************************
 */
template
<class TImplement = cInterfaceBase,
 class TAttachInterface = cAttachInterfaceT<FILE*, TImplement>,
 class TImplements = TAttachInterface>

class c_INTERFACE_CLASS cFILEAttachInterfaceT: virtual public TImplements {
public:
    typedef TImplements cImplements;
};
typedef cFILEAttachInterfaceT<> cFILEAttachInterface;

/**
 **********************************************************************
 *  Class: cFILEDetachInterfaceT
 *
 * Author: $author$
 *   Date: 3/6/2008
 **********************************************************************
 */
template
<class TImplement = cInterfaceBase,
 class TDetachInterface = cDetachInterfaceT<FILE*, TImplement>,
 class TImplements = TDetachInterface>

class c_INTERFACE_CLASS cFILEDetachInterfaceT: virtual public TImplements {
public:
    typedef TImplements cImplements;
};
typedef cFILEDetachInterfaceT<> cFILEDetachInterface;

/**
 **********************************************************************
 *  Class: cFILEAttachedInterfaceT
 *
 * Author: $author$
 *   Date: 3/5/2008
 **********************************************************************
 */
template
<class TImplement = cInterfaceBase,
 class TAttachInterface = cAttachInterfaceT<FILE*, TImplement>,
 class TDetachInterface = cDetachInterfaceT<FILE*, TImplement>,
 class TAttachedInterface = cAttachedInterfaceT
 <FILE*, TAttachInterface, TDetachInterface>,
 class TImplements = TAttachedInterface>

class c_INTERFACE_CLASS cFILEAttachedInterfaceT: virtual public TImplements {
public:
    typedef TImplements cImplements;
};
typedef cFILEAttachedInterfaceT<> cFILEAttachedInterface;

/**
 **********************************************************************
 *  Class: cFILEAttachedImplementT
 *
 * Author: $author$
 *   Date: 9/28/2017
 **********************************************************************
 */
template
<class TImplement = cInterfaceBase,
 class TAttachedInterface = cFILEAttachedInterfaceT<TImplement>,
 class TAttachedImplement = cAttachedImplementT<FILE*, int, NULL, TAttachedInterface>,
 class TImplements = TAttachedImplement>

class c_IMPLEMENT_CLASS cFILEAttachedImplementT: virtual public TImplements {
public:
    typedef TImplements cImplements;
};
typedef cFILEAttachedImplementT<> cFILEAttachedImplement;

/**
 **********************************************************************
 *  Class: cFILEAttachedT
 *
 * Author: $author$
 *   Date: 9/28/2017
 **********************************************************************
 */
template
<class TAttachedImplement = cFILEAttachedImplement,
 class TAttached = cAttachedT<FILE*, int, NULL, TAttachedImplement, cBase>,
 class TImplements = TAttachedImplement, class TExtends = TAttached>

class c_EXPORT_CLASS cFILEAttachedT: virtual public TImplements, public TExtends {
public:
    typedef TImplements cImplements;
    typedef TExtends cExtends;
    /**
     **********************************************************************
     * Constructor: cFILEAttachedT
     *
     *      Author: $author$
     *        Date: 9/28/2017
     **********************************************************************
     */
    cFILEAttachedT(FILE* attached = 0) {
        CTHIS m_attached = attached;
    }
};
typedef cFILEAttachedT<> cFILEAttached;

/**
 **********************************************************************
 **********************************************************************
 */

/**
 **********************************************************************
 *  Class: cFileInterfaceT
 *
 * Author: $author$
 *   Date: 3/5/2008
 **********************************************************************
 */
template
<class TChar = CHAR,
 class TSize = TSIZE,
 class TLength = TLENGTH,
 TLength VUndefinedLength = UNDEFINED_LENGTH,
 class TStreamInterface = cStreamInterfaceT<TChar, TSize, TLength, VUndefinedLength>,
 class TAttachedInterface = cFILEAttachedInterface>

class c_INTERFACE_CLASS cFileInterfaceT
: virtual public TStreamInterface, virtual public TAttachedInterface {
public:
    typedef TStreamInterface cStreamImplements;
    typedef TAttachedInterface cAttachedImplements;
};
/**
 **********************************************************************
 * Typedef: cFileInterface
 *
 *  Author: $author$
 *    Date: 9/28/2017
 **********************************************************************
 */
typedef cFileInterfaceT<CHAR> cFileInterface;
typedef cFileInterfaceT<CHAR> cCHARFileInterface;
typedef cFileInterfaceT<TCHAR> cTCHARFileInterface;
typedef cFileInterfaceT<WCHAR> cWCHARFileInterface;
typedef cFileInterfaceT<char> cCharFileInterface;

/**
 **********************************************************************
 *  Class: cFileImplementT
 *
 * Author: $author$
 *   Date: 3/5/2008
 **********************************************************************
 */
template
<class TChar = CHAR,
 class TSize = TSIZE,
 class TLength = TLENGTH,
 TLength VUndefinedLength = UNDEFINED_LENGTH,
 class TStreamImplement = cStreamImplementT<TChar, TSize, TLength, VUndefinedLength>,
 class TAttachedImplement = cFILEAttachedImplement>

class c_INTERFACE_CLASS cFileImplementT
: virtual public TStreamImplement, virtual public TAttachedImplement {
public:
    typedef TAttachedImplement cImplements;
    typedef cFileImplementT cDerives;
};
/**
 **********************************************************************
 * Typedef: cFileImplement
 *
 *  Author: $author$
 *    Date: 9/28/2017
 **********************************************************************
 */
typedef cFileImplementT<CHAR> cFileImplement;
typedef cFileImplementT<CHAR> cCHARFileImplement;
typedef cFileImplementT<TCHAR> cTCHARFileImplement;
typedef cFileImplementT<WCHAR> cWCHARFileImplement;
typedef cFileImplementT<char> cCharFileImplement;

/**
 **********************************************************************
 **********************************************************************
 */

/**
 **********************************************************************
 *  Class: cFILEStreamT
 *
 * Author: $author$
 *   Date: 3/5/2008
 **********************************************************************
 */
template
<class TWhat = CHAR,
 class TSize = TSIZE,
 class TLength = TLENGTH,
 TLength VUndefinedLength = UNDEFINED_LENGTH,
 class TFileImplement = cFileImplementT<TWhat, TSize, TLength, VUndefinedLength>,
 class TFILEAttached = cFILEAttachedT<TFileImplement>,
 class TStream = cStreamT
 <TWhat, TSize, TLength, VUndefinedLength, TFileImplement, TFILEAttached>,
 class TImplements = TFileImplement,
 class TExtends = TStream>

class c_EXPORT_CLASS cFILEStreamT: virtual public TImplements, public TExtends {
public:
    typedef TImplements cImplements;
    typedef TExtends cExtends;
    /**
     **********************************************************************
     * Constructor: cFILEStreamT
     *
     *      Author: $author$
     *        Date: 3/5/2008
     **********************************************************************
     */
    cFILEStreamT(FILE* attached = 0) {
        CTHIS m_attached = attached;
    }
};
typedef cFILEStreamT<CHAR> cFILEStream;

/**
 **********************************************************************
 **********************************************************************
 */

/**
 **********************************************************************
 *  Class: cFileT
 *
 * Author: $author$
 *   Date: 3/5/2008
 **********************************************************************
 */
template
<class TWhat = CHAR,
 class TSize = TSIZE,
 class TLength = TLENGTH,
 TLength VUndefinedLength = UNDEFINED_LENGTH,
 class TFileImplement = cFileImplementT<TWhat, TSize, TLength, VUndefinedLength>,
 class TStream = cFILEStreamT<TWhat, TSize, TLength, VUndefinedLength, TFileImplement>,
 class TImplements = TFileImplement, class TExtends = TStream>

class c_EXPORT_CLASS cFileT: virtual public TImplements, public TExtends {
public:
    typedef TImplements cImplements;
    typedef TExtends cExtends;
    typedef cFileT cDerives;
    /**
     **********************************************************************
     * Constructor: cFileT
     *
     *      Author: $author$
     *        Date: 3/5/2008
     **********************************************************************
     */
    cFileT(FILE* attached = 0): cExtends(attached) {
    }
    /**
     **********************************************************************
     * Destructor: cFileT
     *
     *     Author: $author$
     *       Date: 3/5/2008
     **********************************************************************
     */
    virtual ~cFileT() {
    }
    /**
     **********************************************************************
     * Function: Open
     *
     *   Author: $author$
     *     Date: 3/18/2008
     **********************************************************************
     */
    virtual eError Open
    (const char* filename, const char* filemode="r", bool onlyClosed = false) {
        eError error = e_ERROR_FAILED;
        eError error2;
        FILE* attached;
        bool opened;

        if ((opened = (0 != (attached = CTHIS Attached()))))
        if (onlyClosed)
            error = e_ERROR_ALREADY_ATTACHED;
        else
        if ((error2 = Close(opened)))
            return error2;

        if ((opened = (0 != (attached
            = ::fopen(filename, filemode)))))
        if ((error = CTHIS Attach(attached)))
            ::fclose(attached);
        return error;
    }
    /**
     **********************************************************************
     * Function: Close
     *
     *   Author: $author$
     *     Date: 3/18/2008
     **********************************************************************
     */
    virtual eError Close(bool onlyOpen = false) {
        eError error = e_ERROR_FAILED;
        FILE* attached;
        bool opened;
        int err;

        if (!(opened = (0 != (attached = CTHIS Attached()))))
        if (onlyOpen)
            error = e_ERROR_NOT_ATTACHED;
        else
        return e_ERROR_NONE;

        if (!(err = ::fclose(attached)))
            error = CTHIS Detach(attached);
        return error;
    }
    /**
     **********************************************************************
     * Function: Write
     *
     *   Author: $author$
     *     Date: 3/5/2008
     **********************************************************************
     */
    virtual TLength Write
    (const TWhat* what, TLength length = VUndefinedLength) {
        TLength count = 0;
        size_t amount;
        FILE* attached;

        if (0 == (attached = CTHIS Attached()))
            count = -e_ERROR_NOT_ATTACHED;
        else
        if (0 > length)
            for (count = 0; *what != 0; what++, count += length)
            {
                if (0 > (length = Write(what, 1)))
                    return length;
            }
        else
        if (0 < (amount = (size_t)(length)))
        if (length <= (TLength)(amount = ::fwrite
            (what, sizeof(TWhat), amount, attached)))
            count = length;
        else count = -e_ERROR_WRITE;
        return count;
    }
    /**
     **********************************************************************
     * Function: Read
     *
     *   Author: $author$
     *     Date: 3/5/2008
     **********************************************************************
     */
    virtual TLength Read
    (TWhat* what, TSize size) {
        TLength count = 0;
        size_t amount;
        FILE* attached;

        if (0 == (attached = CTHIS Attached()))
            count = -e_ERROR_NOT_ATTACHED;
        else
        if (0 < (amount = (size_t)(size)))
        if (size <= (TSize)(amount = ::fread
            (what, sizeof(TWhat), amount, attached)))
            count = (TLength)(size);
        else count = -e_ERROR_READ;
        return count;
    }
};
/**
 **********************************************************************
 * Typedef: cFile
 *
 *  Author: $author$
 *    Date: 9/28/2017
 **********************************************************************
 */
typedef cFileT<CHAR> cFile;
typedef cFileT<CHAR> cCHARFile;
typedef cFileT<TCHAR> cTCHARFile;
typedef cFileT<WCHAR> cWCHARFile;
typedef cFileT<char> cCharFile;

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#endif /* _XDE_COS_CFILE_HXX */
