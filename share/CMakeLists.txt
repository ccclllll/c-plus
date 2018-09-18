# cmake_minimum_required(VERSION <specify CMake version here>)
project(share)

set(CMAKE_CXX_STANDARD 14)

add_executable(share main.cpp MyUtils.cpp MyUtils.h share.cpp share.h industry.cpp industry.h)