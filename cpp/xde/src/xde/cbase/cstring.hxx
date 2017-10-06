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
 *   File: cstring.hxx
 *
 * Author: $author$
 *   Date: 9/28/2017
 **********************************************************************
 */
#ifndef _XDE_BASE_CSTRING_HXX
#define _XDE_BASE_CSTRING_HXX

#include "xde/cbase/cbuffer.hxx"
#include "xde/cdebug/cdebug.hxx"
#include <string>

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/**
 **********************************************************************
 *  Class: cStringInterfaceT
 *
 * Author: $author$
 *   Date: 1/7/2008
 **********************************************************************
 */
template
<class TChar = CHAR,
 class TSize = TSIZE,
 class TLength = TLENGTH,
 TLength VUndefinedLength = UNDEFINED_LENGTH,
 class TNullChar = TChar,
 TNullChar VNullChar = NULL_CHAR,
 class TStreamInterface = cStreamInterfaceT<TChar, TSize, TLength, VUndefinedLength>,
 class TImplements = TStreamInterface>

class c_INTERFACE_CLASS cStringInterfaceT: virtual public TImplements {
public:
    typedef TImplements cImplements;
    typedef cStringInterfaceT cDerives;

    /**
     **********************************************************************
     * Function: ReadLine
     *
     *   Author: $author$
     *     Date: 1/7/2008
     **********************************************************************
     */
    virtual TLength ReadLine
    (TStreamInterface& stream,
     TChar* chars, TSize size,
     bool hasCR=false) = 0;
    /**
     **********************************************************************
     * Function: WriteLine
     *
     *   Author: $author$
     *     Date: 1/7/2008
     **********************************************************************
     */
    virtual TLength WriteLine
    (TStreamInterface& stream,
     TLength length=VUndefinedLength,
     bool hasCR=false) = 0;

    /**
     **********************************************************************
     * Function: Read
     *
     *   Author: $author$
     *     Date: 1/7/2008
     **********************************************************************
     */
    virtual TLength Read
    (TStreamInterface& stream,
     TChar* chars, TSize size) = 0;
    /**
     **********************************************************************
     * Function: Write
     *
     *   Author: $author$
     *     Date: 1/7/2008
     **********************************************************************
     */
    virtual TLength Write
    (TStreamInterface& stream,
     TLength length=VUndefinedLength) = 0;

    /**
     **********************************************************************
     * Function: Assignc
     *
     *   Author: $author$
     *     Date: 1/7/2008
     **********************************************************************
     */
    virtual TLength Assignc
    (const char* chars,
     TLength length=VUndefinedLength) = 0;
    /**
     **********************************************************************
     * Function: Appendc
     *
     *   Author: $author$
     *     Date: 1/7/2008
     **********************************************************************
     */
    virtual TLength Appendc
    (const char* chars,
     TLength length=VUndefinedLength) = 0;

    /**
     **********************************************************************
     * Function: Assign
     *
     *   Author: $author$
     *     Date: 1/7/2008
     **********************************************************************
     */
    virtual TLength Assign
    (const TChar* chars,
     TLength length=VUndefinedLength) = 0;
    /**
     **********************************************************************
     * Function: Append
     *
     *   Author: $author$
     *     Date: 1/7/2008
     **********************************************************************
     */
    virtual TLength Append
    (const TChar* chars,
     TLength length=VUndefinedLength) = 0;
    /**
     **********************************************************************
     * Function: Clear
     *
     *   Author: $author$
     *     Date: 1/7/2008
     **********************************************************************
     */
    virtual TLength Clear() = 0;

