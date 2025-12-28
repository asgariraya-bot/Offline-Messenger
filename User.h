#pragma once
#include <iostream>
#include <string>

using namespace std;

class User
{
private:
    long int userId;
    string username;
    string fullName;
    string birthDate;
    string password;
    int joinData;

public:
    User(long int id, const string& uname = "", const string& name = "", 
         const string& bdate = "", const string& pass = "", int join = 0)
        : userId(id), username(uname), fullName(name), birthDate(bdate), password(pass), joinData(join) {}

    virtual ~User() {}

    long int getUserId() const { return userId; }
    string getUserName() const { return username; }
    string getName() const { return fullName; }
    string getBirthDate() const { return birthDate; }
    string getPassword() const { return password; }
    int getjoinData() const { return joinData; }

    void print() const {
        cout << "UserId: " << userId << " " << "UserName: " << username << " "<< "Name: " << fullName << " " << "BirthDate: " << birthDate << " " << "Password: " << password << " " << "joinData: " << joinData << endl;
    }

    bool checkPassword(const string& pass) const {
        return password == pass;
    }
};
