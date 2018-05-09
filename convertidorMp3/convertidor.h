//
// Created by andres on 08/05/18.
//

#ifndef CONVERTIDORMP3_CONVERTIDOR_H
#define CONVERTIDORMP3_CONVERTIDOR_H

#include <iostream>
#include <fstream>
#include <vector>

using  namespace std;
class convertidor {

private:
    char *bites;
    long size;
    vector<char> bitesNormales;

public:
    void mp3Binario();
    void binarioMp3();

};


#endif //CONVERTIDORMP3_CONVERTIDOR_H
