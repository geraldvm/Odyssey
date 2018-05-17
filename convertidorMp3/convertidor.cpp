//
// Created by andres on 08/05/18.
//

#include <cstring>
#include "convertidor.h"
#include <cstdio>
#include <cstdlib>

void convertidor::mp3Binario() {
    FILE *file = nullptr;
    size_t result;
    file = fopen("cancion.mp3","rb");
    if (file == nullptr) {
        cout << "No se pudo abrir archivo" << endl;
        return;
    }
    fseek(file,0,SEEK_END);
    size = ftell(file);
    rewind(file);
    bites = (char*) malloc(sizeof(char)*size);
    if (bites == nullptr) {
        cout << "Error en reserva memoria" << endl;
        return;
    }
    result = fread(bites,1,size,file);
    if (result != size) {
        cout << "Error al leer archivo" << endl;
    }
    std::ofstream text("bits.txt");
    char line;
    for (int i = 0; i < size; i++) {
        bitesNormales.push_back(bites[i] + '0');
        line = bitesNormales[i] + '0';
        text << line + '0';
        text << '\n';
    }
    fclose(file);
}

void convertidor::binarioMp3() {
    FILE * out;
    auto *buffer = (char*) malloc(sizeof(char)*size);
    for (int i = 0; i < size; i++) {
        buffer[i] = bitesNormales[i] - '0';
    }
    out = fopen("cancionConvertida.mp3","wb");
    fwrite(buffer,size,1,out);
    fclose(out);
}




