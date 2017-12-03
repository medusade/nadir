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
///   File: StringBase.hpp
///
/// Author: $author$
///   Date: 7/30/2017
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_BASE_STRINGBASE_HPP
#define _XOS_BASE_STRINGBASE_HPP

#include "xos/base/CharsBase.hpp"
#include "xos/base/Append.hpp"

namespace xos {

///////////////////////////////////////////////////////////////////////
///  Class: StringBaseT
///////////////////////////////////////////////////////////////////////
template
<typename TChar = char,
 typename TEnd = TChar, TEnd VEnd = 0,
 class TChars = CharsBaseT<TChar, TEnd, VEnd>,
 class TString = Base, size_t VDefaultSize = 128,
 class TImplements = TChars, class TExtends = TString>

class _EXPORT_CLASS StringBaseT: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;

    typedef TChar char_t;
    typedef TEnd end_t;
    static const end_t endof = VEnd;
    static const size_t defaultSize = VDefaultSize;

    typedef typename TChars::from_signed from_signed;
    typedef typename TChars::from_unsigned from_unsigned;

    ///////////////////////////////////////////////////////////////////////
    /// Constructor: StringBaseT
    ///////////////////////////////////////////////////////////////////////
    StringBaseT(const char_t* chars) {
        _construct();
        append(chars);
    }
    StringBaseT(const char_t* chars, size_t length) {
        _construct();
        append(chars, length);
    }
    StringBaseT(const from_signed& from) {
        _construct();
        this->append_signed(from);
    }
    StringBaseT(const from_unsigned& from) {
        _construct();
        this->append_unsigned(from);
    }
    StringBaseT(const StringBaseT& copy) {
        _construct();
        append(copy.c_str(), copy.length());
    }
    StringBaseT() {
        _construct();
    }
    virtual ~StringBaseT() {
        _destruct();
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual StringBaseT& assign_signed(signed from) {
        this->clear();
        append_signed(from);
        return *this;
    }
    virtual StringBaseT& assign_unsigned(unsigned from) {
        this->clear();
        append_unsigned(from);
        return *this;
    }
    virtual StringBaseT& append_signed(signed from) {
        AppendSignedT<StringBaseT, TChar, signed>(*this, from);
        return *this;
    }
    virtual StringBaseT& append_unsigned(unsigned from) {
        AppendUnsignedT<StringBaseT, TChar, unsigned>(*this, from);
        return *this;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    StringBaseT& assign(const StringBaseT& copy) {
        clear();
        return append(copy.c_str(), copy.length());
    }
    StringBaseT& assign(const char_t* chars) {
        clear();
        return append(chars);
    }
    StringBaseT& assign(const char_t* chars, size_t length) {
        clear();
        return append(chars, length);
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    StringBaseT& append(const StringBaseT& copy) {
        return append(copy.c_str(), copy.length());
    }
    StringBaseT& append(const char_t* chars) {
        return append(chars, _length_of(chars));
    }
    StringBaseT& append(const char_t* chars, size_t length) {
        if ((chars) && (0 < length)) {
            size_t newSize = (m_tell+length);
            if (m_size <= newSize) {
                if (m_fixedSize)
                    length = m_size-m_tell;
                else
                if (!(_adjust_to_size(_new_size_of(newSize))))
                    length = 0;
            }
            if (length) {
                _copy_to(m_writeBuffer+m_tell, chars, length);
                if ((m_tell += length) > m_length)
                if ((m_length = m_tell) < m_size)
                    m_writeBuffer[m_tell] = ((char_t)endof);
            }
        }
        return *this;
    }
    StringBaseT& clear() {
        if ((m_writeBuffer)) {
            if (m_size > (m_length = (m_tell = 0))) {
                m_writeBuffer[m_tell] = ((char_t)endof);
            }
        }
        return *this;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int compare(const StringBaseT& to) {
        return compare(to.c_str(), to.length());
    }
    virtual int compare(const char_t* toChars) {
        return compare(toChars, _length_of(toChars));
    }
    virtual int compare(const char_t* toChars, size_t toLength) {
        int unequal = 2;
        const char_t* thisChars = 0;
        char_t toChar = 0, thisChar = 0;
        size_t thisLength = 0;
        ssize_t lendiff = 0;

        if (!(thisChars = (c_str()))) {
            return (toChars)?(-1):(1);
        }

        if (0 < (lendiff = (toLength - (thisLength = length())))) {
            toLength = thisLength;
            unequal = -1;
        } else {
            if (lendiff) {
                unequal = 1;
            }
        }

        if (toLength > 0) {
            do {
                if ((thisChar = *(thisChars++)) > (toChar = *(toChars++))) {
                    return 1;
                } else {
                    if (thisChar < toChar) {
                        return -1;
                    }
                }
            } while (--toLength > 0);
        }
        return unequal;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    using Implements::to_signed;
    using Implements::to_unsigned;
    virtual signed to_signed() const {
        signed to = 0;
        to = Implements::to_signed(chars(), length());
        return to;
    }
    virtual unsigned to_unsigned() const {
        unsigned to = 0;
        to = Implements::to_unsigned(chars(), length());
        return to;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual char_t* buffer() const {
        return str();
    }
    virtual const char_t* chars() const {
        return c_str();
    }
    virtual char_t* str() const {
        return m_writeBuffer;
    }
    virtual const char_t* c_str() const {
        return m_readBuffer;
    }
    virtual size_t length() const {
        return m_length;
    }

protected:
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual void _construct() {
        m_freeBuffer = m_fixedSize = false;
        m_size = defaultSize;
        m_length = m_tell = 0;
        m_readBuffer = m_writeBuffer = m_defaultBuffer;
    }
    virtual void _destruct() {
        if ((m_writeBuffer != m_defaultBuffer)) {
            if ((m_writeBuffer) && (m_freeBuffer)) {
                _free_buffer(m_writeBuffer);
            }
        }
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual size_t _adjust_size(size_t newSize) {
        if (m_writeBuffer) {
            if (m_size < (newSize)) {
                if (!m_fixedSize) {
                    if (0 < (_adjust_to_size(_new_size_of(newSize)))) {
                        return m_size;
                    }
                }
            } else {
                return m_size;
            }
        }
        return 0;
    }
    virtual size_t _adjust_to_size(size_t size) {
        if (m_writeBuffer) {
            if (size > m_size) {
                bool freeBuffer = false;
                char_t* buffer = 0;

                if (!(freeBuffer = m_freeBuffer)) {
                    m_freeBuffer = true;
                }
                if ((buffer = _alloc_buffer(size))) {
                    if (m_length > 0) {
                        _copy_to(buffer, m_writeBuffer, m_length);
                    }
                    if ((m_writeBuffer != m_defaultBuffer) && (freeBuffer)) {
                        _free_buffer(m_writeBuffer);
                    }
                    m_readBuffer = m_writeBuffer = buffer;
                    m_size = size;
                    return m_size;
                } else {
                    m_freeBuffer = freeBuffer;
                }
            } else {
                return m_size;
            }
        }
        return 0;
    }
    virtual size_t _new_size_of(size_t size) const {
        // Lets increase the buffer size by default buffer
        // sized chunks. Note the desired new size is always
        // needed size + 1. The size in chunks is calculated
        // as (new size + (chunk size - 1)) / chunk size.
        // since new size = needed size + 1 then we have
        // chunks = (needed size + chunk size) / chunk size.
        // Finally we need bytes which is chunks * chunk size
        // which can be reduced to
        // ((needed size / chunk size) + 1) * chunk size
        //
        return ((size / defaultSize) + 1) * defaultSize;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual size_t _copy_to
    (char_t* to, const char_t* from, size_t size) const {
        size_t length = 0;

        if ((to) && (from)) {
            for (length = size; size; --size) {
                (*to++) = (*from++);
            }
        }
        return length;
    }
    virtual size_t _length_of(const char_t* chars) const {
        const char_t endChar(((char_t)endof));
        size_t length = 0;

        if ((chars)) {
            for (length = 0; ((*chars) != endChar); chars++) {
                length++;
            }
        }
        return length;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual char_t* _alloc_buffer(size_t size) const {
        char_t* chars = new char_t[size];
        return chars;
    }
    virtual void _free_buffer(char_t* buffer) const {
        delete[] buffer;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    bool m_freeBuffer;
    bool m_fixedSize;

    size_t m_size;
    size_t m_length;
    size_t m_tell;

    const char_t* m_readBuffer;
    char_t* m_writeBuffer;
    char_t m_defaultBuffer[defaultSize];
};
typedef StringBaseT<char, char, 0, CharsBase> StringBase;
typedef StringBaseT<tchar_t, tchar_t, 0, TCharsBase> TStringBase;
typedef StringBaseT<wchar_t, wchar_t, 0, WCharsBase> WStringBase;

typedef StringBaseT<byte_t, byte_t, 0, BytesBase> ByteStringBase;

} // namespace xos 

#endif // _XOS_BASE_STRINGBASE_HPP 

        

