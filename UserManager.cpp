#include "UserManager.h"
#include <fstream>
#include <sstream>
#include <iostream>

bool loadUsers(const std::string& filename, std::vector<User>& users) {
    std::ifstream file(filename);
    if (!file) {
        std::cerr << "Unable to open file. Attempting to create a new one.\n";
        // Attempt to create the file
        std::ofstream outFile(filename);
        if (!outFile) {
            std::cerr << "Failed to create the file. Please check permissions or disk space.\n";
            return false;
        }
        std::cout << "File successfully created.\n";  // Feedback that file was created
        outFile.close();
        return true; // Return true as the file is now created, although it's empty.
    }

    std::string line;
    while (getline(file, line)) {
        std::istringstream iss(line);
        User user;
        getline(iss, user.username, ',');
        getline(iss, user.password, ',');
        iss >> user.cash;
        users.push_back(user);
    }
    file.close();
    return true;
}

bool saveUsers(const std::string& filename, const std::vector<User>& users) {
    std::ofstream file(filename);
    if (!file) {
        std::cerr << "Unable to open file for saving. Check permissions or disk space.\n";
        return false;
    }

    for (const auto& user : users) {
        file << user.username << "," << user.password << "," << user.cash << "\n";
    }
    file.close();
    return true;
}

User* authenticateUser(std::vector<User>& users) {
    std::string username, password;
    std::cout << "Username: ";
    std::cin >> username;
    std::cout << "Password: ";
    std::cin >> password;

    for (auto& user : users) {
        if (user.username == username && user.password == password) {
            return &user;
        }
    }
    std::cerr << "Authentication failed. Username or password incorrect.\n";
    return nullptr;
}

User* registerUser(std::vector<User>& users) {
    std::string username, password;
    std::cout << "Choose a username: ";
    std::cin >> username;
    std::cout << "Choose a password: ";
    std::cin >> password;

    // Check if username already exists
    for (auto& user : users) {
        if (user.username == username) {
            std::cerr << "Username already exists.\n";
            return nullptr;
        }
    }

    int startCash = 100; // Starting cash for new users
    User newUser{username, password, startCash};
    users.push_back(newUser);
    saveUsers("points.voric", users);
    return &users.back();
}

int getBetAmount(User& user) {
    int bet;
    do {
        std::cout << "Enter your bet (min 10, available cash " + std::to_string(user.cash) + "): ";
        std::cin >> bet;
    } while (bet < 10 || bet > user.cash);
    return bet;
}
