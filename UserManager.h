#pragma once
#include <string>
#include <vector>
#include "User.h"

using namespace std;

class UserManager
 {
private:
    vector<User> users;
    string filename;

    bool usernameExists(const string& username) const;
    void loadFromFile();
    void saveToFile() const;

public:
    UserManager(const string& file);

    void signUp(const string& username,
                const string& fullName,
                const string& birthDate,
                const string& password);

    User login(const string& username, const string& password);

    vector<User> searchUser(const string& keyword) const;

    void sortUsersByUsername();
    void sortUsersByFullName();
    void sortUsersById();

    const vector<User>& getAllUsers() const;
};
