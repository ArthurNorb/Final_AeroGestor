#ifndef AUTHSYSTEM_H
#define AUTHSYSTEM_H

#include <vector>
#include <memory>
#include <string>
#include "user.h"  // Classe base
#include "admin.h"
#include "manager.h"
#include "mechanic.h"

class AuthSystem {
private:
    std::vector<std::shared_ptr<User>> users;

public:
    AuthSystem();

    // Função para validar o login
    std::shared_ptr<User> login(const std::string& username, const std::string& password);
};

#endif // AUTHSYSTEM_H
