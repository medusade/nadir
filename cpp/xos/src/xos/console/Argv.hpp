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
///   File: Argv.hpp
///
/// Author: $author$
///   Date: 9/24/2017
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_CONSOLE_ARGV_HPP
#define _XOS_CONSOLE_ARGV_HPP

#include "xos/io/Writer.hpp"
#include "xos/io/Reader.hpp"
#include "xos/base/Array.hpp"

namespace xos {
namespace console {

///////////////////////////////////////////////////////////////////////
///  Class: ArgvT
///////////////////////////////////////////////////////////////////////
template
<typename TChar = char,
 class TImplement = ImplementBase,
 class TArray = ArrayT<TChar*, TImplement, Base>,
 class TImplements = TImplement, class TExtends = TArray>

class _EXPORT_CLASS ArgvT: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;

    typedef TChar* arg_t;
    typedef TChar char_t;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    ArgvT(size_t argc, arg_t* argv): m_end((arg_t)0) {
        Assign(argc, argv);
    }
    ArgvT(): m_end((arg_t)0) {
        Extends::Assign(&m_end, 1);
    }
    virtual ~ArgvT() {
        Free();
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    using Extends::Assign;
    virtual ArgvT& Assign(size_t argc, arg_t* argv) {
        Free();
        Extends::Assign(&m_end, 1);
        if (0 < (argc)) {
            Extends::Assign(argv, argc);
            Extends::Append(&m_end, 1);
            Allocate();
        }
        return *this;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual size_t Allocate() {
        size_t count = 0;
        arg_t* arg = 0;

        if ((arg = this->Elements())) {
            char_t *chars = 0, *chars2 = 0;
            size_t length = 0, size = 0;

            for (chars = (*arg); chars; chars = *(++arg)) {
                size = this->NewSize((length = Count(chars)) + 1);
                if ((chars2 = new char_t[size])) {
                    Copy(chars2, chars, length);
                }
                *arg = chars2;
            }
        }
        return count;
    }
    virtual size_t Free() {
        size_t count = 0;
        arg_t* arg = 0;

        if ((arg = this->Elements())) {
            char_t *chars = 0;
            size_t length = 0;

            for (length = this->Length(); length; --length, ++arg) {
                if ((chars = (*arg))) {
                    delete[] chars;
                    chars = 0;
                }
            }
        }
        return count;
    }

protected:
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual size_t Count(char_t* arg) const {
        size_t count = 0;

        if (arg) {
            while (*(arg++)) {
                ++count;
            }
        }
        return count;
    }
    virtual size_t Copy
    (char_t* to, const char_t* from, size_t length) const {
        size_t count = 0;

        if ((to) && (from) && (length)) {
            for (count = 0; length > 0; --length, count++) {
                (*to++) = (*from++);
            }
            to[length] = 0;
        }
        return count;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    arg_t m_end;
};
typedef ArgvT<char> Argv;
typedef ArgvT<tchar_t> TArgv;
typedef ArgvT<wchar_t> WArgv;

///////////////////////////////////////////////////////////////////////
///  Class: ArgvWriterT
///////////////////////////////////////////////////////////////////////
template
<typename TChar = char,
 class TArgv = ArgvT<TChar*>,
 class TWriter = io::WriterT<TChar>,
 class TImplements = ImplementBase, class TExtends = Base>

class _EXPORT_CLASS ArgvWriterT: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;

    typedef TArgv argv_t;
    typedef TWriter writer_t;
    typedef TChar* arg_t;
    typedef TChar char_t;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    ArgvWriterT() {
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool Write(ssize_t& count, writer_t& writer, const argv_t& argv) {
        return Write(count, writer, argv.Elements());
    }
    virtual bool Write(ssize_t& count, writer_t& writer, char_t** argv) {
        bool success = true;
        ssize_t amount = 0;

        if ((argv) && (*argv)) {
            for (char_t* arg = (*argv); arg; arg = *(++argv)) {

                if (0 <= (amount = writer.Write(arg))) {
                    count += amount;

                    if (0 < (amount = writer.Write(&cr_, 1))) {
                        count += amount;

                        if (0 < (amount = writer.Write(&lf_, 1))) {
                            count += amount;
                            continue;
                        }
                    }
                }
                count = amount;
                success = false;
                break;
            }
        }
        if ((success)) {
            if (0 < (amount = writer.Write(&cr_, 1))) {
                count += amount;

                if (0 < (amount = writer.Write(&lf_, 1))) {
                    count += amount;
                    return success;
                }
            }
            count = amount;
            success = false;
        }
        return success;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    const char_t cr_ = ((char_t)'\r');
    const char_t lf_ = ((char_t)'\n');
};
typedef ArgvWriterT<char, Argv, io::CharWriter> ArgvWriter;
typedef ArgvWriterT<tchar_t, TArgv, io::TCharWriter> TArgvWriter;
typedef ArgvWriterT<wchar_t, WArgv, io::WCharWriter> WArgvWriter;

///////////////////////////////////////////////////////////////////////
///  Class: ArgvReaderT
///////////////////////////////////////////////////////////////////////
template
<typename TChar = char,
 class TArgv = ArgvT<TChar*>,
 class TReader = io::ReaderT<TChar>,
 class TString = StringT<TChar>,
 class TImplements = ImplementBase, class TExtends = Base>

class _EXPORT_CLASS ArgvReaderT: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;
    typedef ArgvReaderT Derives;

    typedef TArgv argv_t;
    typedef TReader reader_t;
    typedef TString string_t;
    typedef TChar* arg_t;
    typedef TChar char_t;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    ArgvReaderT(): m_on(0) {
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool Read(ssize_t& count, reader_t& reader, argv_t& argv) {
        bool success = false;
        ssize_t amount = 0;
        char_t c = 0;

        argv.Free();
        argv.Clear();
        m_value.Clear();
        m_on = &Derives::OnValue;

        for (count = 0, amount = 1; 0 < amount; count += amount) {
            if (0 < (amount = reader.Read(&c, 1))) {
                if ((On(argv, c))) {
                    continue;
                }
            } else {
                if (0 > (amount)) {
                    count = amount;
                }
            }
            break;
        }
        m_on = 0;
        m_value.Clear();
        return success;
    }
    virtual bool On(argv_t& argv, const char_t& c) {
        if ((m_on)) {
            return (this->*m_on)(argv, c);
        }
        return false;
    }
    virtual bool OnValue(argv_t& argv, const char_t& c) {
        if ((cr_ != c)) {
            if ((lf_ != c)) {
                m_value.Append(&c, 1);
            } else {
                return OnAppend(argv, c);
            }
        } else {
            m_on = &Derives::OnCR;
        }
        return true;
    }
    virtual bool OnCR(argv_t& argv, const char_t& c) {
        if ((cr_ != c)) {
            if ((lf_ != c)) {
                m_value.Append(&cr_, 1);
                m_on = &Derives::OnValue;
            } else {
                return OnAppend(argv, c);
            }
        } else {
            m_value.Append(&cr_, 1);
        }
        return true;
    }
    virtual bool OnAppend(argv_t& argv, const char_t& c) {
        char_t* arg = 0;
        const char_t* chars = 0;
        size_t length = 0;

        if ((chars = m_value.HasChars(length))) {
            char_t* args = 0;
            if ((args = (arg = new char_t[length+1]))) {
                for (arg[length] = 0; 0 < length; --length, ++chars, ++args) {
                    *args = *chars;
                }
                argv.Append(&arg, 1);
            }
            m_value.Clear();
        } else {
            argv.Append(&arg, 1);
            return false;
        }
        return true;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    const char_t cr_ = ((char_t)'\r');
    const char_t lf_ = ((char_t)'\n');
    bool (Derives::*m_on)(argv_t& argv, const char_t& c);
    string_t m_value;
};
typedef ArgvReaderT<char, Argv, io::CharReader> ArgvReader;
typedef ArgvReaderT<tchar_t, TArgv, io::TCharReader> TArgvReader;
typedef ArgvReaderT<wchar_t, WArgv, io::WCharReader> WArgvReader;

} // namespace console
} // namespace xos 

#endif // _XOS_CONSOLE_ARGV_HPP 
