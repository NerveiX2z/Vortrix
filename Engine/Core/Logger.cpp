#include "Logger.hpp"

#include <iostream>
#include <mutex>

namespace vortrix {

std::atomic_bool Logger::s_enabled{true};

namespace {

std::mutex g_log_mutex;

const char* GetLevelName(LogLevel level) {

    switch (level) {

        case LogLevel::Trace:
            return "TRACE";

        case LogLevel::Info:
            return "INFO";

        case LogLevel::Warning:
            return "WARNING";

        case LogLevel::Error:
            return "ERROR";

        case LogLevel::Critical:
            return "CRITICAL";

        default:
            return "UNKNOWN";
    }
}

}

void Logger::Initialize() {
    Info("Logger initialized.");
}

void Logger::SetEnabled(bool enabled) noexcept {
    s_enabled.store(enabled);
}

void Logger::Log(
    LogLevel level,
    std::string_view message
) {

    if (!s_enabled.load()) {
        return;
    }

    std::lock_guard<std::mutex> lock(g_log_mutex);

    std::clog
        << "[VORTRIX] "
        << "[" << GetLevelName(level) << "] "
        << message
        << '\n';
}

void Logger::Trace(std::string_view message) {
    Log(LogLevel::Trace, message);
}

void Logger::Info(std::string_view message) {
    Log(LogLevel::Info, message);
}

void Logger::Warning(std::string_view message) {
    Log(LogLevel::Warning, message);
}

void Logger::Error(std::string_view message) {
    Log(LogLevel::Error, message);
}

void Logger::Critical(std::string_view message) {
    Log(LogLevel::Critical, message);
}

}
