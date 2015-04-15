cmake_minimum_required(VERSION 3.1)
project(Labo_05_bastien)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp Calculator.cpp Stack.cpp)
add_executable(calc ${SOURCE_FILES})