    /**
     **********************************************************************
     * Function: AssignChars
     *
     *   Author: $author$
     *     Date: 9/5/2008
     **********************************************************************
     */
    virtual TLength AssignChars
    (const TChar* chars,
     TLength length=VUndefinedLength) = 0;
    /**
     **********************************************************************
     * Function: AppendChars
     *
     *   Author: $author$
     *     Date: 9/5/2008
     **********************************************************************
     */
    virtual TLength AppendChars
    (const TChar* chars,
     TLength length=VUndefinedLength) = 0;
    /**
     **********************************************************************
     * Function: ClearChars
     *
     *   Author: $author$
     *     Date: 9/5/2008
     **********************************************************************
     */
    virtual TLength ClearChars() = 0;

    /**
     **********************************************************************
     * Function: CaseComparec
     *
     *   Author: $author$
     *     Date: 1/7/2008
     **********************************************************************
     */
    virtual int CaseComparec
    (const char* chars,
     TLength length=VUndefinedLength) const = 0;
    /**
     **********************************************************************
     * Function: Comparec
     *
     *   Author: $author$
     *     Date: 1/7/2008
     **********************************************************************
     */
    virtual int Comparec
    (const char* chars,
     TLength length=VUndefinedLength) const = 0;

    /**
     **********************************************************************
     * Function: CaseCompare
     *
     *   Author: $author$
     *     Date: 1/7/2008
     **********************************************************************
     */
    virtual int CaseCompare
    (const TChar* chars,
     TLength length=VUndefinedLength) const = 0;
    /**
     **********************************************************************
     * Function: Compare
     *
     *   Author: $author$
     *     Date: 1/7/2008
     **********************************************************************
     */
    virtual int Compare
    (const TChar* chars,
     TLength length=VUndefinedLength) const = 0;

    /**
     **********************************************************************
     * Function: Length
     *
     *   Author: $author$
     *     Date: 1/7/2008
     **********************************************************************
     */
    virtual TLength Length() const = 0;
    /**
     **********************************************************************
     * Function: HasChars
     *
     *   Author: $author$
     *     Date: 1/7/2008
     **********************************************************************
     */
    virtual const TChar* HasChars
    (TLength& length) const = 0;
    /**
     **********************************************************************
     * Function: Chars
     *
     *   Author: $author$
     *     Date: 1/7/2008
     **********************************************************************
     */
    virtual const TChar* Chars
    (TLength& length) const = 0;
};
/**
 **********************************************************************
 * Typedef: cStringInterface
 *
 *  Author: $author$
 *    Date: 1/7/2008
 **********************************************************************
 */
typedef cStringInterfaceT<CHAR> cStringInterface;
typedef cStringInterfaceT<CHAR> cCHARStringInterface;
typedef cStringInterfaceT<TCHAR> cTCHARStringInterface;
typedef cStringInterfaceT<WCHAR> cWCHARStringInterface;
typedef cStringInterfaceT<char> cChartringInterface;

/**
 **********************************************************************
 *  Class: cStringImplementT
 *
 * Author: $author$
 *   Date: 1/7/2008
 **********************************************************************
 */
template
<class TChar = CHAR,
 class TSize = TSIZE,
 class TLength = TLENGTH,
 TLength VUndefinedLength = UNDEFINED_LENGTH,
 class TNullChar = TChar,
 TNullChar VNullChar = NULL_CHAR,
 class TStreamInterface = cStreamInterfaceT<TChar, TSize, TLength, VUndefinedLength>,
 class TStreamImplement = cStreamImplementT<TChar, TSize, TLength, VUndefinedLength>,
 class TStringInterface = cStringInterfaceT<TChar, TSize, TLength, VUndefinedLength, TNullChar, VNullChar>,
 class TStringImplements = TStringInterface,
 class TStreamImplements = TStreamImplement>

