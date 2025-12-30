#pragma once
#include <vector>
#include <string>
#include "Message.h"

class Conversation {
protected:
    int conversationId;
    std::vector<int> participants; 
    std::vector<Message*> messages;
    std::string name;

public:
    Conversation(int conversationId, const std::vector<int>& participants, const std::string& name);
    virtual ~Conversation();

    int getId() const;
    std::string getName() const;
    const std::vector<int>& getParticipants() const;
    const std::vector<Message*>& getMessages() const;

    void addMessage(Message* msg);
    void displayMessages() const;

    virtual std::string toString() const;
};
