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
///   File: CharsBase.hpp
///
/// Author: $author$
///   Date: 7/29/2017
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_BASE_CHARSBASE_HPP
#define _XOS_BASE_CHARSBASE_HPP

#include "xos/base/Base.hpp"

namespace xos {

typedef ImplementBase CharsBaseTImplements;
///////////////////////////////////////////////////////////////////////
///  Class: CharsBaseT
///////////////////////////////////////////////////////////////////////
template
<typename TChar = char,
 typename TEnd = TChar, TEnd VEnd = 0,
 class TImplements = CharsBaseTImplements>

class _EXPORT_CLASS CharsBaseT: virtual public TImplements {
public:
    typedef TImplements Implements;
    typedef CharsBaseT Derives;

    typedef TChar char_t;
    typedef TEnd end_t;
    static const end_t endof = VEnd;
    typedef char_t (*to_case_t)(char_t c);

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    static char_t* copy
    (char_t* toWhat, const char_t* what) {
        return copy(toWhat, what, -1, endof);
    }
    static char_t* copy
    (char_t* toWhat, const char_t* what, ssize_t length) {
        return copy(toWhat, what, length, endof);
    }
    static char_t* copy
    (char_t* toWhat, const char_t* what,
     ssize_t length, end_t end) {
        if (toWhat) {
            char_t c = 0;
            if (0 > length) {
                while ((c = (*what++)) != end) {
                    (*toWhat++) = c;
                }
                (*toWhat) = c;
            } else {
                while (0 < length) {
                    (*toWhat++) = (c = (*what++));
                    --length;
                }
            }
        }
        return toWhat;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    static int compare(const char_t* what, const char_t* toWhat) {
        int unequal = compare_cased
        (what, -1, toWhat, -1, endof, endof, Derives::to_case);
        return unequal;
    }
    static int compare
    (const char_t* what, const char_t* toWhat, ssize_t length) {
        int unequal = compare_cased
        (what, length, toWhat, length, endof, endof, Derives::to_case);
        return unequal;
    }
    static int compare
    (const char_t* what, ssize_t length,
     const char_t* toWhat, ssize_t toLength) {
        int unequal = compare_cased
        (what, length, toWhat, toLength, endof, endof, Derives::to_case);
        return unequal;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    static int compare_cased(const char_t* what, const char_t* toWhat) {
        int unequal = compare_cased
        (what, -1, toWhat, -1, endof, endof, Derives::to_case);
        return unequal;
    }
    static int compare_cased
    (const char_t* what, ssize_t length,
     const char_t* toWhat, ssize_t toLength,
     end_t end = endof, end_t toEnd = endof,
     to_case_t to_case = Derives::to_case) {
        int unequal = 0;
        char_t c1 = 0, c2 = 0;

        if (what != toWhat) {
            if (what) {
                if (toWhat) {
                    if (0 > length) {
                        if (0 > toLength) {
                            for (c1 = *what, c2 = *toWhat;
                                 ((c1) != end) && ((c2) != toEnd);
                                 ++what, ++toWhat, c1 = *what, c2 = *toWhat) {
                                if ((c1 = to_case(c1)) > (c2 = to_case(c2))) {
                                    return 1;
                                } else {
                                    if (c1 < c2) {
                                        return -1;
                                    }
                                }
                            }
                            if (c1 != end) {
                                unequal = 1;
                            } else {
                                if (c2 != toEnd) {
                                    unequal = -1;
                                }
                            }
                        } else {
                            for (c1 = *what; ((c1) != end) && (0 < toLength);
                                 --toLength, ++what, ++toWhat, c1 = *what) {
                                c2 = *toWhat;
                                if ((c1 = to_case(c1)) > (c2 = to_case(c2))) {
                                    return 1;
                                } else {
                                    if (c1 < c2) {
                                        return -1;
                                    }
                                }
                            }
                            if (c1 != end) {
                                unequal = 1;
                            } else {
                                if (0 < toLength) {
                                    unequal = -1;
                                }
                            }
                        }
                    } else {
                        if (0 > toLength) {
                            for (c2 = *toWhat; (0 < length) && ((c2) != toEnd);
                                 --length, ++what, ++toWhat, c2 = *toWhat) {
                                c1 = *what;
                                if ((c1 = to_case(c1)) > (c2 = to_case(c2))) {
                                    return 1;
                                } else {
                                    if (c1 < c2) {
                                        return -1;
                                    }
                                }
                            }
                            if (0 < length) {
                                unequal = 1;
                            } else {
                                if (c2 != toEnd) {
                                    unequal = -1;
                                }
                            }
                        } else {
                            if (length > toLength) {
                                unequal = 1;
                                length = toLength;
                            } else {
                                if (toLength > length) {
                                    unequal = -1;
                                }
                            }
                            for (; 0 < length; --length, ++what, ++toWhat) {
                                c1 = *what; c2 = *toWhat;
                                if ((c1 = to_case(c1)) > (c2 = to_case(c2))) {
                                    return 1;
                                } else {
                                    if (c1 < c2) {
                                        return -1;
                                    }
                                }
                            }
                        }
                    }
                } else {
                    unequal = 1;
                }
            } else {
                if (toWhat) {
                    unequal = -1;
                }
            }
        }
        return unequal;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    static size_t count(const char_t* chars, end_t end = endof) {
        size_t length = 0;
        if (chars) {
            char_t c = 0;
            for (char_t e = ((char_t)end);
                 ((c = *chars) != e); ++chars) {
                ++length;
            }
        }
        return length;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    static char_t to_lower(char_t c) {
        static const char_t A = ((char_t)'A');
        static const char_t Z = ((char_t)'Z');
        static const char_t a = ((char_t)'a');
        if ((c >= A) && (c <= Z)) {
            c = a + (c - A);
        }
        return c;
    }
    static char_t to_upper(char_t c) {
        static const char_t A = ((char_t)'A');
        static const char_t a = ((char_t)'a');
        static const char_t z = ((char_t)'z');
        if ((c >= a) && (c <= z)) {
            c = A + (c - a);
        }
        return c;
    }
    static char_t to_case(char_t c) {
        return c;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    static char_t to_x(byte_t d, bool upper_case = false) {
        char a = (upper_case)?('A'):('a');
        char_t x = (char_t)(0);
        if ((0 <= d) && (9 >= d)) {
            x = (char_t)(('0') +  d);
        } else {
            if ((10 <= d) && (15 >= d)) {
                x = (char_t)((a) + (d - 10));
            }
        }
        return x;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};

} // namespace xos 

#endif // _XOS_BASE_CHARSBASE_HPP 
