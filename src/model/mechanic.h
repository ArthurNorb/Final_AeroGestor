#ifndef MECHANIC_H
#define MECHANIC_H

#include "user.h"
#include "aeronave.h"
#include "../../include/json.hpp"

/**
 * @brief The Mechanic class represents a mechanic in the system.
 *
 * This class allows the mechanic to perform maintenance operations on aircraft,
 * including checking their status and marking them as ready for use. It inherits from the User class.
 */
class Mechanic : public User {
public:
    /**
     * @brief Constructs a Mechanic object.
     *
     * @param username The username for the mechanic.
     * @param password The password for the mechanic.
     */
    Mechanic(const std::string& username, const std::string& password);

    /**
     * @brief Gets the role of the user.
     *
     * This method overrides the getRole method from the User base class.
     *
     * @return The role of the user as a string.
     */
    std::string getRole() const override;

    /**
     * @brief Checks the status of an aircraft.
     *
     * This method allows the mechanic to verify the condition of the specified aircraft.
     *
     * @param aeronave The aircraft to be checked.
     */
    void verificarAeronave(Aeronave& aeronave) const;

    /**
     * @brief Marks an aircraft as ready for use.
     *
     * This method updates the aircraft's status to indicate that it is ready for
     * operational use after maintenance.
     *
     * @param aeronave The aircraft to be marked as ready.
     */
    void marcarPronta(Aeronave& aeronave) const;

    /**
     * @brief Converts the Mechanic object to a JSON object.
     *
     * This function serializes the Mechanic object into a JSON structure for storage or transmission.
     *
     * @return A nlohmann::json object representing the Mechanic.
     */
    nlohmann::json toJson() const;

    /**
     * @brief Loads the Mechanic object from a JSON object.
     *
     * This function deserializes the Mechanic object from a JSON structure.
     *
     * @param data A nlohmann::json object containing the Mechanic data.
     */
    void fromJson(const nlohmann::json& data);
};

#endif // MECHANIC_H
