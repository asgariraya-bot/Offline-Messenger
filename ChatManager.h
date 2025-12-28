#pragma once
#include <vector>
#include "Conversation.h"

using namespace std;

class ChatManager 
{
private:
    vector<Conversations*> conversations;

public:
    ChatManager() {}

    vector<Conversations*>& getAllConversations() {
        return conversations;
    }

    vector<Conversations*> getUserConversations(long int userId) {
        vector<Conversations*> result;
        for(auto conv : conversations) {
            if(conv->hasUser(userId))
                result.push_back(conv);
        }
        return result;
    }
};
