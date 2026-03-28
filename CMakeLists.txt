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

add_subdirectory(tests)
