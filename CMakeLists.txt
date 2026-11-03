cmake_minimum_required(VERSION 3.24)

project(Vortrix
    VERSION 0.1.0
    DESCRIPTION "Vortrix Proprietary 3D Game Engine"
    LANGUAGES CXX
)

# ==========================================
# C++ CONFIGURATION
# ==========================================

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# ==========================================
# BUILD OPTIONS
# ==========================================

option(VORTRIX_BUILD_SANDBOX
    "Build Vortrix Sandbox"
    ON
)

option(VORTRIX_BUILD_TESTS
    "Build Vortrix Tests"
    OFF
)

option(VORTRIX_ENABLE_LOGGING
    "Enable Engine Logging"
    ON
)

# ==========================================
# RENDERER CONFIGURATION
# ==========================================

set(VORTRIX_RENDERER "VULKAN"
    CACHE STRING "Graphics Backend"
)

set_property(CACHE VORTRIX_RENDERER
    PROPERTY STRINGS VULKAN OPENGLES
)

if(NOT VORTRIX_RENDERER STREQUAL "VULKAN"
   AND NOT VORTRIX_RENDERER STREQUAL "OPENGLES")
    message(FATAL_ERROR "Unsupported Vortrix renderer")
endif()

# ==========================================
# PLATFORM DETECTION
# ==========================================

if(ANDROID)
    set(VORTRIX_PLATFORM "ANDROID")
elseif(WIN32)
    set(VORTRIX_PLATFORM "WINDOWS")
elseif(APPLE)
    set(VORTRIX_PLATFORM "APPLE")
elseif(UNIX)
    set(VORTRIX_PLATFORM "LINUX")
else()
    message(FATAL_ERROR "Unsupported platform")
endif()

message(STATUS "================================")
message(STATUS "       VORTRIX ENGINE")
message(STATUS "================================")
message(STATUS "Version: ${PROJECT_VERSION}")
message(STATUS "Platform: ${VORTRIX_PLATFORM}")
message(STATUS "Renderer: ${VORTRIX_RENDERER}")
message(STATUS "C++ Standard: C++20")
message(STATUS "================================")

# ==========================================
# ENGINE MODULES
# ==========================================

add_subdirectory(Engine)

# ==========================================
# SANDBOX
# ==========================================

if(VORTRIX_BUILD_SANDBOX)
    add_subdirectory(Sandbox)
endif()

# ==========================================
# TESTING
# ==========================================

if(VORTRIX_BUILD_TESTS)
    enable_testing()
endif()
