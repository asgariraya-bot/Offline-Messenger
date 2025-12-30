#pragma once
#include "Conversation.h"
#include "Message.h"
#include <vector>
#include <string>

class PrivateChat;

class ChatManager 
{
private:
    std::vector<Conversation*> chats;
    int generateNewConversationId() const;
public:
    ChatManager();
    ~ChatManager();

    PrivateChat* createPrivateChat(int user1Id, const std::string& user1Name,   int user2Id, const std::string& user2Name);

    std::vector<Conversation*> getUserConversations(int userId) const;

    void addMessageToChat(int conversationId, Message* msg);

    void displayAllChats() const;

    void saveChats(const std::string& filename) const;
    void loadChats(const std::string& filename);
};
