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
 *   File: cbase.hxx
 *
 * Author: $author$
 *   Date: 9/26/2017
 **********************************************************************
 */
#ifndef _XDE_BASE_CBASE_HXX
#define _XDE_BASE_CBASE_HXX

#include "xde/cbase/cerror.hxx"

#define c_INTERFACE_VERSION(major, minor) (((major) << 8) | (minor))
#define c_INTERFACE_VERSION_MAJOR(version) ((version) >> 8)
#define c_INTERFACE_VERSION_MINOR(version) ((version) & 255)

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/**
 **********************************************************************
 *  Class: cBase
 *
 * Author: $author$
 *   Date: 1/26/2007
 **********************************************************************
 */
class c_EXPORT_CLASS cBase {
public:
    /**
     **********************************************************************
     * Destructor: cBase
     *
     *     Author: $author$
     *       Date: 11/13/2007
     **********************************************************************
     */
    virtual ~cBase() {
    }
};

/**
 **********************************************************************
 *  Class: cInterfaceBase
 *
 * Author: $author$
 *   Date: 1/9/2007
 **********************************************************************
 */
class c_INTERFACE_CLASS cInterfaceBase {
public:
    /**
     **********************************************************************
     *  Destructor: ~cInterfaceBase
     *
     *      Author: $author$
     *        Date: 1/16/2007
     **********************************************************************
     */
    virtual ~cInterfaceBase() {
    }
};

/**
 **********************************************************************
 *  Class: cImplementBase
 *
 * Author: $author$
 *   Date: 3/22/2007
 **********************************************************************
 */
class c_IMPLEMENT_CLASS cImplementBase: virtual public cInterfaceBase {
public:
    typedef cInterfaceBase cImplements;
    typedef cImplementBase cDerives;
};

/**
 **********************************************************************
 *  Class: cInterface
 *
 * Author: $author$
 *   Date: 7/5/2003
 **********************************************************************
 */
class c_INTERFACE_CLASS cInterface: virtual public cInterfaceBase {
public:
    typedef cInterfaceBase cImplements;
    typedef cInterface cDerives;
    /**
     **********************************************************************
     * Function: HoldInstance
     *
     *   Author: $author$
     *     Date: 1/9/2007
     **********************************************************************
     */
    virtual eError HoldInstance() = 0;
    /**
     **********************************************************************
     * Function: FreeInstance
     *
     *   Author: $author$
     *     Date: 1/9/2007
     **********************************************************************
     */
    virtual eError FreeInstance() = 0;
    /**
     **********************************************************************
     * Function: DeleteInstance
     *
     *   Author: $author$
     *     Date: 1/9/2007
     **********************************************************************
     */
    virtual eError DeleteInstance() = 0;

    /**
     **********************************************************************
     * Function: SetLastError
     *
     *   Author: $author$
     *     Date: 1/9/2007
     **********************************************************************
     */
    virtual eError SetLastError
    (eError error, const CHAR* description=0, TLENGTH length=-1) = 0;
    /**
     **********************************************************************
     * Function: GetLastError
     *
     *   Author: $author$
     *     Date: 1/9/2007
     **********************************************************************
     */
    virtual eError GetLastError
    (const CHAR*& description, TLENGTH &length) const = 0;
};

/**
 **********************************************************************
 *  Class: cImplement
 *
 * Author: $author$
 *   Date: 7/5/2003
 **********************************************************************
 */
class c_IMPLEMENT_CLASS cImplement: virtual public cInterface {
public:
    /**
     **********************************************************************
     * Function: HoldInstance
     *
     *   Author: $author$
     *     Date: 7/5/2003
     **********************************************************************
     */
    virtual eError HoldInstance() {
        return e_ERROR_NOT_ALLOWED;
    }
    /**
     **********************************************************************
     * Function: FreeInstance
     *
     *   Author: $author$
     *     Date: 7/5/2003
     **********************************************************************
     */
    virtual eError FreeInstance() {
        return e_ERROR_NOT_ALLOWED;
    }
    /**
     **********************************************************************
     * Function: DeleteInstance
     *
     *   Author: $author$
     *     Date: 8/22/2003
     **********************************************************************
     */
    virtual eError DeleteInstance() {
        return e_ERROR_NOT_ALLOWED;
    }
    /**
     **********************************************************************
     * Function: SetLastError
     *
     *   Author: $author$
     *     Date: 7/5/2003
     **********************************************************************
     */
    virtual eError SetLastError
    (eError error, const CHAR* description = 0, TLENGTH length = -1) {
        return -e_ERROR_NOT_ALLOWED;
    }
    /**
     **********************************************************************
     * Function: GetLastError
     *
     *   Author: $author$
     *     Date: 7/5/2003
     **********************************************************************
     */
    virtual eError GetLastError
    (const CHAR*& description, TLENGTH& length) const {
        return -e_ERROR_NOT_ALLOWED;
    }
};

