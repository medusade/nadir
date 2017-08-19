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
///   File: MainArg.hpp
///
/// Author: $author$
///   Date: 8/15/2017
///////////////////////////////////////////////////////////////////////
#ifndef _NADIR_CONSOLE_MAINARG_HPP
#define _NADIR_CONSOLE_MAINARG_HPP

#include "xos/base/std/String.hpp"
#include "xos/base/String.hpp"

namespace nadir {
namespace console {

typedef xos::ImplementBase MainArgTImplements;
///////////////////////////////////////////////////////////////////////
///  Class: MainArgT
///////////////////////////////////////////////////////////////////////
template
<typename TChar = char,
 typename TEndChar = TChar, TEndChar VEndChar = 0,
 class TImplements = MainArgTImplements>

class _EXPORT_CLASS MainArgT: virtual public MainArgTImplements {
public:
    typedef MainArgTImplements Implements;
    typedef TChar char_t;
    typedef TEndChar endchar_t;
    static const TEndChar endchar = VEndChar;
protected:
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int GetArguments(int argc, char_t**argv, char_t** env) {
        int err = 0;
        if (argc > (optind)) {
            for (int argind = optind; argind < argc; ++argind) {
                if ((err = OnArgument(argv[argind], argind-optind, argc, argv, env))) {
                    break;
                }
            }
        }
        return err;
    }
    virtual int BeforeGetArguments(int argc, char_t**argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int AfterGetArguments(int argc, char_t**argv, char_t** env) {
        int err = 0;
        return err;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int OnArgument
    (const char_t* arg, int argind,
     int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int MissingArgument(const char_t* arg) {
        int err = 1;
        return err;
    }
    virtual const char_t* Arguments(const char_t**& args) {
        args = 0;
        return 0;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int Usage(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual const char_t* UsageName
    (int argc, char_t** argv, char_t** env) const {
        const char_t* arg0 = (0 < argc)?((argv)?(argv[0]):(0)):(0);
        if ((arg0)) {
            for (const char_t* i = arg0; *i; ++i) {
                char c = ((char)(*i));
                if (('/' == c) || ('\\' == c) || (':' == c)) {
                    arg0 = i + 1;
                }
            }
        }
        return arg0;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool SetDidUsage(bool to = true) {
        return DidUsage();
    }
    virtual bool DidUsage() const {
        return false;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};
typedef MainArgT<char, char, 0> MainArg;

} // namespace console
} // namespace nadir 

#endif // _NADIR_CONSOLE_MAINARG_HPP 
