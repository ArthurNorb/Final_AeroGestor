#ifndef AUTHSYSTEM_H
#define AUTHSYSTEM_H

#include <vector>
#include <memory>
#include <string>
#include "user.h"
#include "admin.h"
#include "manager.h"
#include "mechanic.h"
#include "aeronave.h"

/**
 * @brief The AuthSystem class manages user authentication.
 *
 * This class provides functionality for validating user login credentials and
 * managing the list of registered users in the system.
 */
class AuthSystem {
private:
    std::vector<std::shared_ptr<User>> users;  /**< List of registered users in the system */

public:
    /**
     * @brief Constructs the AuthSystem object.
     *
     * Initializes the system for managing user authentication.
     */
    AuthSystem();

    /**
     * @brief Validates user login credentials.
     *
     * This function checks if the provided username and password match a registered user.
     *
     * @param username The username of the user attempting to log in.
     * @param password The password of the user attempting to log in.
     * @return A shared pointer to the authenticated User object if credentials are valid,
     * or nullptr if the login fails.
     */
    std::shared_ptr<User> login(const std::string& username, const std::string& password);
};

#endif // AUTHSYSTEM_H
