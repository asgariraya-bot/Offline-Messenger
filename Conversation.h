#pragma once
#include <vector>
#include <string>
#include "Message.h"

#include <iostream>

class Conversation {
protected:
    int conversationId;
    std::vector<int> participants;
    std::string name;
    std::vector<Message*> messages;

public:
    Conversation(int conversationId, const std::vector<int>& participants,const std::string& name);

    virtual ~Conversation();

    int getId() const;
        virtual std::string getName() const = 0;

    virtual std::string getChatName(int currentUserId) const = 0;
    const std::vector<Message*>& getMessages() const;

    virtual const std::vector<int>& getParticipants() const = 0;
    virtual void addMessage(Message* msg);
    virtual void displayMessages() const;
    virtual std::string toString() const;
};
