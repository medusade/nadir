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
///   File: main_opt.hpp
///
/// Author: $author$
///   Date: 1/13/2017
///////////////////////////////////////////////////////////////////////
#ifndef _NADIR_CONSOLE_GETOPT_MAIN_OPT_HPP
#define _NADIR_CONSOLE_GETOPT_MAIN_OPT_HPP

#include "nadir/base/base.hpp"
#include <getopt.h>

enum {
    NADIR_CONSOLE_GETOPT_MAIN_OPT_ARGUMENT_NONE     = 0,
    NADIR_CONSOLE_GETOPT_MAIN_OPT_ARGUMENT_REQUIRED = 1,
    NADIR_CONSOLE_GETOPT_MAIN_OPT_ARGUMENT_OPTIONAL = 2
};

#define NADIR_CONSOLE_GETOPT_MAIN_LOGGING_OPT "logging-level"
#define NADIR_CONSOLE_GETOPT_MAIN_LOGGING_OPTARG_REQUIRED NADIR_CONSOLE_GETOPT_MAIN_OPT_ARGUMENT_REQUIRED
#define NADIR_CONSOLE_GETOPT_MAIN_LOGGING_OPTARG "{(a)all | (n)none | (f)fatal | (e)error | (w)waring | (i)info | (d)debug | (t)trace}"
#define NADIR_CONSOLE_GETOPT_MAIN_LOGGING_OPTUSE ""
#define NADIR_CONSOLE_GETOPT_MAIN_LOGGING_OPTVAL_S "l:"
#define NADIR_CONSOLE_GETOPT_MAIN_LOGGING_OPTVAL_C 'l'

#define NADIR_CONSOLE_GETOPT_MAIN_LOGGING_OPTIONS_OPTION \
   {NADIR_CONSOLE_GETOPT_MAIN_LOGGING_OPT, \
    NADIR_CONSOLE_GETOPT_MAIN_LOGGING_OPTARG_REQUIRED, 0, \
    NADIR_CONSOLE_GETOPT_MAIN_LOGGING_OPTVAL_C},

#define NADIR_CONSOLE_GETOPT_MAIN_HELP_OPT "help"
#define NADIR_CONSOLE_GETOPT_MAIN_HELP_OPTARG_REQUIRED NADIR_CONSOLE_GETOPT_MAIN_OPT_ARGUMENT_NONE
#define NADIR_CONSOLE_GETOPT_MAIN_HELP_OPTARG ""
#define NADIR_CONSOLE_GETOPT_MAIN_HELP_OPTUSE "Usage options"
#define NADIR_CONSOLE_GETOPT_MAIN_HELP_OPTVAL_S "h"
#define NADIR_CONSOLE_GETOPT_MAIN_HELP_OPTVAL_C 'h'

#define NADIR_CONSOLE_GETOPT_MAIN_HELP_OPTIONS_OPTION \
   {NADIR_CONSOLE_GETOPT_MAIN_HELP_OPT, \
    NADIR_CONSOLE_GETOPT_MAIN_HELP_OPTARG_REQUIRED, 0, \
    NADIR_CONSOLE_GETOPT_MAIN_HELP_OPTVAL_C},

#define NADIR_CONSOLE_GETOPT_MAIN_OPTIONS_CHARS \
    NADIR_CONSOLE_GETOPT_MAIN_LOGGING_OPTVAL_S \
    NADIR_CONSOLE_GETOPT_MAIN_HELP_OPTVAL_S

#define NADIR_CONSOLE_GETOPT_MAIN_OPTIONS_OPTIONS \
    NADIR_CONSOLE_GETOPT_MAIN_LOGGING_OPTIONS_OPTION \
    NADIR_CONSOLE_GETOPT_MAIN_HELP_OPTIONS_OPTION

namespace nadir {
namespace console {
namespace getopt {

} // namespace getopt 
} // namespace console 
} // namespace nadir 

#endif // _NADIR_CONSOLE_GETOPT_MAIN_OPT_HPP 
