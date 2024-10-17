#ifndef MANAGER_H
#define MANAGER_H

#include "user.h"
#include "aeronave.h"
#include "../../include/json.hpp"

/**
 * @brief The Manager class represents a fleet manager in the system.
 *
 * This class allows the manager to manage aircraft operations, including sending
 * aircraft for maintenance. It inherits from the User class.
 */
class Manager : public User {
public:
    /**
     * @brief Constructs a Manager object.
     *
     * @param username The username for the manager.
     * @param password The password for the manager.
     */
    Manager(const std::string& username, const std::string& password);

    /**
     * @brief Gets the role of the user.
     *
     * @return The role of the user as a string.
     */
    std::string getRole() const override;

    /**
     * @brief Sends an aircraft for maintenance.
     *
     * This function updates the aircraft's status to indicate that it is
     * under maintenance.
     *
     * @param aeronave The aircraft to be sent for maintenance.
     */
    void enviarParaManutencao(Aeronave& aeronave) const;

    /**
     * @brief Converts the Manager object to a JSON object.
     *
     * This function serializes the Manager object into a JSON structure for storage or transmission.
     *
     * @return A nlohmann::json object representing the Manager.
     */
    nlohmann::json toJson() const;

    /**
     * @brief Loads the Manager object from a JSON object.
     *
     * This function deserializes the Manager object from a JSON structure.
     *
     * @param data A nlohmann::json object containing the Manager data.
     */
    void fromJson(const nlohmann::json& data);
};

#endif // MANAGER_H
