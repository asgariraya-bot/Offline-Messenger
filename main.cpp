#include <iostream>
#include <string>
#include "UserManager.h"
#include "LocalUser.h"
#include "ChatManager.h"

using namespace std;

int main() {
    UserManager userManager;
    ChatManager chatManager;

    cout << "OFFLINE MESSENGER TEST\n";

    int choice = -1;

    while (choice != 0) {
        cout << "\n1. Sign Up\n";
        cout << "2. Login\n";
        cout << "0. Exit\n";
        cout << "Choose: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1: {
                string username, fullname, birthdate, password, joinDate;
                cout << "Username: ";
                getline(cin, username);
                cout << "Fullname: ";
                getline(cin, fullname);
                cout << "Birthdate (YYYY-MM-DD): ";
                getline(cin, birthdate);
                cout << "Password: ";
                getline(cin, password);
                cout << "Join date (YYYY-MM-DD): ";
                getline(cin, joinDate);

                try {
                    userManager.signUp(username, fullname, birthdate, password, joinDate);
                    cout << "User signed up successfully!\n";
                } catch (const exception& e) {
                    cout << "Error: " << e.what() << "\n";
                }
                break;
            }

            case 2: {
                string username, password;
                cout << "Username: ";
                getline(cin, username);
                cout << "Password: ";
                getline(cin, password);

                try {
                    LocalUser localUser = userManager.login(username, password);
                    cout << "Login successful!\n";

                    localUser.showDashboard(userManager, chatManager);
                } catch (const exception& e) {
                    cout << "Error: " << e.what() << "\n";
                }
                break;
            }

            case 0:
                cout << "Exiting program...\n";
                break;

            default:
                cout << "Invalid option.\n";
        }
    }

    return 0;
}
