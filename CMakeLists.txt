cmake_minimum_required(VERSION 3.23)

project(mini-lib CXX)

set(CMAKE_CXX_STANDARD 26)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories("${CMAKE_SOURCE_DIR}/include")

add_library(mini-lib STATIC
    src/threadpool.cpp
    src/argumentparser.cpp
)
target_include_directories(mini-lib PUBLIC
    "${CMAKE_SOURCE_DIR}/include"
)

# Enable testing
option(BUILD_TESTING "Build test routines" ON)
if(BUILD_TESTING)
    message("Building mini-lib with tests!")

    # Ensure Catch2 is available
    Include(FetchContent)
    FetchContent_Declare(
        Catch2
        GIT_REPOSITORY https://github.com/catchorg/Catch2.git
        GIT_TAG        v3.8.1 # or a later release
    )
    FetchContent_MakeAvailable(Catch2)

    # Build tests
    enable_testing()
    add_subdirectory(tests)
endif()

# To use clangd as LSP
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
