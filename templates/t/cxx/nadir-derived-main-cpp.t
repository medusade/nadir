%########################################################################
%# Copyright (c) 1988-2014 $organization$
%#
%# This software is provided by the author and contributors ``as is'' 
%# and any express or implied warranties, including, but not limited to, 
%# the implied warranties of merchantability and fitness for a particular 
%# purpose are disclaimed. In no event shall the author or contributors 
%# be liable for any direct, indirect, incidental, special, exemplary, 
%# or consequential damages (including, but not limited to, procurement 
%# of substitute goods or services; loss of use, data, or profits; or 
%# business interruption) however caused and on any theory of liability, 
%# whether in contract, strict liability, or tort (including negligence 
%# or otherwise) arising in any way out of the use of this software, 
%# even if advised of the possibility of such damage.
%#
%#   File: nadir-derived-main-cpp.t
%#
%# Author: $author$
%#   Date: 12/15/2014
%########################################################################
%with(%
%_lt_,%(%if(%equal(%content_type%,text/html)%,%(&lt;)%,%(<)%)%)%,%
%_gt_,%(%if(%equal(%content_type%,text/html)%,%(&gt;)%,%(>)%)%)%,%
%filepath,%(%else-then(%filepath%,%(%filepath(%input%)%)%)%)%,%
%file,%(%else-then(%file%,%(main)%)%)%,%
%File,%(%else-then(%File%,%(%file%)%)%)%,%
%FILE,%(%else-then(%FILE%,%(%toupper(%File%)%)%)%)%,%
%file,%(%else-then(%_File%,%(%tolower(%File%)%)%)%)%,%
%file_base,%(%else-then(%file_base%,%(%filebase(%File%)%)%)%)%,%
%File_base,%(%else-then(%File_base%,%(%file_base%)%)%)%,%
%FILE_BASE,%(%else-then(%FILE_BASE%,%(%toupper(%File_base%)%)%)%)%,%
%file_base,%(%else-then(%_File_base%,%(%tolower(%File_base%)%)%)%)%,%
%file_type,%(%else-then(%file_type%,%(hpp)%)%)%,%
%File_type,%(%else-then(%File_type%,%(%file_type%)%)%)%,%
%FILE_TYPE,%(%else-then(%FILE_TYPE%,%(%toupper(%File_type%)%)%)%)%,%
%file_type,%(%else-then(%_File_type%,%(%tolower(%File_type%)%)%)%)%,%
%file_extension,%(%else-then(%file_extension%,%(%File_type%)%)%)%,%
%File_extension,%(%else-then(%File_extension%,%(%file_extension%)%)%)%,%
%FILE_EXTENSION,%(%else-then(%FILE_EXTENSION%,%(%toupper(%File_extension%)%)%)%)%,%
%file_extension,%(%else-then(%_File_extension%,%(%tolower(%File_extension%)%)%)%)%,%
%framework,%(%else-then(%framework%,%(%else-then(%class%,%(framework)%)%)%)%)%,%
%Framework,%(%else-then(%Framework%,%(%framework%)%)%)%,%
%FRAMEWORK,%(%else-then(%FRAMEWORK%,%(%toupper(%Framework%)%)%)%)%,%
%framework,%(%else-then(%_Framework%,%(%tolower(%Framework%)%)%)%)%,%
%base,%(%else-then(%base%,%(xos)%)%)%,%
%Base,%(%else-then(%Base%,%(%base%)%)%)%,%
%BASE,%(%else-then(%BASE%,%(%toupper(%Base%)%)%)%)%,%
%base,%(%else-then(%_Base%,%(%tolower(%Base%)%)%)%)%,%
%%(%
%%include(%filepath%/nadir-cpp-file-begin.t)%%
%%if(%equal(%file_type%,cpp)%,%(%
%#include "%Framework%/console/%File%.hpp"

namespace %Framework% {

} // namespace %Framework%
%
%)%,%(%
%#ifndef _%FRAMEWORK%_CONSOLE_%FILE%_%FILE_EXTENSION%
#define _%FRAMEWORK%_CONSOLE_%FILE%_%FILE_EXTENSION%

#include "%Framework%/base/base.hpp"
#include "%Base%/base/main.hpp"
#include "%Base%/base/getopt/main.hpp"
#include "%Base%/base/getopt/main_opt.hpp"

#define %FRAMEWORK%_MAIN_LOGGING_OPTVAL_C %BASE%_MAIN_LOGGING_OPTVAL_C
#define %FRAMEWORK%_MAIN_LOGGING_OPTARG %BASE%_MAIN_LOGGING_OPTARG
#define %FRAMEWORK%_MAIN_LOGGING_OPTUSE %BASE%_MAIN_LOGGING_OPTUSE

#define %FRAMEWORK%_MAIN_HELP_OPTVAL_C %BASE%_MAIN_HELP_OPTVAL_C
#define %FRAMEWORK%_MAIN_HELP_OPTARG %BASE%_MAIN_HELP_OPTARG
#define %FRAMEWORK%_MAIN_HELP_OPTUSE %BASE%_MAIN_HELP_OPTUSE

namespace %Framework% {
namespace console {

typedef int main_opt_argument_t;
enum {
    MAIN_OPT_ARGUMENT_NONE     = %BASE%_MAIN_OPT_ARGUMENT_NONE,
    MAIN_OPT_ARGUMENT_REQUIRED = %BASE%_MAIN_OPT_ARGUMENT_REQUIRED,
    MAIN_OPT_ARGUMENT_OPTIONAL = %BASE%_MAIN_OPT_ARGUMENT_OPTIONAL
};

} // namespace console

namespace app {
namespace console {

typedef %Framework%::console::main_opt_argument_t main_opt_argument_t;
enum {
    MAIN_OPT_ARGUMENT_NONE     = %Framework%::console::MAIN_OPT_ARGUMENT_NONE,
    MAIN_OPT_ARGUMENT_REQUIRED = %Framework%::console::MAIN_OPT_ARGUMENT_REQUIRED,
    MAIN_OPT_ARGUMENT_OPTIONAL = %Framework%::console::MAIN_OPT_ARGUMENT_OPTIONAL
};

} // namespace console
} // namespace app
} // namespace %Framework%

#define %FRAMEWORK%_CONSOLE_MAIN_LOGGING_LEVELS_OPT "logging"
#define %FRAMEWORK%_CONSOLE_MAIN_LOGGING_LEVELS_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_REQUIRED
#define %FRAMEWORK%_CONSOLE_MAIN_LOGGING_LEVELS_OPTARG_RESULT 0
#define %FRAMEWORK%_CONSOLE_MAIN_LOGGING_LEVELS_OPTARG %FRAMEWORK%_MAIN_LOGGING_OPTARG
#define %FRAMEWORK%_CONSOLE_MAIN_LOGGING_LEVELS_OPTUSE %FRAMEWORK%_MAIN_LOGGING_OPTUSE
#define %FRAMEWORK%_CONSOLE_MAIN_LOGGING_LEVELS_OPTVAL_S "l:"
#define %FRAMEWORK%_CONSOLE_MAIN_LOGGING_LEVELS_OPTVAL_C 'l'
#define %FRAMEWORK%_CONSOLE_MAIN_LOGGING_LEVELS_OPTION \
   {%FRAMEWORK%_CONSOLE_MAIN_LOGGING_LEVELS_OPT, \
    %FRAMEWORK%_CONSOLE_MAIN_LOGGING_LEVELS_OPTARG_REQUIRED, \
    %FRAMEWORK%_CONSOLE_MAIN_LOGGING_LEVELS_OPTARG_RESULT, \
    %FRAMEWORK%_CONSOLE_MAIN_LOGGING_LEVELS_OPTVAL_C}, \

#define %FRAMEWORK%_CONSOLE_MAIN_HELP_OPT "help"
#define %FRAMEWORK%_CONSOLE_MAIN_HELP_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_NONE
#define %FRAMEWORK%_CONSOLE_MAIN_HELP_OPTARG_RESULT 0
#define %FRAMEWORK%_CONSOLE_MAIN_HELP_OPTARG %FRAMEWORK%_MAIN_HELP_OPTARG
#define %FRAMEWORK%_CONSOLE_MAIN_HELP_OPTUSE %FRAMEWORK%_MAIN_HELP_OPTUSE
#define %FRAMEWORK%_CONSOLE_MAIN_HELP_OPTVAL_S "?"
#define %FRAMEWORK%_CONSOLE_MAIN_HELP_OPTVAL_C '?'
#define %FRAMEWORK%_CONSOLE_MAIN_HELP_OPTION \
   {%FRAMEWORK%_CONSOLE_MAIN_HELP_OPT, \
    %FRAMEWORK%_CONSOLE_MAIN_HELP_OPTARG_REQUIRED, \
    %FRAMEWORK%_CONSOLE_MAIN_HELP_OPTARG_RESULT, \
    %FRAMEWORK%_CONSOLE_MAIN_HELP_OPTVAL_C}, \

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
#define %FRAMEWORK%_CONSOLE_MAIN_OPTIONS_CHARS \
    %FRAMEWORK%_CONSOLE_MAIN_LOGGING_LEVELS_OPTVAL_S \
    %FRAMEWORK%_CONSOLE_MAIN_HELP_OPTVAL_S \

#define %FRAMEWORK%_CONSOLE_MAIN_OPTIONS_OPTIONS \
    %FRAMEWORK%_CONSOLE_MAIN_LOGGING_LEVELS_OPTION \
    %FRAMEWORK%_CONSOLE_MAIN_HELP_OPTION \

namespace %Framework% {
namespace console {

typedef %Base%::base::getopt::main_implement main_implement;
typedef %Base%::base::getopt::main main_extend;
///////////////////////////////////////////////////////////////////////
///  Class: main
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS main: virtual public main_implement, public main_extend {
public:
    typedef main_implement Implements;
    typedef main_extend Extends;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    main() {
    }
    virtual ~main() {
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int on_logging_levels_option
    (int optval, const char* optarg,
     const char* optname, int optind,
     int argc, char**argv, char**env) {
        int err = on_logging_option
        (%FRAMEWORK%_MAIN_LOGGING_OPTVAL_C,
         optarg, optname, optind, argc, argv, env);
        return err;
    }
    ///////////////////////////////////////////////////////////////////////
    virtual int on_help_option
    (int optval, const char* optarg,
     const char* optname, int optind,
     int argc, char**argv, char**env) {
        int err = usage(argc, argv, env);
        return err;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int on_option
    (int optval, const char* optarg,
     const char* optname, int optind,
     int argc, char**argv, char**env) {
        int err = 0;
        switch(optval) {
        case %FRAMEWORK%_CONSOLE_MAIN_LOGGING_LEVELS_OPTVAL_C:
            err = on_logging_levels_option
            (optval, optarg, optname, optind, argc, argv, env);
            break;
        case %FRAMEWORK%_CONSOLE_MAIN_HELP_OPTVAL_C:
            err = on_help_option
            (optval, optarg, optname, optind, argc, argv, env);
            break;
        default:
            err = Extends::on_option
            (optval, optarg, optname, optind, argc, argv, env);
        }
        return err;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual const char* option_usage
    (const char*& optarg, const struct option* longopt) {
        const char* chars = "";
        switch(longopt->val) {
        case %FRAMEWORK%_CONSOLE_MAIN_LOGGING_LEVELS_OPTVAL_C:
            optarg = %FRAMEWORK%_CONSOLE_MAIN_LOGGING_LEVELS_OPTARG;
            chars = %FRAMEWORK%_CONSOLE_MAIN_LOGGING_LEVELS_OPTUSE;
            break;
        case %FRAMEWORK%_CONSOLE_MAIN_HELP_OPTVAL_C:
            optarg = %FRAMEWORK%_CONSOLE_MAIN_HELP_OPTARG;
            chars = %FRAMEWORK%_CONSOLE_MAIN_HELP_OPTUSE;
            break;
        default:
            chars = Extends::option_usage(optarg, longopt);
        }
        return chars;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual const char* options(const struct option*& longopts) {
        int err = 0;
        static const char* chars = %FRAMEWORK%_CONSOLE_MAIN_OPTIONS_CHARS;
        static struct option optstruct[]= {
            %FRAMEWORK%_CONSOLE_MAIN_OPTIONS_OPTIONS
            {0, 0, 0, 0}};
        longopts = optstruct;
        return chars;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};

} // namespace console
} // namespace %Framework%

#endif // _%FRAMEWORK%_CONSOLE_%FILE%_%FILE_EXTENSION%
%
%)%)%%
%%include(%filepath%/nadir-cpp-file-end.t)%%
%)%)%