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
 *   File: cbuffer.hxx
 *
 * Author: $author$
 *   Date: 9/28/2017
 **********************************************************************
 */
#ifndef _XDE_BASE_CBUFFER_HXX
#define _XDE_BASE_CBUFFER_HXX

#include "xde/cbase/cstream.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/**
 **********************************************************************
 *  Class: cBufferInterfaceT
 *
 * Author: $author$
 *   Date: 2/15/2007
 **********************************************************************
 */
template
<class TWhat = CHAR,
 class TSize = TSIZE,
 class TLength = TLENGTH,
 TLength VUndefined = UNDEFINED_LENGTH,
 class TStreamInterface = cStreamInterfaceT<TWhat, TSize, TLength, VUndefined>,
 class TImplements = TStreamInterface>

class c_INTERFACE_CLASS cBufferInterfaceT
: virtual public TImplements
{
public:
    typedef TImplements cImplements;
    /**
     **********************************************************************
     * Function: GetBuffer
     *
     *   Author: $author$
     *     Date: 12/28/2008
     **********************************************************************
     */
    virtual const TWhat* GetBuffer(TLength& length) const = 0;
};
/**
 **********************************************************************
 * Typedef: cBufferInterface
 *
 *  Author: $author$
 *    Date: 1/4/2008
 **********************************************************************
 */
typedef cBufferInterfaceT<CHAR> cBufferInterface;
typedef cBufferInterfaceT<CHAR> cCHARBufferInterface;
typedef cBufferInterfaceT<TCHAR> cTCHARBufferInterface;
typedef cBufferInterfaceT<WCHAR> cWCHARBufferInterface;
typedef cBufferInterfaceT<char> cCharBufferInterface;

/**
 **********************************************************************
 *  Class: cBufferImplementT
 *
 * Author: $author$
 *   Date: 12/28/2008
 **********************************************************************
 */
template
<class TWhat = CHAR,
 class TSize = TSIZE,
 class TLength = TLENGTH,
 TLength VUndefined = UNDEFINED_LENGTH,
 class TBufferInterface = cBufferInterfaceT<TWhat, TSize, TLength, VUndefined>,
 class TStreamImplement = cStreamImplementT<TWhat, TSize, TLength, VUndefined>,
 class TBufferImplements = TBufferInterface,
 class TStreamImplements = TStreamImplement>

class c_IMPLEMENT_CLASS cBufferImplementT
: virtual public TStreamImplements, virtual public TBufferImplements {
public:
    typedef TStreamImplements cStreamImplements;
    typedef TBufferImplements cBufferImplements;
    typedef cBufferImplementT cDerives;
    /**
     **********************************************************************
     * Function: GetBuffer
     *
     *   Author: $author$
     *     Date: 12/28/2008
     **********************************************************************
     */
    virtual const TWhat* GetBuffer(TLength& length) const {
        const TWhat* buffer = 0;
        length = -e_ERROR_NOT_IMPLEMENTED;
        return buffer;
    }
};
/**
 **********************************************************************
 * Typedef: cBufferImplement
 *
 *  Author: $author$
 *    Date: 9/28/2017
 **********************************************************************
 */
typedef cBufferImplementT<CHAR> cBufferImplement;
typedef cBufferImplementT<CHAR> cCHARBufferImplement;
typedef cBufferImplementT<TCHAR> cTCHARBufferImplement;
typedef cBufferImplementT<WCHAR> cWCHARBufferImplement;
typedef cBufferImplementT<char> cCharBufferImplement;

/**
 **********************************************************************
 *  Class: cBufferT
 *
 * Author: $author$
 *   Date: 2/15/2007
 **********************************************************************
 */
template
<class TWhat = CHAR,
 class TSize = TSIZE,
 class TLength = TLENGTH,
 class TEnd = TWhat, TEnd VEnd = NULL_CHAR,
 TLength VUndefined = UNDEFINED_LENGTH,
 TSize VDefaultSize = 128,
 class TImplements = cBufferImplementT<TWhat, TSize, TLength, VUndefined>,
 class TExtends = cBase>

class cBufferT: virtual public TImplements, public TExtends {
public:
    typedef TImplements cImplements;
    typedef TExtends cExtends;
    typedef cBufferT cDerives;

    bool m_freeBuffer;
    bool m_fixedSize;

    TSize m_size;
    TLength m_length;
    TLength m_tell;

    const TWhat* m_readBuffer;
    TWhat* m_writeBuffer;
    TWhat m_defaultBuffer[VDefaultSize];

