#pragma once
#include <string>
using namespace std;

class Message 
{
protected:
    int senderId;
    string sendTime;

public:
    Message(int senderId, const string& sendTime);
    virtual ~Message() {}

    int getSenderId() const;
    string getSendTime() const;

    virtual string getType() const = 0;
    virtual void print() const = 0;

    virtual string toString() const = 0;
};