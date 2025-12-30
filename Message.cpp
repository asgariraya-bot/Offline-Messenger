#include "Message.h"

Message::Message(int senderId, const string& sendTime) : senderId(senderId), sendTime(sendTime) {}

int Message::getSenderId() const 

{
    return senderId;
}

string Message::getSendTime() const 
{
    return sendTime;
}
