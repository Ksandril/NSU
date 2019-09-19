cmake_minimum_required(VERSION 3.14)
project(c_buff)

set(CMAKE_CXX_STANDARD 17)

add_executable(c_buff main.cpp circular_buffer.h tests/tests.cpp)