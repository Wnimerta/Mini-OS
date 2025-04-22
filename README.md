# 🌌 ORKANE - The Mini OS

**ORKANE - The Mini OS** is a command-line-based mini operating system written in C that simulates essential OS-level features like file management, user handling, messaging, visual themes, and utility commands. It is designed to demonstrate core OS concepts in an interactive and fun way, making it a perfect academic project or learning tool for beginners in Operating Systems and C programming.

---

## 🧠 Features

- 📁 **File System**
  - Create, read, and delete virtual files
  - Persist file data across sessions

- 👤 **User Management**
  - Register new users
  - Login/logout system
  - Simple authentication mechanism

- 💬 **Messaging System**
  - Logged-in users can send messages
  - Message inbox accessible to all users
  - Simple inter-user communication

- 🎨 **Utility Commands**
  - `clear` screen
  - Display current `date` and time
  - Set terminal `theme` (dark/light)
  - `help` menu for all commands

- 🎮 **Mini Game**
  - "Guess the Number" terminal game

- ✨ **Visual Enhancements**
  - Shimmer effect welcome banner
  - Colored CLI output for better user experience

- 🧪 **Ready for Expansion**
  - Process scheduling simulation
  - Multitasking support using pthreads (coming soon)

---

## 🚀 Getting Started

### 📦 Prerequisites

- GCC compiler
- Linux or macOS terminal (for ANSI escape sequences)
- Basic understanding of terminal commands

### 🛠️ How to Compile

```bash
gcc arcane_os.c -o arcane_os -lpthread
```

### ▶️ How to Run

```bash
./arcane_os
```

---

## 🖥️ Sample Commands

| Command   | Description                        |
|-----------|------------------------------------|
| `create`  | Create a new file                  |
| `read`    | Read an existing file              |
| `delete`  | Delete a file                      |
| `register`| Register a new user                |
| `login`   | Log in as a user                   |
| `logout`  | Log out from current user session  |
| `send`    | Send a message                     |
| `view`    | View all messages                  |
| `clear`   | Clear the terminal screen          |
| `date`    | Show current date and time         |
| `theme`   | Change theme (dark/light)          |
| `game`    | Play guess-the-number game         |
| `help`    | Show available commands            |
| `exit`    | Exit ARCANE - The Mini OS          |

---

## 📂 Project Structure

```
arcane_os.c          # Source code file
filesystem.dat       # Auto-generated to store virtual file system
README.md            # This file
```

---

## 📸 Screenshots

 <img width="416" alt="image" src="https://github.com/user-attachments/assets/86a0198d-7f38-457e-9568-0791093875df" />

---

## 🧑‍💻 Authors

- 👩‍💻 Nimerta Wadhwani  
  _Computer Systems Engineer

---

## 📜 License

This project is licensed under the **MIT License**. You are free to modify, distribute, or use it in your own projects with proper attribution.

---

## 🙌 Acknowledgments

- Designed and developed as part of Operating Systems coursework.
- Inspired by real OS-level functionalities simplified for educational purposes.
