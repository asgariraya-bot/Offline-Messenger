#pragma once
#include <string>
using namespace std;
class User {
protected:
    int id;
    string username;
    string fullname;
    string birthdate;
    string password;
    string joinDate;

public:
    User(int id, const std::string& username, const std::string& fullname, const std::string& birthdate, const std::string& password, const std::string& joinDate);

    virtual ~User() = default;

    int getId() const;
    string getUsername() const;
   string getFullname() const;
    string getBirthdate() const;
    string getJoinDate() const;

    virtual void displayInfo() const;
    bool checkPassword(const string& pass) const;

};