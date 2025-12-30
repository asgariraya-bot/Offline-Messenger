#include "PrivateChat.h"
#include <iostream>

PrivateChat::PrivateChat(int conversationId, int u1Id, const std::string& u1Name,  int u2Id, const std::string& u2Name)
    : Conversation(conversationId, {u1Id, u2Id}, "private"), user1Id(u1Id), user1Name(u1Name),user2Id(u2Id), user2Name(u2Name) {}

std::string PrivateChat::getChatName(int currentUserId) const 
{
    return (currentUserId == user1Id) ? user2Name : user1Name;
}

std::string PrivateChat::getName() const 
{
    return user1Name + " & " + user2Name;
}

const std::vector<int>& PrivateChat::getParticipants() const 
{
    return participants;
}
