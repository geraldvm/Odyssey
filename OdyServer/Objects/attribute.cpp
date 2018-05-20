#include "attribute.h"

Attribute::Attribute(string type, string value)
{
    this->type=type;
    this->value=value;
}

string Attribute::getType()
{
    return this->type;
}

string Attribute::getValue()
{
    return this->value;
}

void Attribute::setAttribute(string type, string value)
{
    this->type=type;
    this->value=value;
}
