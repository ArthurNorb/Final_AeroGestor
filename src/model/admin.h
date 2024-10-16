#ifndef ADMIN_H
#define ADMIN_H

#include "user.h"
#include "aeronave.h"
#include "mechanic.h"
#include "manager.h"
#include <vector>

class Admin : public User {
public:
    // Construtor
    Admin(const std::string& username, const std::string& password);

    // Retorna o papel do usuário
    std::string getRole() const override;

    // Cadastra uma aeronave na frota
    void cadastrarAeronave(std::vector<Aeronave>& frota, const Aeronave& aeronave) const;

    // Editar mecânico
    void editarUsuario(Mechanic& mechanic, const std::string& novoNome) const;

    // Editar gestor
    void editarUsuario(Manager& manager, const std::string& novoNome) const;
};

#endif // ADMIN_H
