cmake_minimum_required(VERSION 3.20)
project(containers)

set(CMAKE_CXX_STANDARD 98)

include_directories(Vector)

add_executable(containers
        Vector/vector.hpp
        Utils/random_access_iterator.hpp
        Vector/main.cpp)
