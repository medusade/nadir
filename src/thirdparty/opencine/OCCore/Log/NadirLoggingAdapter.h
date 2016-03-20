///////////////////////////////////////////////////////////////////////
///   File: NadirLoggingAdapter.h
///   Date: 2/27/2016
///////////////////////////////////////////////////////////////////////
#ifndef _OPENCINE_OCCORE_LOG_NADIRLOGGINGADAPTER_H
#define _OPENCINE_OCCORE_LOG_NADIRLOGGINGADAPTER_H

#include "xos/io/logger.hpp"
#include <string>
#include <sstream>

#if !defined(OC_EXPORT)
#define OC_EXPORT
#endif // !defined(OC_EXPORT)

///
/// Map these per platform and build conditions
///
#if !defined(OC_LOGGER__)
#define OC_LOGGER__FILE__ __FILE__
#define OC_LOGGER__LINE__ __LINE__
#define OC_LOGGER__FUNCTION__ __PRETTY_FUNCTION__
#endif // !defined(OC_LOGGER__)

///
/// Level ids
///
#if !defined(OC_LOGGER_LEVEL_ID_)
#define OC_LOGGER_LEVEL_ID_INFO LogInfo
#define OC_LOGGER_LEVEL_ID_WARNING LogWarning
#define OC_LOGGER_LEVEL_ID_ERROR LogError
#define OC_LOGGER_LEVEL_ID_FATAL LogFatal
#endif // !defined(OC_LOGGER_LEVEL_ID_)

///
/// Level names
///
#if !defined(OC_LOGGER_LEVEL_NAME_)
#define OC_LOGGER_LEVEL_NAME_INFO "INFO"
#define OC_LOGGER_LEVEL_NAME_WARNING "WARNING"
#define OC_LOGGER_LEVEL_NAME_ERROR "ERROR"
#define OC_LOGGER_LEVEL_NAME_FATAL "FATAL"
#endif // !defined(OC_LOGGER_LEVEL_NAME_)

///
/// Note this macro expands to one line so the __LINE__ is where it is calld
///
#if !defined(OC_LOG)
#define OC_LOG(__level_id__, __level_name__, __message__) { \
    Message msg; msg << __level_name__ << " " << OC_LOGGER__FILE__ << "[" << OC_LOGGER__LINE__ << "]" \
    " " << OC_LOGGER__FUNCTION__ << " " << __message__; \
    __level_id__(msg); }
#endif // !defined(OC_LOG)

///
/// Shortcuts for different levels
///
#if !defined(OC_LOG_)
#define OC_LOG_INFO(__message__) OC_LOG(OC_LOGGER_LEVEL_ID_INFO, OC_LOGGER_LEVEL_NAME_INFO, __message__)
#define OC_LOG_WARNING(__message__) OC_LOG(OC_LOGGER_LEVEL_ID_WARNING, OC_LOGGER_LEVEL_NAME_WARNING, __message__)
#define OC_LOG_ERROR(__message__) OC_LOG(OC_LOGGER_LEVEL_ID_ERROR, OC_LOGGER_LEVEL_NAME_ERROR, __message__)
#define OC_LOG_FATAL(__message__) OC_LOG(OC_LOGGER_LEVEL_ID_FATAL, OC_LOGGER_LEVEL_NAME_FATAL, __message__)
#endif // !defined(OC_LOG_)

namespace OC {
namespace Log {
namespace xos {
namespace io {

class OC_EXPORT ILogger {
public:
    virtual void LogWarning(std::string message) = 0;
    virtual void LogError(std::string message) = 0;
    virtual void LogInfo(std::string message) = 0;
    virtual void LogFatal(std::string message) = 0;
};

class OC_EXPORT Logger : virtual public ILogger {
public:
    Logger();
    virtual ~Logger();

    virtual void LogWarning(std::string message);
    virtual void LogError(std::string message);
    virtual void LogInfo(std::string message);
    virtual void LogFatal(std::string message);

protected:
    enum Level {
        LevelNone,
        LevelFatal,
        LevelError,
        LevelWarning,
        LevelInfo,

        FirstLevel = LevelFatal,
        LastLevel =  LevelInfo,
        Levels = LastLevel - FirstLevel + 1
    };
    std::string FormatMessage
    (Level level, std::string message, std::string file, int lineNumber);

protected:
    class Message: public std::string {
    public:
        Message& operator << (Message message) {
            this->append(message);
            return *this;
        }
        Message& operator << (std::string message) {
            this->append(message);
            return *this;
        }
        Message& operator << (int message) {
            std::stringstream ss;
            ss << message;
            this->append(ss.str());
            return *this;
        }
    };

protected:
    ILogger* loggerImplementation;
};

///////////////////////////////////////////////////////////////////////
/// TLogger to ::xos::io::logger
///////////////////////////////////////////////////////////////////////
template <class TLogger>
class LoggingAdapterT : virtual public TLogger {
public:
    LoggingAdapterT(): _logger(::xos::io::logger::get_default()) {}
    virtual void LogWarning(std::string message) {
        if ((_logger)) _logger->log
           (XOS_LOGGING_LEVELS_WARN, ::xos::io::logger::message()
            << OC_LOGGER_LEVEL_NAME_WARNING << ": " << message.c_str());
    }
    virtual void LogError(std::string message) {
        if ((_logger)) _logger->log
           (XOS_LOGGING_LEVELS_ERROR, ::xos::io::logger::message()
            << OC_LOGGER_LEVEL_NAME_ERROR << ": " << message.c_str());
    }
    virtual void LogInfo(std::string message) {
        if ((_logger)) _logger->log
           (XOS_LOGGING_LEVELS_INFO, ::xos::io::logger::message()
            << OC_LOGGER_LEVEL_NAME_INFO << ": " << message.c_str());
    }
    virtual void LogFatal(std::string message) {
        if ((_logger)) _logger->log
           (XOS_LOGGING_LEVELS_FATAL, ::xos::io::logger::message()
            << OC_LOGGER_LEVEL_NAME_FATAL << ": " << message.c_str());
    }
protected:
    ::xos::io::logger* _logger;
};

} // namespace io
} // namespace xos
} // namespace Log
} // namespace OC

#endif // _OPENCINE_OCCORE_LOG_NADIRLOGGINGADAPTER_H
