#include "mechanic.h"
#include <iostream>

Mechanic::Mechanic(const std::string& username, const std::string& password)
    : User(username, password) {}

nlohmann::json Mechanic::toJson() const {
    return nlohmann::json{
        {"username", getUsername()},
        {"password", getPassword()}
    };
}
void Mechanic::fromJson(const nlohmann::json& data) {
    setUsername(data["username"]);
    setPassword(data["password"]);
}

std::string Mechanic::getRole() const {
    return "Mechanic";
}

void Mechanic::verificarAeronave(Aeronave& aeronave) const {
    if (aeronave.getMaintence()) {
        std::cout << "Aeronave " << aeronave.getId() << " está em manutenção." << std::endl;
    } else {
        std::cout << "Aeronave " << aeronave.getId() << " está pronta para uso." << std::endl;
    }
}

void Mechanic::marcarPronta(Aeronave& aeronave) const {
    if (!aeronave.getMaintence()) {  // Verifica se NÃO está em manutenção
        aeronave.setProntaParaUso(true);
        std::cout << "Aeronave " << aeronave.getId() << " ainda está em manutenção." << std::endl;
    } else {
        std::cout << "Aeronave " << aeronave.getId() << " foi marcada como pronta para uso." << std::endl;

    }
}

