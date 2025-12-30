#pragma once
#include "Conversation.h"
#include <string>

class PrivateChat : public Conversation 
{
private:
    int user1Id, user2Id;
    std::string user1Name, user2Name;
public:
    PrivateChat(int conversationId, int user1Id, const std::string& user1Name,int user2Id, const std::string& user2Name);

    std::string getChatName(int currentUserId) const override;
    std::string getName() const override;
    const std::vector<int>& getParticipants() const;
};

