#include "PrivateChat.h"
#include <algorithm>
#include <sstream>
#include <iostream>

using namespace std;

PrivateChat::PrivateChat(int conversationId, int user1Id, int user2Id, const std::string& user2Name, const std::vector<Conversation*>& existingChats)
    : Conversation(conversationId, {user1Id, user2Id}, user2Name)
{
    for (const Conversation* chat : existingChats) 
    {
        const vector<int>& participants = chat->getParticipants();
        if ((participants[0] == user1Id && participants[1] == user2Id) ||
            (participants[0] == user2Id && participants[1] == user1Id)) {
            throw runtime_error("Private chat between these users already exists.");
        }
    }
}

void PrivateChat::addMessage(Message* msg) 
{
    Conversation::addMessage(msg);
}