    /**
     **********************************************************************
     * Constructor: cBufferT
     *
     *      Author: $author$
     *        Date: 2/15/2007
     **********************************************************************
     */
    cBufferT
    (const TWhat* what = 0, TLength length = VUndefined)
    : m_freeBuffer(false), m_fixedSize(false),
      m_size(VDefaultSize), m_length(0), m_tell(0),
      m_readBuffer(m_defaultBuffer), m_writeBuffer(m_defaultBuffer) {

        m_defaultBuffer[0] = VEnd;

        if (what) {
            if (0 > (length = Write(what, length))) {
                eError error = 0;
                throw (error = -length);
            }
        }
    }
    /**
     **********************************************************************
     *  Destructor: ~cBufferT
     *
     *      Author: $author$
     *        Date: 2/15/2007
     **********************************************************************
     */
    virtual ~cBufferT() {
    }

    /**
     **********************************************************************
     * Function: Read
     *
     *   Author: $author$
     *     Date: 2/15/2007
     **********************************************************************
     */
    virtual TLength Read
    (TWhat* what, TSize size) {
        TLength length = VUndefined;

        if (size < 1)
            return 0;

        if (!what)
            return -e_ERROR_NULL_PARAMETER;

        if (!m_readBuffer)
            return -e_ERROR_NOT_ATTACHED;

        if (m_tell >= m_length)
            return -e_ERROR_ENDOF;

        if (m_tell + (length = (TLength)(size)) >= m_length)
            size = (TSize)(length = (m_length - m_tell));

        CopyBuffer(what, m_readBuffer+m_tell, size);

        m_tell += length;
        return length;
    }
    /**
     **********************************************************************
     * Function: Copy
     *
     *   Author: $author$
     *     Date: 2/20/2007
     **********************************************************************
     */
    virtual TLength Copy
    (const TWhat* what, TLength length = VUndefined) {
        TLength count = 0;

        if (0 > (count = Clear()))
            return count;

        length = Write(what, length);
        return length;
    }
    /**
     **********************************************************************
     * Function: Write
     *
     *   Author: $author$
     *     Date: 2/15/2007
     **********************************************************************
     */
    virtual TLength Write
    (const TWhat* what, TLength length = VUndefined) {
        eError error = 0;
        TSize newSize = 0;

        if (length < 0)
            length = GetLengthOf(what);

        if (length < 1)
            return 0;

        if (!what)
            return -e_ERROR_NULL_PARAMETER;

        if (!m_writeBuffer)
            return -e_ERROR_NOT_ATTACHED;

        if (m_size < (newSize = (m_tell+length))) {
            if (m_fixedSize) {
                return -e_ERROR_FULL;
            } else {
                if ((error = AdjustToSize(NewSize(newSize))))
                    return -error;
            }
        }

        CopyBuffer(m_writeBuffer+m_tell, what, length);

        if ((m_tell += length) > m_length) {
            if ((TSize)(m_length = m_tell) < m_size)
                m_writeBuffer[m_tell] = (TWhat)(VEnd);
        }
        return length;
    }
    /**
     **********************************************************************
     * Function: Clear
     *
     *   Author: $author$
     *     Date: 2/15/2007
     **********************************************************************
     */
    virtual TLength Clear() {
        TLength length = 0;

        if (!m_writeBuffer)
            return -e_ERROR_NOT_ATTACHED;

        length = m_length;

        if (m_size > (TSize)(m_length = (m_tell = 0)))
            m_writeBuffer[m_tell] = (TWhat)(VEnd);

        return length;
    }

    /**
     **********************************************************************
     * Function: Seek
     *
     *   Author: $author$
     *     Date: 7/6/2003
     **********************************************************************
     */
    virtual TLength Seek
    (TLength offset, int origin = e_SEEK_SET) {
        TLength tell = 0;

        switch(origin) {
        case e_SEEK_SET:
            if (offset < 0)
                tell = -e_ERROR_BEGINOF;
            else {
                if (offset > m_length)
                    tell = -e_ERROR_ENDOF;
                else {
                    tell = (m_tell = offset);
                }
            }
            break;

        case e_SEEK_CUR:
            if ((tell = m_tell+offset) < 0)
                tell = -e_ERROR_BEGINOF;
            else {
                if (tell > m_length)
                    tell = -e_ERROR_ENDOF;
                else {
                    m_tell = tell;
                }
            }
            break;

        case e_SEEK_END:
            if (offset > 0)
                tell = -e_ERROR_ENDOF;
            else {
                if ((tell = m_length-offset) < 0)
                    tell = -e_ERROR_BEGINOF;
                else {
                    m_tell = tell;
                }
            }
            break;

        default:
            tell = -e_ERROR_INVALID_PARAMETER;
        }

        return tell;
    }
    /**
     **********************************************************************
     * Function: Tell
     *
     * Author: $author$
     * Date:   7/17/2003
     **********************************************************************
     */
    virtual TLength Tell() const {
        return m_tell;
    }

