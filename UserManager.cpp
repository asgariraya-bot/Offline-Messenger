#include "UserManager.h"
#include <fstream>
#include <algorithm>
#include <stdexcept>

using namespace std;

UserManager::UserManager(const string& file) : filename(file) {
    ifstream fin(filename);
    long int userId;
    string userName, name, password;
    int birthDate, loginData;

    while (fin >> userId >> userName >> name >> birthDate >> password >> loginData) {
        users.emplace_back(userId, userName, name, birthDate, password, loginData);
    }
}

bool UserManager::usernameExists(const string& username) const {
    return any_of(users.begin(), users.end(), [&](const User& u){ 
        return u.getUserName() == username; 
    });
}

void UserManager::signUp(const string& username, const string& name,
                         const string& birthDate, const string& password) {
    if(usernameExists(username)) throw runtime_error("Username already exists!");

    long int newId = users.empty() ? 1 : users.back().getUserId() + 1;
    users.emplace_back(newId, username, name, stoi(birthDate), password, 0);

    ofstream fout(filename);
    for(const auto &u : users)
        fout << u.getUserId() << ' ' << u.getUserName() << ' ' << u.getName() << ' '
             << u.getUserBirthday() << ' ' << u.getUserPassword() << ' ' << u.getLoginData() << '\n';
}

User UserManager::login(const string& username, const string& password) {
    auto it = find_if(users.begin(), users.end(), [&](const User& u){ 
        return u.getUserName() == username; 
    });

    if(it == users.end()) throw runtime_error("Username does not exist!");
    if(it->getUserPassword() != password) throw runtime_error("Incorrect password!");
    return *it;
}

vector<User> UserManager::searchUser(const string& keyword) const {
    vector<User> result;
    copy_if(users.begin(), users.end(), back_inserter(result),
            [&](const User& u){
                return u.getUserName().find(keyword) != string::npos ||
                       u.getName().find(keyword) != string::npos;
            });
    return result;
}

void UserManager::sortUsersByUsername() {
    sort(users.begin(), users.end(), [](const User& a,const User& b){
        return a.getUserName() < b.getUserName();
    });
}

void UserManager::sortUsersByFullName() {
    sort(users.begin(), users.end(), [](const User& a,const User& b){
        return a.getName() < b.getName();
    });
}

void UserManager::sortUsersById() {
    sort(users.begin(), users.end(), [](const User& a,const User& b){
        return a.getUserId() < b.getUserId();
    });
}

const vector<User>& UserManager::getAllUsers() const {
    return users;
}
