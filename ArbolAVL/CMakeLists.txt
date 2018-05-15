cmake_minimum_required(VERSION 3.10)
project(ArbolAVL)

set(CMAKE_CXX_STANDARD 11)

find_package( Qt5Core REQUIRED )
find_package( Qt5Widgets REQUIRED )
find_package( Qt5Gui REQUIRED )
find_package( Qt5Xml REQUIRED )


add_executable(ArbolAVL main.cpp
        logic/Mapa.cpp  headers/Mapa.h
        estructuras/logic/NodoAVL.cpp estructuras/headers/NodoAVL.h
        estructuras/logic/ArbolAVL.cpp estructuras/headers/ArbolAVL.h
        logic/Mapa.cpp headers/Mapa.h
        logic/JsonMaker.cpp headers/JsonMaker.h
        logic/guardarJson.cpp headers/guardarJson.h
        logic/leerJson.cpp headers/leerJson.h
        estructuras/headers/ListaSimple.h
        estructuras/headers/NodoListaSimple.h
        estructuras/logic/cancion.cpp estructuras/headers/cancion.h
        estructuras/headers/hashMap.h)

target_link_libraries(ArbolAVL Qt5::Widgets Qt5::Core ${Boost_LIBRARIES})