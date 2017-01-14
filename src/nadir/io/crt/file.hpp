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
///   File: file.hpp
///
/// Author: $author$
///   Date: 1/13/2017
///////////////////////////////////////////////////////////////////////
#ifndef _NADIR_IO_CRT_FILE_HPP
#define _NADIR_IO_CRT_FILE_HPP

#include "nadir/io/stream.hpp"
#include "nadir/base/opened.hpp"
#include "nadir/io/logger.hpp"

#define NADIR_IO_CRT_FILE_MODE_READ "r"
#define NADIR_IO_CRT_FILE_MODE_WRITE "w"

#define NADIR_IO_CRT_FILE_MODE_BINARY "b"
#define NADIR_IO_CRT_FILE_MODE_APPEND "+"

#define NADIR_IO_CRT_FILE_MODE_READ_BINARY \
    NADIR_IO_CRT_FILE_MODE_READ \
    NADIR_IO_CRT_FILE_MODE_BINARY

#define NADIR_IO_CRT_FILE_MODE_WRITE_BINARY \
    NADIR_IO_CRT_FILE_MODE_WRITE \
    NADIR_IO_CRT_FILE_MODE_BINARY

namespace nadir {
namespace io {
namespace crt {

typedef FILE* file_attached_t;
typedef openert<io::stream> file_opener;
typedef attachert<file_attached_t, int, 0, file_opener> file_attacher;
typedef attachedt<file_attached_t, int, 0, file_attacher, base> file_attached;
typedef openedt<file_attached_t, int, 0, file_attacher, file_attached> file_opened;
typedef file_attacher filet_implements;
typedef file_opened filet_extends;
///////////////////////////////////////////////////////////////////////
///  Class: filet
///////////////////////////////////////////////////////////////////////
template
<class TImplements = filet_implements, class TExtends = filet_extends>
class _EXPORT_CLASS filet: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;
    typedef typename Extends::attached_t attached_t;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    filet(attached_t detached, bool is_open = false)
    : Extends(detached, is_open) {
    }
    virtual ~filet() {
        if (!(this->closed())) {
            open_exception e(close_failed);
            throw (e);
        }
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};
typedef filet<> file;

} // namespace crt
} // namespace io 
} // namespace nadir 

#endif // _NADIR_IO_CRT_FILE_HPP 
