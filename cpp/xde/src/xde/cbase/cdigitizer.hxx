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
 *   File: cdigitizer.hxx
 *
 * Author: $author$
 *   Date: 10/2/2017
 **********************************************************************
 */
#ifndef _XDE_BASE_CDIGITIZER_HXX
#define _XDE_BASE_CDIGITIZER_HXX

#include "xde/cbase/cbase.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/**
 **********************************************************************
 *  Class: cDigitizerT
 *
 * Author: $author$
 *   Date: 3/21/2008
 **********************************************************************
 */
template
<class TWhat=CHAR,
 class TLength=TLENGTH,
 TLength VUndefinedLength=UNDEFINED_LENGTH,
 class TNull=TWhat,
 TNull VNull=NULL_CHAR,
 class TSigned=TSIGNED,
 class TUnsigned=TUNSIGNED,
 class TExtends=cBase>

class cDigitizerT
: public TExtends
{
public:
    typedef TExtends cExtends;
    typedef cDigitizerT cDerives;
    /**
     **********************************************************************
     * Function: Signed
     *
     *   Author: $author$
     *     Date: 1/7/2008
     **********************************************************************
     */
    virtual TSigned Signed
    (TLength& digits, const TWhat* chars,
     TLength length=VUndefinedLength) const
    {
        bool negative = false;
        TSigned value = 0;
        TLength count;
        TWhat c, d;

        if ((0 < length) && (VUndefinedLength != length))
        for (digits = 0, count = 0; count < length; count++)
        {
            if (((c = chars[count]) >= '0') && (c <= '9'))
            {
                value = (value*10) + (d = (c - '0'));
                if (d || digits)
                    digits++;
            }
            else if (('-' == c) && (1 > digits))
                    negative = true;
        }
        else
        for (digits = 0, count = 0; (c = chars[count]) != VNull; count++)
        {
            if ((c >= '0') && (c <= '9'))
            {
                value = (value*10) + (d = (c - '0'));
                if (d || digits)
                    digits++;
            }
            else if (('-' == c) && (1 > digits))
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
    virtual TUnsigned Unsigned
    (TLength& digits, const TWhat* chars,
     TLength length=VUndefinedLength) const
    {
        TUnsigned value = 0;
        TLength count;
        TWhat c, d;

        if ((0 < length) && (VUndefinedLength != length))
        for (digits = 0, count = 0; count < length; count++)
        {
            if (((c = chars[count]) >= '0') && (c <= '9'))
            {
                value = (value*10) + (d = (c - '0'));
                if (d || digits)
                    digits++;
            }
        }
        else
        for (digits = 0, count = 0; (c = chars[count]) != VNull; count++)
        {
            if ((c >= '0') && (c <= '9'))
            {
                value = (value*10) + (d = (c - '0'));
                if (d || digits)
                    digits++;
            }
        }
        return value;
    }
};
/**
 **********************************************************************
 *  Typedef: cDigitizer
 *
 *  Author: $author$
 *    Date: 3/21/2008
 **********************************************************************
 */
typedef cDigitizerT<CHAR> cDigitizer;
typedef cDigitizerT<CHAR> cCHARDigitizer;
typedef cDigitizerT<TCHAR> cTCHARDigitizer;
typedef cDigitizerT<WCHAR> cWCHARDigitizer;
typedef cDigitizerT<char> cCharDigitizer;

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#endif /* _XDE_BASE_CDIGITIZER_HXX */
