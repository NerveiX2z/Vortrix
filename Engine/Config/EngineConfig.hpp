#pragma once

#include <cstdint>
#include <string>

namespace vortrix {

struct EngineConfig {

    std::string application_name =
        "Vortrix Engine";

    std::uint32_t target_fps = 60;

    bool enable_logging = true;

};

}
