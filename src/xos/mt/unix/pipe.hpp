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
///   File: pipe.hpp
///
/// Author: $author$
///   Date: 2/1/2015
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_NADIR_XOS_MT_UNIX_PIPE_HPP
#define _XOS_NADIR_XOS_MT_UNIX_PIPE_HPP

#include "xos/io/writer.hpp"
#include "xos/io/reader.hpp"
#include "xos/base/created.hpp"
#include "xos/io/logger.hpp"

namespace xos {
namespace mt {
namespace unix {

typedef int pipe_fd_t;
typedef pipe_fd_t* pipe_attached_t;
typedef int pipe_unattached_t;
enum { pipe_unattached = 0 };

typedef base::attachert
<pipe_attached_t, pipe_unattached_t,
 pipe_unattached, base::implement_base> pipe_attacher;

typedef base::creatort
<pipe_attached_t, pipe_unattached_t,
 pipe_unattached, pipe_attacher> pipe_creator;

typedef base::attachedt
<pipe_attached_t, pipe_unattached_t,
 pipe_unattached,  pipe_creator, base::base> pipe_attached;

typedef base::createdt
<pipe_attached_t, pipe_unattached_t,
 pipe_unattached,  pipe_creator, pipe_attached> pipe_created;

typedef pipe_creator pipe_implements;
typedef pipe_created pipe_extends;
///////////////////////////////////////////////////////////////////////
///  Class: pipet
///////////////////////////////////////////////////////////////////////
template
<class TImplements = pipe_implements, class TExtends = pipe_extends>

class _EXPORT_CLASS pipet: virtual public TImplements,public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;

    typedef pipe_fd_t pipe_fd_t;

    typedef int end_t;
    enum { in = 0, out = 1, ends = 2 };

    typedef void what_t;
    typedef char sized_t;
    typedef int endof_t;
    enum { endof = 0 };

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    pipet(): invalid_fd_(-1) {
    }
    virtual ~pipet() {
        if (!(this->destroyed())) {
            base::creator_exception e = base::failed_to_destroy;
            XOS_LOG_ERROR("...throwing base::creator_exception e = " << e);
            throw (e);
        }
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool create() {
        if ((this->destroyed())) {
            int err = 0;
            if (!(err = ::pipe(ends_))) {
                this->attach_created(ends_);
                return true;
            } else {
                XOS_LOG_ERROR("failed " << errno << " on pipe(...)");
            }
        }
        return false;
    }
    virtual bool destroy() {
        pipe_attached_t detached;
        if ((detached = this->detach())) {
            bool success = true;
            pipe_fd_t fd;
            int err;
            for (end_t end = in; end < ends; ++end) {
                if (invalid_fd_ != (fd = detached[end])) {
                    if ((err = ::close(fd))) {
                        XOS_LOG_ERROR("failed " << errno << " on close(" << fd << ")");
                        success = false;
                    }
                }
            }
            return success;
        }
        return false;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t write(const what_t* what, ssize_t size = -1) {
        pipe_attached_t detached;
        if ((detached = this->attached_to())) {
            const sized_t* sized;
            if ((sized = ((const sized_t*)what))) {
                ssize_t amount;
                if (0 > (size)) {
                    const sized_t sized_endof = ((sized_t)endof);
                    ssize_t count;
                    for (count = 0; sized_endof != (*sized); ++sized, ++count) {
                        if (0 > (amount = ::write(detached[out], sized, sizeof(sized_t)))) {
                            return amount;
                        }
                    }
                    return count;
                } else {
                    if (0 > (amount = ::write(detached[out], what, size*sizeof(sized_t)))) {
                        return amount;
                    }
                    return size;
                }
            }
        }
        return 0;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool close(end_t end) {
        if ((end >= in) && (end <= out)) {
            pipe_attached_t detached;
            if ((detached = this->attached_to())) {
                pipe_fd_t fd;
                if (invalid_fd_ != (fd = detached[end])) {
                    int err;
                    detached[end] = invalid_fd_;
                    if ((err = ::close(fd))) {
                        XOS_LOG_ERROR("failed " << errno << " on close(" << fd << ")");
                    } else {
                        return true;
                    }
                }
            }
        }
        return false;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual pipe_fd_t& operator[](end_t end) const {
        if ((end >= in) && (end <= out)) {
            return ((pipe_fd_t&)ends_[end]);
        }
        return ((pipe_fd_t&)invalid_fd_);
    }
    virtual operator pipe_attached_t() const {
        return this->attached_to();
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    pipe_fd_t invalid_fd_;
    pipe_fd_t ends_[ends];
};
typedef pipet<> pipe;

} // namespace unix 
} // namespace mt 
} // namespace xos 

#endif // _XOS_NADIR_XOS_MT_UNIX_PIPE_HPP 
