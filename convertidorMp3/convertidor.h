//
// Created by andres on 08/05/18.
//

#ifndef CONVERTIDORMP3_CONVERTIDOR_H
#define CONVERTIDORMP3_CONVERTIDOR_H

#include <iostream>
#include <fstream>
#include <vector>

using  namespace std;
/**
 * Clase que convierte mp3 a binario y viceversa
 */
class convertidor {

private:
    /**
     * Caracteres para contener el archivo
     */
    char *bites;
    /**
     * Tamaño del archivo
     */
    long size;
    /**
     * Lista para contener los caracteres legibles, se utiliza vector por rapidez en lectura
     */
    vector<char> bitesNormales;

public:
    /**
     * Función que convierte mp3 a arreglo de caracteres
     */
    void mp3Binario();
    /**
     * Función que convierte un arreglo de caracteres a mp3
     */
    void binarioMp3();

};


#endif //CONVERTIDORMP3_CONVERTIDOR_H
