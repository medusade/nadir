///////////////////////////////////////////////////////////////////////
///   File: NadirLoggingAdapter.cpp
///   Date: 2/27/2016
///////////////////////////////////////////////////////////////////////
#include "NadirLoggingAdapter.h"
#include "OCCore/Log/ILogger.h"

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
    Message msg;
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
