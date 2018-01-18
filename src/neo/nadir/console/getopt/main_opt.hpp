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
///   File: main_opt.hpp
///
/// Author: $author$
///   Date: 1/17/2018
///////////////////////////////////////////////////////////////////////
#ifndef _NADIR_CONSOLE_GETOPT_MAIN_OPT_HPP
#define _NADIR_CONSOLE_GETOPT_MAIN_OPT_HPP

#include "nadir/console/main_arg.hpp"
#include <getopt.h>

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
enum {
    MAIN_OPT_ARGUMENT_NONE     = 0,
    MAIN_OPT_ARGUMENT_REQUIRED = 1,
    MAIN_OPT_ARGUMENT_OPTIONAL = 2
};

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
#define NADIR_CONSOLE_GETOPT_MAIN_LOGGING_OPT "logging-level"
#define NADIR_CONSOLE_GETOPT_MAIN_LOGGING_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_REQUIRED
#define NADIR_CONSOLE_GETOPT_MAIN_LOGGING_OPTARG "{ (a)all | (n)none | (f)fatal | (e)error | (w)waring | (i)info | (d)debug | (t)trace }"
#define NADIR_CONSOLE_GETOPT_MAIN_LOGGING_OPTARG_C_ALL 'a'
#define NADIR_CONSOLE_GETOPT_MAIN_LOGGING_OPTARG_C_NONE 'n'
#define NADIR_CONSOLE_GETOPT_MAIN_LOGGING_OPTARG_C_FATAL 'f'
#define NADIR_CONSOLE_GETOPT_MAIN_LOGGING_OPTARG_C_ERROR 'e'
#define NADIR_CONSOLE_GETOPT_MAIN_LOGGING_OPTARG_C_WARN 'w'
#define NADIR_CONSOLE_GETOPT_MAIN_LOGGING_OPTARG_C_INFO 'i'
#define NADIR_CONSOLE_GETOPT_MAIN_LOGGING_OPTARG_C_DEBUG 'd'
#define NADIR_CONSOLE_GETOPT_MAIN_LOGGING_OPTARG_C_TRACE 't'
#define NADIR_CONSOLE_GETOPT_MAIN_LOGGING_OPTARG_C_MESSAGE_FATAL 'F'
#define NADIR_CONSOLE_GETOPT_MAIN_LOGGING_OPTARG_C_MESSAGE_ERROR 'E'
#define NADIR_CONSOLE_GETOPT_MAIN_LOGGING_OPTARG_C_MESSAGE_WARN 'W'
#define NADIR_CONSOLE_GETOPT_MAIN_LOGGING_OPTARG_C_MESSAGE_INFO 'I'
#define NADIR_CONSOLE_GETOPT_MAIN_LOGGING_OPTARG_C_MESSAGE_DEBUG 'D'
#define NADIR_CONSOLE_GETOPT_MAIN_LOGGING_OPTARG_C_MESSAGE_TRACE 'T'
#define NADIR_CONSOLE_GETOPT_MAIN_LOGGING_OPTUSE ""
#define NADIR_CONSOLE_GETOPT_MAIN_LOGGING_OPTVAL_S "l:"
#define NADIR_CONSOLE_GETOPT_MAIN_LOGGING_OPTVAL_C 'l'

#define NADIR_CONSOLE_GETOPT_MAIN_LOGGING_OPTIONS_OPTION \
   {NADIR_CONSOLE_GETOPT_MAIN_LOGGING_OPT, \
    NADIR_CONSOLE_GETOPT_MAIN_LOGGING_OPTARG_REQUIRED, 0, \
    NADIR_CONSOLE_GETOPT_MAIN_LOGGING_OPTVAL_C},

///////////////////////////////////////////////////////////////////////
#define NADIR_CONSOLE_GETOPT_MAIN_USAGE_OPT "usage"
#define NADIR_CONSOLE_GETOPT_MAIN_USAGE_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_NONE
#define NADIR_CONSOLE_GETOPT_MAIN_USAGE_OPTARG ""
#define NADIR_CONSOLE_GETOPT_MAIN_USAGE_OPTUSE "Usage options"
#define NADIR_CONSOLE_GETOPT_MAIN_USAGE_OPTVAL_S "?"
#define NADIR_CONSOLE_GETOPT_MAIN_USAGE_OPTVAL_C '?'

#define NADIR_CONSOLE_GETOPT_MAIN_USAGE_OPTIONS_OPTION \
   {NADIR_CONSOLE_GETOPT_MAIN_USAGE_OPT, \
    NADIR_CONSOLE_GETOPT_MAIN_USAGE_OPTARG_REQUIRED, 0, \
    NADIR_CONSOLE_GETOPT_MAIN_USAGE_OPTVAL_C},

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
#define NADIR_CONSOLE_GETOPT_MAIN_OPTIONS_CHARS \
    NADIR_CONSOLE_GETOPT_MAIN_LOGGING_OPTVAL_S \
    NADIR_CONSOLE_GETOPT_MAIN_USAGE_OPTVAL_S

