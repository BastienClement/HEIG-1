cmake_minimum_required(VERSION 3.1)
project(Labo_08_Peretti_Verdon)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp morsewav.cpp)
add_executable(Labo_08_Peretti_Verdon ${SOURCE_FILES} morse.h morse.h morse.cpp)
