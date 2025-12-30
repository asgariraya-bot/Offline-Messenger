#include "LocalUser.h"
#include <iostream>
#include "TextMessage.h"
#include "VoiceMessage.h"
#include <ctime>
#include <iomanip>
#include <sstream>
#include <algorithm>
#include "PrivateChat.h"
#include "ChatManager.h"
using namespace std;

string getCurrentTime() {
    time_t now = time(nullptr);
    tm* localTime = localtime(&now);

    stringstream ss;
    ss << put_time(localTime, "%Y-%m-%d %H:%M");
    return ss.str();
}

LocalUser::LocalUser(const User& user) : User(user) {}

void LocalUser::showDashboard(UserManager& userManager, ChatManager& chatManager) {
    int choice = -1;

    while (choice != 0) {
        cout << "\nUSER DASHBOARD\n";
        cout << "Logged in as: " << username << "\n";
        cout << "1. View users\n";
        cout << "2. Create private chat\n";
        cout << "3. View conversations\n";
        cout << "0. Logout\n";
        cout << "Choose: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1: viewUsers(userManager); break;
            case 2: createPrivateChat(userManager, chatManager); break;
            case 3: viewConversations(chatManager); break;
            case 0: logout(); break;
            default: cout << "Invalid option.\n";
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

void LocalUser::createPrivateChat(UserManager& userManager, ChatManager& chatManager) 
{
    string receiverUsername;
    cout << "Receiver username: ";
    getline(cin, receiverUsername);

    User* receiver = userManager.findUserInternal(receiverUsername);
    if (!receiver) {
        cout << "User not found.\n";
        return;
    }

    PrivateChat* chat = nullptr;
    auto conversations = chatManager.getUserConversations(this->id);
    for (Conversation* c : conversations) {
        auto participants = c->getParticipants();
        if (participants.size() == 2 &&
            ((participants[0] == this->id && participants[1] == receiver->getId()) ||
             (participants[1] == this->id && participants[0] == receiver->getId()))) {
            chat = dynamic_cast<PrivateChat*>(c);
            break;
        }
    }

    if (!chat) 
    {
        chat = chatManager.createPrivateChat(this->id, this->username,  receiver->getId(), receiver->getUsername() );
        cout << "New private chat created.\n";
    }

    cout << "\n1. Text Message\n2. Voice Message\nChoose message type: ";
    int choice;
    cin >> choice;
    cin.ignore();

    Message* msg = nullptr;
    string time = getCurrentTime();

    if (choice == 1) {
        string text;
        cout << "Enter text: ";
        getline(cin, text);
        msg = new TextMessage(this->id, time, text);

    } else if (choice == 2) {
        msg = new VoiceMessage(this->id, time, this->username);

    } else {
        cout << "Invalid choice.\n";
        return;
    }

    chat->addMessage(msg);
    cout << "Message sent successfully.\n";
}

void LocalUser::viewConversations(ChatManager& chatManager) {
    auto conversations = chatManager.getUserConversations(this->id);
    vector<PrivateChat*> privateChats;

    for (Conversation* c : conversations) {
        if (auto pc = dynamic_cast<PrivateChat*>(c)) {
            privateChats.push_back(pc);
        }
    }

    if (privateChats.empty()) {
        cout << "No private chats found.\n";
        return;
    }

    cout << "\nYOUR PRIVATE CHATS\n";
    cout << "1. Show all\n2. Search by username\n3. Sort by username\nChoose: ";
    int choice;
    cin >> choice;
    cin.ignore();

    vector<PrivateChat*> filtered = privateChats;

    if (choice == 2) {
        string keyword;
        cout << "Enter username to search: ";
        getline(cin, keyword);
        filtered.clear();
        for (PrivateChat* pc : privateChats) {
            if (pc->getName() == keyword || pc->getName().find(keyword) != string::npos) {
                filtered.push_back(pc);
            }
        }
    } else if (choice == 3) {
        sort(filtered.begin(), filtered.end(),
             [](PrivateChat* a, PrivateChat* b) {
                 return a->getName() < b->getName();
             });
    }

    if (filtered.empty()) {
        cout << "No matching conversations.\n";
        return;
    }

    cout << "\nConversations:\n";
    for (size_t i = 0; i < filtered.size(); ++i) {
        cout << i + 1 << ". " << filtered[i]->getName() << endl;
    }

    cout << "Select conversation number (0 to cancel): ";
    int select;
    cin >> select;
    cin.ignore();

    if (select <= 0 || select > (int)filtered.size())
        return;

    cout << "\nCHAT WITH " << filtered[select - 1]->getName() << "\n";
    filtered[select - 1]->displayMessages();
}

void LocalUser::logout() {
    cout << "\nLogging out...\n";
}
