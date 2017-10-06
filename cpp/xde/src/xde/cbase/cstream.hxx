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
 *   File: cstream.hxx
 *
 * Author: $author$
 *   Date: 9/27/2017
 **********************************************************************
 */
#ifndef _XDE_BASE_CSTREAM_HXX
#define _XDE_BASE_CSTREAM_HXX

#include "xde/cbase/cbase.hxx"
#include <stdarg.h>

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/**
 **********************************************************************
 *   Enum:  eSeek
 *
 * Author: $author$
 *   Date: 4/2/2008
 **********************************************************************
 */
typedef int eSeek;
enum {
    e_FIRST_SEEK = 0,

    e_SEEK_SET = e_FIRST_SEEK,
    e_SEEK_CUR,
    e_SEEK_END,

    e_NEXT_SEEK,
    e_LAST_SEEK = e_NEXT_SEEK-1,
    e_COUNT_SEEK = e_LAST_SEEK-e_FIRST_SEEK+1
};

/**
 **********************************************************************
 *  Class: cReaderInterfaceT
 *
 * Author: $author$
 *   Date: 1/10/2007
 **********************************************************************
 */
template
<class TWhat = CHAR,
 class TSize = TSIZE,
 class TLength = TLENGTH,
 TLength VUndefined = UNDEFINED_LENGTH,
 class TImplements = cInterfaceBase>

class c_INTERFACE_CLASS cReaderInterfaceT: virtual public TImplements {
public:
    typedef TImplements cImplements;
    typedef TWhat tWhat;
    typedef TSize tSize;
    typedef TLength tLength;

    /**
     **********************************************************************
     * Function: Look
     *
     *   Author: $author$
     *     Date: 2/29/2008
     **********************************************************************
     */
    virtual TLength Look
    (TWhat* what, TSize size) = 0;
    /**
     **********************************************************************
     * Function: Read
     *
     *   Author: $author$
     *     Date: 1/10/2007
     **********************************************************************
     */
    virtual TLength Read
    (TWhat* what, TSize size) = 0;
    /**
     **********************************************************************
     * Function: Peek
     *
     *   Author: $author$
     *     Date: 2/29/2008
     **********************************************************************
     */
    virtual TLength Peek(TWhat& what) = 0;
    /**
     **********************************************************************
     * Function: Get
     *
     *   Author: $author$
     *     Date: 1/10/2007
     **********************************************************************
     */
    virtual TLength Get(TWhat& what) = 0;
    /**
     **********************************************************************
     * Function: See
     *
     *   Author: $author$
     *     Date: 3/2/2008
     **********************************************************************
     */
    virtual const TWhat* See
    (TLength& length) const = 0;
};
/**
 **********************************************************************
 * Typedef: cReaderInterface
 *
 *  Author: $author$
 *    Date: 1/4/2008
 **********************************************************************
 */
typedef cReaderInterfaceT<CHAR> cReaderInterface;
typedef cReaderInterfaceT<CHAR> cCHAReaderInterface;
typedef cReaderInterfaceT<TCHAR> cTCHAReaderInterface;
typedef cReaderInterfaceT<WCHAR> cWCHAReaderInterface;
typedef cReaderInterfaceT<BYTE> cBYTEReaderInterface;
typedef cReaderInterfaceT<char> cCharReaderInterface;

/**
 **********************************************************************
 *  Class: cReaderImplementT
 *
 * Author: $author$
 *   Date: 1/10/2007
 **********************************************************************
 */
template
<class TWhat = CHAR,
 class TSize = TSIZE,
 class TLength = TLENGTH,
 TLength VUndefined = UNDEFINED_LENGTH,
 class TReaderInterface = cReaderInterfaceT<TWhat, TSize, TLength, VUndefined>,
 class TImplements = TReaderInterface>

class cReaderImplementT: virtual public TImplements {
public:
    /**
     **********************************************************************
     * Function: Look
     *
     *   Author: $author$
     *     Date: 2/29/2008
     **********************************************************************
     */
    virtual TLength Look
    (TWhat* what, TSize size)
    {
        TLength length = -e_ERROR_NOT_IMPLEMENTED;
        return length;
    }
    /**
     **********************************************************************
     * Function: Read
     *
     *   Author: $author$
     *     Date: 1/10/2007
     **********************************************************************
     */
    virtual TLength Read
    (TWhat* what, TSize size)
    {
        TLength length = -e_ERROR_NOT_IMPLEMENTED;
        return length;
    }
    /**
     **********************************************************************
     * Function: Peek
     *
     *   Author: $author$
     *     Date: 2/29/2008
     **********************************************************************
     */
    virtual TLength Peek(TWhat& what)
    {
        TLength length = Look(&what, 1);
        return length;
    }
    /**
     **********************************************************************
     * Function: Get
     *
     *   Author: $author$
     *     Date: 1/10/2007
     **********************************************************************
     */
    virtual TLength Get(TWhat& what)
    {
        TLength length = Read(&what, 1);
        return length;
    }
    /**
     **********************************************************************
     * Function: See
     *
     *   Author: $author$
     *     Date: 3/2/2008
     **********************************************************************
     */
    virtual const TWhat* See
    (TLength& length) const
    {
        const TWhat* what = 0;
        length = 0;
        return what;
    }
};
/**
 **********************************************************************
 * Typedef: cReaderImplement
 *
 *  Author: $author$
 *    Date: 1/4/2008
 **********************************************************************
 */