/**
 **********************************************************************
 *  Class: cInterfaceInstance
 *
 * Author: $author$
 *   Date: 11/4/2008
 **********************************************************************
 */
class c_IMPLEMENT_CLASS cInterfaceInstance
: virtual public cImplement, public cBase {
public:
    typedef cImplement cImplements;
    typedef cBase cExtends;
    typedef cInterfaceInstance cDerives;

    int m_holdInstance;

    /**
     **********************************************************************
     * Constructor: cInterfaceInstance
     *
     *      Author: $author$
     *        Date: 11/4/2008
     **********************************************************************
     */
    cInterfaceInstance(int holdInstance=-1): m_holdInstance(holdInstance) {
    }
    /**
     **********************************************************************
     * Destructor: ~cInterfaceInstance
     *
     *     Author: $author$
     *       Date: 11/4/2008
     **********************************************************************
     */
    virtual ~cInterfaceInstance() {
    }

    /**
     **********************************************************************
     * Function: HoldInstance
     *
     *   Author: $author$
     *     Date: 11/4/2008
     **********************************************************************
     */
    virtual eError HoldInstance() {
        if (0 <= m_holdInstance) {
            m_holdInstance++;
        }
        return e_ERROR_NONE;
    }
    /**
     **********************************************************************
     * Function: FreeInstance
     *
     *   Author: $author$
     *     Date: 11/4/2008
     **********************************************************************
     */
    virtual eError FreeInstance() {
        if (0 < m_holdInstance) {
            --m_holdInstance;
        } else {
            if (!m_holdInstance) {
                return DeleteInstance();
            }
        }
        return e_ERROR_NONE;
    }
    /**
     **********************************************************************
     * Function: DeleteInstance
     *
     *   Author: $author$
     *     Date: 11/4/2008
     **********************************************************************
     */
    virtual eError DeleteInstance() {
        if (m_holdInstance) {
            return e_ERROR_NOT_ALLOWED;
        }
        return DeleteThis();
    }
    /**
     **********************************************************************
     * Function: DeleteThis
     *
     *   Author: $author$
     *     Date: 11/4/2008
     **********************************************************************
     */
    virtual eError DeleteThis() {
        return e_ERROR_NOT_ALLOWED;
    }
};

/**
 **********************************************************************
 *  Class: cInstanceInterfaceT
 *
 * Author: $author$
 *   Date: 3/13/2008
 **********************************************************************
 */
template
<class TImplements = cInterfaceBase>

class c_INTERFACE_CLASS cInstanceInterfaceT
{
public:
    typedef cInstanceInterfaceT cDerives;
    /**
     **********************************************************************
     * Function: DeleteInstance
     *
     *   Author: $author$
     *     Date: 3/13/2008
     **********************************************************************
     */
    virtual eError DeleteInstance
    (bool onlyNotIsStaticInstance = false) = 0;
    /**
     **********************************************************************
     * Function: DeleteThis
     *
     *   Author: $author$
     *     Date: 3/13/2008
     **********************************************************************
     */
    virtual eError DeleteThis() = 0;
    /**
     **********************************************************************
     * Function: SetIsStaticInstance
     *
     *   Author: $author$
     *     Date: 3/13/2008
     **********************************************************************
     */
    virtual int SetIsStaticInstance(bool is = true) = 0;
    /**
     **********************************************************************
     * Function: GetIsStaticInstance
     *
     *   Author: $author$
     *     Date: 3/13/2008
     **********************************************************************
     */
    virtual bool GetIsStaticInstance() const = 0;
};

/**
 **********************************************************************
 *  Class: cInstanceInterface
 *
 * Author: $author$
 *   Date: 3/13/2008
 **********************************************************************
 */
class c_INTERFACE_CLASS cInstanceInterface
: virtual public cInstanceInterfaceT<cInterfaceBase> {
public:
    typedef cInstanceInterfaceT<cInterfaceBase> cImplements;
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#endif /* _XDE_BASE_CBASE_HXX */