class cStringImplementT
: virtual public TStreamImplements, virtual public TStringImplements {
public:
    typedef TStreamImplements cStreamImplements;
    typedef TStringImplements cStringImplements;
    typedef cStringImplementT cDerives;

    /**
     **********************************************************************
     * Function: AssignL
     *
     *   Author: $author$
     *     Date: 5/1/2008
     **********************************************************************
     */
    virtual TLength AssignL
    (const TChar* chars, ...) {
        TLength count = 0;
        TLength count2;
        va_list arg;

        va_start(arg, chars);

        if (0 <= (count = Assign(chars)))
        if (0 <= (count2 = AppendV(arg)))
            count += count2;

        va_end(arg);
        return count;
    }
    /**
     **********************************************************************
     * Function: AppendL
     *
     *   Author: $author$
     *     Date: 5/1/2008
     **********************************************************************
     */
    virtual TLength AppendL
    (const TChar* chars, ...) {
        TLength count = 0;
        TLength count2;
        va_list arg;

        va_start(arg, chars);

        if (0 <= (count = Append(chars)))
        if (0 <= (count2 = AppendV(arg)))
            count += count2;

        va_end(arg);
        return count;
    }

    /**
     **********************************************************************
     * Function: AssignV
     *
     *   Author: $author$
     *     Date: 10/1/2017
     **********************************************************************
     */
    virtual TLength AassignV(va_list va) {
        TLength count = 0;
        Clear();
        count = AppendV(va);
        return count;
    }
    /**
     **********************************************************************
     * Function: AppendV
     *
     *   Author: $author$
     *     Date: 5/1/2008
     **********************************************************************
     */
    virtual TLength AppendV(va_list va) {
        TLength count = 0;
        TLength count2;
        const TChar* chars;

        while ((chars = va_arg(va, const TChar*)))
        {
            if (0 > (count2 = Append(chars)))
                return count2;
            count += count2;
        }
        return count;
    }

    /**
     **********************************************************************
     * Function: CopyTo
     *
     *   Author: $author$
     *     Date: 1/7/2008
     **********************************************************************
     */
    virtual TLength CopyTo
    (TChar* toChars, const TChar* chars, TSize size) const {
        TLength count = (TLength)(size);
        memcpy(toChars, chars, sizeof(TChar)*size);
        return count;
    }
    /**
     **********************************************************************
     * Function: LengthOf
     *
     *   Author: $author$
     *     Date: 1/7/2008
     **********************************************************************
     */
    virtual TLength LengthOf
    (const TChar* chars) const {
        TLength count = -e_ERROR_NOT_IMPLEMENTED;
        for (count=0; *chars != VNullChar; count++)
            chars++;
        return count;
    }

    /**
     **********************************************************************
     * Function: ReadLine
     *
     *   Author: $author$
     *     Date: 1/7/2008
     **********************************************************************
     */
    virtual TLength ReadLine
    (TStreamInterface& stream,
     TChar* chars, TSize size,
     bool hasCR=false)
    {
        const TChar lf = (TChar)('\n');
        const TChar cr = (TChar)('\r');
        TLength count = -e_ERROR_NOT_IMPLEMENTED;
        TSize length;
        TChar c;

        for (length = 0; (length < size);)
        {
            if (0 > (count = stream.Read(chars+length, 1)))
                return count = -e_ERROR_READ;

            if ((c = chars[length]) != lf)
            {
                if (hasCR || (c != cr))
                    length++;
                continue;
            }
            break;
        }

        count = Assign(chars, length);
        return count;
    }
    /**
     **********************************************************************
     * Function: WriteLine
     *
     *   Author: $author$
     *     Date: 1/7/2008
     **********************************************************************
     */
    virtual TLength WriteLine
    (TStreamInterface& stream,
     TLength length=VUndefinedLength,
     bool hasCR=false)
    {
        const TChar lf = (TChar)('\n');
        const TChar cr = (TChar)('\r');
        TLength count = -e_ERROR_NOT_IMPLEMENTED;

        if (0 <= (count = Write(stream, length)))
        if (0 < (length = stream.Write(&lf, 1)))
        if (0 < (count += length))
        if (hasCR)
        if (0 >= (length = stream.Write(&cr, 1)))
            return count = -e_ERROR_WRITE;

        return count;
    }

    /**
     **********************************************************************
     * Function: Read
     *
     *   Author: $author$
     *     Date: 1/7/2008
     **********************************************************************
     */
    virtual TLength Read
    (TStreamInterface& stream,
     TChar* chars, TSize size)
    {
        TLength count = -e_ERROR_NOT_IMPLEMENTED;

        if (0 > (count = stream.Read(chars, size)))
            return count = -e_ERROR_FAILED;

        count = Assign(chars, count);
        return count;
    }
    /**
     **********************************************************************
     * Function: Write
     *
     *   Author: $author$
     *     Date: 1/7/2008
     **********************************************************************
     */
    virtual TLength Write
    (TStreamInterface& stream,
     TLength length=VUndefinedLength)
    {
        TLength count = -e_ERROR_NOT_IMPLEMENTED;
        const TChar* chars;

        if (!(chars = HasChars(count)))
            return count;

        if ((0 > length) || (length > count))
            length = count;

        if (0 > (count = stream.Write(chars, length)))
            count = -e_ERROR_FAILED;
        return count;
    }

    /**
     **********************************************************************
     * Function: Assignc
     *
     *   Author: $author$
     *     Date: 1/7/2008
     **********************************************************************
     */
    virtual TLength Assignc
    (const char* chars,
     TLength length=VUndefinedLength)
    {
        TLength count = -e_ERROR_NOT_IMPLEMENTED;
        return count;
    }
    /**
     **********************************************************************
     * Function: Appendc
     *
     *   Author: $author$
     *     Date: 1/7/2008
     **********************************************************************
     */
    virtual TLength Appendc
    (const char* chars,
     TLength length=VUndefinedLength)
    {
        TLength count = -e_ERROR_NOT_IMPLEMENTED;
        return count;
    }

    /**
     **********************************************************************
     * Function: Assign
     *
     *   Author: $author$
     *     Date: 1/7/2008
     **********************************************************************
     */
    virtual TLength Assign
    (const TChar* chars,
     TLength length=VUndefinedLength)
    {
        TLength count = AssignChars(chars, length);
        return count;
    }
    /**
     **********************************************************************
     * Function: Append
     *
     *   Author: $author$
     *     Date: 1/7/2008
     **********************************************************************
     */
    virtual TLength Append
    (const TChar* chars,
     TLength length=VUndefinedLength)
    {
        TLength count = AppendChars(chars, length);
        return count;
    }
    /**
     **********************************************************************
     * Function: Clear
     *
     *   Author: $author$
     *     Date: 1/7/2008
     **********************************************************************
     */
    virtual TLength Clear()
    {
        TLength count = ClearChars();
        return count;
    }

    /**
     **********************************************************************
     * Function: AssignChars
     *
     *   Author: $author$
     *     Date: 9/5/2008
     **********************************************************************
     */
    virtual TLength AssignChars
    (const TChar* chars,
     TLength length=VUndefinedLength)
    {
        TLength count = -e_ERROR_NOT_IMPLEMENTED;
        if (0 <= (count = ClearChars()))
            count = AppendChars(chars, length);
        return count;
    }
    /**
     **********************************************************************
     * Function: AppendChars
     *
     *   Author: $author$
     *     Date: 9/5/2008
     **********************************************************************
     */
    virtual TLength AppendChars
    (const TChar* chars,
     TLength length=VUndefinedLength)
    {
        TLength count = -e_ERROR_NOT_IMPLEMENTED;
        return count;
    }
    /**
     **********************************************************************
     * Function: ClearChars
     *
     *   Author: $author$
     *     Date: 9/5/2008
     **********************************************************************
     */
    virtual TLength ClearChars()
    {
        TLength count = -e_ERROR_NOT_IMPLEMENTED;
        return count;
    }

    /**
     **********************************************************************
     * Function: CaseComparec
     *
     *   Author: $author$
     *     Date: 1/7/2008
     **********************************************************************
     */
    virtual int CaseComparec
    (const char* chars,
     TLength length=VUndefinedLength) const
    {
        int unequal = -e_ERROR_NOT_IMPLEMENTED-1;
        return unequal;
    }
    /**
     **********************************************************************
     * Function: Comparec
     *
     *   Author: $author$
     *     Date: 1/7/2008
     **********************************************************************
     */
    virtual int Comparec
    (const char* chars,
     TLength length=VUndefinedLength) const
    {
        int unequal = -e_ERROR_NOT_IMPLEMENTED-1;
        return unequal;
    }
    /**
     **********************************************************************
     * Function: CaseCompare
     *
     *   Author: $author$
     *     Date: 1/7/2008
     **********************************************************************
     */
    virtual int CaseCompare
    (const TChar* chars,
     TLength length=VUndefinedLength) const
    {
        int unequal = -e_ERROR_NOT_IMPLEMENTED-1;
        return unequal;
    }
    /**
     **********************************************************************
     * Function: Compare
     *
     *   Author: $author$
     *     Date: 1/7/2008
     **********************************************************************
     */
    virtual int Compare
    (const TChar* chars,
     TLength length=VUndefinedLength) const
    {
        int unequal = -e_ERROR_NOT_IMPLEMENTED-1;
        return unequal;
    }

    /**
     **********************************************************************
     * Function: Length
     *
     *   Author: $author$
     *     Date: 1/7/2008
     **********************************************************************
     */
    virtual TLength Length() const
    {
        TLength count = -e_ERROR_NOT_IMPLEMENTED;
        return count;
    }
    /**
     **********************************************************************
     * Function: HasChars
     *
     *   Author: $author$
     *     Date: 1/7/2008
     **********************************************************************
     */
    virtual const TChar* HasChars
    (TLength& length) const
    {
        const TChar* chars = 0;
        if (!(chars = Chars(length)) || (0 >= length))
            chars = 0;
        return chars;
    }
    /**
     **********************************************************************
     * Function: Chars
     *
     *   Author: $author$
     *     Date: 1/7/2008
     **********************************************************************
     */
    virtual const TChar* Chars
    (TLength& length) const
    {
        const TChar* chars = 0;
        return chars;
    }
};
/**
 **********************************************************************
 * Typedef: cStringImplement
 *
 *  Author: $author$
 *    Date: 1/7/2008
 **********************************************************************
 */
