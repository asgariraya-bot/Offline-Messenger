#include "TextMessage.h"
#include <iostream>
#include <string>

using namespace std;

string TextMessage::toString() const
{
    return "TEXT|" + to_string(senderId) + "|" + sendTime + "|" + text;
}

void TextMessage::print() const
{
    cout << "[" << sendTime << "] "
         << "User" << senderId << ": "
         << text << endl;
}
