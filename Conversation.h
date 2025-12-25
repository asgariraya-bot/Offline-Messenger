#pragma once
#include<iostream>
#include<vector>
#include<string>
 using namespace std;
class Conversations
{
 long int ConversationsId;
vector<string> participantIds;
string NameOfConversations;

public:

Conversations( long int ConversationsId,vector<string> participantIds,string NameOfConversations)
:ConversationsId(ConversationsId),participantIds(participantIds),NameOfConversations(NameOfConversations){}

virtual ~Conversations() = 0;
virtual void print() const = 0;

};