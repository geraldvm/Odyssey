#ifndef MESSAGE_H
#define MESSAGE_H

#include <iostream>

using namespace std;

class Message
{
public:
    Message(string sender, string receiver, string song);
    string getSong();
    string getSender();
    string getReceiver();


private:
    string sender;
    string song;
    string receiver;
};

#endif // MESSAGE_H
