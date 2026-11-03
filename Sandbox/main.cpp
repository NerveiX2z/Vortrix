#include <Core/Application.hpp>
#include <Core/Logger.hpp>

#include <iostream>

class VortrixSandbox final : public vortrix::Application {

public:

    explicit VortrixSandbox(
        const vortrix::EngineConfig& config
    )
        : Application(config) {
    }

protected:

    bool OnInitialize() override {

        vortrix::Logger::Info(
            "Vortrix Sandbox initialized."
        );

        return true;
    }

    void OnUpdate(float delta_time) override {

        ++m_frame_count;

        vortrix::Logger::Info(
            "Running frame: " +
            std::to_string(m_frame_count)
        );

        if (m_frame_count >= 5) {

            vortrix::Logger::Info(
                "Sandbox test completed."
            );

            RequestStop();
        }

        (void)delta_time;
    }

    void OnShutdown() override {

        vortrix::Logger::Info(
            "Sandbox shutdown complete."
        );
    }

private:

    std::uint32_t m_frame_count = 0;

};

int main() {

    vortrix::EngineConfig config;

    config.application_name = "Vortrix Sandbox";

    config.target_fps = 60;

    config.enable_logging = true;

    VortrixSandbox application(config);

    return application.Run();
}