typedef cStringImplementT<CHAR> cStringImplement;
typedef cStringImplementT<CHAR> cCHARStringImplement;
typedef cStringImplementT<TCHAR> cTCHARStringImplement;
typedef cStringImplementT<WCHAR> cWCHARStringImplement;
typedef cStringImplementT<char> cCharStringImplement;

/**
 **********************************************************************
 *  Class: cStringT
 *
 * Author: $author$
 *   Date: 1/7/2008
 **********************************************************************
 */
template
<class TChar = CHAR,
 class TSize = TSIZE,
 class TLength = TLENGTH,
 TLength VUndefinedLength = UNDEFINED_LENGTH,
 class TNullChar = TChar,
 TNullChar VNullChar = NULL_CHAR,
 class TStringBase = ::std::basic_string<TChar>,
 class TStringImplement = cStringImplementT<TChar, TSize, TLength, VUndefinedLength, TNullChar, VNullChar>,
 class TImplements = TStringImplement, class TExtends = TStringBase>

class cStringT: virtual public TImplements, public TExtends {
public:
    typedef TImplements cImplements;
    typedef TExtends cExtends;
    typedef cStringT cDerives;

    TSize m_tell;

    /**
     **********************************************************************
     * Constructor: cStringT
     *
     *      Author: $author$
     *        Date: 1/7/2008
     **********************************************************************
     */
    cStringT
    (const TChar* chars=0,
     TLength length=VUndefinedLength)
    : m_tell(0)
    {
        eError error;
        if (chars)
        if (0 > (length = Append(chars, length)))
            throw(error = -length);
    }
    /**
     **********************************************************************
     * Destructor: cStringT
     *
     *     Author: $author$
     *       Date: 1/7/2008
     **********************************************************************
     */
    virtual ~cStringT()
    {
    }

