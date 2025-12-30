#pragma once
#include "Conversation.h"
#include <vector>
#include <stdexcept>

class PrivateChat : public Conversation {
public:
    PrivateChat(int conversationId, int user1Id, int user2Id, const std::string& user2Name, const std::vector<Conversation*>& existingChats);
    std::string getChatName(int currentUserId) const;

    void addMessage(Message* msg);
};
