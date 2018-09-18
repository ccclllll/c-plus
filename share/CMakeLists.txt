# cmake_minimum_required(VERSION <specify CMake version here>)
project(share)

set(CMAKE_CXX_STANDARD 14)

add_executable(share main.cpp utils/MyUtils.cpp utils/MyUtils.h domain/share.cpp domain/share.h domain/industry.cpp domain/industry.h service/QueryService.cpp service/QueryService.h service/MapService.cpp service/MapService.h)