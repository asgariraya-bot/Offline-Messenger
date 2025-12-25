#pragma once
#include "Conversation.h"
#include <iostream>
#include <stdexcept>

class PrivateChat : public Conversations
{
public:
    PrivateChat(long int id, long int user1, long int user2)
        : Conversations(id, { user1, user2 }, "Private Chat")
    {
        if (user1 == user2)
            throw invalid_argument("A private chat cannot be created with the same user");
    }

    bool isBetween(long int u1, long int u2) const
    {
        return (participantIds[0] == u1 && participantIds[1] == u2) ||
               (participantIds[0] == u2 && participantIds[1] == u1);
    }

    bool involvesUser(long int userId) const
    {
        return participantIds[0] == userId || participantIds[1] == userId;
    }

    long int getOtherParticipant(long int userId) const
    {
        if (participantIds[0] == userId) return participantIds[1];
        if (participantIds[1] == userId) return participantIds[0];
        throw std::invalid_argument("User is not a participant in this chat");
    }

    void print() const override
    {
        std::cout << "Private Chat [" << ConversationsId << "]: User "
                  << participantIds[0] << " ↔ User "
                  << participantIds[1] << std::endl;
    }
    
};