#ifndef LOGIC_H
#define LOGIC_H
#include <iostream>
#include "parserxml.h"
#include "xmldocument.h"
using namespace std;
class Logic
{
public:
    Logic(string GET);
    void decision();

private:
    string GET;
    XMLDocument POST;
    ParserXML xml;
    /**
     * @brief writeGET create requested.xml
     */
    void writeGET();

};

#endif // LOGIC_H
