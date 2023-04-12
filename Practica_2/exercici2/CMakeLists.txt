cmake_minimum_required(VERSION 3.23)
project(exercici2)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(exercici2
        Llista.h
        MainExercici2.cpp
        NodeLlista.h
        Posicio.h)
