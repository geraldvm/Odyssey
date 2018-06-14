#include "raidcontroller.h"

RaidController::RaidController()
{
    std::ifstream file (auxInfo.toStdString());
    std::string str;
    if(!file.is_open()){
        return;
    }
    while(getline(file,str)) {
        int i = 0;
        if (i == 0){
            listaNombres.push_back(QString::fromStdString(str));
            i ++;
        }  else {
            if(i == 1){
                indexes.push_back(stoi(str));
                i ++;
            } else {
                fileSizes.push_back(stoi(str));
                i = 0;
            }
        }
    }
    indicePar = indexes.get(indexes.size -1);
    file.close();
}
//funcion delete y corregir paths
void RaidController::writeSong(QString nombre, QByteArray in)
{
    if(indicePar == 3){
        stripping(in,disc1+nombre+".part1",disc2+nombre+".part2",disc3+nombre+".par");
        guardarRegistro(nombre,3,in.size());
        indicePar = 1;
        return;
    }
    if(indicePar == 1){
        stripping(in,disc3+nombre+".par",disc1+nombre+".part1",disc2+nombre+".part2");
        guardarRegistro(nombre,1,in.size());
        indicePar = 2;
        return;
    }
    if(indicePar == 2){
        stripping(in,disc2+nombre+".part2",disc3+nombre+".par",disc1+nombre+".part1");
        guardarRegistro(nombre,2,in.size());
        indicePar = 3;
        return;
    }

}

void RaidController::stripping(QByteArray in,QString d1,QString d2,QString d3)
{
    int strip= in.size()/2;

    QByteArray bytes1 = in.mid(0, strip+1);
    converter.setPathFull(d1);
    converter.toFile(bytes1);

    QByteArray bytes2 = in.mid(strip,2*strip);
    converter.setPathFull(d2);
    converter.toFile(bytes2);

    QByteArray paridad = calcularParidad(bytes1,bytes2);
    converter.setPathFull(d3);
    converter.toFile(paridad);
    std::cout << "doneStripping" << std::endl;

}

QByteArray RaidController::songRequest(QString nombre, int pos)
{
    int indice = indexes.get(listaNombres.getIndex(nombre));
    int size = fileSizes.get(listaNombres.getIndex(nombre));

    QByteArray full;
    if(indice == 3){
        full = Autorecovery(disc1+nombre+".part1",disc2+nombre+".part2",disc3+nombre+".par");
    }
    if(indicePar == 1){
        full = Autorecovery(disc2+nombre+".part1",disc3+nombre+".part2",disc1+nombre+".par");
    }
    if(indicePar == 2){
        full = Autorecovery(disc3+nombre+".part1",disc1+nombre+".part2",disc2+nombre+".par");
    }
    if(pos < size/2){
       return full.mid(0,size);
    } else {
       return full.mid(size,size*2);
    }
}

QByteArray RaidController::Autorecovery(QString d1,QString d2,QString d3)
{
    QFile disco1(d1);
    QFile disco2(d2);
    QFile disco3(d3);

    QByteArray p1;
    QByteArray p2;

    if (disco1.exists() && disco2.exists() && disco3.exists()){
        disco1.open(QIODevice::ReadOnly);
        p1 = disco1.readAll();
        disco2.open(QIODevice::ReadOnly);
        p2 = disco2.readAll();

        std::cout << "fine"<< std::endl;
    } else {
        if (disco1.exists() && disco2.exists()){
            std::cout << "error en: " << d3.toStdString() << std::endl;;
            disco1.open(QIODevice::ReadOnly);
            p1 = disco1.readAll();
            disco2.open(QIODevice::ReadOnly);
            p2 = disco2.readAll();
            return  calcularParidad(p1, p2);

        } else {
            if (disco3.exists()){
                 if(disco1.exists()){

                     std::cout << "error en: " << d2.toStdString() << std::endl;;
                     disco1.open(QIODevice::ReadOnly);
                     p1 = disco1.readAll();
                     disco3.open(QIODevice::ReadOnly);
                     QByteArray par = disco3.readAll();
                     p2 = calcularParidad(p1,par);

                 } else {

                     std::cout << "error en: " << d1.toStdString() << std::endl;
                     disco2.open(QIODevice::ReadOnly);
                     p2 = disco2.readAll();
                     disco3.open(QIODevice::ReadOnly);
                     QByteArray par = disco3.readAll();
                     p1 = calcularParidad(p2,par);

                 }

            } else {
                std::cout << "error irrecuperable en mas de 1 disco" << std::endl;
                p1.resize(2);
                return p1;
            }
        }
    }
    return p1+p2;
}

QBitArray RaidController::convertirABits(QByteArray in){
    QBitArray out(in.count()*8);
    for(int i=0; i<in.count(); ++i) {
        for(int b=0; b<8;b++) {
            out.setBit( i*8+b, in.at(i)&(1<<(7-b)) );
        }
    }
    return out;
}

QByteArray RaidController::convertirABytes(QBitArray in){
    QByteArray out;
    out.resize(in.size()/8);
    for(int b=0; b<in.count();++b) {
        out[b/8] = (out.at(b/8) | ((in[b]?1:0)<<(7-(b%8))));
    }
    return out;
}

QByteArray RaidController::calcularParidad(QByteArray p1, QByteArray p2){
    QBitArray bits1 = convertirABits(p1);
    QBitArray bits2 = convertirABits(p2);
    QBitArray res = QBitArray(bits1.size());

    for (int bitPos = 0; bitPos < res.size(); bitPos++) {
        res[bitPos] = bits1[bitPos] ^ bits2[bitPos];
    }

    return convertirABytes(res);
}

void RaidController::guardarRegistro(QString nombre, int i, int size)
{
    indexes.push_back(i);
    listaNombres.push_back(nombre);
    fileSizes.push_back(size);
    std::ofstream file(auxInfo.toStdString(), std::ios::binary | std::ofstream::app);
    file << nombre.toStdString() + '\n';
    file << std::to_string(i) + '\n';
    file << std::to_string(size) + '\n';
    file.close();

}
