#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <pthread.h>

// Constants
#define MAX_FILES 10
#define MAX_FILENAME 20
#define MAX_CONTENT 100
#define MAX_USERS 5
#define MAX_COMMAND_LEN 50

// File system structures
typedef struct {
    char name[MAX_FILENAME];
    char content[MAX_CONTENT];
    int isOccupied;
} File;

File fileSystem[MAX_FILES];

// User system structures
typedef struct {
    char username[20];
    char password[20];
} User;

User users[MAX_USERS];
int currentUser = -1;

// Message system structures
typedef struct {
    char sender[20];
    char message[100];
} Message;

Message messageBox[10];
int messageCount = 0;

// Task system
typedef struct {
    int id;
    int burstTime;
} Process;

Process processQueue[10];
int processCount = 0;

// Function Prototypes
void initializeFileSystem();
void loadFileSystem();
void saveFileSystem();
void createFile();
void readFile();
void deleteFile();

void registerUser();
void loginUser();
void logoutUser();
void sendMessage();
void viewMessages();

void clearScreen();
void showDate();
void showHelp();
void setTheme();
void guessNumberGame();

void priorityScheduling();
void simulateMultitasking();

void shimmerEffect(const char *text);
void displayWelcomeMessage();
void handleCommand(char *command);

// Shimmer Effect
void shimmerEffect(const char *text) {
    const char *colors[] = {
        "\033[1;31m", // Bright Red
        "\033[1;33m", // Bright Yellow
        "\033[1;32m", // Bright Green
        "\033[1;36m", // Bright Cyan
        "\033[1;34m", // Bright Blue
        "\033[1;35m"  // Bright Magenta
    };

    int colorCount = sizeof(colors) / sizeof(colors[0]);

    for (int i = 0; i < 10; i++) { // 10 iterations of shimmering effect
        printf("\r"); // Reset cursor to start of line
        printf("%s%s\033[0m", colors[i % colorCount], text);
        fflush(stdout);
        usleep(150000); // Delay for smooth effect
    }
    printf("\n"); // Move to the next line
}

// Display Welcome Message with ASCII Art
void displayWelcomeMessage() {
    printf("=====================================\n");
    printf("         WELCOME TO                 \n");
    shimmerEffect("  ARCANE - THE MINI OS  ");
    printf("=====================================\n");
}

// Main Program
int main() {
    initializeFileSystem();
    loadFileSystem();

    displayWelcomeMessage();

    char command[MAX_COMMAND_LEN];
    while (1) {
        printf("ARCANE> ");
        fgets(command, MAX_COMMAND_LEN, stdin);
        command[strcspn(command, "\n")] = 0;  // Remove newline
        if (strcmp(command, "exit") == 0) {
            saveFileSystem();
            printf("Exiting ARCANE-THE MINI OS. Goodbye!\n");
            break;
        }
        handleCommand(command);
    }
    return 0;
}

// File System Functions
void initializeFileSystem() {
    for (int i = 0; i < MAX_FILES; i++) {
        fileSystem[i].isOccupied = 0;
    }
}

void loadFileSystem() {
    FILE *fp = fopen("filesystem.dat", "rb");
    if (fp) {
        fread(fileSystem, sizeof(File), MAX_FILES, fp);
        fclose(fp);
        printf("File system loaded.\n");
    } else {
        printf("No existing file system found.\n");
    }
}

void saveFileSystem() {
    FILE *fp = fopen("filesystem.dat", "wb");
    fwrite(fileSystem, sizeof(File), MAX_FILES, fp);
    fclose(fp);
    printf("File system saved.\n");
}

// File System Functions
void createFile() {
    char name[MAX_FILENAME];
    char content[MAX_CONTENT];
    printf("Enter file name: ");
    scanf("%s", name);
    printf("Enter file content: ");
    getchar();  // Clear newline
    fgets(content, MAX_CONTENT, stdin);

    for (int i = 0; i < MAX_FILES; i++) {
        if (!fileSystem[i].isOccupied) {
            strcpy(fileSystem[i].name, name);
            strcpy(fileSystem[i].content, content);
            fileSystem[i].isOccupied = 1;
            printf("File created successfully.\n");
            return;
        }
    }
    printf("File system is full!\n");
}

void readFile() {
    char name[MAX_FILENAME];
    printf("Enter file name to read: ");
    scanf("%s", name);

    for (int i = 0; i < MAX_FILES; i++) {
        if (fileSystem[i].isOccupied && strcmp(fileSystem[i].name, name) == 0) {
            printf("File content: %s\n", fileSystem[i].content);
            return;
        }
    }
    printf("File not found.\n");
}

void deleteFile() {
    char name[MAX_FILENAME];
    printf("Enter file name to delete: ");
    scanf("%s", name);

    for (int i = 0; i < MAX_FILES; i++) {
        if (fileSystem[i].isOccupied && strcmp(fileSystem[i].name, name) == 0) {
            fileSystem[i].isOccupied = 0;
            printf("File deleted successfully.\n");
            return;
        }
    }
    printf("File not found.\n");
}

