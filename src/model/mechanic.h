#ifndef MECHANIC_H
#define MECHANIC_H

#include "user.h"
#include "aeronave.h"

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
};

#endif // MECHANIC_H
