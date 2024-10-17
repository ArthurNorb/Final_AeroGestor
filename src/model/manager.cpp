#include "manager.h"
#include <iostream>

Manager::Manager(const std::string& username, const std::string& password)
    : User(username, password) {}

nlohmann::json Manager::toJson() const {
    return nlohmann::json{
        {"username", getUsername()},
        {"password", getPassword()}
    };
}
void Manager::fromJson(const nlohmann::json& data) {
    setUsername(data["username"]);
    setPassword(data["password"]);
}

std::string Manager::getRole() const {
    return "Manager";
}

void Manager::enviarParaManutencao(Aeronave& aeronave) const {
    aeronave.setMaintence(true);
    aeronave.setProntaParaUso(false);
    std::cout << "Aeronave " << aeronave.getId() << " enviada para manutenção." << std::endl;
}