// User Management Functions
void registerUser() {
    char username[20], password[20];
    printf("Enter username: ");
    scanf("%s", username);
    printf("Enter password: ");
    scanf("%s", password);

    for (int i = 0; i < MAX_USERS; i++) {
        if (users[i].username[0] == '\0') {
            strcpy(users[i].username, username);
            strcpy(users[i].password, password);
            printf("User '%s' registered successfully.\n", username);
            return;
        }
    }
    printf("User limit reached!\n");
}

void loginUser() {
    char username[20], password[20];
    printf("Enter username: ");
    scanf("%s", username);
    printf("Enter password: ");
    scanf("%s", password);

    for (int i = 0; i < MAX_USERS; i++) {
        if (strcmp(users[i].username, username) == 0 &&
            strcmp(users[i].password, password) == 0) {
            currentUser = i;
            printf("Welcome, %s!\n", username);
            return;
        }
    }
    printf("Invalid credentials.\n");
}

void logoutUser() {
    if (currentUser == -1) {
        printf("You are not logged in.\n");
    } else {
        printf("Logging out...\n");
        currentUser = -1; // Reset to -1 to indicate no user is logged in
    }
}

// Messaging Functions
void sendMessage() {
    if (currentUser == -1) {
        printf("Please log in to send a message.\n");
        return;
    }

    char message[100];
    printf("Enter your message: ");
    getchar();  // Clear newline
    fgets(message, 100, stdin);

    if (messageCount < 10) {
        strcpy(messageBox[messageCount].sender, users[currentUser].username);
        strcpy(messageBox[messageCount].message, message);
        messageCount++;
        printf("Message sent!\n");
    } else {
        printf("Message box is full!\n");
    }
}

void viewMessages() {
    if (messageCount == 0) {
        printf("No messages available.\n");
        return;
    }

    for (int i = 0; i < messageCount; i++) {
        printf("From %s: %s\n", messageBox[i].sender, messageBox[i].message);
    }
}

// CLI Utility Functions
void clearScreen() {
    system("clear");
}

void showDate() {
    time_t t = time(NULL);
    printf("Current date and time: %s", ctime(&t));
}

void setTheme() {
    printf("Theme options: dark, light\n");
    char theme[10];
    scanf("%s", theme);

    if (strcmp(theme, "dark") == 0) {
        printf("\033[0;37m"); // White text
        printf("\033[40m");  // Black background
    } else if (strcmp(theme, "light") == 0) {
        printf("\033[0;30m"); // Black text
        printf("\033[47m");  // White background
    }
    printf("Theme set to %s.\n", theme);
}

void showHelp() {
    printf("Available commands:\n");
    printf("create - Create a file\n");
    printf("read - Read a file\n");
    printf("delete - Delete a file\n");
    printf("register - Register a new user\n");
    printf("login - Log in as a user\n");
    printf("logout - Log out from the system\n");
    printf("send - Send a message\n");
    printf("view - View messages\n");
    printf("clear - Clear the screen\n");
    printf("date - Show the current date\n");
    printf("theme - Set a theme\n");
    printf("exit - Exit the Mini OS\n");
}

void guessNumberGame() {
    printf("Welcome to the Guess the Number game!\n");
    int number = rand() % 100 + 1;
    int guess = 0;

    while (guess != number) {
        printf("Enter your guess (1-100): ");
        scanf("%d", &guess);

        if (guess < number) {
            printf("Too low!\n");
        } else if (guess > number) {
            printf("Too high!\n");
        } else {
            printf("Congratulations! You guessed the number.\n");
        }
    }
}

// Process Functions
void priorityScheduling() {
    printf("Simulating Priority Scheduling...\n");
}

void simulateMultitasking() {
    printf("Simulating Multitasking...\n");
}

// Command Handler
void handleCommand(char *command) {
    if (strcmp(command, "create") == 0) {
        createFile();
    } else if (strcmp(command, "read") == 0) {
        readFile();
    } else if (strcmp(command, "delete") == 0) {
        deleteFile();
    } else if (strcmp(command, "register") == 0) {
        registerUser();
    } else if (strcmp(command, "login") == 0) {
        loginUser();
    } else if (strcmp(command, "logout") == 0) {
        logoutUser();
    } else if (strcmp(command, "send") == 0) {
        sendMessage();
    } else if (strcmp(command, "view") == 0) {
        viewMessages();
    } else if (strcmp(command, "clear") == 0) {
        clearScreen();
    } else if (strcmp(command, "date") == 0) {
        showDate();
    } else if (strcmp(command, "theme") == 0) {
        setTheme();
    } else if (strcmp(command, "game") == 0) {
        guessNumberGame();
    } else if (strcmp(command, "help") == 0) {
        showHelp();
    } else {
        printf("Unknown command. Type 'help' for a list of commands.\n");
    }
}