#pragma once

#include "Message.h"
#include <string>

class TextMessage : public Message 
{
private:
    std::string text;

public:
    TextMessage(int senderId,  const std::string& sendDate,  const std::string& text) : Message(senderId, sendDate), text(text) {}

    std::string getText() const 
    {
        return text;
    }
    void print() const;
 std::string getType() const override;
string toString() const override;
};