typedef cReaderImplementT<CHAR> cReaderImplement;
typedef cReaderImplementT<CHAR> cCHAReaderImplement;
typedef cReaderImplementT<TCHAR> cTCHAReaderImplement;
typedef cReaderImplementT<WCHAR> cWCHAReaderImplement;
typedef cReaderImplementT<BYTE> cBYTEReaderImplement;
typedef cReaderImplementT<char> cCharReaderImplement;

/**
 **********************************************************************
 **********************************************************************
 */

/**
 **********************************************************************
 *  Class: cWriterInterfaceT
 *
 * Author: $author$
 *   Date: 1/13/2007
 **********************************************************************
 */
template
<class TWhat = CHAR,
 class TSize = TSIZE,
 class TLength = TLENGTH,
 TLength VUndefined = UNDEFINED_LENGTH,
 class TImplements = cInterfaceBase>

class c_INTERFACE_CLASS cWriterInterfaceT: virtual public TImplements {
public:
    /**
     **********************************************************************
     * Function: Write
     *
     *   Author: $author$
     *     Date: 1/13/2007
     **********************************************************************
     */
    virtual TLength Write
    (const TWhat* what, TLength length = VUndefined) = 0;
    /**
     **********************************************************************
     * Function: WriteL
     *
     *   Author: $author$
     *     Date: 3/7/2008
     **********************************************************************
     */
    virtual TLength WriteL
    (const TWhat* what, ...) = 0;
    /**
     **********************************************************************
     * Function: WriteV
     *
     *   Author: $author$
     *     Date: 3/16/2007
     **********************************************************************
     */
    virtual TLength WriteV
    (TWhat*const* vwhat, TLength vlength = VUndefined) = 0;
    /**
     **********************************************************************
     * Function: VWrite
     *
     *   Author: $author$
     *     Date: 3/16/2007
     **********************************************************************
     */
    virtual TLength VWrite
    (va_list va, TLength vlength = VUndefined) = 0;
    /**
     **********************************************************************
     * Function: Put
     *
     *   Author: $author$
     *     Date: 1/13/2007
     **********************************************************************
     */
    virtual TLength Put(TWhat what) = 0;
};
/**
 **********************************************************************
 * Typedef: cWriterInterface
 *
 *  Author: $author$
 *    Date: 1/4/2008
 **********************************************************************
 */
typedef cWriterInterfaceT<CHAR> cWriterInterface;
typedef cWriterInterfaceT<CHAR> cCHARWriterInterface;
typedef cWriterInterfaceT<TCHAR> cTCHARWriterInterface;
typedef cWriterInterfaceT<WCHAR> cWCHARWriterInterface;
typedef cWriterInterfaceT<BYTE> cBYTEWriterInterface;
typedef cWriterInterfaceT<char> cCharWriterInterface;

/**
 **********************************************************************
 *  Class: cWriterImplementT
 *
 * Author: $author$
 *   Date: 1/13/2007
 **********************************************************************
 */
template
<class TWhat = CHAR,
 class TSize = TSIZE,
 class TLength = TLENGTH,
 TLength VUndefined = UNDEFINED_LENGTH,
 class TWriterInterface = cWriterInterfaceT<TWhat, TSize, TLength, VUndefined>,
 class TImplements = TWriterInterface>

