cmake_minimum_required(VERSION 3.10)
project(ArbolAVL)

set(CMAKE_CXX_STANDARD 11)

add_executable(ArbolAVL main.cpp
        logic/Mapa.cpp  headers/Mapa.h
        logic/NodoAVL.cpp headers/NodoAVL.h
        logic/ArbolAVL.cpp headers/ArbolAVL.h
        logic/Mapa.cpp headers/Mapa.h)