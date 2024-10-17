#include "aeronave.h"
#include <iostream>

// Construtor
Aeronave::Aeronave(const string& id, const string& model)
    : id(id), model(model), maintence(false), prontaParaUso(true) {}

nlohmann::json Aeronave::toJson() const {
    return nlohmann::json{
        {"id", getId()},
        {"model", getModel()},
        {"maintence", getMaintence()}
    };
}
void Aeronave::fromJson(const nlohmann::json& data) {
    setId(data["id"]);
    setModel(data["model"]);
    setMaintence(data["maintence"]);
}

// Getters e Setters
std::string Aeronave::getId() const { return id; }
void Aeronave::setId(const std::string& id) { this->id = id; }

std::string Aeronave::getModel() const { return model; }
void Aeronave::setModel(const std::string& model) { this->model = model; }

bool Aeronave::getMaintence() const { return maintence; }
void Aeronave::setMaintence(bool status) { maintence = status; }

bool Aeronave::estaProntaParaUso() const { return prontaParaUso; }
void Aeronave::setProntaParaUso(bool status) { prontaParaUso = status; }

// Histórico de manutenção
void Aeronave::registrarManutencao(const std::string& detalhes) {
    historicoManutencao.push_back(detalhes);
    setMaintence(false);  // Manutenção concluída
    setProntaParaUso(true);
}

void Aeronave::exibirHistorico() const {
    std::cout << "Histórico de Manutenção da Aeronave " << id << ":\n";
    for (const auto& registro : historicoManutencao) {
        std::cout << registro << std::endl;
    }
}
