#include "database.h"
#include <fstream>
#include <iostream>

Database::Database(const string& dbFilename) : dbFilename(dbFilename) {
    load();  // Carrega o banco de dados ao inicializar
}

Database::~Database() {
    save();  // Salva o banco de dados ao destruir o objeto
}

bool Database::load() {
    ifstream file(dbFilename);
    if (file.is_open()) {
        file >> database;
        file.close();
        return true;
    } else {
        cerr << "Error opening JSON file to load database." << endl;
        return false;
    }
}

bool Database::save() const {
    ofstream file(dbFilename);
    if (file.is_open()) {
        file << database.dump(4);  // Salva com indentação de 4 espaços
        file.close();
        return true;
    } else {
        cerr << "Error opening JSON file to save database." << endl;
        return false;
    }
}

// Funções para adicionar dados ao banco de dados

void Database::addUser(const string& username, const string& password, const string& role) {
    database["users"].push_back({
        {"username", username},
        {"password", password},
        {"role", role}
    });
}

void Database::addMechanic(const string& username, const string& name, const string& password) {
    database["mechanics"].push_back({
        {"username", username},
        {"name", name},
        {"password", password}
    });
}

void Database::addAircraft(const string& id, const string& model, bool maintence) {
    database["aircrafts"].push_back({
        {"id", id},
        {"model", model},
        {"maintence", maintence}
    });
}

void Database::addManager(const string& username, const string& name, const string& password) {
    database["managers"].push_back({
        {"username", username},
        {"name", name},
        {"password", password}
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
