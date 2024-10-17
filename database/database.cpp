#include "database.h"
#include <fstream>
#include <iostream>

Database::Database(const std::string& dbFilename) : dbFilename(dbFilename) {
    load();  // Carrega o banco de dados ao inicializar
}

Database::~Database() {
    save();  // Salva o banco de dados ao destruir o objeto
}

bool Database::load() {
    std::ifstream file(dbFilename);
    if (file.is_open()) {
        file >> database;
        file.close();
        return true;
    } else {
        std::cerr << "Erro ao abrir o arquivo JSON para carregar o banco de dados." << std::endl;
        return false;
    }
}

bool Database::save() const {
    std::ofstream file(dbFilename);
    if (file.is_open()) {
        file << database.dump(4);  // Salva com indentação de 4 espaços
        file.close();
        return true;
    } else {
        std::cerr << "Erro ao abrir o arquivo JSON para salvar o banco de dados." << std::endl;
        return false;
    }
}

// Funções para adicionar dados ao banco de dados

void Database::addUser(const std::string& username, const std::string& password, const std::string& role) {
    database["users"].push_back({
        {"username", username},
        {"password", password},
        {"role", role}
    });
}

void Database::addMechanic(const std::string& username, const std::string& name, const std::string& certification) {
    database["mechanics"].push_back({
        {"username", username},
        {"name", name},
        {"certification", certification}
    });
}

void Database::addAeronave(const std::string& matricula, const std::string& modelo, bool emManutencao) {
    database["aircrafts"].push_back({
        {"matricula", matricula},
        {"modelo", modelo},
        {"em_manutencao", emManutencao}
    });
}

void Database::addManager(const std::string& username, const std::string& name, const std::string& department) {
    database["managers"].push_back({
        {"username", username},
        {"name", name},
        {"department", department}
    });
}

// Funções para acessar dados
json Database::getUsers() const {
    return database["users"];
}

json Database::getMechanics() const {
    return database["mechanics"];
}

json Database::getAircrafts() const {
    return database["aircrafts"];
}

json Database::getManagers() const {
    return database["managers"];
}
