#pragma once
#include <string>
#include"Message.h"
#include<iostream>
 using namespace std;
 class TextMessage:public Message
 {
  string text;

  public:

   TextMessage(long int senderId, const string& sentAt, const string& text)
     : Message(senderId, sentAt), text(text) {}
   string getType() const override
  {
   return "TEXT";
  }
    void saveasFile(ostream& out) const override
    {
        out << "TEXT"<<" Sender:" << senderId<< " Time:" << sentAt<< " Message:" << text<< endl;
    }

     void print() const override {
       cout << "Text Message from " << senderId<< " at " << sentAt << endl;
         cout << text << endl;
    }

 };