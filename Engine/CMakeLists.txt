add_library(vortrix_core STATIC

    Core/Application.cpp
    Core/Logger.cpp

)

add_library(Vortrix::Core ALIAS vortrix_core)

target_include_directories(vortrix_core

    PUBLIC

        ${CMAKE_CURRENT_SOURCE_DIR}

)

target_compile_features(vortrix_core

    PUBLIC

        cxx_std_20

)

set_target_properties(vortrix_core PROPERTIES

    CXX_EXTENSIONS OFF

)

if(MSVC)

    target_compile_options(vortrix_core PRIVATE
        /W4
        /permissive-
    )

else()

    target_compile_options(vortrix_core PRIVATE
        -Wall
        -Wextra
        -Wpedantic
    )

endif()

message(STATUS "Vortrix Core module configured.")
