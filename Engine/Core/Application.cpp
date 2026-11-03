#include "Application.hpp"
#include "Logger.hpp"

#include <chrono>
#include <thread>

namespace vortrix {

Application::Application(const EngineConfig& config)
    : m_config(config) {
}

bool Application::Initialize() {

    if (m_initialized) {
        return true;
    }

    Logger::SetEnabled(m_config.enable_logging);

    Logger::Initialize();

    Logger::Info("Initializing Vortrix Engine...");

    if (!OnInitialize()) {

        Logger::Critical(
            "Application initialization failed."
        );

        return false;
    }

    m_initialized = true;

    Logger::Info("Vortrix Engine initialized.");

    return true;
}

int Application::Run() {

    if (!Initialize()) {
        return 1;
    }

    using Clock = std::chrono::steady_clock;

    using Seconds = std::chrono::duration<float>;

    const auto frame_duration =
        m_config.target_fps > 0
        ? std::chrono::duration_cast<Clock::duration>(
            Seconds(1.0f /
                static_cast<float>(m_config.target_fps))
          )
        : Clock::duration::zero();

    auto previous_time = Clock::now();

    m_running.store(true);

    Logger::Info("Starting application loop.");

    while (m_running.load()) {

        const auto frame_start = Clock::now();

        const float delta_time =
            Seconds(frame_start - previous_time).count();

        previous_time = frame_start;

        OnUpdate(delta_time);

        if (frame_duration > Clock::duration::zero()) {

            const auto next_frame =
                frame_start + frame_duration;

            std::this_thread::sleep_until(next_frame);
        }
    }

    Shutdown();

    return 0;
}

void Application::Shutdown() {

    if (!m_initialized) {
        return;
    }

    Logger::Info("Shutting down Vortrix...");

    OnShutdown();

    m_initialized = false;

    Logger::Info("Vortrix Engine stopped.");
}

void Application::RequestStop() noexcept {

    m_running.store(false);
}

bool Application::IsRunning() const noexcept {

    return m_running.load();
}

bool Application::OnInitialize() {

    return true;
}

void Application::OnUpdate(float delta_time) {

    (void)delta_time;
}

void Application::OnShutdown() {

}

}
