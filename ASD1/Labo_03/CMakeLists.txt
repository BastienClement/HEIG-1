cmake_minimum_required(VERSION 3.1)
project(Labo_03)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall -O3")

set(SOURCE_FILES labo3.cpp)
add_executable(Labo_03 ${SOURCE_FILES})
