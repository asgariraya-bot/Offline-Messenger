#include "Conversation.h"
#include <iostream>
#include <algorithm>

using namespace std;

long int Conversations::getId() const 
{
    return ConversationsId;
}

vector<long int> Conversations::getParticipants() const 
{
    return participantIds;
}

string Conversations::getName() const 
{
    return NameOfConversations;
}

bool Conversations::hasUser(long int userId) const 
{
    return find(participantIds.begin(), participantIds.end(), userId) != participantIds.end();
}

void Conversations::print() const 
{
    cout << "Conversation Id: " << ConversationsId << endl;
    cout << "Name: " << NameOfConversations << endl;
    cout << "Participants: ";
    for(auto id : participantIds)
        cout << id << " ";
    cout << endl;
}

