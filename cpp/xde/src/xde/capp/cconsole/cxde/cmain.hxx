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
 *   File: cMain.hxx
 *
 * Author: $author$
 *   Date: 9/29/2017
 **********************************************************************
 */
#ifndef _XDE_CAPP_CCONSOLE_CXDE_CMAIN_HXX
#define _XDE_CAPP_CCONSOLE_CXDE_CMAIN_HXX

#include "xde/cconsole/cmain.hxx"

namespace capp {
namespace cconsole {
namespace cxde {

typedef c_NAMESPACE_::cMainImplements cMainImplements;
typedef c_NAMESPACE_::cMain cMainExtends;
/**
 **********************************************************************
 *  Class: cMain
 *
 * Author: $author$
 *   Date: 9/29/2017
 **********************************************************************
 */
class c_EXPORT_CLASS cMain: virtual public cMainImplements, public cMainExtends {
public:
    typedef cMainImplements cImplements;
    typedef cMainExtends cExtends;
    /**
     **********************************************************************
     * Constructor: cMain
     *
     *      Author: $author$
     *        Date: 9/29/2017
     **********************************************************************
     */
    cMain() {
    }
    /**
     **********************************************************************
     * Function: Run
     *
     *   Author: $author$
     *     Date: 9/29/2017
     **********************************************************************
     */
    virtual int Run
    (int argc, const char_t** argv, const char_t** env) {
        int err = 0;
        this->Out("Hello\n");
        return err;
    }
};

} /* namespace cxde */
} /* namespace cconsole */
} /* namespace capp */

#endif /* _XDE_CAPP_CCONSOLE_CXDE_CMAIN_HXX */

        