class cWriterImplementT: virtual public TImplements {
public:
    /**
     **********************************************************************
     * Function: Write
     *
     *   Author: $author$
     *     Date: 1/13/2007
     **********************************************************************
     */
    virtual TLength Write
    (const TWhat* what, TLength length = VUndefined)
    {
        TLength count = -e_ERROR_NOT_IMPLEMENTED;
        return count;
    }
    /**
     **********************************************************************
     * Function: WriteL
     *
     *   Author: $author$
     *     Date: 3/7/2008
     **********************************************************************
     */
    virtual TLength WriteL
    (const TWhat* what, ...)
    {
        TLength length = 0;
        TLength count;
        va_list va;

        va_start(va, what);

        if (0 <= (length = Write(what)))
        if (0 > (count = VWrite(va)))
            length = count;
        else length += count;
        va_end(va);
        return length;
    }
    /**
     **********************************************************************
     * Function: WriteV
     *
     *   Author: $author$
     *     Date: 3/16/2007
     **********************************************************************
     */
    virtual TLength WriteV
    (TWhat*const* vwhat, TLength vlength = VUndefined)
    {
        TLength length = 0;
        TLength count;

        if (0 > vlength)
        {
            for (;0 != *vwhat; vwhat++, length += count)
            {
                if (0 >= (count = Write(*vwhat)))
                    break;
            }
        }
        else
        {
            for (;0 < vlength; --vlength, vwhat++, length += count)
            {
                if (0 >= (count = Write(*vwhat)))
                    break;
            }
        }
        return length;
    }
    /**
     **********************************************************************
     * Function: VWrite
     *
     *   Author: $author$
     *     Date: 3/16/2007
     **********************************************************************
     */
    virtual TLength VWrite
    (va_list va, TLength vlength = VUndefined)
    {
        TLength length = 0;
        TLength count;
        const TWhat* what;

        if (0 > vlength)
        {
            while (0 != (what = va_arg(va, const TWhat*)))
            {
                if (0 > (count = Write(what)))
                {
                    length = count;
                    break;
                }
                length += count;
            }
        }
        else
        {
            while (0 < vlength--)
            {
                if (0 != (what = va_arg(va, const TWhat*)))
                if (0 > (count = Write(what)))
                    length = count;
                else
                {
                    length += count;
                    continue;
                }
                break;
            }
        }
        return length;
    }
    /**
     **********************************************************************
     * Function: Put
     *
     *   Author: $author$
     *     Date: 1/13/2007
     **********************************************************************
     */
    virtual TLength Put(TWhat what)
    {
        TLength length = Write(&what, 1);
        return length;
    }
};
/**
 **********************************************************************
 * Typedef: cWriterImplement
 *
 *  Author: $author$
 *    Date: 1/4/2008
 **********************************************************************
 */
typedef cWriterImplementT<CHAR> cWriterImplement;
typedef cWriterImplementT<CHAR> cCHARWriterImplement;
typedef cWriterImplementT<TCHAR> cTCHARWriterImplement;
typedef cWriterImplementT<WCHAR> cWCHARWriterImplement;
typedef cWriterImplementT<BYTE> cBYTEWriterImplement;
typedef cWriterImplementT<char> cCharWriterImplement;

/**
 **********************************************************************
 **********************************************************************
 */

/**
 **********************************************************************
 *  Class: cStreamInterfaceT
 *
 * Author: $author$
 *   Date: 15/11/2007
 **********************************************************************
 */
template
<class TWhat = CHAR,
 class TSize = TSIZE,
 class TLength = TLENGTH,
 TLength VUndefinedLength = UNDEFINED_LENGTH,
 class TReaderInterface = cReaderInterfaceT<TWhat, TSize, TLength, VUndefinedLength>,
 class TWriterInterface = cWriterInterfaceT<TWhat, TSize, TLength, VUndefinedLength>,
 class TReaderImplements = TReaderInterface,
 class TWriterImplements = TWriterInterface>

class c_INTERFACE_CLASS cStreamInterfaceT
: virtual public TReaderImplements, virtual public TWriterImplements {
public:
    typedef TReaderImplements cReaderImplements;
    typedef TWriterImplements cWriterImplements;
    typedef TWhat tWhat;
    typedef TSize tSize;
    typedef TLength tLength;

    /**
     **********************************************************************
     * Function: WriteReader
     *
     *   Author: $author$
     *     Date: 15/11/2007
     **********************************************************************
     */
    virtual TLength WriteReader
    (TReaderInterface& reader,
     TLength length=VUndefinedLength) = 0;
    /**
     **********************************************************************
     * Function: GetReader
     *
     *   Author: $author$
     *     Date: 15/11/2007
     **********************************************************************
     */
    virtual TReaderInterface& GetReader() const = 0;
    /**
     **********************************************************************
     * Function: GetWriter
     *
     *   Author: $author$
     *     Date: 15/11/2007
     **********************************************************************
     */
    virtual TWriterInterface& GetWriter() const = 0;
};
/**
 **********************************************************************
 * Typedef: cStreamInterface
 *
 * Author: $author$
 *   Date: 15/11/2007
 **********************************************************************
 */
typedef cStreamInterfaceT<CHAR> cStreamInterface;
typedef cStreamInterfaceT<CHAR> cCHARStreamInterface;
typedef cStreamInterfaceT<TCHAR> cTCHARStreamInterface;
typedef cStreamInterfaceT<WCHAR> cWCHARStreamInterface;
typedef cStreamInterfaceT<BYTE> cBYTEStreamInterface;
typedef cStreamInterfaceT<char> cCharStreamInterface;

