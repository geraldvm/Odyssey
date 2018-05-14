#include "mainwindow.h"
#include <QApplication>
#include "server.h"
#include "Mp3Binary/converter.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
   // MainWindow w;
    //w.show();
    Converter c;
    c.mp3ToBinary();
    c.binaryToMp3();
    //Server mserver;

    return a.exec();
}
