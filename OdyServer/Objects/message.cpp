#include "message.h"


Message::Message(string sender, string receiver, string song)
{
    this->sender=sender;
    this->receiver=receiver;
    this->song=song;

}

string Message::getSong()
{
    return this->song;
}

string Message::getSender()
{
    return this->sender;
}

string Message::getReceiver()
{
    return this->receiver;
}
