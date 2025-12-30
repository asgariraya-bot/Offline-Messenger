#include "ChatManager.h"
#include "PrivateChat.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>

using namespace std;

ChatManager::ChatManager() {}

ChatManager::~ChatManager()
{
    for (Conversation* chat : chats) {
        delete chat;
    }
    chats.clear();
}

int ChatManager::generateNewConversationId() const
{
    int maxId = 0;
    for (const Conversation* chat : chats) {
        if (chat->getId() > maxId)
            maxId = chat->getId();
    }
    return maxId + 1;
}

PrivateChat* ChatManager::createPrivateChat(int user1Id, const std::string& user1Name,  int user2Id, const std::string& user2Name)
{
    for (Conversation* c : chats)
    {
        const auto& p = c->getParticipants();
        if (p.size() == 2 &&
            ((p[0] == user1Id && p[1] == user2Id) ||
             (p[0] == user2Id && p[1] == user1Id)))
        {
            return dynamic_cast<PrivateChat*>(c);
        }
    }

    int newId = generateNewConversationId();

    PrivateChat* newChat =
        new PrivateChat(newId, user1Id, user1Name, user2Id, user2Name);

    chats.push_back(newChat);
    return newChat;
}


vector<Conversation*> ChatManager::getUserConversations(int userId) const
{
    vector<Conversation*> result;

    for (Conversation* chat : chats)
    {
        const vector<int>& participants = chat->getParticipants();
        if (find(participants.begin(), participants.end(), userId) != participants.end()) {
            result.push_back(chat);
        }
    }
    return result;
}

void ChatManager::addMessageToChat(int conversationId, Message* msg)
{
    for (Conversation* chat : chats) {
        if (chat->getId() == conversationId) {
            chat->addMessage(msg);
            return;
        }
    }
    throw runtime_error("Conversation not found.");
}

void ChatManager::displayAllChats() const
{
    for (const Conversation* chat : chats) {
        cout << "Conversation " << chat->getId()
             << " (" << chat->getName() << ")\n";
        chat->displayMessages();
        cout << endl;
    }
}

void ChatManager::saveChats(const string& filename) const
{
    ofstream file(filename);
    if (!file)
        throw runtime_error("Cannot open file for writing.");

    for (const Conversation* chat : chats) {
        file << chat->toString() << endl;
    }
    file.close();
}

void ChatManager::loadChats(const string& filename)
{
    ifstream file(filename);
    if (!file) return;
    file.close();
}
