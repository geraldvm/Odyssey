#ifndef LOGIC_H
#define LOGIC_H
#include <iostream>
#include "parserxml.h"
#include "xmldocument.h"
#include <string>
#include <iostream>
#include <filesystem>

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
    void getFileList();

};

#endif // LOGIC_H
