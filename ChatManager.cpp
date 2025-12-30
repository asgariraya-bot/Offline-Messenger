#include "ChatManager.h"
#include "PrivateChat.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>

using namespace std;

ChatManager::ChatManager() {}

ChatManager::~ChatManager() {
    for (Conversation* chat : chats) {
        delete chat;
    }
    chats.clear();
}
int ChatManager::generateNewConversationId() const {
    int maxId = 0;
    for (const Conversation* chat : chats) {
        if (chat->getId() > maxId)
            maxId = chat->getId();
    }
    return maxId + 1;
}
PrivateChat* ChatManager::createPrivateChat(int user1Id, int user2Id, const string& user2Name) {
    int newId = generateNewConversationId();
    PrivateChat* newChat = new PrivateChat(newId, user1Id, user2Id, user2Name, chats);
    chats.push_back(newChat);
    return newChat;
}
vector<Conversation*> ChatManager::getUserConversations(int userId) const {
    vector<Conversation*> result;
    for (Conversation* chat : chats) {
        const vector<int>& participants = chat->getParticipants();
        if (find(participants.begin(), participants.end(), userId) != participants.end()) {
            result.push_back(chat);
        }
    }
    return result;
}
void ChatManager::addMessageToChat(int conversationId, Message* msg) {
    for (Conversation* chat : chats) {
        if (chat->getId() == conversationId) {
            chat->addMessage(msg);
            return;
        }
    }
    throw runtime_error("Conversation not found.");
}

void ChatManager::displayAllChats() const {
    for (const Conversation* chat : chats) {
        cout << "Conversation " << chat->getId() << " (" << chat->getName() << ")" << endl;
        chat->displayMessages();
        cout << "                       " << endl;
    }
}

void ChatManager::saveChats(const string& filename) const {
    ofstream file(filename);
    if (!file) throw runtime_error("Cannot open file for writing.");

    for (const Conversation* chat : chats) {
        file << chat->toString() << endl;
    }

    file.close();
}

void ChatManager::loadChats(const std::string& filename) {
    ifstream file(filename);
    if (!file) return;
    file.close();
}

