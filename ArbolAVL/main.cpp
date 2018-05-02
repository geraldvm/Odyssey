#include <iostream>
#include "headers/ArbolAVL.h"
#include "headers/Mapa.h"

int main() {

    mapa mapa1;
    //carga archivo con claves
    mapa1.leerMapa();
    //para asignar un nuevo usuario es. nombreUsuario , contranenna
    mapa1.escribirPass("pepe","pass");
    //mapa1.escribirPass("usuario","pahss"); ya esta en archivo
    mapa1.guardarMapa();
    //confirmarPass retorna bool si la contrasenna es la misma que se le tiene al usuario
    std::cout << mapa1.confirmarPass("NOpass","pepe") << "." << mapa1.confirmarPass("pahss","usuario") << std::endl;

    //cada nodo tiene un nombre de cancion y un campo direccion asociado
    ArbolAVL arbolAVL = ArbolAVL("pepe", "dir1");

    arbolAVL.agregarValor("nopepe", "dir2");
    arbolAVL.agregarValor("persona", "dir 3");
    arbolAVL.agregarValor("bo","dir6");
    arbolAVL.agregarValor("nop23epe", "dir2345");
    arbolAVL.agregarValor("sona", "dir 56778");
    arbolAVL.agregarValor("ffffbo","disdfgr6");
    arbolAVL.agregarValor("noasdfe", "dir8965656");
    arbolAVL.agregarValor("persna", "dir 22345");
    arbolAVL.agregarValor("boas","d6");
    arbolAVL.agregarValor("nase", "diddf2");
    arbolAVL.agregarValor("personaasd", "dir 3asd");
    arbolAVL.agregarValor("abo","dirasd6");

    //al buscar por nombre devuelve la direccion
    cout << arbolAVL.buscarValor("noasdfe");

    return 0;
}