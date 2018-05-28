#ifndef HASHMAP_H
#define HASHMAP_H

#include <iostream>
#include <string>
#include <fstream>
#include "mapa.h"
#include <QDir>
#include "listasimple.h"

class hashmap {

private:
    /**
     * @brief keys : Lista con los valores de id
     */
    ListaSimple<int> keys;
    /**
     * @brief passMap : Clase que corresponde a un mapa de hash para la contraseña y los ids
     */
    Mapa<std::string, int> passMap;
    /**
     * @brief dirMap : Dirección para guardar y cargar la información de contraseñas
     */
    std::string dirMap = QDir::homePath().toStdString().append("/Music/Odyssey/data/passMap.txt");


public:
    /**
     * @brief leerMapa : Función que carga el mapa de mamoria
     */
    void leerMapa();
    /**
     * @brief guardarMapa : Función que guarda el mapa al terminar la ejecución
     */
    void guardarMapa();
    /**
     * @brief escribirPass : Función que guarda en el mapa una contraseña nueva
     * @param nombre : Usuario al que se le agrega la contraseña
     * @param pass : Contraseña a agregar
     */
    void escribirPass(std::string nombre, std::string pass);
    /**
     * @brief confirmarPass : Función que comprueba si la clave indicada le corresponde al usuario
     * @param pass : Contraseña a verificar
     * @param nombre : Usuario a verificar
     * @return resultado de la comparación
     */
    bool confirmarPass(std::string pass, std::string nombre);
    /**
     * @brief generearId : Función que genera un entero para usarlo de id
     * @param nombre : Nombre del usuario a asignar valor
     * @return : Entero con el la suma de los valores en entero de cada carácter del nombre de usuario
     */
    int generarId(std::string nombre);
};

#endif // HASHMAP_H
