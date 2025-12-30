#pragma once
#include <vector>
#include <string>
#include "Conversation.h"
#include "PrivateChat.h"
#include "Message.h"
#include <stdexcept>

class ChatManager {
private:
    std::vector<Conversation*> chats;

public:
    ChatManager();
    ~ChatManager();
        int generateNewConversationId() const;

    PrivateChat* createPrivateChat(int user1Id, int user2Id, const std::string& user2Name);

    std::vector<Conversation*> getUserConversations(int userId) const;
    void addMessageToChat(int conversationId, Message* msg);
    
    void displayAllChats() const;

    void saveChats(const std::string& filename) const;
    void loadChats(const std::string& filename);
};