    /**
     **********************************************************************
     * Function: Read
     *
     *   Author: $author$
     *     Date: 1/7/2008
     **********************************************************************
     */
    virtual TLength Read
    (TChar* chars, TSize size)
    {
        TLength count = -e_ERROR_NOT_IMPLEMENTED;
        TSize length;
        TSize told;
        const TChar* thisChars;

        if (!(thisChars = this->HasChars(count)))
            return count;

        if (m_tell >= (length = (TSize)(count)))
            return 0;

        if (length < (told = m_tell+size))
            count = (TLength)((told = length) - m_tell);
        else count = (TLength)(size);

        if (0 <= (count = this->CopyTo
            (chars, thisChars+m_tell, count)))
            m_tell = told;
        return count;
    }

    /**
     **********************************************************************
     * Function: AssignSigned
     *
     *   Author: $author$
     *     Date: 8/1/2008
     **********************************************************************
     */
    virtual TLength AssignSigned(TLength value)
    {
        TLength length = 0;
        if (0 > (length = Clear()))
            return length;
        length = AppendSigned(value);
        return length;
    }
    /**
     **********************************************************************
     * Function: AssignUnsigned
     *
     *   Author: $author$
     *     Date: 8/1/2008
     **********************************************************************
     */
    virtual TLength AssignUnsigned(TLength value)
    {
        TLength length = 0;
        if (0 > (length = Clear()))
            return length;
        length = AppendUnsigned(value);
        return length;
    }
    /**
     **********************************************************************
     * Function: AssignUpper
     *
     *   Author: $author$
     *     Date: 8/1/2008
     **********************************************************************
     */
    virtual TLength AssignUpper
    (const TChar* chars,
     TLength length=VUndefinedLength)
    {
        TLength llength = 0;
        if (0 > (llength = Clear()))
            return llength;
        length = AppendUpper(chars, length);
        return length;
    }
    /**
     **********************************************************************
     * Function: AssignLower
     *
     *   Author: $author$
     *     Date: 8/1/2008
     **********************************************************************
     */
    virtual TLength AssignLower
    (const TChar* chars,
     TLength length=VUndefinedLength)
    {
        TLength llength = 0;
        if (0 > (llength = Clear()))
            return llength;
        length = AppendLower(chars, length);
        return length;
    }

