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
 *   File: csplitter.hxx
 *
 * Author: $author$
 *   Date: 10/2/2017
 **********************************************************************
 */
#ifndef _XDE_CBASE_CSPLITTER_HXX
#define _XDE_CBASE_CSPLITTER_HXX

#include "xde/cbase/cbase.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/**
 **********************************************************************
 *  Class: cCounterT
 *
 * Author: $author$
 *   Date: 3/21/2008
 **********************************************************************
 */
template
<class TWhat=CHAR,
 class TLength=TLENGTH,
 class TNull=TWhat,
 TNull VNull=NULL_CHAR,
 class TExtends=cBase>

class cCounterT
: public TExtends
{
public:
    typedef TExtends cExtends;
    typedef cCounterT cDerives;
    /**
     **********************************************************************
     * Function: LengthOf
     *
     *   Author: $author$
     *     Date: 3/19/2008
     **********************************************************************
     */
    virtual TLength LengthOf
    (const TWhat* what) const
    {
        TLength count = 0;
        if (what)
        while ((*what++) != VNull)
            count++;
        return count;
    }
};
/**
 **********************************************************************
 *  Typedef: cCounter
 *
 *  Author: $author$
 *    Date: 3/21/2008
 **********************************************************************
 */
typedef cCounterT<CHAR> cCounter;
typedef cCounterT<CHAR> cCHARCounter;
typedef cCounterT<TCHAR> cTCHARCounter;
typedef cCounterT<WCHAR> cWCHARCounter;
typedef cCounterT<char> cCharCounter;

/**
 **********************************************************************
 *  Class: cSplitterT
 *
 * Author: $author$
 *   Date: 3/21/2008
 **********************************************************************
 */
template
<class TChar=CHAR,
 class TLength=TLENGTH,
 class TExtends=cCounter>

class cSplitterT
: public TExtends
{
public:
    typedef TExtends cExtends;
    typedef cSplitterT cDerives;
    /**
     **********************************************************************
     * Function: LeftOf
     *
     *   Author: $author$
     *     Date: 1/1/2009
     **********************************************************************
     */
    virtual const TChar* LeftOf
    (TLength& count, TChar c,
     const TChar* chars, TLength length=-1) const
    {
        const TChar* found = 0;
        TLength tell;

        count = 0;

        if (0 > length)
        if (0 >= (length = this->LengthOf(chars)))
            return found;

        for (tell=0; tell<length; tell++)
        {
            if (c != chars[tell])
                continue;
            found = chars;
            count = tell;
            break;
        }
        return found;
    }
    /**
     **********************************************************************
     * Function: RightOf
     *
     *   Author: $author$
     *     Date: 3/7/2008
     **********************************************************************
     */
    virtual const TChar* RightOf
    (TLength& count, TChar c,
     const TChar* chars, TLength length=-1) const
    {
        const TChar* found = 0;
        TLength tell;

        count = 0;

        if (0 > length)
        if (0 >= (length = this->LengthOf(chars)))
            return found;

        for (tell=length; 0<tell; --tell)
        {
            if (c != chars[tell-1])
                continue;
            found = chars+tell;
            count = length-tell;
            break;
        }
        return found;
    }
};
/**
 **********************************************************************
 *  Typedef: cSplitter
 *
 *  Author: $author$
 *    Date: 3/27/2008
 **********************************************************************
 */
typedef cSplitterT<CHAR> cSplitter;
typedef cSplitterT<CHAR> cCHARSplitter;
typedef cSplitterT<TCHAR> cTCHARSplitter;
typedef cSplitterT<WCHAR> cWCHARSplitter;
typedef cSplitterT<char> cCharSplitter;

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#endif /* _XDE_CBASE_CSPLITTER_HXX */
