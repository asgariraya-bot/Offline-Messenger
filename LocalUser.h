#pragma once
#include<iostream>
#include<vector>
#include<string>
#include"User.h"

class LocalUser : public User
{
vector<string> conversations;
public:
  LocalUser(long int userId, string userName, string name, int userBirthday, string userPassword, int loginData)
: User(userId, userName, name, userBirthday, userPassword, loginData) {}

void showDashboard() const
{
    cout << "Welcome to our offline messenger, " << getUserName() << ":)" << endl;
    cout << "1. Show Users\n2. Show Conversations\n3. Create Private Chat\n4. Logout\n";
}

void showConversations() const
{
    cout << "Your conversations:" << endl;
    for (const auto& conv : conversations) 
    {
        cout << " " << conv << endl;
    }
}
 void addConversation(const string& name) 
    {
        conversations.push_back(name);
    }
    void logout() 
    {
        cout << "User logged out.\n";
    }
};