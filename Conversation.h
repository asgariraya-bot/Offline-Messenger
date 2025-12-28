#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Conversations 
{
protected:
    long int ConversationsId;
    vector<long int> participantIds;
    string NameOfConversations;

public:
    Conversations(long int ConversationsId, vector<long int> participantIds, string NameOfConversations)
        : ConversationsId(ConversationsId), participantIds(participantIds), NameOfConversations(NameOfConversations) {}

    virtual ~Conversations() {}
    virtual void print() const = 0;
    long int getId() const { return ConversationsId; }
    vector<long int> getParticipants() const { return participantIds; }
    string getName() const { return NameOfConversations; }
    bool hasUser(long int userId) const {
        return find(participantIds.begin(), participantIds.end(), userId) != participantIds.end();
    }
};
