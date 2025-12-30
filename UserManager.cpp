#include "UserManager.h"
#include <fstream>
#include <sstream>
#include <algorithm>
#include<iostream>

using namespace std;

UserManager::UserManager() {}

int UserManager::generateNewId() const {
    if (users.empty())
        return 1;
    return users.back().getId() + 1;
}

User* UserManager::findUserInternal(const string& username) {
    for (auto& user : users) {
        if (user.getUsername() == username)
            return &user;
    }
    return nullptr;
}
void UserManager::loadUsers(const string& filename) {
    ifstream file(filename);
    if (!file.is_open())
        return;

    users.clear();
    string line;

    while (getline(file, line)) {
        stringstream ss(line);
        string idStr, username, fullname, birthdate, password, joinDate;

        getline(ss, idStr, '|');
        getline(ss, username, '|');
        getline(ss, fullname, '|');
        getline(ss, birthdate, '|');
        getline(ss, password, '|');
        getline(ss, joinDate, '|');

        users.emplace_back(
            stoi(idStr),
            username,
            fullname,
            birthdate,
            password,
            joinDate
        );
    }
}

void UserManager::saveUsers(const string& filename) const {
    ofstream file(filename);
    for (const auto& user : users)
    {
        file << user.getId() << "|"<< user.getUsername() << "|" << user.getFullname() << "|" << user.getBirthdate() << "|"<< "*****" << "|" << user.getJoinDate() << endl;
    }
}

void UserManager::signUp(const string& username, const string& fullname, const string& birthdate,const string& password,const string& joinDate) {
    if (findUserInternal(username))
        throw UserAlreadyExistsException();
    if (!isValidDate(birthdate) || !isValidDate(joinDate))
        throw std::invalid_argument("Invalid date format.");
    int newId = generateNewId();
    users.emplace_back(newId, username, fullname, birthdate, password, joinDate);
    
}

LocalUser UserManager::login(const string& username,const string& password) 
{
    User* user = findUserInternal(username);

    if (!user)
        throw UserNotFoundException();

    if (!user->checkPassword(password))
        throw IncorrectPasswordException();

    return LocalUser(*user);
}
vector<User> UserManager::getAllUsers() const 
{
    return users;
}


bool UserManager::isValidDate(const std::string& date) const
{
    if (date.size() != 10) return false;

    if (date[4] != '-' || date[7] != '-') return false;

    int year = stoi(date.substr(0, 4));
    int month = stoi(date.substr(5, 2));
    int day = stoi(date.substr(8, 2));

    if (year < 1900 || year > 2100) return false;
    if (month < 1 || month > 12) return false;

    int daysInMonth[] = {31,28,31,30,31,30,31,31,30,31,30,31};
    if (month == 2) {
        bool leap = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
        if (leap) daysInMonth[1] = 29;
    }

    if (day < 1 || day > daysInMonth[month - 1]) return false;

    return true;
}