    /**
     **********************************************************************
     * Function: Compare
     *
     *   Author: $author$
     *     Date: 12/28/2008
     **********************************************************************
     */
    int Compare
    (const TImplements& to, TLength length=VUndefined) {
        int unequal = 1;
        const TWhat* toBuffer = 0;
        TLength toLength = 0;

        if ((toBuffer = to.GetBuffer(toLength))) {
            if ((0 <= length) && (toLength < length)) {
                length = toLength;
            }
            unequal = Compare(toBuffer, length);
        }
        return unequal;
    }
    /**
     **********************************************************************
     * Function: Compare
     *
     *   Author: $author$
     *     Date: 2/20/2003
     **********************************************************************
     */
    virtual int Compare
    (const TWhat* toBuffer, TLength length=VUndefined) const {
        TLength lendiff = 0;
        const TWhat* whatBuffer = 0;
        TWhat to, what;

        if (!(whatBuffer = m_readBuffer)) {
            return toBuffer?-1:1;
        }

        if (length < 0) {
            length = GetLengthOf(toBuffer);
        }

        if (0 < (lendiff = (length - m_length))) {
            lendiff = -1;
            length = m_length;
        } else {
            if (lendiff) {
                lendiff = 1;
            }
        }

        if (length > 0) {
            do {
                if ((what = *(whatBuffer++)) > (to = *(toBuffer++))) {
                    return 1;
                }
                if (what < to) {
                    return -1;
                }
            } while (--length > 0);
        }
        return lendiff;
    }

    /**
     **********************************************************************
     * Function: GetBuffer
     *
     *   Author: $author$
     *     Date: 2/15/2007
     **********************************************************************
     */
    virtual const TWhat* GetBuffer() const {
        TSize size;
        TLength length;
        return GetBuffer(size, length);
    }
    /**
     **********************************************************************
     * Function: GetBuffer
     *
     *   Author: $author$
     *     Date: 2/15/2007
     **********************************************************************
     */
    virtual const TWhat* GetBuffer(TLength &length) const {
        TSize size;
        return GetBuffer(size, length);
    }
    /**
     **********************************************************************
     * Function: GetBuffer
     *
     *   Author: $author$
     *     Date: 2/15/2007
     **********************************************************************
     */
    virtual const TWhat* GetBuffer(TSize& size, TLength &length) const {
        size = m_size;
        length = m_length;
        return m_readBuffer;
    }

    /**
     **********************************************************************
     * Function: GetWriteBuffer
     *
     *   Author: $author$
     *     Date: 2/15/2007
     **********************************************************************
     */
    virtual TWhat* GetWriteBuffer() const {
        TSize size;
        TLength length;
        return GetWriteBuffer(size, length);
    }
    /**
     **********************************************************************
     * Function: GetWriteBuffer
     *
     *   Author: $author$
     *     Date: 2/15/2007
     **********************************************************************
     */
    virtual TWhat* GetWriteBuffer(TLength &length) const {
        TSize size;
        return GetWriteBuffer(size, length);
    }
    /**
     **********************************************************************
     * Function: GetWriteBuffer
     *
     *   Author: $author$
     *     Date: 2/15/2007
     **********************************************************************
     */
    virtual TWhat* GetWriteBuffer(TSize& size, TLength &length) const {
        size = m_size;
        length = m_length;
        return m_writeBuffer;
    }

    /**
     **********************************************************************
     * Function: SetSize
     *
     *   Author: $author$
     *     Date: 2/15/2007
     **********************************************************************
     */
    virtual TLength SetSize(TSize size) {
        eError error = 0;
        if (size >= m_size) {
            if (m_fixedSize) {
                return -e_ERROR_FULL;
             } else {
                if ((error = AdjustToSize(NewSize(size)))) {
                    return -error;
                }
            }
        }
        return (TLength)(m_size);
    }
    /**
     **********************************************************************
     * Function: GetSize
     *
     *   Author: $author$
     *     Date: 2/15/2007
     **********************************************************************
     */
    virtual TLength GetSize() const {
        return (TLength)(m_size);
    }

