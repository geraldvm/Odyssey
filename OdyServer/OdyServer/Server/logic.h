#ifndef LOGIC_H
#define LOGIC_H

#include <iostream>
#include "Document/parserxml.h"
#include "Document/xmldocument.h"
#include <string>
#include <iostream>
//#include "page.h"
#include <QTcpSocket>

using namespace std;
class Logic
{
public:
    Logic(QTcpSocket *socket);
    void decision();
    void setGET(string GET);
    /**
     * @brief writeGET create requested.xml
     */
    void writeGET();
    void sendMP3(QString fileName);
    void sendFile();


private:
    string GET;
    XMLDocument *POST= new XMLDocument();
    ParserXML *xml= new ParserXML();
    void getFileList();
    QTcpSocket socket;


    //Page* page;


};


#endif // LOGIC_H
