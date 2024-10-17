#ifndef ADMIN_H
#define ADMIN_H

#include "user.h"
#include "aeronave.h"
#include "mechanic.h"
#include "manager.h"
#include <vector>
#include "../../include/json.hpp"

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
     * Initializes the admin with a username and password.
     *
     * @param username The username for the admin.
     * @param password The password for the admin.
     */
    Admin(const std::string& username, const std::string& password);

    /**
     * @brief Gets the role of the user.
     *
     * Returns the role of the user, which in this case is "Admin".
     *
     * @return The role of the user as a string ("Admin").
     */
    std::string getRole() const override;

    /**
     * @brief Registers a new aircraft into the fleet.
     *
     * This function adds a new aircraft to the fleet by appending the provided
     * aircraft to the vector of aircraft.
     *
     * @param frota The fleet where the aircraft will be added (a vector of Aeronave).
     * @param aeronave The aircraft to be registered (an instance of Aeronave).
     */
    void cadastrarAeronave(std::vector<Aeronave>& frota, const Aeronave& aeronave) const;

    /**
     * @brief Edits the details of a mechanic.
     *
     * This function changes the name of a mechanic.
     *
     * @param mechanic The mechanic whose details will be edited.
     * @param novoNome The new name for the mechanic.
     */
    void editarUsuario(Mechanic& mechanic, const std::string& novoNome) const;

    /**
     * @brief Edits the details of a manager.
     *
     * This function changes the name of a manager.
     *
     * @param manager The manager whose details will be edited.
     * @param novoNome The new name for the manager.
     */
    void editarUsuario(Manager& manager, const std::string& novoNome) const;

    /**
     * @brief Converts the Admin object to a JSON object.
     *
     * This function serializes the Admin object into a JSON structure for storage or transmission.
     *
     * @return A nlohmann::json object representing the Admin.
     */
    nlohmann::json toJson() const;

    /**
     * @brief Loads the Admin object from a JSON object.
     *
     * This function deserializes the Admin object from a JSON structure.
     *
     * @param data A nlohmann::json object containing the admin data.
     */
    void fromJson(const nlohmann::json& data);
};

#endif // ADMIN_H
