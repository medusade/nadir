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
///   File: cplatform.cpp
///
/// Author: $author$
///   Date: 1/22/2015
///////////////////////////////////////////////////////////////////////
#include "cplatform.hpp"

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
static cFormattedWriter*& db_writer() {
    static cFormattedWriter* writer = 0;
    return writer;
}
cFormattedWriter* db_get_writer() {
    return db_writer();
}
cFormattedWriter* db_set_writer(cFormattedWriter* writer) {
    return db_writer() = writer;
}

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
int platform_db_printf(const char* format, ...) {
    int count = 0;
    va_list va;
    va_start(va, format);
    count = platform_db_vprintf(format, va);
    va_end(va);
    return count;
}
int platform_db_vprintf(const char* format, va_list va) {
    int count = 0;
    cFormattedWriter* writer;
    if ((writer = db_get_writer())) {
        count = writer->WriteFormattedV(format, va);
    }
    return count;
}
