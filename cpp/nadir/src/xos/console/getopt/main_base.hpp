///////////////////////////////////////////////////////////////////////
/// Copyright (c) 1988-2017 $organization$
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
///   File: main_base.hpp
///
/// Author: $author$
///   Date: 9/9/2017
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_CONSOLE_GETOPT_MAIN_BASE_HPP
#define _XOS_CONSOLE_GETOPT_MAIN_BASE_HPP

#include "xos/console/getopt/main_opt.hpp"
#include "xos/console/main.hpp"

namespace xos {
namespace console {
namespace getopt {

typedef console::getopt::main_opt main_baset_opt_implements;
typedef console::main::Implements main_baset_implements;
typedef console::main main_baset_extends;
///////////////////////////////////////////////////////////////////////
///  Class: main_baset
///////////////////////////////////////////////////////////////////////
template
<class TOptImplements = main_baset_opt_implements,
 class TImplements = main_baset_implements, class TExtends = main_baset_extends>

class _EXPORT_CLASS main_baset
: virtual public TOptImplements, virtual public TImplements, public TExtends {
public:
    typedef TOptImplements OptImplements;
    typedef TImplements Implements;
    typedef TExtends Extends;

    typedef typename Extends::char_t char_t;
    typedef typename Extends::end_char_t end_char_t;
    enum { end_char = Extends::end_char };

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    main_baset(): did_usage_(false) {
    }
    virtual ~main_baset() {
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

typedef main_baset_opt_implements main_base_opt_implements;
typedef main_baset_implements main_base_implements;
typedef main_baset<> main_base_extends;
///////////////////////////////////////////////////////////////////////
///  Class: main_base
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS main_base
: virtual public main_base_opt_implements,
  virtual public main_base_implements, public main_base_extends {
public:
    typedef main_base_opt_implements OptImplements;
    typedef main_base_implements Implements;
    typedef main_base_extends Extends;

protected:
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int usage(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(did_usage())) {
            const char_t* arg = 0;
            const char_t** args = 0;
            const char_t* argstring = arguments(args);
            const struct option* longopts = 0;
            const char_t* optstring = this->options(longopts);
            const char_t* name = usage_name(argc, argv, env);

            this->outl
            ("Usage: ", (name)?(name):(""),(optstring)?(" [options]"):(""),
             (argstring)?(" "):(""), (argstring)?(argstring):(""), "\n", NULL);

            if ((optstring) && (longopts)) {
                this->out("\nOptions:\n");

                while ((longopts->name)) {
                    const char_t* optarg =
                    (MAIN_OPT_ARGUMENT_REQUIRED == longopts->has_arg)?(" arg"):
                    ((MAIN_OPT_ARGUMENT_OPTIONAL == longopts->has_arg)?(" [arg]"):(""));
                    const char_t* optusage = option_usage(optarg, longopts);
                    const char_t* optarg_separator = (optarg[0])?(" "):("");
                    const char_t* optusage_separator = "  ";
                    const char_t* optarg_name = longopts->name;
                    const char optarg_value[2] = {((char)(longopts->val)), 0};

                    this->outl
                    (" -", optarg_value, " --", optarg_name,
                     optarg_separator, optarg, optusage_separator, optusage, "\n", NULL);
                    longopts++;
                }
            }
            if ((argstring) && (args)) {
                this->out("\nArguments:\n");

                while ((arg = (*args))) {
                    this->outl(" ", arg, "\n", NULL);
                    args++;
                }
            }
            set_did_usage();
        }
        return err;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};

} // namespace getopt
} // namespace console 
} // namespace xos 

#endif // _XOS_CONSOLE_GETOPT_MAIN_BASE_HPP 
