#include "Conversation.h"
#include <iostream>
#include <sstream>

using namespace std;

Conversation::Conversation(int conversationId, const vector<int>& participants, const string& name)
    : conversationId(conversationId), participants(participants), name(name) {}

Conversation::~Conversation() {
    for (Message* msg : messages) {
        delete msg;
    }
    messages.clear();
}

int Conversation::getId() const 
{
    return conversationId;
}

string Conversation::getName() const 
{
    return name;
}

const vector<int>& Conversation::getParticipants() const 
{
    return participants;
}

const vector<Message*>& Conversation::getMessages() const

{
    return messages;
}

void Conversation::addMessage(Message* msg) {
    messages.push_back(msg);
}

void Conversation::displayMessages() const {
    for (const Message* msg : messages) {
        msg->print();
    }
}

string Conversation::toString() const {
    ostringstream out;
    out << "CONVERSATION|" << conversationId;
    for (int id : participants) {
        out << "|" << id;
    }
    out << endl;
    for (const Message* msg : messages) {
        out << msg->toString() << endl;
    }
    return out.str();
}
