#include "User.h"
#include <iostream>

User::User(int id, const std::string& username,const std::string& fullname, const std::string& birthdate, const std::string& password, const std::string& joinDate)
 : id(id),username(username),fullname(fullname), birthdate(birthdate), password(password), joinDate(joinDate) {}

int User::getId() const 
{
    return id;
}

string User::getUsername() const 
{
    return username;
}

string User::getFullname() const 
{
    return fullname;
}

string User::getBirthdate() const 
{
    return birthdate;
}

string User::getJoinDate() const 
{
    return joinDate;
}

void User::displayInfo() const 
{
    cout << "ID: " << id << endl;
    cout << "Username: " << username << endl;
    cout << "Full Name: " << fullname << endl;
    cout << "Birthdate: " << birthdate << endl;
    cout << "Join Date: " << joinDate << endl;
}
bool User::checkPassword(const string& pass) const 
{
    return password == pass;
}
