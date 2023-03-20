cmake_minimum_required(VERSION 3.23)
project(practica_2)

set(CMAKE_CXX_STANDARD 14)

include_directories(Exercici-1)
include_directories(Exercici-2)
include_directories(Exercici-3)

add_executable(practica_2
        Exercici-1/MainExercici1.cpp
        Exercici-1/PilaEstatica.cpp
        Exercici-1/PilaEstatica.h
        Exercici-2/Llista.h
        Exercici-2/MainExercici2.cpp
        Exercici-2/NodeLlista.h
        Exercici-2/Posicio.h
        Exercici-3/Client.h
        Exercici-3/Clinica.h
        Exercici-3/Llista.h
        Exercici-3/MainExercici3.cpp
        Exercici-3/Mascota.h
        Exercici-3/NodeLlista.h
        Exercici-3/Posicio.h)
