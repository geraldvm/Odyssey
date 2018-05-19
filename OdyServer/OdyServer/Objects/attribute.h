#ifndef ATTRIBUTE_H
#define ATTRIBUTE_H



#include <iostream>
using namespace std;

class Attribute
{
public:
    Attribute(string type, string value);
    string getType();
    string getValue();
    void setAttribute(string type, string value);

private:
    string type;
    string value;

};

#endif // ATTRIBUTE_H
