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
///   File: Main.hpp
///
/// Author: $author$
///   Date: 8/17/2017
///////////////////////////////////////////////////////////////////////
#ifndef _NADIR_CONSOLE_GETOPT_MAIN_HPP
#define _NADIR_CONSOLE_GETOPT_MAIN_HPP

#include "nadir/console/getopt/MainOpt.hpp"
#include "nadir/console/Main.hpp"

namespace nadir {
namespace console {
namespace getopt {

typedef console::MainTImplements MainTImplements;
typedef console::MainTExtends MainTExtends;
///////////////////////////////////////////////////////////////////////
///  Class: MainT
///////////////////////////////////////////////////////////////////////
template
<typename TChar = char,
 typename TEndChar = TChar, TEndChar VEndChar = 0,
 class TOpt = getopt::MainOptT
 <TChar, TEndChar, VEndChar, console::MainArgT
  <TChar, TEndChar, VEndChar, MainTImplements> >,
 class TIO = xos::console::IOT<TChar, TEndChar, VEndChar, MainTImplements>,
 class TMain = console::MainT<TChar, TEndChar, VEndChar, TOpt, TIO, MainTExtends>,
 class TOptImplements = TOpt, class TImplements = TIO, class TExtends = TMain>

class _EXPORT_CLASS MainT
:  virtual public TOptImplements, virtual public TImplements, public TExtends {
public:
    typedef TOptImplements OptImplements;
    typedef TImplements Implements;
    typedef TExtends Extends;
    ///////////////////////////////////////////////////////////////////////
    /// Constructor: MainT
    ///////////////////////////////////////////////////////////////////////
    MainT() {
    }
    virtual ~MainT() {
    }
protected:
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int Run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        err = this->Usage(argc, argv, env);
        return err;
    }
    virtual int BeforeRun(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = this->BeforeGetOptions(argc, argv, env))) {
            int err2 = 0;
            err = this->GetOptions(argc, argv, env);
            if ((err2 = this->AfterGetOptions(argc, argv, env))) {
                if (!err) err = err2;
            } else {
                if ((err2 = this->BeforeGetArguments(argc, argv, env))) {
                    if (!(err)) err = err2;
                } else {
                    if ((err2 = this->GetArguments(argc, argv, env))) {
                        if (!(err)) err = err2;
                    }
                    if ((err2 = this->AfterGetArguments(argc, argv, env))) {
                        if (!(err)) err = err2;
                    }
                }
            }
        }
        return err;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int OnInvalidOption
    (int optval, const char_t* optarg,
     const char_t* optname, int optind,
     int argc, char_t** argv, char_t** env) {
        int err = 1;
        this->ErrF("invalid option \"%s\"\n", optname);
        return err;
    }
    virtual int OnInvalidOptionArg
    (int optval, const char_t* optarg,
     const char_t* optname, int optind,
     int argc, char_t** argv, char_t** env) {
        int err = 1;
        this->ErrF("invalid argument \"%s\" for option \"%s\"\n", optarg, optname);
        return err;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};

typedef console::MainImplements MainImplements;
typedef MainT<char, char, 0, MainOpt, MainImplements, console::Main> MainExtends;
///////////////////////////////////////////////////////////////////////
///  Class: MainExtendT
///////////////////////////////////////////////////////////////////////
template
<class TOptImplements = MainOpt,
 class TImplements = MainImplements, class TExtends = MainExtends>

class _EXPORT_CLASS MainExtendT
: virtual public TOptImplements, virtual public TImplements, public TExtends {
public:
    typedef TOptImplements OptImplements;
    typedef TImplements Implements;
    typedef TExtends Extends;
    ///////////////////////////////////////////////////////////////////////
    /// Constructor: MainExtendT
    ///////////////////////////////////////////////////////////////////////
    MainExtendT() {
    }
    virtual ~MainExtendT() {
    }
protected:
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int Usage(int argc, char** argv, char** env) {
        int err = 0;
        err = RunUsage(argc, argv, env);
        return err;
    }
    virtual int RunUsage(int argc, char** argv, char** env) {
        int err = 0;

        if (!(this->DidUsage())) {
            const char* arg = 0;
            const char** args = 0;
            const char* argstring = this->Arguments(args);
            const struct option* longopts = 0;
            const char* optstring = this->Options(longopts);
            const char* name = this->UsageName(argc, argv, env);

            this->OutF
            ("Usage: %s%s%s%s\n", (name)?(name):(""),
             (optstring)?(" [options]"):(""),
             (argstring)?(" "):(""), (argstring)?(argstring):(""));

            if ((optstring) && (longopts)) {
                this->OutF("\nOptions:\n");

                while ((longopts->name)) {
                    const char* optarg =
                    (MAIN_OPT_ARGUMENT_REQUIRED == longopts->has_arg)?(" arg"):
                    ((MAIN_OPT_ARGUMENT_OPTIONAL == longopts->has_arg)?(" [arg]"):(""));
                    const char* optusage = this->OptionUsage(optarg, longopts);
                    const char* optargSeparator = (optarg[0])?(" "):("");
                    const char* optusageSeparator = "  ";

                    this->OutF
                    (" -%c --%s%s%s%s%s\n",
                     longopts->val, longopts->name,
                     optargSeparator, optarg, optusageSeparator, optusage);
                    longopts++;
                }
            }
            if ((argstring) && (args)) {
                this->OutF("\nArguments:\n");

                while ((arg = (*args))) {
                    this->OutF(" %s\n", arg);
                    args++;
                }
            }
            this->SetDidUsage();
        }
        return err;
    }
};
typedef MainExtendT<> Main;

} // namespace getopt
} // namespace console 
} // namespace nadir 

#endif // _NADIR_CONSOLE_GETOPT_MAIN_HPP 
