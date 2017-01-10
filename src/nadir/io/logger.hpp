///////////////////////////////////////////////////////////////////////
/// Copyright (c) 1988-2016 $organization$
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
///   File: logger.hpp
///
/// Author: $author$
///   Date: 12/30/2016
///////////////////////////////////////////////////////////////////////
#ifndef _NADIR_IO_LOGGER_HPP
#define _NADIR_IO_LOGGER_HPP

#include "nadir/base/string.hpp"
#include "nadir/base/locked.hpp"
#include <iostream>

namespace nadir {
namespace io {

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
typedef unsigned logger_level;
enum {
    logger_level_fatal_shift = 0,
    logger_level_error_shift,
    logger_level_warn_shift,
    logger_level_info_shift,
    logger_level_debug_shift,
    logger_level_trace_shift,

    next_logger_level_shift
};
enum {
    logger_level_none  = 0,

    logger_level_fatal = (1 << logger_level_fatal_shift),
    logger_level_error = (1 << logger_level_error_shift),
    logger_level_warn  = (1 << logger_level_warn_shift),
    logger_level_info  = (1 << logger_level_info_shift),
    logger_level_debug = (1 << logger_level_debug_shift),
    logger_level_trace = (1 << logger_level_trace_shift),

    next_logger_level  = (1 << next_logger_level_shift),
    all_logger_level   = (next_logger_level - 1)
};
enum {
    logger_levels_none  = 0,

    logger_levels_fatal = ((1 << (logger_level_fatal_shift + 1)) - 1),
    logger_levels_error = ((1 << (logger_level_error_shift + 1)) - 1),
    logger_levels_warn  = ((1 << (logger_level_warn_shift + 1)) - 1),
    logger_levels_info  = ((1 << (logger_level_info_shift + 1)) - 1),
    logger_levels_debug = ((1 << (logger_level_debug_shift + 1)) - 1),
    logger_levels_trace = ((1 << (logger_level_trace_shift + 1)) - 1),

