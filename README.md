# Offline Messenger Project

## Project Description
This is a simple terminal-based offline messenger.  
Messages can be **text** or **symbolic voice**, and all user and message data are stored in files.

### Features
- User management (Sign-up and Login)
- Private chat between users
- File-based message storage
- Support for text and symbolic voice messages
- Display sender and message timestamp

---

## File Structure

### `include/` folder
- `User.hpp` and `LocalUser.hpp` → User classes
- `Message.hpp`, `TextMessage.hpp`, `VoiceMessage.hpp` → Message classes
- `Conversation.hpp`, `PrivateChat.hpp` → Chat classes
- `UserManager.hpp`, `ChatManager.hpp` → User and chat managers

### `src/` folder
Contains implementation of all classes (.cpp files)
---
## Author
This project was developed and completed by Raya Asgari.

---نخ

## Compilation and Execution

### Step 1: Compile (C++)
In VS Code terminal or CMD:
```bash
g++ main.cpp User.cpp UserManager.cpp LocalUser.cpp Message.cpp TextMessage.cpp VoiceMessage.cpp Conversation.cpp PrivateChat.cpp ChatManager.cpp -o messenger.exe