    /**
     **********************************************************************
     * Function: AppendSigned
     *
     *   Author: $author$
     *     Date: 1/7/2008
     **********************************************************************
     */
    virtual TLength AppendSigned(TLength value)
    {
        TChar c = ((TChar)('0'));
        TChar s = ((TChar)('-'));
        TLength length = 0;
        TSize digits;
        TSize msdValue;

        if (0 == value)
            length = Append(&c, 1);
        else
        {
            if (0 > value)
            {
                length = Append(&s, 1);
                value = -value;
            }
            for (digits = 0, msdValue = 0;
                 value; value /= 10, digits++)
                msdValue = (msdValue*10) + (value%10);
            for (; msdValue; msdValue /= 10, --digits)
            {
                TChar d = c + (TChar)(msdValue%10);
                length += Append(&d, 1);
            }
            for (; digits; --digits)
                length += Append(&c, 1);
        }
        return length;
    }
    /**
     **********************************************************************
     * Function: AppendUnsigned
     *
     *   Author: $author$
     *     Date: 1/7/2008
     **********************************************************************
     */
    virtual TLength AppendUnsigned(TSize value)
    {
        TChar c = ((TChar)('0'));
        TLength length = 0;
        TSize digits;
        TSize msdValue;

        if (0 == value)
            length = Append(&c, 1);
        else
        {
            for (digits = 0, msdValue = 0;
                 value; value /= 10, digits++)
                msdValue = (msdValue*10) + (value%10);
            for (; msdValue; msdValue /= 10, --digits)
            {
                TChar d = c + (TChar)(msdValue%10);
                length += Append(&d, 1);
            }
            for (; digits; --digits)
                length += Append(&c, 1);
        }
        return length;
    }
    /**
     **********************************************************************
     * Function: AppendUpper
     *
     *   Author: $author$
     *     Date: 1/7/2008
     **********************************************************************
     */
    virtual TLength AppendUpper
    (const TChar* chars,
     TLength length=VUndefinedLength)
    {
        DF(AppendUpper)
        const TChar a = ((TChar)'a');
        const TChar z = ((TChar)'z');
        const TChar A = ((TChar)'A');
        TLength oldLength = Length();
        TLength i;
        TChar c;

        if (chars)
        for (i = 0; length; i++)
        {
            c = chars[i];

            if (0 < length)
                --length;
            else if ((0 > length) && !c)
                    break;

            if ((c >= a) && (c <= z))
                c = A + (c - a);

            this->append(&c, 1);
        }
        length = Length()-oldLength;
        return length;
    }
    /**
     **********************************************************************
     * Function: AppendLower
     *
     *   Author: $author$
     *     Date: 1/7/2008
     **********************************************************************
     */
    virtual TLength AppendLower
    (const TChar* chars,
     TLength length=VUndefinedLength)
    {
        DF(AppendLower)
        const TChar A = ((TChar)'A');
        const TChar Z = ((TChar)'Z');
        const TChar a = ((TChar)'a');
        TLength oldLength = Length();
        TLength i;
        TChar c;

        if (chars)
        for (i = 0; length; i++)
        {
            c = chars[i];

            if (0 < length)
                --length;
            else if ((0 > length) && !c)
                    break;

            if ((c >= A) && (c <= Z))
                c = a + (c - A);

            this->append(&c, 1);
        }
        length = Length()-oldLength;
        return length;
    }

