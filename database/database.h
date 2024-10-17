#ifndef DATABASE_H
#define DATABASE_H

#include "../include/json.hpp"  // Inclua a biblioteca nlohmann/json
#include <string>
#include <vector>

using json = nlohmann::json;

class Database {
public:
    Database(const std::string& dbFilename);
    ~Database();

    // Carregar o banco de dados a partir de um arquivo JSON
    bool load();

    // Salvar o banco de dados em um arquivo JSON
    bool save() const;

    // Funções para adicionar dados ao banco de dados
    void addUser(const std::string& username, const std::string& password, const std::string& role);
    void addMechanic(const std::string& username, const std::string& name, const std::string& certification);
    void addAeronave(const std::string& matricula, const std::string& modelo, bool emManutencao);
    void addManager(const std::string& username, const std::string& name, const std::string& department);

    // Acesso aos dados do banco de dados
    json getUsers() const;
    json getMechanics() const;
    json getAircrafts() const;
    json getManagers() const;

private:
    json database;              // Estrutura de dados JSON que armazena o banco de dados
    std::string dbFilename;     // Nome do arquivo onde o banco de dados será salvo/carregado
};

#endif // DATABASE_H
