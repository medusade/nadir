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
///   File: Array.hpp
///
/// Author: $author$
///   Date: 9/20/2017
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_BASE_ARRAY_HPP
#define _XOS_BASE_ARRAY_HPP

#include "xos/base/CharsBase.hpp"

namespace xos {

///////////////////////////////////////////////////////////////////////
///  Class: ArrayT
///////////////////////////////////////////////////////////////////////
template
<typename TWhat = char,
 class TImplement = ImplementBase,
 class TExtend = Base,
 size_t VDefaultSize = 128,
 class TImplements = TImplement, class TExtends = TExtend>

class _EXPORT_CLASS ArrayT: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;

    typedef TWhat what_t;
    static const size_t defaultSize = VDefaultSize;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    ArrayT(ssize_t length)
    : m_elements(m_default), m_size(defaultSize), m_length(0) {
        SetLength(length);
    }
    ArrayT(const ArrayT& copy)
    : m_elements(m_default), m_size(defaultSize), m_length(0) {
        Append(copy.elements(), copy.length());
    }
    ArrayT()
    : m_elements(m_default), m_size(defaultSize), m_length(0) {
    }
    virtual ~ArrayT() {
        Clear();
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual size_t Assign(const what_t* elements, size_t elementsLength) {
        size_t count = 0;
        size_t newelementsLength;

        if ((!elements) || (!m_elements) || (elementsLength < 1)) {
            return 0;
        }
        if (m_size < (newelementsLength = (elementsLength))) {
            if (0 >= (count = AdjustToSize(NewSize(newelementsLength)))) {
                return count;
            }
        }
        CopyElements(m_elements, elements, elementsLength);
        m_length = (count = elementsLength);
        return count;
    }
    virtual size_t Append(const what_t* elements, size_t elementsLength) {
        size_t count = 0;
        size_t newelementsLength;

        if ((!elements) || (!m_elements) || (elementsLength < 1)) {
            return 0;
        }
        if (m_size < (newelementsLength = (m_length + elementsLength))) {
            if (0 >= (count = AdjustToSize(NewSize(newelementsLength)))) {
                return count;
            }
        }
        CopyElements(m_elements+m_length, elements, elementsLength);
        m_length += (count = elementsLength);
        return count;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual size_t Set(const what_t& element){
        return Set(element, m_length);
    }
    virtual size_t Set(const what_t& element, size_t elementsLength){
        size_t count = 0;
        size_t newelementsLength;

        if ((!m_elements) || (elementsLength < 1)) {
            return 0;
        }
        if (m_size < (newelementsLength = (elementsLength))) {
            if (0 >= (count = AdjustToSize(NewSize(newelementsLength)))) {
                return count;
            }
        }
        SetElements(m_elements, element, elementsLength);
        m_length = (count = elementsLength);
        return count;
    }
    virtual size_t Clear(){
        size_t count = m_length;
        if (m_elements) {
            if (m_elements != m_default) {
                delete[] m_elements;
            }
        }
        m_elements = m_default;
        m_size = defaultSize;
        m_length = 0;
        return count;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual size_t SetLength(ssize_t toLength){
        size_t toSize = 0;

        if (!m_elements) {
            return 0;
        }
        if (0 > toLength) {
            toLength = defaultSize;
        }
        if ((toSize = (size_t)(toLength)) > m_size) {
            if (toLength > ((ssize_t)(SetSize(toSize)))) {
                return 0;
            }
        }
        m_length = toLength;
        return m_length;
    }
    virtual size_t Length() const {
        return m_length;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual size_t SetSize(size_t toSize){
        if (toSize != m_size){
            AdjustToSize(NewSize(toSize));
        }
        return m_size;
    }
    virtual size_t Size() const {
        return m_size;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual what_t* Elements() const {
        return m_elements;
    }
    virtual what_t& operator[](size_t index) const {
        return (what_t&)(m_elements[index]);
    }
#if !defined(__MSC__)
    virtual operator what_t*() const {
        return (what_t*)(m_elements);
    }
#endif // !defined(__MSC__)

protected:
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual size_t AdjustToSize(size_t size) {
        size_t count = 0;
        what_t* elements;

        if (!m_elements) {
            return 0;
        }
        if (size <= m_size) {
            // elements is already big enough
            //
            return m_size;
        }
        if (!(elements = new what_t[size])) {
            return 0;
        }
        if (m_elements) {
            if (m_length > 0) {
                CopyElements(elements, m_elements, m_length);
            }
            if (m_elements != m_default) {
                delete m_elements;
            }
        }
        m_elements = elements;
        m_size = size;
        count = m_size;
        return count;
    }
    virtual size_t NewSize(size_t size) const {
        size_t count = 0;
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
        count = (size = ((size / defaultSize) + 1) *defaultSize);
        return count;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual size_t SetElements(what_t* to, const what_t& from, size_t size) const {
        size_t count = 0;
        if ((to)) {
            for (count = 0; size > 0; --size, count++) {
                (*to++) = from;
            }
        }
        return count;
    }
    virtual size_t CopyElements(what_t* to, const what_t* from, size_t size) const {
        size_t count = 0;
        if ((to) && (from)) {
            for (count = 0; size > 0; --size, count++) {
                (*to++) = (*from++);
            }
        }
        return count;
    }
    virtual size_t CountElements(what_t* what, const what_t& end) const {
        size_t count = 0;
        if (what) {
            while (end != *(what++)) {
                ++count;
            }
        }
        return count;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    what_t m_default[defaultSize], *m_elements;
    size_t m_size, m_length;
};

///////////////////////////////////////////////////////////////////////
/// Class CharArrayT
///////////////////////////////////////////////////////////////////////
template
<typename TChar = char,
 typename TEnd = TChar, TEnd VEnd = 0,
 class TChars = CharsBaseT<TChar, TEnd, VEnd, ImplementBase>,
 class TArray = ArrayT<TChar, TChars, Base>,
 class TImplements = TChars, class TExtends = TArray>

class _EXPORT_CLASS CharArrayT: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;
    typedef CharArrayT Derives;

    typedef TChar char_t;
    typedef TEnd end_t;
    static const end_t endof = VEnd;

    typedef typename Extends::what_t what_t;
    static const size_t defaultSize = Extends::defaultSize;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    CharArrayT(const char_t* chars) {
        this->Append(chars);
    }
    CharArrayT(const char_t* chars, size_t length) {
        this->Append(chars, length);
    }
    CharArrayT(const CharArrayT& copy): Extends(copy) {
    }
    CharArrayT() {
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    using Extends::Assign;
    virtual CharArrayT& Assign(const char_t* chars) {
        this->Clear();
        this->Append(chars);
        return *this;
    }
    using Extends::Append;
    virtual CharArrayT& Append(const char_t* chars) {
        if ((chars)) {
            for (char_t c = *(chars); (c != endof); c = *(++chars)) {
                this->Append(&c, 1);
            }
        }
        return *this;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};
typedef CharArrayT<char> CharArray;
typedef CharArrayT<tchar_t> TCharArray;
typedef CharArrayT<wchar_t> WCharArray;

} // namespace xos

#endif // _XOS_BASE_ARRAY_HPP 
