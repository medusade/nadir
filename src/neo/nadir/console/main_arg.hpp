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
///   File: main_arg.hpp
///
/// Author: $author$
///   Date: 1/17/2018
///////////////////////////////////////////////////////////////////////
#ifndef _NADIR_CONSOLE_MAIN_ARG_HPP
#define _NADIR_CONSOLE_MAIN_ARG_HPP

#include "nadir/console/main.hpp"

namespace nadir {
namespace console {

///////////////////////////////////////////////////////////////////////
///  Class: main_argt
///////////////////////////////////////////////////////////////////////
template <class TImplements = main::Implements>

class _EXPORT_CLASS main_argt: virtual public TImplements {
public:
    typedef TImplements Implements;

    typedef typename Implements::char_t char_t;
    typedef typename Implements::end_char_t end_char_t;
    enum { end_char = Implements::end_char };

protected:
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
    virtual int on_argument
    (const char_t* arg, int argind,
     int argc, char_t**argv, char_t**env) {
        int err = 0;
        return err;
    }
    virtual int on_invalid_argument(const char_t* arg) {
        int err = 1;
        return err;
    }
    virtual int on_missing_argument(const char_t* arg) {
        int err = 1;
        return err;
    }
    virtual const char_t* arguments(const char_t**& args) {
        args = 0;
        return 0;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int usage(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual const char_t* usage_name
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
    virtual bool set_did_usage(bool to = true) {
        return did_usage();
    }
    virtual bool did_usage() const {
        return false;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};
typedef main_argt<> main_arg;

} // namespace console 
} // namespace nadir 

#endif // _NADIR_CONSOLE_MAIN_ARG_HPP 
