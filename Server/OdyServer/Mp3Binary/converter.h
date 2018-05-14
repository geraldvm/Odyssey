#ifndef CONVERTER_H
#define CONVERTER_H
#include <iostream>
#include <fstream>
#include <vector>
#include <QFile>
using  namespace std;

class Converter
{
public:
    Converter();
    void mp3ToBinary();
    void binaryToMp3();
private:
    char *bites;
    long size;
    vector<char> bitesNormales;
};

#endif // CONVERTER_H
