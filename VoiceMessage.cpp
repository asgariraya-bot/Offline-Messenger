#include "VoiceMessage.h"
#include <iostream>

using namespace std;

VoiceMessage::VoiceMessage(int senderId, const string& time, const string& desc) : Message(senderId, time) {}

void VoiceMessage::print() const {
    cout << "[Voice Message] Sent by user ID: " << senderId
         << " at " << sendTime << endl;
}

string VoiceMessage::toString() const {
    return "[Voice Message] Sent by user ID: " + to_string(senderId) + 
           " at " + sendTime;
}

string VoiceMessage::getType() const {
    return "Voice";
}
