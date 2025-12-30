#pragma once
#include "Message.h"
#include <string>

class VoiceMessage : public Message 
{
        std::string senderUsername;

public:
VoiceMessage(int senderId, const std::string& time, const std::string& senderUsername);

    ~VoiceMessage() override {}

    void print() const;
    std::string toString() const override;
    std::string getType() const override;
};
