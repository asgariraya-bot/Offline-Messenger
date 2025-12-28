#pragma once

#include <vector>
#include <string>
#include "User.h"
#include "LocalUser.h"

#include <exception>

class UserAlreadyExistsException : public std::exception 
{
public:
    const char* what() const noexcept override {
        return "Username already exists.";
    }
};

class UserNotFoundException : public std::exception 
{
public:
    const char* what() const noexcept override {
        return "User not found.";
    }
};

class IncorrectPasswordException : public std::exception 
{
public:
    const char* what() const noexcept override {
        return "Incorrect password.";
    }
};

class UserManager 
{
private:
    std::vector<User> users;

    int generateNewId() const;

public:
    UserManager();
    void loadUsers(const std::string& filename);
    void saveUsers(const std::string& filename) const;

    void signUp(const std::string& username, const std::string& fullname, const std::string& birthdate, const std::string& password, const std::string& joinDate);

    LocalUser login(const std::string& username,  const std::string& password);
        User* findUserInternal(const std::string& username);

    std::vector<User> getAllUsers() const;
};
