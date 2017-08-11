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
///   File: MainOpt.hpp
///
/// Author: $author$
///   Date: 8/9/2017
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_CONSOLE_GETOPT_MAINOPT_HPP
#define _XOS_CONSOLE_GETOPT_MAINOPT_HPP

#include "xos/console/MainArg.hpp"
#include <getopt.h>

///////////////////////////////////////////////////////////////////////
/// Enum: MAIN_OPT_ARGUMENT_T
///////////////////////////////////////////////////////////////////////
typedef int MAIN_OPT_ARGUMENT_T;
enum {
    MAIN_OPT_ARGUMENT_NONE     = 0,
    MAIN_OPT_ARGUMENT_REQUIRED = 1,
    MAIN_OPT_ARGUMENT_OPTIONAL = 2
};

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
#define MAIN_HELP_OPT "help"
#define MAIN_HELP_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_NONE
#define MAIN_HELP_OPTARG_RESULT 0
#define MAIN_HELP_OPTARG ""
#define MAIN_HELP_OPTUSE "Usage options"
#define MAIN_HELP_OPTVAL_S "?"
#define MAIN_HELP_OPTVAL_C '?'
#define MAIN_HELP_OPTION \
   {MAIN_HELP_OPT, \
    MAIN_HELP_OPTARG_REQUIRED, \
    MAIN_HELP_OPTARG_RESULT, \
    MAIN_HELP_OPTVAL_C}, \

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
#define MAIN_OPTIONS_CHARS \
    MAIN_HELP_OPTVAL_S

#define MAIN_OPTIONS_OPTIONS \
    MAIN_HELP_OPTION

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
namespace xos {
namespace console {
namespace getopt {

typedef ImplementBase MainOptTImplements;
///////////////////////////////////////////////////////////////////////
///  Class: MainOptT
///////////////////////////////////////////////////////////////////////
template
<typename TChar = char,
 typename TEndChar = TChar, TEndChar VEndChar = 0,
 class TArg = MainArgT<TChar, TEndChar, VEndChar, MainOptTImplements>,
 class TImplements = TArg>

class _EXPORT_CLASS MainOptT: virtual public TImplements {
public:
    typedef TImplements Implements;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int GetOptions(int argc, char_t**argv, char_t** env) {
        int err = 1;
        return err;
    }
    virtual int BeforeGetOptions(int argc, char_t**argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int AfterGetOptions(int argc, char_t**argv, char_t** env) {
        int err = 0;
        return err;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int OnOption
    (int optval, const char_t* optarg,
     const char_t* optname, int optind,
     int argc, char_t** argv, char_t** env) {
        int err = 0;
        switch(optval) {
        default:
            err = OnInvalidOption
            (optval, optarg, optname, optind, argc, argv, env);
            break;
        }
        return err;
    }
    virtual int OnUsageOption
    (int optval, const char_t* optarg,
     const char_t* optname, int optind,
     int argc, char_t** argv, char_t** env) {
        int err = this->Usage(argc, argv, env);
        return err;
    }
    virtual int OnInvalidOption
    (int optval, const char_t* optarg,
     const char_t* optname, int optind,
     int argc, char_t** argv, char_t** env) {
        int err = 1;
        return err;
    }
    virtual int OnInvalidOptionArg
    (int optval, const char_t* optarg,
     const char_t* optname, int optind,
     int argc, char_t** argv, char_t** env) {
        int err = 1;
        return err;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};

typedef MainOptT<char, char, 0, MainArg> MainOptImplements;
///////////////////////////////////////////////////////////////////////
///  Class: MainOpt
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS MainOpt: virtual public MainOptImplements {
public:
    typedef MainOptImplements Implements;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int GetOptions(int argc, char**argv, char** env) {
        int err = 0;
        int longindex = 0;
        const struct option* longopts = 0;
        char optvaluename[2] = {0,0};
        const char* optname = optvaluename;
        const char* optstring = 0;
        int optvalue = 0;

        if ((optstring = Options(longopts)) && (longopts)) {
            while (0 <= (optvalue = getopt_long(argc, argv, optstring, longopts, &longindex))) {
                optvaluename[0] = optvalue;
                optname = (longindex)?(longopts[longindex].name):(optvaluename);

                if ((err = OnOption(optvalue, optarg, optname, longindex, argc, argv, env))) {
                    break;
                }
            }
        }
        return err;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int OnOption
    (int optval, const char* optarg,
     const char* optname, int optind,
     int argc, char** argv, char** env) {
        int err = 0;
        switch(optval) {
        case MAIN_HELP_OPTVAL_C:
            err = OnUsageOption
            (optval, optarg, optname, optind, argc, argv, env);
            break;
        default:
            err = OnInvalidOption
            (optval, optarg, optname, optind, argc, argv, env);
            break;
        }
        return err;
    }
    virtual const char* OptionUsage
    (const char*& optarg, const struct option* longopt) {
        const char* chars = "";
        switch(longopt->val) {
        case MAIN_HELP_OPTVAL_C:
            chars = MAIN_HELP_OPTUSE;
            break;
        default:
            break;
        }
        return chars;
    }
    virtual const char* Options(const struct option*& longopts) {
        static const char* chars = MAIN_OPTIONS_CHARS;
        static struct option optstruct[] = {
            MAIN_OPTIONS_OPTIONS
            {0, 0, 0, 0}};
        longopts = optstruct;
        return chars;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};

} // namespace getopt
} // namespace console 
} // namespace xos 

#endif // _XOS_CONSOLE_GETOPT_MAINOPT_HPP 

        

