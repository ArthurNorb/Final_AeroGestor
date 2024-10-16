#ifndef USER_H
#define USER_H

#include <string>

/**
 * @brief The User class represents a base user in the system.
 *
 * This class provides the foundational attributes and methods for all user types,
 * including username and password management. It serves as an abstract base class
 * for specific user roles such as Admin, Mechanic, and Manager.
 */
class User {
protected:
    std::string username;  /**< The username of the user */
    std::string password;  /**< The password of the user */

public:
    /**
     * @brief Constructs a User object.
     *
     * @param username The username of the user.
     * @param password The password of the user.
     */
    User(const std::string& username, const std::string& password)
        : username(username), password(password) {}

    /**
     * @brief Virtual destructor for the User class.
     */
    virtual ~User() = default;

    /**
     * @brief Gets the username of the user.
     *
     * @return The username as a string.
     */
    std::string getUsername() const {
        return username;
    }

    /**
     * @brief Checks if the provided password matches the user's password.
     *
     * @param pass The password to check.
     * @return True if the passwords match, false otherwise.
     */
    bool checkPassword(const std::string& pass) const {
        return pass == password;
    }

    /**
     * @brief Gets the role of the user.
     *
     * This is a pure virtual function that must be overridden by derived classes.
     *
     * @return The role of the user as a string.
     */
    virtual std::string getRole() const = 0;  // Pure virtual method for user role
};

#endif // USER_H