    /**
     **********************************************************************
     * Function: SetLength
     *
     *   Author: $author$
     *     Date: 2/15/2007
     **********************************************************************
     */
    virtual TLength SetLength(TLength length) {
        TLength size = 0;

        if (!m_writeBuffer) {
            return -e_ERROR_NOT_ATTACHED;
        }
        if (0 > length) {
            if (0 > (length = GetLengthOf(m_writeBuffer))) {
                return -e_ERROR_FAILED;
            }
        }
        if ((TSize)(length) > m_size) {
            if (length > (size = SetSize(length))) {
                if (size < 0) {
                    return size;
                } else {
                    return -e_ERROR_FULL;
                }
            }
        }
        m_tell = length;
        if (m_size > (TSize)(m_length = m_tell)) {
            m_writeBuffer[m_tell] = (TWhat)(VEnd);
        }
        return m_length;
    }
    /**
     **********************************************************************
     * Function: GetLength
     *
     *   Author: $author$
     *     Date: 2/15/2007
     **********************************************************************
     */
    virtual TLength GetLength() const {
        return m_length;
    }

    /**
     **********************************************************************
     * Function: CopyBuffer
     *
     *   Author: $author$
     *     Date: 2/15/2007
     **********************************************************************
     */
    virtual TLength CopyBuffer
    (TWhat* to, const TWhat* from, TSize size) {
        TLength length = size;
        memcpy(to, from, sizeof(TWhat)*size);
        return length;
    }
    /**
     **********************************************************************
     * Function: AdjustToSize
     *
     *   Author: $author$
     *     Date: 2/15/2007
     **********************************************************************
     */
    virtual eError AdjustToSize(TSize size) {
        bool allocBuffer = false;
        TWhat* buffer = 0;

        if (!m_writeBuffer) {
            return e_ERROR_NOT_ATTACHED;
        }
        if (size <= m_size) {
            return e_ERROR_NONE;
        }
        /* Set m_free_buffer here if it has not already been
         * done to make sure the buffer will be freed upon
         * destruction.
         */
        if ((allocBuffer = !m_freeBuffer)) {
            m_freeBuffer = true;
        }
        if (!(buffer = new TWhat[size])) {
            if (allocBuffer) {
                m_freeBuffer = false;
            }
            return e_ERROR_NEW;
        }
        if (m_writeBuffer) {
            if (m_length > 0) {
                CopyBuffer(buffer, m_writeBuffer, m_length);
            }
            if (m_writeBuffer != m_defaultBuffer) {
                delete m_writeBuffer;
            }
        }
        m_writeBuffer = buffer;
        m_readBuffer = buffer;
        m_size = size;
        return e_ERROR_NONE;
    }
    /**
     **********************************************************************
     * Function: NewSize
     *
     *   Author: $author$
     *     Date: 2/15/2007
     **********************************************************************
     */
    virtual TSize NewSize(TSize size) {
        /* Lets increase the buffer size by default buffer
         * sized chunks. Note the desired new size is always
         * needed size + 1. The size in chunks is calculated
         * as (new size + (chunk size - 1)) / chunk size.
         * since new size = needed size + 1 then we have
         * chunks = (needed size + chunk size) / chunk size.
         * Finally we need bytes which is chunks * chunk size
         * which can be reduced to
         * ((needed size / chunk size) + 1) * chunk size
         */
        return ((size / VDefaultSize) + 1) * VDefaultSize;
    }
    /**
     **********************************************************************
     * Function: GetLengthOf
     *
     *   Author: $author$
     *     Date: 2/15/2007
     **********************************************************************
     */
    virtual TLength GetLengthOf(const TWhat* buffer) const {
        TLength length = 0;
        TWhat what = 0;

        for (length = 0; (what = *buffer) != (TWhat)(VEnd); buffer++) {
            length++;
        }
        return length;
    }
};
/**
 **********************************************************************
 * Typedef: cBuffer
 *
 *  Author: $author$
 *    Date: 9/28/2017
 **********************************************************************
 */
typedef cBufferT<CHAR> cBuffer;
typedef cBufferT<CHAR> cCHARBuffer;
typedef cBufferT<TCHAR> cTCHARBuffer;
typedef cBufferT<WCHAR> cWCHARBuffer;
typedef cBufferT<char> cCharBuffer;

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#endif /* _XDE_BASE_CBUFFER_HXX */