    /**
     **********************************************************************
     * Function: Assign
     *
     *   Author: $author$
     *     Date: 9/5/2008
     **********************************************************************
     */
    virtual TLength Assign
    (const TChar* chars,
     TLength length=VUndefinedLength)
    {
        TLength count = AssignChars(chars, length);
        return count;
    }
    /**
     **********************************************************************
     * Function: Append
     *
     *   Author: $author$
     *     Date: 1/7/2008
     **********************************************************************
     */
    virtual TLength Append
    (const TChar* chars,
     TLength length=VUndefinedLength)
    {
        TLength count = AppendChars(chars, length);
        return count;
    }
    /**
     **********************************************************************
     * Function: Clear
     *
     *   Author: $author$
     *     Date: 1/7/2008
     **********************************************************************
     */
    virtual TLength Clear()
    {
        TLength count = ClearChars();
        return count;
    }

    /**
     **********************************************************************
     * Function: AssignChars
     *
     *   Author: $author$
     *     Date: 9/5/2008
     **********************************************************************
     */
    virtual TLength AssignChars
    (const TChar* chars,
     TLength length=VUndefinedLength)
    {
        TLength count = 0;
        if (!chars)
        {
            if (0 > (count = Clear()))
                return count;
            return 0;
        }
        if (0 > length)
        if (0 > (length = this->LengthOf(chars)))
            return length;
        this->assign(chars, length);
        count = length;
        m_tell = 0;
        return count;
    }
    /**
     **********************************************************************
     * Function: AppendChars
     *
     *   Author: $author$
     *     Date: 9/5/2008
     **********************************************************************
     */
    virtual TLength AppendChars
    (const TChar* chars,
     TLength length=VUndefinedLength)
    {
        TLength count = 0;
        if (!chars)
            return 0;
        if (0 > length)
        if (0 > (length = this->LengthOf(chars)))
            return length;
        this->append(chars, length);
        count = length;
        return count;
    }
    /**
     **********************************************************************
     * Function: ClearChars
     *
     *   Author: $author$
     *     Date: 9/5/2008
     **********************************************************************
     */
    virtual TLength ClearChars()
    {
        TLength count = Length();
        CTHIS clear();
        m_tell = 0;
        return count;
    }

