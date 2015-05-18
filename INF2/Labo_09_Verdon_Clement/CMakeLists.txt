cmake_minimum_required(VERSION 3.2)
project(Labo_09_Verdon_Clement)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp)
add_executable(Labo_09_Verdon_Clement ${SOURCE_FILES} Labo_09_Verdon_Clement_Dictionnaire.h Labo_09_Verdon_Clement_Dictionnaire.cpp Labo_09_Verdon_Clement_Liste.h Labo_09_Verdon_Clement_Liste.cpp Labo_09_Verdon_Clement_Element.h Labo_09_Verdon_Clement_Element.cpp)