#define NADIR_CONSOLE_GETOPT_MAIN_OPTIONS_OPTIONS \
    NADIR_CONSOLE_GETOPT_MAIN_LOGGING_OPTIONS_OPTION \
    NADIR_CONSOLE_GETOPT_MAIN_USAGE_OPTIONS_OPTION

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////

namespace nadir {
namespace console {
namespace getopt {

///////////////////////////////////////////////////////////////////////
///  Class: main_optt
///////////////////////////////////////////////////////////////////////
template <class TImplements = main_arg>

class _EXPORT_CLASS main_optt: virtual public TImplements {
public:
    typedef TImplements Implements;
    
    typedef typename Implements::char_t char_t;
    typedef typename Implements::end_char_t end_char_t;
    enum { end_char = Implements::end_char };

protected:
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int get_options(int argc, char_t** argv, char_t** env) {
        int err = 0;
        int longindex = 0;
        const struct option* longopts = 0;
        char_t optvaluename[2] = {0,0};
        const char_t* optname = optvaluename;
        const char_t* optstring = 0;
        int optvalue = 0;

        if ((optstring = this->options(longopts)) && (longopts)) {
            while (0 <= (optvalue = ::getopt_long(argc, argv, optstring, longopts, &longindex))) {
                optvaluename[0] = optvalue;
                optname = (longindex)?(longopts[longindex].name):(optvaluename);

                if ((err = this->on_option(optvalue, optarg, optname, longindex, argc, argv, env)))
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
    virtual int usage(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(this->did_usage())) {
            const char_t* arg = 0;
            const char_t** args = 0;
            const char_t* argstring = this->arguments(args);
            const struct option* longopts = 0;
            const char_t* optstring = this->options(longopts);
            const char_t* name = this->usage_name(argc, argv, env);

            this->outl
            ("Usage: ", (name)?(name):(""),(optstring)?(" [options]"):(""),
             (argstring)?(" "):(""), (argstring)?(argstring):(""), "\n", NULL);

            if ((optstring) && (longopts)) {
                this->out("\nOptions:\n");

                while ((longopts->name)) {
                    const char_t* optarg =
                    (MAIN_OPT_ARGUMENT_REQUIRED == longopts->has_arg)?(" arg"):
                    ((MAIN_OPT_ARGUMENT_OPTIONAL == longopts->has_arg)?(" [arg]"):(""));
                    const char_t* optusage = this->option_usage(optarg, longopts);
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
            this->set_did_usage();
        }
        return err;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int on_invalid_option
    (int optval, const char_t* optarg,
     const char_t* optname, int optind,
     int argc, char_t** argv, char_t** env) {
        int err = 1;
        char_t optval_chars[2] = {((char_t)optval), 0};
        this->errl
        ("invalid option -'", optval_chars, "' --\"", optname, "\"\n", NULL);
        return err;
    }
    virtual int on_invalid_option_arg
    (int optval, const char_t* optarg,
     const char_t* optname, int optind,
     int argc, char_t** argv, char_t** env) {
        int err = 1;
        char_t optval_chars[2] = {((char_t)optval), 0};
        this->errl
        ("invalid argument \"", optarg,
         "\" for option -'", optval_chars, "' --\"", optname, "\"\n", NULL);
        return err;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int on_logging_option
    (int optval, const char_t* optarg,
     const char_t* optname, int optind,
     int argc, char_t**argv, char_t**env) {
        int err = 0;
        return err;
    }
    ///////////////////////////////////////////////////////////////////////
    virtual int on_usage_option
    (int optval, const char_t* optarg,
     const char_t* optname, int optind,
     int argc, char_t**argv, char_t**env) {
        int err = 0;
        err = this->usage(argc, argv, env);
        return err;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int on_option
    (int optval, const char_t* optarg,
     const char_t* optname, int optind,
     int argc, char_t** argv, char_t** env) {
        int err = 0;
        switch(optval) {
        case NADIR_CONSOLE_GETOPT_MAIN_LOGGING_OPTVAL_C :
            err = this->on_logging_option
            (optval, optarg, optname, optind, argc, argv, env);
            break;
        case NADIR_CONSOLE_GETOPT_MAIN_USAGE_OPTVAL_C :
            err = this->on_usage_option
            (optval, optarg, optname, optind, argc, argv, env);
            break;
        default:
            err = this->on_invalid_option
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
            chars = NADIR_CONSOLE_GETOPT_MAIN_LOGGING_OPTUSE;
            break;
        case NADIR_CONSOLE_GETOPT_MAIN_USAGE_OPTVAL_C:
            optarg = NADIR_CONSOLE_GETOPT_MAIN_USAGE_OPTARG;
            chars = NADIR_CONSOLE_GETOPT_MAIN_USAGE_OPTUSE;
            break;
        default:
            break;
        }
        return chars;
    }
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
};
typedef main_optt<> main_opt;

} // namespace getopt 
} // namespace console 
} // namespace nadir 

#endif // _NADIR_CONSOLE_GETOPT_MAIN_OPT_HPP 
