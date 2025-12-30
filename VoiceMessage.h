#pragma once
#include "Message.h"
#include <string>

class VoiceMessage : public Message {
public:
    VoiceMessage(int senderId, const std::string& sendTime);
    ~VoiceMessage() override {}

    void print() const;
    std::string toString() const override;
    std::string getType() const override;
};
