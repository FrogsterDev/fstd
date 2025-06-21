cmake_minimum_required(VERSION 3.16)
project(FSTD)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# --- Library ---
add_subdirectory(src)

# --- Tests ---
option(FSTD_BUILD_TESTS "Build tests" ON)
if(FSTD_BUILD_TESTS)
    enable_testing()

    # --- GoogleTest ---
    include(FetchContent)
    FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/refs/tags/v1.14.0.zip
    )
    # For Windows: Prevent overriding the parent project's compiler/linker settings
    set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
    FetchContent_MakeAvailable(googletest)

    add_subdirectory(tests)
endif()
