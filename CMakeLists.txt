cmake_minimum_required(VERSION 3.26)
project(trabalhoED1)

set(CMAKE_CXX_STANDARD 14)

include_directories(includes)

add_executable(trabalhoED1
        includes/func.cpp
        includes/func.h
        main.cpp)
