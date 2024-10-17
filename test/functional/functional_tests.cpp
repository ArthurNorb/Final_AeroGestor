#include <iostream>
#include <cassert> // Include the assert library
#include "../../src/model/authSystem.h"

using namespace std;

/**
 * @brief Function to load users from JSON and test login functionality.
 *
 * This function loads the user credentials from a JSON file and attempts to log in
 * using valid credentials for an administrator.
 */
void testLoginWithValidCredentials() {
    AuthSystem auth;

    // Load users from the JSON file
    auth.loadUsersFromJson("C:/Users/Arthur/OneDrive/Documentos/AeroGestor/database/database.json");

    // Attempt to authenticate the administrator with valid credentials
    string username = "admin";
    string password = "admin123";
    auto user = auth.login(username, password);

    // Check if the login was successful
    assert(user != nullptr); // The user should not be null
    assert(user->getUsername() == username); // The username should be "admin"
    assert(user->getRole() == "Admin"); // The role of the user should be "Admin"

    // If all assertions pass, the login was successful
    cout << "Login successful!" << endl;
    cout << "User: " << user->getUsername() << ", Role: " << user->getRole() << endl;
}

/**
 * @brief Main function to run the test.
 *
 * This function calls the testLoginWithValidCredentials function
 * to verify if the login functionality works as expected.
 *
 * @return int Status code of the execution.
 */
int main() {
    // Call the test function
    testLoginWithValidCredentials();

    cout << "Functional test completed successfully!" << endl;
    return 0;
}
