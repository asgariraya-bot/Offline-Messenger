#include "VoiceMessage.h"
#include <iostream>

using namespace std;

VoiceMessage::VoiceMessage(int senderId, const string& time, const string& username): Message(senderId, time), senderUsername(username) {}

void VoiceMessage::print() const 
{
    cout << "[Voice Message] Sent by user ID: " << senderId
         << " at " << sendTime << endl;
}

std::string VoiceMessage::toString() const 
{
    return "[Voice Message] Sent by " + senderUsername + " at " + sendTime;
}


string VoiceMessage::getType() const {
    return "Voice";
}
