#ifndef LOGIC_H
#define LOGIC_H

#include <iostream>
#include "Document/parserxml.h"
#include "Document/xmldocument.h"
#include <string>
#include <iostream>
#include "Objects/file.h"
#include <QTcpSocket>
#include "Document/backtracking.h"
//#include "Objects/page.h"

using namespace std;
class Logic
{
public:
    Logic(ParserXML *parser, QTcpSocket* socket);
    void decision();
    void setGET(string GET);
    /**
     * @brief writeGET create requested.xml
     */
    void writeGET();

private:

    string GET;
    XMLDocument *POST= new XMLDocument();
    ParserXML *xml;
    void getFileList();
    QTcpSocket* socket;
    void sendFile();
    backtracking BT;

    //Page* page;


};


#endif // LOGIC_H
