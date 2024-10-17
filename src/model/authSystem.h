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
    /**
     * @brief List of registered users in the system.
     *
     * This vector contains all users (e.g., Admin, Manager, Mechanic) registered in the system.
     */
    std::vector<std::shared_ptr<User>> users;

public:
    /**
     * @brief Constructs the AuthSystem object.
     *
     * Initializes the system for managing user authentication and loading users.
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

    /**
     * @brief Loads users from a JSON file.
     *
     * This function reads the specified JSON file and loads the user information
     * into the AuthSystem. It creates User objects (Admin, Manager, Mechanic) based on the role.
     *
     * @param filePath Path to the JSON file containing user data.
     */
    void loadUsersFromJson(const std::string& filePath);

    /**
 * @brief Adds a user to the authentication system.
 *
 * This function adds a new user to the list of registered users.
 *
 * @param user A shared pointer to the User object to be added.
 */
    void addUser(std::shared_ptr<User> user);
};

#endif // AUTHSYSTEM_H
