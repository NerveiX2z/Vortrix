#pragma once

#include "Config/EngineConfig.hpp"

#include <atomic>
#include <cstdint>

namespace vortrix {

class Application {

public:

    explicit Application(const EngineConfig& config);

    virtual ~Application() = default;

    int Run();

    void RequestStop() noexcept;

    bool IsRunning() const noexcept;

protected:

    virtual bool OnInitialize();

    virtual void OnUpdate(float delta_time);

    virtual void OnShutdown();

private:

    bool Initialize();

    void Shutdown();

    EngineConfig m_config;

    std::atomic_bool m_running{false};

    bool m_initialized = false;

};

}
