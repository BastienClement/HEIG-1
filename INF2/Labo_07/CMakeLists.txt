cmake_minimum_required(VERSION 3.1)
project(Labo_07)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall")

set(SOURCE_FILES main.cpp carnet.cpp personne.cpp)
add_executable(Labo_07 ${SOURCE_FILES})
