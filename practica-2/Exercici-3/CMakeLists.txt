cmake_minimum_required(VERSION 3.23)
project(Exercici_3)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Exercici_3
        Client.h
        Clinica.h
        Llista.h
        MainExercici3.cpp
        Mascota.h
        NodeLlista.h
        Posicio.h)
