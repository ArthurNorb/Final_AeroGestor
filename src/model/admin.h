#ifndef ADMIN_H
#define ADMIN_H

#include "user.h"
#include "aeronave.h"
#include "mechanic.h"
#include "manager.h"
#include <vector>

/**
 * @brief The Admin class represents an administrator in the system.
 *
 * This class allows the admin to manage users (mechanics and managers) and
 * register new aircraft in the fleet. It inherits from the User class.
 */
class Admin : public User {
public:
    /**
     * @brief Constructs an Admin object.
     *
     * @param username The username for the admin.
     * @param password The password for the admin.
     */
    Admin(const std::string& username, const std::string& password);

    /**
     * @brief Gets the role of the user.
     *
     * @return The role of the user as a string.
     */
    std::string getRole() const override;

    /**
     * @brief Registers a new aircraft into the fleet.
     *
     * @param frota The fleet where the aircraft will be added.
     * @param aeronave The aircraft to be registered.
     */
    void cadastrarAeronave(std::vector<Aeronave>& frota, const Aeronave& aeronave) const;

    /**
     * @brief Edits the details of a mechanic.
     *
     * @param mechanic The mechanic whose details will be edited.
     * @param novoNome The new name for the mechanic.
     */
    void editarUsuario(Mechanic& mechanic, const std::string& novoNome) const;

    /**
     * @brief Edits the details of a manager.
     *
     * @param manager The manager whose details will be edited.
     * @param novoNome The new name for the manager.
     */
    void editarUsuario(Manager& manager, const std::string& novoNome) const;
};

#endif // ADMIN_H
