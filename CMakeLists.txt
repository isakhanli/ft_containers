cmake_minimum_required(VERSION 3.20)
project(containers)

set(CMAKE_CXX_STANDARD 11)

include_directories(Vector)

add_executable(containers
       Map/test2.cpp
    )
