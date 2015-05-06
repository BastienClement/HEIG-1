cmake_minimum_required(VERSION 3.2)
project(Labo_08_bastien)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall")

IF(CMAKE_COMPILER_IS_GNUCC)
   set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static-libgcc -static-libstdc++")
ENDIF(CMAKE_COMPILER_IS_GNUCC)

set(SOURCE_FILES main.cpp)
add_executable(Labo_08_bastien ${SOURCE_FILES})
