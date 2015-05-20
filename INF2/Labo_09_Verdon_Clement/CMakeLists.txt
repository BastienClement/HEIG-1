cmake_minimum_required(VERSION 3.2)
project(Labo_09_Verdon_Clement)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES Labo_09_Verdon_Clement.cpp Labo_09_Verdon_Clement_Dictionnaire.cpp)
add_executable(Labo_09_Verdon_Clement ${SOURCE_FILES})
