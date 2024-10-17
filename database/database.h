#ifndef DATABASE_H
#define DATABASE_H

#include "../include/json.hpp"  // Inclua a biblioteca nlohmann/json
#include <string>
#include <vector>

using namespace std;

using json = nlohmann::json;

class Database {
public:
    Database(const string& dbFilename);
    ~Database();

    // Carregar o banco de dados a partir de um arquivo JSON
    bool load();

    // Salvar o banco de dados em um arquivo JSON
    bool save() const;

    // Funções para adicionar dados ao banco de dados
    void addUser(const string& username, const string& password, const string& role);
    void addMechanic(const string& username, const string& name, const string& password);
    void addAircraft(const string& id, const string& model, bool maintence);
    void addManager(const string& username, const string& name, const string& password);

    // Acesso aos dados do banco de dados
    json getUsers() const;
    json getMechanics() const;
    json getAircrafts() const;
    json getManagers() const;

private:
    json database;              // Estrutura de dados JSON que armazena o banco de dados
    string dbFilename;     // Nome do arquivo onde o banco de dados será salvo/carregado
};

#endif // DATABASE_H
