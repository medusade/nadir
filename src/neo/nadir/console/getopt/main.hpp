///////////////////////////////////////////////////////////////////////
/// Copyright (c) 1988-2018 $organization$
///
/// This software is provided by the author and contributors ``as is'' 
/// and any express or implied warranties, including, but not limited to, 
/// the implied warranties of merchantability and fitness for a particular 
/// purpose are disclaimed. In no event shall the author or contributors 
/// be liable for any direct, indirect, incidental, special, exemplary, 
/// or consequential damages (including, but not limited to, procurement 
/// of substitute goods or services; loss of use, data, or profits; or 
/// business interruption) however caused and on any theory of liability, 
/// whether in contract, strict liability, or tort (including negligence 
/// or otherwise) arising in any way out of the use of this software, 
/// even if advised of the possibility of such damage.
///
///   File: main.hpp
///
/// Author: $author$
///   Date: 1/17/2018
///////////////////////////////////////////////////////////////////////
#ifndef _NADIR_CONSOLE_GETOPT_MAIN_HPP
#define _NADIR_CONSOLE_GETOPT_MAIN_HPP

#include "nadir/console/getopt/main_opt.hpp"

namespace nadir {
namespace console {
namespace getopt {

///////////////////////////////////////////////////////////////////////
///  Class: maint
///////////////////////////////////////////////////////////////////////
template <class TImplements = main_opt, class TExtends = main_extend>

class _EXPORT_CLASS maint: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    maint(): did_usage_(false) {
    }
    virtual ~maint() {
    }

protected:
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int before_main(int argc, char_t** argv, char_t** env) {
        int err = 0;

        if (!(err = this->before_get_options(argc, argv, env))) {
            int err2 = 0;

            err = this->get_options(argc, argv, env);

            if ((err2 = this->after_get_options(argc, argv, env))) {
                if (!(err)) err = err2;
            } else {

                if ((err2 = this->before_get_arguments(argc, argv, env))) {
                    if (!(err)) err = err2;
                } else {

                    if ((err2 = this->get_arguments(argc, argv, env))) {
                        if (!(err)) err = err2;
                    }

                    if ((err2 = this->after_get_arguments(argc, argv, env))) {
                        if (!(err)) err = err2;
                    }
                }
            }
        }
        return err;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool set_did_usage(bool to = true) {
        this->set_did_run(did_usage_ = to);
        return did_usage_;
    }
    virtual bool did_usage() const {
        return did_usage_;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    bool did_usage_;
};
typedef maint<> main;

} // namespace getopt 
} // namespace console 
} // namespace nadir 

#endif // _NADIR_CONSOLE_GETOPT_MAIN_HPP 
