#include "mechanic.h"
#include <iostream>

Mechanic::Mechanic(const std::string& username, const std::string& password)
    : User(username, password) {}

std::string Mechanic::getRole() const {
    return "Mechanic";
}

void Mechanic::verificarAeronave(Aeronave& aeronave) const {
    if (aeronave.estaEmManutencao()) {
        std::cout << "Aeronave " << aeronave.getMatricula() << " está em manutenção." << std::endl;
    } else {
        std::cout << "Aeronave " << aeronave.getMatricula() << " está pronta para uso." << std::endl;
    }
}

void Mechanic::marcarPronta(Aeronave& aeronave) const {
    if (!aeronave.estaEmManutencao()) {  // Verifica se NÃO está em manutenção
        aeronave.setProntaParaUso(true);
        std::cout << "Aeronave " << aeronave.getMatricula() << " ainda está em manutenção." << std::endl;
    } else {
        std::cout << "Aeronave " << aeronave.getMatricula() << " foi marcada como pronta para uso." << std::endl;

    }
}

