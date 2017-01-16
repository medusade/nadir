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
///   File: file_stream.hpp
///
/// Author: $author$
///   Date: 1/14/2017
///////////////////////////////////////////////////////////////////////
#ifndef _NADIR_IO_CRT_FILE_STREAM_HPP
#define _NADIR_IO_CRT_FILE_STREAM_HPP

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
typedef attachert<file_attached_t, int, 0, io::stream> file_attacher;
typedef attachedt<file_attached_t, int, 0, file_attacher, base> file_attached;
typedef file_attacher file_streamt_implements;
typedef file_attached file_streamt_extends;
///////////////////////////////////////////////////////////////////////
///  Class: file_streamt
///////////////////////////////////////////////////////////////////////
template
<class TImplements = file_streamt_implements,
 class TExtends = file_streamt_extends>

class _EXPORT_CLASS file_streamt
: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;

    typedef typename Extends::attached_t attached_t;
    typedef typename Extends::what_t what_t;
    typedef typename Extends::sized_t sized_t;
    enum { end = Extends::end };

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    file_streamt(attached_t detached): Extends(detached) {
    }
    virtual ~file_streamt() {
        if (!(this->detached())) {
            attach_exception e(detach_failed);
            throw (e);
        }
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t writefv(const char* format, va_list va) {
        FILE* detached = 0;
        if ((format) && (detached = this->attached_to())) {
            ssize_t count = 0;
            if (0 > (count = vfprintf(detached, format, va))) {
                LOG_ERROR("...failed errno = " << errno << " on vfprintf(detached, format, va)");
            }
            return count;
        }
        return 0;
    }
    virtual ssize_t write(const what_t* what, ssize_t size = -1) {
        FILE* detached = 0;
        if ((what) && (size) && (detached = this->attached_to())) {
            ssize_t count = 0, amount = 0;
            if (0 > (size)) {
                for (const sized_t* sized = ((const sized_t*)what); *sized != end; ++sized) {
                    if (1 != (amount = fwrite(sized, sizeof(sized_t), 1, detached))) {
                        LOG_ERROR("...failed errno = " << errno << " on fwrite(sized, sizeof(sized_t), 1, detached)");
                        return amount;
                    }
                    count += amount;
                }
            } else {
                if (size != (count = fwrite(what, sizeof(sized_t), size, detached))) {
                    LOG_ERROR("...failed errno = " << errno << " on fwrite(what, sizeof(sized_t), size, detached)");
                }
            }
            return count;
        }
        return 0;
    }
    virtual ssize_t flush() {
        FILE* detached = 0;
        if ((detached = this->attached_to())) {
            int err = 0;
            if ((err = fflush(detached))) {
                LOG_ERROR("...failed errno = " << errno << " on fflush(detached)");
                return -1;
            }
        }
        return 0;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t readfv(const char* format, va_list va) {
        FILE* detached = 0;
        if ((format) && (detached = this->attached_to())) {
            ssize_t count = 0;
            if (0 > (count = vfscanf(detached, format, va))) {
                LOG_ERROR("...failed errno = " << errno << " on vfscanf(detached, format, va)");
            }
            return count;
        }
        return 0;
    }
    virtual ssize_t read(what_t* what, size_t size) {
        FILE* detached = 0;
        if ((what) && (size) && (detached = this->attached_to())) {
            ssize_t count = 0;
            if (0 > (count = fread(what, sizeof(sized_t), size, detached))) {
                LOG_ERROR("...failed errno = " << errno << " on fread(what, sizeof(sized_t), size, detached)");
            }
            return count;
        }
        return 0;
    }
    virtual ssize_t fill() {
        return 0;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t seek(ssize_t offset, int whence) {
        FILE* detached = 0;
        if ((detached = this->attached_to())) {
            int err = 0;
            if (!(err = fseek(detached, offset, whence))) {
                ssize_t told = 0;
                if (0 <= (told = ftell(detached))) {
                    return told;
                } else {
                    LOG_ERROR("...failed errno = " << errno << " on ftell(detached)");
                }
            } else {
                LOG_ERROR("...failed errno = " << errno << " on fseek(detached, offset, whence)");
            }
        }
        return -1;
    }
    virtual ssize_t tell() {
        FILE* detached = 0;
        if ((detached = this->attached_to())) {
            ssize_t told = 0;
            if (0 <= (told = ftell(detached))) {
                return told;
            } else {
                LOG_ERROR("...failed errno = " << errno << " on ftell(detached)");
            }
        }
        return -1;
    }
    virtual ssize_t eof() {
        FILE* detached = 0;
        if ((detached = this->attached_to())) {
            int end = 0;
            if (0 <= (end = feof(detached))) {
                return end;
            } else {
                LOG_ERROR("...failed errno = " << errno << " on feof(detached)");
            }
        }
        return -1;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool set_mode_is_binary(bool mode_is_binary = true) {
        FILE* detached = 0;
        if ((detached = this->attached_to())) {
#if defined(WINDOWS)
            int fd = -1;
            if (0 <= (fd = _fileno(detached))) {
                int mode = (mode_is_binary)?(_O_BINARY):(_O_TEXT);
                int err = 0;
                if (!(err = _setmode(fd, mode))) {
                    return true;
                } else {
                    LOG_ERROR("...failed errno = " << errno << " on _setmode(fd = " << fd << ", mode = " << mode << ")");
                }
            }
#else // defined(WINDOWS)
            return mode_is_binary;
#endif // defined(WINDOWS)
        }
        return false;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};
typedef file_streamt<> file_stream;

} // namespace crt 
} // namespace io 
} // namespace nadir 

#endif // _NADIR_IO_CRT_FILE_STREAM_HPP 
