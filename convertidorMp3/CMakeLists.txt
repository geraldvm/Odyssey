cmake_minimum_required(VERSION 3.10)
project(convertidorMp3)

set(CMAKE_CXX_STANDARD 11)

add_executable(convertidorMp3 main.cpp convertidor.cpp convertidor.h ListaSimple.h NodoListaSimple.h)