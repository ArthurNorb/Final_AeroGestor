#include "admin.h"
#include <iostream>

Admin::Admin(const std::string& username, const std::string& password)
    : User(username, password) {}

nlohmann::json Admin::toJson() const {
    return nlohmann::json{
        {"username", getUsername()},
        {"password", getPassword()},
        {"role", "Admin"}
    };
}
void Admin::fromJson(const nlohmann::json& data) {
    setUsername(data["username"]);
    setPassword(data["password"]);
}

std::string Admin::getRole() const {
    return "Admin";
}

void Admin::cadastrarAeronave(std::vector<Aeronave>& frota, const Aeronave& aeronave) const {
    frota.push_back(aeronave);
    std::cout << "Aeronave " << aeronave.getId() << " cadastrada com sucesso." << std::endl;
}

void Admin::editarUsuario(Mechanic& mechanic, const std::string& novoNome) const {
    //mechanic = Mechanic(novoNome, mechanic.getId());
    //std::cout << "Mecânico atualizado: " << novoNome << std::endl;
}

void Admin::editarUsuario(Manager& manager, const std::string& novoNome) const {
    //manager = Manager(novoNome, manager.getId());
    //std::cout << "Gestor atualizado: " << novoNome << std::endl;
}

