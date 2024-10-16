#include "manager.h"
#include <iostream>

Manager::Manager(const std::string& username, const std::string& password)
    : User(username, password) {}

std::string Manager::getRole() const {
    return "Manager";
}

void Manager::enviarParaManutencao(Aeronave& aeronave) const {
    aeronave.setEmManutencao(true);
    aeronave.setProntaParaUso(false);
    std::cout << "Aeronave " << aeronave.getMatricula() << " enviada para manutenção." << std::endl;
}
