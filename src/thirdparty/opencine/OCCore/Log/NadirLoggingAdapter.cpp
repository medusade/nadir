///////////////////////////////////////////////////////////////////////
///   File: NadirLoggingAdapter.cpp
///   Date: 2/27/2016
///////////////////////////////////////////////////////////////////////
#include "NadirLoggingAdapter.h"
#include "OCCore/Log/ILogger.h"
#include "xos/io/logger.hpp"

///////////////////////////////////////////////////////////////////////
/// TLogger to ::xos::io::logger
///////////////////////////////////////////////////////////////////////
template <class TLogger>
class LoggingAdapterT : virtual public TLogger {
public:
    LoggingAdapterT(): _logger(::xos::io::logger::get_default()) {}
    virtual void LogWarning(std::string message) {
        if ((_logger)) _logger->log
           (XOS_LOGGING_LEVELS_WARN,
            ::xos::io::logger::message() << message.c_str());
    }
    virtual void LogError(std::string message) {
        if ((_logger)) _logger->log
           (XOS_LOGGING_LEVELS_ERROR,
            ::xos::io::logger::message() << message.c_str());
    }
    virtual void LogInfo(std::string message) {
        if ((_logger)) _logger->log
           (XOS_LOGGING_LEVELS_INFO,
            ::xos::io::logger::message() << message.c_str());
    }
    virtual void LogFatal(std::string message) {
        if ((_logger)) _logger->log
           (XOS_LOGGING_LEVELS_FATAL,
            ::xos::io::logger::message() << message.c_str());
    }
protected:
    ::xos::io::logger* _logger;
};

namespace OC {
namespace Log {
namespace xos {
namespace io {

///////////////////////////////////////////////////////////////////////
/// ::xos::io::logger implementation Logger
///////////////////////////////////////////////////////////////////////
Logger::Logger() {
    loggerImplementation = new LoggingAdapterT<ILogger>();
}
Logger::~Logger() {
    if ((loggerImplementation)) {
        delete loggerImplementation;
    }
}
std::string Logger::FormatMessage
(Level level, std::string message, std::string file, int lineNumber) {
    static const char* level_name[Levels] = {
        OC_LOGGER_LEVEL_NAME_FATAL,
        OC_LOGGER_LEVEL_NAME_ERROR,
        OC_LOGGER_LEVEL_NAME_WARNING,
        OC_LOGGER_LEVEL_NAME_INFO
    };
    Message msg;
    if ((level >= FirstLevel) && (level <= LastLevel)) {
        msg << level_name[level - FirstLevel] << ": ";
    }
    return msg << file << "[" << lineNumber << "] " << message;
}
void Logger::LogWarning(std::string message) {
    if ((loggerImplementation))
        loggerImplementation->LogWarning(message);
}
void Logger::LogError(std::string message) {
    if ((loggerImplementation))
        loggerImplementation->LogError(message);
}
void Logger::LogInfo(std::string message) {
    if ((loggerImplementation))
        loggerImplementation->LogInfo(message);
}
void Logger::LogFatal(std::string message) {
    if ((loggerImplementation))
        loggerImplementation->LogFatal(message);
}

} // namespace io
} // namespace xos
} // namespace Log
} // namespace OC
