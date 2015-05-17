cmake_minimum_required(VERSION 3.1)
project(bubble_sort_list)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp)
add_executable(bubble_sort_list ${SOURCE_FILES})