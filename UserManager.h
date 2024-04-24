//
// Created by voric on 24.04.2024.
//

#ifndef CPP_KARTENSPIEL_USERMANAGER_H
#define CPP_KARTENSPIEL_USERMANAGER_H
#include <vector>
#include <string>

struct User {
    std::string username;
    std::string password;
    int cash;
};

bool loadUsers(const std::string& filename, std::vector<User>& users);
bool saveUsers(const std::string& filename, const std::vector<User>& users);
User* authenticateUser(std::vector<User>& users);
User* registerUser(std::vector<User>& users);
int getBetAmount(User& user);


#endif //CPP_KARTENSPIEL_USERMANAGER_H
