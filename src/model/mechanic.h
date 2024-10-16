#ifndef MECHANIC_H
#define MECHANIC_H

#include "user.h"
#include "aeronave.h"

class Mechanic : public User {
public:
    // Construtor
    Mechanic(const std::string& username, const std::string& password);

    // Método para verificar o papel do usuário (sobrescrito da classe base User)
    std::string getRole() const override;

    // Métodos específicos do mecânico
    void verificarAeronave(Aeronave& aeronave) const;
    void marcarPronta(Aeronave& aeronave) const;
};

#endif // MECHANIC_H
