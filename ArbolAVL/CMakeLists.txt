cmake_minimum_required(VERSION 3.10)
project(ArbolAVL)

set(CMAKE_CXX_STANDARD 11)

find_package( Qt5Core REQUIRED )
find_package( Qt5Widgets REQUIRED )
find_package( Qt5Gui REQUIRED )
find_package( Qt5Xml REQUIRED )

add_executable(ArbolAVL main.cpp
        logic/Mapa.cpp  headers/Mapa.h
        logic/NodoAVL.cpp headers/NodoAVL.h
        logic/ArbolAVL.cpp headers/ArbolAVL.h
        logic/Mapa.cpp headers/Mapa.h logic/JsonMaker.cpp headers/JsonMaker.h logic/guardarJson.cpp headers/guardarJson.h logic/leerJson.cpp headers/leerJson.h)

target_link_libraries(ArbolAVL Qt5::Widgets Qt5::Core ${Boost_LIBRARIES})