    /**
     **********************************************************************
     * Function: Length
     *
     *   Author: $author$
     *     Date: 1/7/2008
     **********************************************************************
     */
    virtual TLength Length() const
    {
        TLength count = (TLength)(CTHIS length());
        return count;
    }

    /**
     **********************************************************************
     * Function: Signed
     *
     *   Author: $author$
     *     Date: 1/7/2008
     **********************************************************************
     */
    virtual TLength Signed(TLength& digits) const
    {
        const TChar c0 = (TChar)('0');
        const TChar c9 = (TChar)('9');
        const TChar minus = (TChar)('-');
        bool negative = false;
        TLength value = 0;
        TLength count, length;
        const TChar* chars;
        TChar c, d;

        if (((chars = Chars(length))) && (0 < length))
        for (digits = 0, count = 0; count < length; count++)
        {
            if (((c = chars[count]) >= c0) && (c <= c9))
            {
                value = (value*10) + (TLength)(d = (TChar)(c - c0));

                if ((d != 0) || digits)
                    digits++;
            }
            else if (minus == c)
                    negative = true;
        }
        if (negative)
            return -value;
        return value;
    }
    /**
     **********************************************************************
     * Function: Unsigned
     *
     *   Author: $author$
     *     Date: 1/7/2008
     **********************************************************************
     */
    virtual TSize Unsigned(TLength& digits) const
    {
        const TChar c0 = (TChar)('0');
        const TChar c9 = (TChar)('9');
        TSize value = 0;
        TLength count, length;
        const TChar* chars;
        TChar c, d;

        if (((chars = Chars(length))) && (0 < length))
        for (digits = 0, count = 0; count < length; count++)
        {
            if (((c = chars[count]) >= c0) && (c <= c9))
            {
                value = (value*10) + (TLength)(d = (TChar)(c - c0));

                if ((d != 0) || digits)
                    digits++;
            }
        }
        return value;
    }
    /**
     **********************************************************************
     * Function: Chars
     *
     *   Author: $author$
     *     Date: 1/7/2008
     **********************************************************************
     */
    virtual const TChar* Chars
    (TLength& length) const
    {
        const TChar* chars = CTHIS c_str();
        length = Length();
        return chars;
    }
    /**
     **********************************************************************
     * Function: Compare
     *
     *   Author: $author$
     *     Date: 1/7/2008
     **********************************************************************
     */
    virtual int Compare
    (const TChar* chars,
     TLength length=VUndefinedLength) const
    {
        int unequal = -e_ERROR_FAILED-1;
        if (chars)
        if (0 > length)
            unequal = this->compare(chars);
        else
        {
            cExtends to;
            to.assign(chars, length);
            unequal = this->compare(to);
        }
        return unequal;
    }
#if defined(NO_STD_STRING_CLEAR)
    /**
     **********************************************************************
     * Function: clear
     *
     *   Author: $author$
     *     Date: 1/7/2008
     **********************************************************************
     */
    void clear() {
        assign("");
    }
#endif /* defined(NO_STD_STRING_CLEAR) */
};
/**
 **********************************************************************
 * Typedef: cString
 *
 *  Author: $author$
 *    Date: 1/7/2008
 **********************************************************************
 */
typedef cStringT<CHAR> cString;
typedef cStringT<CHAR> cCHARString;
typedef cStringT<TCHAR> cTCHARString;
typedef cStringT<WCHAR> cWCHARString;
typedef cStringT<char> cCharString;

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#endif /* _XDE_BASE_CSTRING_HXX */
