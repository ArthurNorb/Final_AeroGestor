#ifndef MANAGER_H
#define MANAGER_H

#include "user.h"
#include "aeronave.h"  // Inclua para que Manager possa usar a classe Aeronave

class Manager : public User {
public:
    // Construtor
    Manager(const std::string& username, const std::string& password);

    // Retorna o papel do usuário
    std::string getRole() const override;

    // Envia uma aeronave para manutenção
    void enviarParaManutencao(Aeronave& aeronave) const;
};

#endif // MANAGER_H
