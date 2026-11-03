#pragma once

#if defined(__ANDROID__)

    #define VORTRIX_PLATFORM_ANDROID 1

#elif defined(_WIN32)

    #define VORTRIX_PLATFORM_WINDOWS 1

#elif defined(__APPLE__)

    #include <TargetConditionals.h>

    #if TARGET_OS_IPHONE

        #define VORTRIX_PLATFORM_IOS 1

    #else

        #define VORTRIX_PLATFORM_MACOS 1

    #endif

#elif defined(__linux__)

    #define VORTRIX_PLATFORM_LINUX 1

#else

    #error "Unsupported Vortrix platform"

#endif

namespace vortrix {

enum class Platform {

    Android,
    IOS,
    MacOS,
    Windows,
    Linux

};

#if defined(VORTRIX_PLATFORM_ANDROID)

inline constexpr Platform CurrentPlatform =
    Platform::Android;

#elif defined(VORTRIX_PLATFORM_IOS)

inline constexpr Platform CurrentPlatform =
    Platform::IOS;

#elif defined(VORTRIX_PLATFORM_MACOS)

inline constexpr Platform CurrentPlatform =
    Platform::MacOS;

#elif defined(VORTRIX_PLATFORM_WINDOWS)

inline constexpr Platform CurrentPlatform =
    Platform::Windows;

#elif defined(VORTRIX_PLATFORM_LINUX)

inline constexpr Platform CurrentPlatform =
    Platform::Linux;

#endif

}
