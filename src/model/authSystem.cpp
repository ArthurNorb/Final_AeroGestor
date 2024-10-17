#include "authSystem.h"
#include "../../include/json.hpp"
#include <iostream>
#include <fstream>

AuthSystem::AuthSystem() {
   loadUsersFromJson("C:/Users/Arthur/OneDrive/Documentos/AeroGestor/database/database.json");
}

void AuthSystem::loadUsersFromJson(const std::string& filePath) {
    std::ifstream file(filePath);
    nlohmann::json data;

    if (file.is_open()) {
        file >> data;
        file.close();

        for (const auto& item : data["users"]) {
            std::string role = item["role"];
            std::shared_ptr<User> user;
            if (role == "Admin") {
                user = std::make_shared<Admin>(item["username"], item["password"]);
            } else if (role == "Manager") {
                user = std::make_shared<Manager>(item["username"], item["password"]);
            } else if (role == "Mechanic") {
                user = std::make_shared<Mechanic>(item["username"], item["password"]);
            }

            if (user) {
                addUser(user); // Adiciona o usuário ao sistema
            }
        }
    } else {
        std::cerr << "Erro ao abrir o arquivo " << filePath << std::endl;
    }
}

std::shared_ptr<User> AuthSystem::login(const std::string& username, const std::string& password) {
    for (const auto& user : users) {
        if (user->getUsername() == username && user->checkPassword(password)) {
            return user;  // Retorna o usuário logado
        }
    }
    return nullptr;  // Se não encontrar, retorna nullptr
}

void AuthSystem::addUser(std::shared_ptr<User> user) {
    users.push_back(user);
}
