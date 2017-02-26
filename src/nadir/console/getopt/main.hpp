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
///   File: main.hpp
///
/// Author: $author$
///   Date: 1/13/2017
///////////////////////////////////////////////////////////////////////
#ifndef _NADIR_CONSOLE_GETOPT_MAIN_HPP
#define _NADIR_CONSOLE_GETOPT_MAIN_HPP

#include "nadir/console/getopt/main_opt.hpp"
#include "nadir/console/main.hpp"
#include "nadir/io/logger.hpp"

namespace nadir {
namespace console {
namespace getopt {

typedef console::maint_implements maint_implements;
typedef console::main maint_extends;
///////////////////////////////////////////////////////////////////////
///  Class: maint
///////////////////////////////////////////////////////////////////////
template
<class TImplements = maint_implements, class TExtends = maint_extends>

class _EXPORT_CLASS maint: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    maint()
        : fs_path_colon_((char_t)':'),
          fs_path_bslash_((char_t)'\\'),
          fs_path_slash_((char_t)'/'),
          did_usage_(false) {
    }
    virtual ~maint() {
    }

protected:
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int before_main(int argc, char_t** argv, char_t** env) {
        int err = 0;

        if (!(err = before_get_options(argc, argv, env))) {
            int err2 = 0;

            err = get_options(argc, argv, env);

            if ((err2 = after_get_options(argc, argv, env))) {
                if (!(err)) err = err2;
            } else {

                if ((err2 = before_get_arguments(argc, argv, env))) {
                    if (!(err)) err = err2;
                } else {

                    if ((err2 = get_arguments(argc, argv, env))) {
                        if (!(err)) err = err2;
                    }

                    if ((err2 = after_get_arguments(argc, argv, env))) {
                        if (!(err)) err = err2;
                    }
                }
            }
        }
        return err;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int usage(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(did_usage())) {
            const char_t* arg = 0;
            const char_t** args = 0;
            const char_t* argstring = arguments(args);
            const struct option* longopts = 0;
            const char_t* optstring = options(longopts);
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
                    const char optarg_value[2] = {longopts->val, 0};

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
    virtual const char_t* usage_name
    (int argc, char_t** argv, char_t** env) const {
        const char_t* arg0 = (0 < argc)?((argv)?(argv[0]):(0)):(0);
        if ((arg0)) {
            for (const char_t* i = arg0; *i; ++i) {
                char c = (char)(*i);
                if ((fs_path_slash_ == c)
                    || (fs_path_bslash_ == c)
                    || (fs_path_colon_ == c)) {
                    arg0 = i + 1;
                }
            }
        }
        return arg0;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int get_options(int argc, char_t** argv, char_t** env) {
        int err = 0;
        int longindex = 0;
        const struct option* longopts = 0;
        char_t optvaluename[2] = {0,0};
        const char_t* optname = optvaluename;
        const char_t* optstring;
        int optvalue;

        if ((optstring = options(longopts)) && (longopts)) {
            while (0 <= (optvalue = getopt_long(argc, argv, optstring, longopts, &longindex))) {
                optvaluename[0] = optvalue;
                optname = (longindex)?(longopts[longindex].name):(optvaluename);

                if ((err = on_option (optvalue, optarg, optname, longindex, argc, argv, env)))
                    break;
            }
        }
        return err;
    }
    virtual int before_get_options(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_get_options(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int get_arguments(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int before_get_arguments(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_get_arguments(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int on_logging_option
    (int optval, const char_t* optarg,
     const char_t* optname, int optind,
     int argc, char_t**argv, char_t**env) {
        int err = 0;
        char c = 0;
        if ((optarg) && (c = optarg[0]) && (!optarg[1])) {
            switch(c) {

            case '7':
            case NADIR_CONSOLE_GETOPT_MAIN_LOGGING_OPTARG_C_ALL:
                SET_LOGGING_LEVEL(LOGGING_LEVELS_ALL | LOGGING_MESSAGE_LEVELS_ALL);
                break;
            case '0':
            case NADIR_CONSOLE_GETOPT_MAIN_LOGGING_OPTARG_C_NONE:
                SET_LOGGING_LEVEL(LOGGING_LEVELS_NONE | LOGGING_MESSAGE_LEVELS_NONE);
                break;
            case '1':
            case NADIR_CONSOLE_GETOPT_MAIN_LOGGING_OPTARG_C_FATAL:
                SET_LOGGING_LEVEL(LOGGING_LEVELS_FATAL | LOGGING_MESSAGE_LEVELS_FATAL);
                break;
            case '2':
            case NADIR_CONSOLE_GETOPT_MAIN_LOGGING_OPTARG_C_ERROR:
                SET_LOGGING_LEVEL(LOGGING_LEVELS_ERROR | LOGGING_MESSAGE_LEVELS_ERROR);
                break;
            case '3':
            case NADIR_CONSOLE_GETOPT_MAIN_LOGGING_OPTARG_C_WARN:
                SET_LOGGING_LEVEL(LOGGING_LEVELS_WARN | LOGGING_MESSAGE_LEVELS_WARN);
                break;
            case '4':
            case NADIR_CONSOLE_GETOPT_MAIN_LOGGING_OPTARG_C_INFO:
                SET_LOGGING_LEVEL(LOGGING_LEVELS_INFO | LOGGING_MESSAGE_LEVELS_INFO);
                break;
            case '5':
            case NADIR_CONSOLE_GETOPT_MAIN_LOGGING_OPTARG_C_DEBUG:
                SET_LOGGING_LEVEL(LOGGING_LEVELS_DEBUG | LOGGING_MESSAGE_LEVELS_DEBUG);
                break;
            case '6':
            case NADIR_CONSOLE_GETOPT_MAIN_LOGGING_OPTARG_C_TRACE:
                SET_LOGGING_LEVEL(LOGGING_LEVELS_TRACE | LOGGING_MESSAGE_LEVELS_TRACE);
                break;

            case NADIR_CONSOLE_GETOPT_MAIN_LOGGING_OPTARG_C_MESSAGE_FATAL:
                SET_LOGGING_LEVEL(LOGGING_LEVELS_FATAL | LOGGING_MESSAGE_LEVELS_FATAL);
                break;
            case NADIR_CONSOLE_GETOPT_MAIN_LOGGING_OPTARG_C_MESSAGE_ERROR:
                SET_LOGGING_LEVEL(LOGGING_LEVELS_ERROR | LOGGING_MESSAGE_LEVELS_ERROR);
                break;
            case NADIR_CONSOLE_GETOPT_MAIN_LOGGING_OPTARG_C_MESSAGE_WARN:
                SET_LOGGING_LEVEL(LOGGING_MESSAGE_LEVELS_WARN);
                break;
            case NADIR_CONSOLE_GETOPT_MAIN_LOGGING_OPTARG_C_MESSAGE_INFO:
                SET_LOGGING_LEVEL(LOGGING_MESSAGE_LEVELS_INFO);
                break;
            case NADIR_CONSOLE_GETOPT_MAIN_LOGGING_OPTARG_C_MESSAGE_DEBUG:
                SET_LOGGING_LEVEL(LOGGING_MESSAGE_LEVELS_DEBUG);
                break;
            case NADIR_CONSOLE_GETOPT_MAIN_LOGGING_OPTARG_C_MESSAGE_TRACE:
                SET_LOGGING_LEVEL(LOGGING_MESSAGE_LEVELS_TRACE);
                break;

            default:
                err = on_invalid_option_arg
                (optval, optarg, optname, optind, argc, argv, env);
                break;
            }
        }
        return err;
    }
    ///////////////////////////////////////////////////////////////////////
    virtual int on_usage_option
    (int optval, const char_t* optarg,
     const char_t* optname, int optind,
     int argc, char_t**argv, char_t**env) {
        int err = 0;
        err = usage(argc, argv, env);
        return err;
    }
    ///////////////////////////////////////////////////////////////////////
    virtual int on_invalid_option
    (int optval, const char_t* optarg,
     const char_t* optname, int optind,
     int argc, char_t**argv, char_t**env) {
        int err = 1;
        char_t optval_chars[2] = {optval, 0};
        this->errl
        ("Invalid option -", optval_chars, " --", optname, "\n", NULL);
        return err;
    }
    ///////////////////////////////////////////////////////////////////////
    virtual int on_invalid_option_arg
    (int optval, const char_t* optarg,
     const char_t* optname, int optind,
     int argc, char_t**argv, char_t**env) {
        int err = 1;
        this->errl
        ("invalid argument \"", optarg,
         "\" for option \"", optname, "\"\n", NULL);
        return err;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int on_option
    (int optval, const char_t* optarg,
     const char_t* optname, int optind,
     int argc, char_t**argv, char_t**env) {
        int err = 0;
        switch(optval) {
        case NADIR_CONSOLE_GETOPT_MAIN_LOGGING_OPTVAL_C:
            err = on_logging_option
            (optval, optarg, optname, optind, argc, argv, env);
            break;
        case NADIR_CONSOLE_GETOPT_MAIN_HELP_OPTVAL_C:
            err = on_usage_option
            (optval, optarg, optname, optind, argc, argv, env);
            break;
        default:
            err = on_invalid_option
            (optval, optarg, optname, optind, argc, argv, env);
        }
        return err;
    }
    ///////////////////////////////////////////////////////////////////////
    virtual const char_t* option_usage
    (const char_t*& optarg, const struct option* longopt) {
        const char_t* chars = "";
        switch(longopt->val) {
        case NADIR_CONSOLE_GETOPT_MAIN_LOGGING_OPTVAL_C:
            optarg = NADIR_CONSOLE_GETOPT_MAIN_LOGGING_OPTARG;
            break;
        case NADIR_CONSOLE_GETOPT_MAIN_HELP_OPTVAL_C:
            chars = NADIR_CONSOLE_GETOPT_MAIN_HELP_OPTUSE;
            break;
        default:
            break;
        }
        return chars;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual const char_t* options(const struct option*& longopts) {
        static const char_t* chars = NADIR_CONSOLE_GETOPT_MAIN_OPTIONS_CHARS;
        static struct option optstruct[]= {
            NADIR_CONSOLE_GETOPT_MAIN_OPTIONS_OPTIONS
            {0, 0, 0, 0}};
        longopts = optstruct;
        return chars;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int on_argument
    (const char_t* arg, int argind,
     int argc, char_t**argv, char_t**env) {
        int err = 0;
        return err;
    }
    ///////////////////////////////////////////////////////////////////////
    virtual int missing_argument(const char_t* arg) {
        int err = 1;
        return err;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual const char_t* arguments(const char_t**& args) {
        args = 0;
        return 0;
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
    const char_t fs_path_colon_;
    const char_t fs_path_bslash_;
    const char_t fs_path_slash_;
    bool did_usage_;
};
typedef maint<> main;

} // namespace getopt 
} // namespace console 
} // namespace nadir 

#endif // _NADIR_CONSOLE_GETOPT_MAIN_HPP 
