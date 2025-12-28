#pragma once
#include "User.h"
#include "UserManager.h"
#include <string>

class LocalUser : public User 
{
public:
    LocalUser(const User& user);
    void showDashboard(UserManager& userManager);

private:
    void viewUsers(UserManager& userManager) const;
    void sendMessage(UserManager& userManager);
    void viewConversations() const;
    void logout();
};