    next_logger_levels  = ((1 << (next_logger_level_shift + 1)) - 1),
    all_logger_levels   = (next_logger_levels >> 1)
};

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS logger_location {
public:
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    logger_location
    (const char* function_name, const char* file_name, size_t line_number)
    : function_name_(function_name),
      file_name_(file_name),
      line_number_(line_number) {
    }
    logger_location
    (const logger_location& copy)
    : function_name_(copy.function_name_),
      file_name_(copy.file_name_),
      line_number_(copy.line_number_) {
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    inline char_string function_name() const { return function_name_; }
    inline char_string file_name() const { return file_name_; }
    inline char_string line_number() const {
        return char_string().assign_unsigned(line_number_);
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    char_string function_name_;
    char_string file_name_;
    size_t line_number_;
};

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS logger_message: public char_string {
public:
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    logger_message& operator << (const char_string& str){ append(str); return *this; }
    logger_message& operator << (const char* chars){ append(chars); return *this; }
    logger_message& operator << (int n) { append_signed(n); return *this; }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};

typedef locked logger_implements;
///////////////////////////////////////////////////////////////////////
///  Class: logger
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS logger: virtual public logger_implements {
public:
    typedef logger_implements Implements;

    typedef logger_level level;
    typedef logger_message message;
    typedef logger_location location;
    enum {
        level_none  = logger_level_none,
        level_fatal = logger_level_fatal,
        level_error = logger_level_error,
        level_warn  = logger_level_warn,
        level_info  = logger_level_info,
        level_debug = logger_level_debug,
        level_trace = logger_level_trace,
        all_level   = all_logger_level
    };
    enum {
        levels_none  = logger_levels_none,
        levels_fatal = logger_levels_fatal,
        levels_error = logger_levels_error,
        levels_warn  = logger_levels_warn,
        levels_info  = logger_levels_info,
        levels_debug = logger_levels_debug,
        levels_trace = logger_levels_trace,
        all_levels   = all_logger_levels
    };

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool lock() { return true; }
    virtual bool unlock() { return true; }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool init() { return true; }
    virtual bool fini() { return true; }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual void log
    (const level& _level, const location& _location, const message& _message) {
        locker lock(*this);
        if ((this->is_enabled_for(_level))) {
            this->log(_location);
            this->log(_message.chars());
            this->logln();
        }
    }
    virtual void logf
    (const level& _level, const location& _location, const char* format, ...) {
        locker lock(*this);
        if ((this->is_enabled_for(_level))) {
            this->log(_location);
            if ((format)) {
                va_list va;
                va_start(va, format);
                this->logfv(format, va);
                va_end(va);
            }
            this->logln();
        }
    }
    virtual void logfv
    (const level& _level, const location& _location, const char* format, va_list va) {
        locker lock(*this);
        if ((this->is_enabled_for(_level))) {
            this->log(_location);
            this->logln();
        }
    }
    virtual void logfv
    (const level& _level, const location& _location,
     const message& _message, const char* format, va_list va) {
        locker lock(*this);
        if ((this->is_enabled_for(_level))) {
            this->log(_location);
            if ((format)) {
                this->logfv(format, va);
            }
            this->logln();
        }
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual void log
    (const level& _level, const message& _message) {
        locker lock(*this);
        if ((this->is_enabled_for(_level))) {
            this->log(_message);
            this->logln();
        }
    }
    virtual void logf
    (const level& _level, const char* format, ...) {
        locker lock(*this);
        if ((this->is_enabled_for(_level))) {
            if ((format)) {
                va_list va;
                va_start(va, format);
                this->logfv(format, va);
                va_end(va);
            }
            this->logln();
        }
    }
    virtual void logfv
    (const level& _level, const char* format, va_list va) {
        locker lock(*this);
        if ((this->is_enabled_for(_level))) {
            if ((format)) {
                this->logfv(format, va);
            }
            this->logln();
        }
    }
    virtual void logfv
    (const level& _level, const message& _message, const char* format, va_list va) {
        locker lock(*this);
        if ((this->is_enabled_for(_level))) {
            this->log(_message);
            if ((format)) {
                this->logfv(format, va);
            }
            this->logln();
        }
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual void enable_for(const level& _level) {}
    virtual level enabled_for() const { return enabled_for_default(); }
    virtual level enabled_for_default() const {
#if defined(DEBUG_BUILD)
        return levels_debug;
#else // defined(DEBUG_BUILD)
        return levels_error;
#endif // defined(DEBUG_BUILD)
    }
    virtual bool is_enabled_for(const level& _level) const {
        if ((_level) && (_level == (enabled_for() & _level))) {
            return true;
        }
        return false;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    static logger* set_the_logger(logger* to) {
        logger *old_logger = the_logger();
        the_logger() = to;
        return old_logger;
    }
    static logger* get_the_logger() {
        return the_logger();
    }
protected:
    static logger*& the_logger() {
        static logger *the_logger = 0;
        return the_logger;
    }

protected:
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual void logfv(const char* format, va_list va) {
    }
    virtual void log(const location& _location) {
        log(_location.file_name().chars());
        log("[");
        log(_location.line_number().chars());
        log("]");
        log(" ");
        log(_location.function_name().chars());
        log(" ");
    }
    virtual void log(const message& _message) {
        log(_message.chars());
    }
    virtual void log(const char* chars) {
    }
    virtual void logln() {
        log("\n");
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};

typedef logger logger_instance_implements;
typedef base logger_instance_extends;
///////////////////////////////////////////////////////////////////////
///  Class: logger_instance
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS logger_instance
: virtual public logger_instance_implements, public logger_instance_extends {
public:
    typedef logger_instance_implements Implements;
    typedef logger_instance_extends Extends;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    logger_instance(): old_logger_(the_logger()) {
        the_logger() = this;
    }
    virtual ~logger_instance() {
        if (this == the_logger()) {
            the_logger() = old_logger_;
        }
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    logger* old_logger_;
};

} // namespace io
} // namespace nadir 

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////

#if !defined(LOGGER_LOCATION)
#if !defined(__LOGGER_FUNC__)
#if defined(__GNUC__)
#define __LOGGER_FUNC__ __FUNCTION__
#else // defined(__GNUC__)
#if defined(_MSC_VER)
#if (_MSC_VER >= 1300)
#define __LOGGER_FUNC__ __FUNCTION__
#else // (_MSC_VER >= 1300)
#define __LOGGER_FUNC__ ""
#endif // (_MSC_VER >= 1300)
#else // defined(_MSC_VER)
#define __LOGGER_FUNC__ ""
#endif // defined(_MSC_VER)
#endif // defined(__GNUC__)
#endif // !defined(__LOGGER_FUNC__)
#define LOGGER_LOCATION ::nadir::io::logger::location(__LOGGER_FUNC__, __FILE__, __LINE__)
#endif // !defined(LOGGER_LOCATION)

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////

#define INIT_LOGGER(logger_) { \
::nadir::io::logger* logger = logger_; \
if ((logger)) { logger->init(); } }

#define FINI_LOGGER(logger_) { \
::nadir::io::logger* logger = logger_; \
if ((logger)) { logger->fini(); } }

#define SET_LOGGER_LEVEL(logger_, level_) { \
::nadir::io::logger* logger = logger_; \
if ((logger)) { logger->enable_for(level_); } }

#define GET_LOGGER_LEVEL(logger_) \
((logger_)?(logger_->enabled_for()):(::nadir::io::logger::level\
(::nadir::io::logger::levels_none)))

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
#define LOGGER_LOG(logger_, level_, message_) { \
::nadir::io::logger* logger = logger_; \
if ((logger)?(logger->is_enabled_for(level_)):(false)) {\
   ::nadir::io::logger::message message; \
   logger->log(level_, LOGGER_LOCATION, message << message_); } }

#define LOGGER_LOGF(logger_, level_, format_, ...) { \
::nadir::io::logger* logger = logger_; \
if ((logger)?(logger->is_enabled_for(level_)):(false)) {\
   logger->logf(level_, LOGGER_LOCATION, format_, ##__VA_ARGS__); } }

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
#define SET_THE_LOGGER(_logger) ::nadir::io::logger::set_the_logger(_logger)
#define THE_LOGGER ::nadir::io::logger::get_the_logger()

#define LOGGER_INIT() INIT_LOGGER(THE_LOGGER)
#define LOGGER_FINI() FINI_LOGGER(THE_LOGGER)

#define SET_LOGGING_LEVEL(level)  SET_LOGGER_LEVEL(THE_LOGGER, level)
#define GET_LOGGING_LEVEL(level)  (level = GET_LOGGER_LEVEL(THE_LOGGER))

#define LOGGING_LEVELS_ALL ::nadir::io::logger::levels_all
#define LOGGING_LEVELS_NONE ::nadir::io::logger::levels_none
#define LOGGING_LEVELS_FATAL ::nadir::io::logger::levels_fatal
#define LOGGING_LEVELS_ERROR ::nadir::io::logger::levels_error
#define LOGGING_LEVELS_WARN ::nadir::io::logger::levels_warn
#define LOGGING_LEVELS_INFO ::nadir::io::logger::levels_info
#define LOGGING_LEVELS_DEBUG ::nadir::io::logger::levels_debug
#define LOGGING_LEVELS_TRACE ::nadir::io::logger::levels_trace

#define LOG_FATAL(message) LOGGER_LOG(THE_LOGGER, ::nadir::io::logger::level_fatal, message)
#define LOG_ERROR(message) LOGGER_LOG(THE_LOGGER, ::nadir::io::logger::level_error, message)
#define LOG_WARN(message) LOGGER_LOG(THE_LOGGER, ::nadir::io::logger::level_warn, message)
#define LOG_INFO(message) LOGGER_LOG(THE_LOGGER, ::nadir::io::logger::level_info, message)
#define LOG_DEBUG(message) LOGGER_LOG(THE_LOGGER, ::nadir::io::logger::level_debug, message)
#define LOG_TRACE(message) LOGGER_LOG(THE_LOGGER, ::nadir::io::logger::level_trace, message)

#define LOG_FATALF(message, ...) LOGGER_LOGF(THE_LOGGER, ::nadir::io::logger::level_fatal, message, ##__VA_ARGS__)
#define LOG_ERRORF(message, ...) LOGGER_LOGF(THE_LOGGER, ::nadir::io::logger::level_error, message, ##__VA_ARGS__)
#define LOG_WARNF(message, ...) LOGGER_LOGF(THE_LOGGER, ::nadir::io::logger::level_warn, message, ##__VA_ARGS__)
#define LOG_INFOF(message, ...) LOGGER_LOGF(THE_LOGGER, ::nadir::io::logger::level_info, message, ##__VA_ARGS__)
#define LOG_DEBUGF(message, ...) LOGGER_LOGF(THE_LOGGER, ::nadir::io::logger::level_debug, message, ##__VA_ARGS__)
#define LOG_TRACEF(message, ...) LOGGER_LOGF(THE_LOGGER, ::nadir::io::logger::level_trace, message, ##__VA_ARGS__)

#define IS_LOGGING_FATAL(message) if (this->is_logging()) LOG_FATAL(message)
#define IS_LOGGING_ERROR(message) if (this->is_logging()) LOG_ERROR(message)
#define IS_LOGGING_WARN(message)  if (this->is_logging()) LOG_WARN(message)
#define IS_LOGGING_INFO(message)  if (this->is_logging()) LOG_INFO(message)
#define IS_LOGGING_DEBUG(message) if (this->is_logging()) LOG_DEBUG(message)
#define IS_LOGGING_TRACE(message) if (this->is_logging()) LOG_TRACE(message)

#define IS_LOGGING_FATALF(message, ...) if (this->is_logging()) LOG_FATAL(message, ##__VA_ARGS__)
#define IS_LOGGING_ERRORF(message, ...) if (this->is_logging()) LOG_ERROR(message, ##__VA_ARGS__)
#define IS_LOGGING_WARNF(message, ...)  if (this->is_logging()) LOG_WARN(message, ##__VA_ARGS__)
#define IS_LOGGING_INFOF(message, ...)  if (this->is_logging()) LOG_INFO(message, ##__VA_ARGS__)
#define IS_LOGGING_DEBUGF(message, ...) if (this->is_logging()) LOG_DEBUG(message, ##__VA_ARGS__)
#define IS_LOGGING_TRACEF(message, ...) if (this->is_logging()) LOG_TRACE(message, ##__VA_ARGS__)

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
#if !defined(STDERR_LOG)
#define STDERR_LOG(__message__) \
    std::cerr << __FILE__ << "[" << __LINE__ << "] " << __FUNCTION__ << " " << __message__ << "\n"
#endif // !defined(STDERR_LOG)

#if !defined(STDERR_LOG_DEBUG)
#if defined(DEBUG_BUILD)
#define STDERR_LOG_DEBUG(__message__) STDERR_LOG(__message__)
#else // defined(DEBUG_BUILD)
#define STDERR_LOG_DEBUG(__message__)
#endif // defined(DEBUG_BUILD)
#endif // !defined(STDERR_LOG_DEBUG)

#if !defined(STDERR_LOG_ERROR)
#define STDERR_LOG_ERROR(__message__) STDERR_LOG(__message__)
#endif // !defined(STDERR_LOG_ERROR)

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
#if !defined(LOG_DEBUG)
#define LOG_DEBUG(__message__) STDERR_LOG_DEBUG(__message__)
#endif // !defined(LOG_DEBUG)

#if !defined(LOG_ERROR)
#define LOG_ERROR(__message__) STDERR_LOG_ERROR(__message__)
#endif // !defined(LOG_ERROR)

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////

#endif // _NADIR_IO_LOGGER_HPP
