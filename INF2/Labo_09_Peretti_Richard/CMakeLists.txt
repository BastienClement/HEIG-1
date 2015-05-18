cmake_minimum_required(VERSION 3.2)
project(Labo_09_Peretti_Richard)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES Labo_09_Peretti_Richard.cpp Labo_09_Peretti_Richard_liste.cpp)
add_executable(Labo_09_Peretti_Richard ${SOURCE_FILES} Labo_09_Peretti_Richard_liste.h Labo_09_Peretti_Richard_liste.cpp)
