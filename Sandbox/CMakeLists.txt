add_executable(vortrix_sandbox

    main.cpp

)

target_link_libraries(vortrix_sandbox

    PRIVATE

        Vortrix::Core

)

target_compile_features(vortrix_sandbox

    PRIVATE

        cxx_std_20

)
