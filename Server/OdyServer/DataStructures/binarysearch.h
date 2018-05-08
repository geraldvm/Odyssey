#ifndef BINARYSEARCH_H
#define BINARYSEARCH_H

#include <fstream>
#include <iostream>
using namespace std;
template <class T>
/**
 * @brief The BinarySearch class: Clase que realiza el algoritmo de búsqueda
 * binaria para encontrar un dato en una lista ordenada
 */
class BinarySearch
{
public:
    BinarySearch(std::string file);
    /**
     * @brief binarySearch: Método de búsqueda en los archivo de tipo binario
     * @param data: dato que se desea buscar
     * @return: retorna la posición del dato
     */
    int binarySearch (T data);
    ~BinarySearch();

private:
    int binarySearch(int l, int r, T data);
    std::string file;

};

#endif // BINARYSEARCH_H
