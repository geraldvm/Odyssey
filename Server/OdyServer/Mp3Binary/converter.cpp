#include "converter.h"
#include <cstring>
#include <cstdio>
#include <cstdlib>
Converter::Converter()
{

}

void Converter::mp3ToBinary()
{
    QFile xml("myXml.xml");
    xml.open(QIODevice::WriteOnly);
    FILE *file = nullptr;
    size_t result;
    file = fopen("cancion.mp3","rb");
    if (file == nullptr) {
        cout << "No se pudo abrir archivo" << endl;
        return;
    }
    fseek(file,0,SEEK_END);
    size = ftell(file)/2;
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
    for (int i = 0; i < size; i++) {
        bitesNormales.push_back(bites[i] + '0');
        xml.write(new QString(bites[i]));

    }
    fclose(file);


}

void Converter::binaryToMp3()
{
    FILE * out;
    auto *buffer = (char*) malloc(sizeof(char)*size);
    for (int i = 0; i < size; i++) {
        buffer[i] = bitesNormales[i] - '0';
        //std::cout<<buffer[i]<<"-";

        //cout << bitesNormales[i] + '0' << endl; siempre se tiene que sumar '0'
        // para leerlos normal y restarlo al pasarlo
    }
    out = fopen("cancionConvertida.mp3","wb");
    fwrite(buffer,size,1,out);//si le cambia el size a menos, se corta el tamaño de
    // la cancion pero no se cae
    fclose(out);

}
