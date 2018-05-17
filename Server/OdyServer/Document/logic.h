#ifndef LOGIC_H
#define LOGIC_H
#include <iostream>
#include "parserxml.h"
#include "xmldocument.h"
#include <string>
#include <iostream>


using namespace std;
class Logic
{
public:
    Logic(string GET);
    void decision();

private:
    string GET;
    XMLDocument *POST= new XMLDocument();
    ParserXML *xml= new ParserXML();
    /**
     * @brief writeGET create requested.xml
     */
    void writeGET();
    void getFileList();

};

#endif // LOGIC_H
