#include "authSystem.h"
#include <iostream>

AuthSystem::AuthSystem() {
    // Inicializar usuários para testes
    users.push_back(std::make_shared<Admin>("admin", "admin123"));
    users.push_back(std::make_shared<Manager>("manager", "manager123"));
    users.push_back(std::make_shared<Mechanic>("mechanic", "mech123"));
}

std::shared_ptr<User> AuthSystem::login(const std::string& username, const std::string& password) {
    for (const auto& user : users) {
        if (user->getUsername() == username && user->checkPassword(password)) {
            return user;  // Retorna o usuário logado
        }
    }
    return nullptr;  // Se não encontrar, retorna nullptr
}
