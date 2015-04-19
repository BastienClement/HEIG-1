cmake_minimum_required(VERSION 3.1)
project(Labo_05_bastien)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall")

set(SOURCE_FILES Labo_05_ClementCotza.cpp Labo_05_ClementCotza_Calculator.cpp Labo_05_ClementCotza_Stack.cpp)
add_executable(calc ${SOURCE_FILES})