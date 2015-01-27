///////////////////////////////////////////////////////////////////////
/// Copyright (c) 1988-2015 $organization$
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
///   File: cplatform.hpp
///
/// Author: $author$
///   Date: 1/22/2015
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_NADIR_THIRDPARTY_XDE_CLIB_COS_CPLATFORM_HPP
#define _XOS_NADIR_THIRDPARTY_XDE_CLIB_COS_CPLATFORM_HPP

#include "cplatform.h"
#include "cwriter.hxx"

#if !defined(DB_GET_WRITER)
#define DB_GET_WRITER() db_get_writer()
#endif // !defined(DB_GET_WRITER)

#if !defined(DB_SET_WRITER)
#define DB_SET_WRITER(writer) db_set_writer(writer)
#endif // !defined(DB_SET_WRITER)

///////////////////////////////////////////////////////////////////////
///  Class: cFormattedWriter
///////////////////////////////////////////////////////////////////////
class c_INTERFACE_CLASS cFormattedWriter: public cCharWriter {
public:
    typedef cCharWriter cExtends;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    cFormattedWriter() {
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual tLength WriteFormattedV(const tWhat* format, va_list va) {
        tLength length = 0;
        return length;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};

cFormattedWriter* db_get_writer();
cFormattedWriter* db_set_writer(cFormattedWriter* writer);

#endif // _XOS_NADIR_THIRDPARTY_XDE_CLIB_COS_CPLATFORM_HPP
