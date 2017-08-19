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
///   Date: 8/13/2017
///////////////////////////////////////////////////////////////////////
#ifndef _NADIR_APP_CONSOLE_HELLO_MAINOPT_HPP
#define _NADIR_APP_CONSOLE_HELLO_MAINOPT_HPP

#include "nadir/console/getopt/MainOpt.hpp"

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
#define HELLO_MAIN_MESSAGE_OPT "message"
#define HELLO_MAIN_MESSAGE_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_REQUIRED
#define HELLO_MAIN_MESSAGE_OPTARG_RESULT 0
#define HELLO_MAIN_MESSAGE_OPTARG "<string>"
#define HELLO_MAIN_MESSAGE_OPTUSE "Hello Message"
#define HELLO_MAIN_MESSAGE_OPTVAL_S "m:"
#define HELLO_MAIN_MESSAGE_OPTVAL_C 'm'
#define HELLO_MAIN_MESSAGE_OPTION \
   {HELLO_MAIN_MESSAGE_OPT, \
    HELLO_MAIN_MESSAGE_OPTARG_REQUIRED, \
    HELLO_MAIN_MESSAGE_OPTARG_RESULT, \
    HELLO_MAIN_MESSAGE_OPTVAL_C}, \

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
#define NADIR_CONSOLE_HELLO_MAIN_OPTIONS_CHARS \
   HELLO_MAIN_MESSAGE_OPTVAL_S \
   NADIR_CONSOLE_MAIN_OPTIONS_CHARS

#define NADIR_CONSOLE_HELLO_MAIN_OPTIONS_OPTIONS \
   HELLO_MAIN_MESSAGE_OPTION \
   NADIR_CONSOLE_MAIN_OPTIONS_OPTIONS

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
#define NADIR_CONSOLE_HELLO_MAIN_ARGS "[who]"
#define NADIR_CONSOLE_HELLO_MAIN_ARGV "[who] Hello Who",

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////

namespace nadir {
namespace app {
namespace console {
namespace hello {

typedef nadir::console::getopt::MainOpt MainOptImplements;
///////////////////////////////////////////////////////////////////////
///  Class: MainOptT
///////////////////////////////////////////////////////////////////////
template <class TImplements = MainOptImplements>

class _EXPORT_CLASS MainOptT: virtual public TImplements {
public:
    typedef TImplements Implements;
protected:
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int OnMessageOption
    (int optval, const char_t* optarg,
     const char_t* optname, int optind,
     int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
        }
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
        case HELLO_MAIN_MESSAGE_OPTVAL_C:
            err = OnMessageOption
            (optval, optarg, optname, optind, argc, argv, env);
            break;
        default:
            err = Implements::OnOption
            (optval, optarg, optname, optind, argc, argv, env);
        }
        return err;
    }
    virtual const char_t* OptionUsage
    (const char_t*& optarg, const struct option* longopt) {
        const char_t* chars = "";
        switch(longopt->val) {
        case HELLO_MAIN_MESSAGE_OPTVAL_C:
            optarg = HELLO_MAIN_MESSAGE_OPTARG;
            chars = HELLO_MAIN_MESSAGE_OPTUSE;
            break;
        default:
            chars = Implements::OptionUsage(optarg, longopt);
        }
        return chars;
    }
    virtual const char_t* Options(const struct option*& longopts) {
        int err = 0;
        static const char_t* chars = NADIR_CONSOLE_HELLO_MAIN_OPTIONS_CHARS;
        static struct option optstruct[]= {
            NADIR_CONSOLE_HELLO_MAIN_OPTIONS_OPTIONS
            {0, 0, 0, 0}};
        longopts = optstruct;
        return chars;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual const char_t* Arguments(const char_t**& argv) {
        static const char_t* _args = NADIR_CONSOLE_HELLO_MAIN_ARGS;
        static const char_t* _argv[] = {
            NADIR_CONSOLE_HELLO_MAIN_ARGV
            0};
        argv = _argv;
        return _args;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};
typedef MainOptT<> MainOpt;

} // namespace hello
} // namespace console 
} // namespace app 
} // namespace nadir 

#endif // _NADIR_APP_CONSOLE_HELLO_MAINOPT_HPP 
