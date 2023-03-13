cmake_minimum_required(VERSION 3.23)
project(Exercici_2)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Exercici_2
        Llista.h
        MainLlista.cpp
        NodeLlista.h
        Posicio.h)
