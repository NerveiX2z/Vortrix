#pragma once

#include <atomic>
#include <string_view>

namespace vortrix {

enum class LogLevel {
    Trace,
    Info,
    Warning,
    Error,
    Critical
};

class Logger {
public:

    static void Initialize();

    static void SetEnabled(bool enabled) noexcept;

    static void Log(
        LogLevel level,
        std::string_view message
    );

    static void Trace(std::string_view message);
    static void Info(std::string_view message);
    static void Warning(std::string_view message);
    static void Error(std::string_view message);
    static void Critical(std::string_view message);

private:

    static std::atomic_bool s_enabled;
};

}
