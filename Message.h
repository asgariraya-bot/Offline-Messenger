#pragma once
#include <string>

 using namespace std;

class Message
 {
 protected:
     long int senderId;
     string sentAt;

 public:
     Message(long int senderId, const string& sentAt)
         : senderId(senderId), sentAt(sentAt) {}

    virtual ~Message() {}

    long int getSenderId() const { return senderId; }
    string getSentAt() const { return sentAt; }

     virtual string getType() const = 0;

    virtual void saveasFile(ostream& out) const = 0;

    virtual void print() const = 0;
 };


