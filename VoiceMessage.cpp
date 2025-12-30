#include "VoiceMessage.h"
#include <iostream>
#include <string>

using namespace std;

VoiceMessage::VoiceMessage(int senderId, const string& sendTime)
    : Message(senderId, sendTime)
{
}

void VoiceMessage::print() const {
    cout << "[" << sendTime << "] "
         << "User" << senderId << ": "
         << "<Voice message>" << endl;
}

string VoiceMessage::toString() const {
    return "VOICE|" + to_string(senderId) + "|" + sendTime + "|<Voice message>";
}

string VoiceMessage::getType() const {
    return "VOICE";
}
