#include "aeronave.h"
#include <iostream>

// Construtor
Aeronave::Aeronave(const std::string& matricula, const std::string& modelo)
    : matricula(matricula), modelo(modelo), emManutencao(false), prontaParaUso(true) {}

// Getters e Setters
std::string Aeronave::getMatricula() const { return matricula; }
void Aeronave::setMatricula(const std::string& matricula) { this->matricula = matricula; }

std::string Aeronave::getModelo() const { return modelo; }
void Aeronave::setModelo(const std::string& modelo) { this->modelo = modelo; }

bool Aeronave::estaEmManutencao() const { return emManutencao; }
void Aeronave::setEmManutencao(bool status) { emManutencao = status; }

bool Aeronave::estaProntaParaUso() const { return prontaParaUso; }
void Aeronave::setProntaParaUso(bool status) { prontaParaUso = status; }

// Histórico de manutenção
void Aeronave::registrarManutencao(const std::string& detalhes) {
    historicoManutencao.push_back(detalhes);
    setEmManutencao(false);  // Manutenção concluída
    setProntaParaUso(true);
}

void Aeronave::exibirHistorico() const {
    std::cout << "Histórico de Manutenção da Aeronave " << matricula << ":\n";
    for (const auto& registro : historicoManutencao) {
        std::cout << registro << std::endl;
    }
}
