cmake_minimum_required(VERSION 3.16)
project(FSTD CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(fstd main.cpp)
target_include_directories(fstd PRIVATE base)
