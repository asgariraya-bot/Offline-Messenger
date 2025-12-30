#pragma once
#include "User.h"
#include "UserManager.h"
#include <string>
class UserManager;
class ChatManager;

class LocalUser : public User 
{
public:
    LocalUser(const User& user);
    void showDashboard(UserManager& userManager, ChatManager& chatManager);
    void viewUsers(UserManager& userManager) const;
    void creatPrivetChat(UserManager& userManager);
    void viewConversations() const;
    void logout();
};