/**
 **********************************************************************
 *  Class: cStreamImplementT
 *
 * Author: $author$
 *   Date: 15/11/2007
 **********************************************************************
 */
template
<class TWhat = CHAR,
 class TSize = TSIZE,
 class TLength = TLENGTH,
 TLength VUndefinedLength = UNDEFINED_LENGTH,
 class TReaderInterface = cReaderInterfaceT<TWhat, TSize, TLength, VUndefinedLength>,
 class TWriterInterface = cWriterInterfaceT<TWhat, TSize, TLength, VUndefinedLength>,
 class TStreamInterface = cStreamInterfaceT
 <TWhat, TSize, TLength, VUndefinedLength, TReaderInterface, TWriterInterface>,
 class TReaderImplement = cReaderImplementT
 <TWhat, TSize, TLength, VUndefinedLength, TReaderInterface>,
 class TWriterImplement = cWriterImplementT
 <TWhat, TSize, TLength, VUndefinedLength, TWriterInterface>,
 class TReaderImplements = TReaderImplement,
 class TWriterImplements = TWriterImplement,
 class TImplements = TStreamInterface>

class cStreamImplementT
: virtual public TReaderImplements,
  virtual public TWriterImplements,
  virtual public TImplements
{
public:
    typedef TImplements cImplements;
    /**
     **********************************************************************
     * Function: WriteReader
     *
     *   Author: $author$
     *     Date: 15/11/2007
     **********************************************************************
     */
    virtual TLength WriteReader
    (TReaderInterface& reader,
     TLength length=VUndefinedLength)
    {
        TLength count = 0;
        TLength count2;
        TWhat what;

        if ((0 <= length) && (length != VUndefinedLength))
        while (count < length)
        {
            if (0 > (count2 = reader.Read(&what, 1)))
                break;
            else
            if (0 > (count2 = CTHIS Write(&what, 1)))
                return count2;
            else
            count += count2;
        }
        else
        while (0 < (count2 = reader.Read(&what, 1)))
        {
            if (0 > (count2 = CTHIS Write(&what, 1)))
                return count2;
            else
            count += count2;
        }
        return count;
    }
    /**
     **********************************************************************
     * Function: GetReader
     *
     *   Author: $author$
     *     Date: 15/11/2007
     **********************************************************************
     */
    virtual TReaderInterface& GetReader() const
    {
        return *(TReaderInterface*)(this);
    }
    /**
     **********************************************************************
     * Function: GetWriter
     *
     *   Author: $author$
     *     Date: 15/11/2007
     **********************************************************************
     */
    virtual TWriterInterface& GetWriter() const
    {
        return *(TWriterInterface*)(this);
    }
};
/**
 **********************************************************************
 * Typedef: cStreamImplement
 *
 * Author: $author$
 *   Date: 15/11/2007
 **********************************************************************
 */
typedef cStreamImplementT<CHAR> cStreamImplement;
typedef cStreamImplementT<CHAR> cCHARStreamImplement;
typedef cStreamImplementT<TCHAR> cTCHARStreamImplement;
typedef cStreamImplementT<WCHAR> cWCHARStreamImplement;
typedef cStreamImplementT<BYTE> cBYTEStreamImplement;
typedef cStreamImplementT<char> cCharStreamImplement;

/**
 **********************************************************************
 *  Class: cStreamT
 *
 * Author: $author$
 *   Date: 1/16/2008
 **********************************************************************
 */
template
<class TWhat = CHAR,
 class TSize = TSIZE,
 class TLength = TLENGTH,
 TLength VUndefinedLength = UNDEFINED_LENGTH,
 class TImplements = cStreamImplementT<TWhat, TSize, TLength, VUndefinedLength>,
 class TExtends = cBase>

class cStreamT: virtual public TImplements, public TExtends {
public:
    typedef TImplements cImplements;
    typedef TExtends cExtends;
    typedef cStreamT cDerives;

    /**
     **********************************************************************
     * Constructor: cStreamT
     *
     *      Author: $author$
     *        Date: 1/16/2008
     **********************************************************************
     */
    cStreamT()
    {
    }
    /**
     **********************************************************************
     * Destructor: cStreamT
     *
     *     Author: $author$
     *       Date: 1/16/2008
     **********************************************************************
     */
    virtual ~cStreamT()
    {
    }
};
/**
 **********************************************************************
 *  Typedef: cStream
 *
 *  Author: $author$
 *    Date: 1/16/2008
 **********************************************************************
 */
typedef cStreamT<CHAR> cStream;
typedef cStreamT<CHAR> cCHARStream;
typedef cStreamT<TCHAR> cTCHARStream;
typedef cStreamT<WCHAR> cWCHARStream;
typedef cStreamT<BYTE> cBYTEStream;
typedef cStreamT<char> cCharStream;

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#endif /* _XDE_BASE_CSTREAM_HXX */
