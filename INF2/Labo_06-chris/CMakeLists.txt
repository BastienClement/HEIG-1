cmake_minimum_required(VERSION 3.1)
project(Labo5)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES Labo_06_CotzaPeretti.cpp)
add_executable(Labo5 ${SOURCE_FILES})