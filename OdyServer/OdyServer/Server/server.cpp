

    return convertirABytes(res);
}

QBitArray Server::convertirABits(QByteArray in){
    QBitArray out(in.count()*8);
    for (int bytePos = 0; bytePos < in.count(); bytePos++){
        for (int bitPos = 0; bitPos < 8; bitPos++){
            int bitIndex = bytePos*8+bitPos;
            out.setBit(bitIndex,in.at(bytePos)&(1<<bitPos));
        }
    }
    return out;
}

QByteArray Server::convertirABytes(QBitArray in){
    QByteArray out;
    out.resize(in.count()/8);
    for (int posBit = 0; posBit < out.count(); posBit++){
        out[posBit/8] = ( out.at(posBit/8) | ((in[posBit]?1:0)<<(posBit%8)));
    }
    return out;
}

QByteArray Server::calcularParidad(QByteArray p1, QByteArray p2){

    QBitArray bits1 = convertirABits(p1);
    QBitArray bits2 = convertirABits(p2);
    QBitArray res = QBitArray(bits1.size());

    for (int bitPos = 0; bitPos < bits1.size(); bitPos++) {
        res.setBit(bitPos,(bits1.at(bitPos) ^ bits2.at(bitPos)));
    }

    return convertirABytes(res);
}
