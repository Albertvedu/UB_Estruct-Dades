cmake_minimum_required(VERSION 3.23)
project(Practica_3)

set(CMAKE_CXX_STANDARD 14)

add_executable(Practica_3 src/main.cpp src/ArbreBinari.h
        src/NodeBinari.h src/Movie.h src/Movie.cpp src/CercadorMoviesAB.h
        src/MinHeap.h
        src/NodeHeap.h src/CercadorMoviesHeap.h)
