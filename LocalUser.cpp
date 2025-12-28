#include "LocalUser.h"
#include <iostream>

using namespace std;

LocalUser::LocalUser(const User& user) : User(user) {}

void LocalUser::showDashboard(UserManager& userManager) 
{
    int choice = -1;

    while (choice != 0) {
        cout << "\nUSER DASHBOARD\n";
        cout << "Logged in as: " << username << "\n";
        cout << "1. View users\n";
        cout << "2. Send message\n";
        cout << "3. View conversations\n";
        cout << "0. Logout\n";
        cout << "Choose: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1:
                viewUsers(userManager);
                break;

            case 2:
                sendMessage(userManager);
                break;

            case 3:
                viewConversations();
                break;

            case 0:
                logout();
                break;

            default:
                cout << "Invalid option.\n";
        }
    }
}

void LocalUser::viewUsers(UserManager& userManager) const {
    auto users = userManager.getAllUsers();
    cout << "\n[USER LIST]\n";
    for (const auto& user : users) {
        cout << "Username: " << user.getUsername()
             << ", Fullname: " << user.getFullname()
             << ", Join Date: " << user.getJoinDate() << "\n";
    }
}

void LocalUser::sendMessage(UserManager& userManager) {
    string receiverUsername, text;
    cout << "Receiver username: ";
    getline(cin, receiverUsername);

    try {
        auto* receiver = userManager.findUserInternal(receiverUsername);
        if (!receiver) throw runtime_error("User not found");

        cout << "Message text: ";
        getline(cin, text);

        cout << "\n[TEXT MESSAGE SENT]\n";
        cout << "From: " << username << "\n";
        cout << "To: " << receiverUsername << "\n";
        cout << "Content: " << text << "\n";

    } catch (const exception& e) {
        cout << "Error: " << e.what() << "\n";
    }
}

void LocalUser::viewConversations() const {
    cout << "\n[CONVERSATIONS]\n";
    cout << "No conversations yet.\n";
}

void LocalUser::logout() {
    cout << "\nLogging out...\n";
}
