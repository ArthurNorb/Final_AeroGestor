#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H

#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QLabel>
#include "../model/authSystem.h"
#include "../../include/json.hpp"
#include <fstream>
#include <iostream>

/**
 * @brief The LoginWindow class represents the login interface for the application.
 *
 * This class allows users to enter their credentials to authenticate and access the system.
 * It inherits from QWidget and utilizes Qt's signal-slot mechanism for event handling.
 */
class LoginWindow : public QWidget {
    Q_OBJECT

private:
    QLineEdit* usernameInput;  /**< Input field for the username */
    QLineEdit* passwordInput;  /**< Input field for the password */
    QPushButton* loginButton;   /**< Button to initiate the login process */
    AuthSystem& authSystem;     /**< Reference to the authentication system */

public:
    /**
     * @brief Constructs the LoginWindow object.
     *
     * @param authSystem Reference to the authentication system used for login.
     * @param parent The parent widget (default is nullptr).
     */
    explicit LoginWindow(AuthSystem& authSystem, QWidget* parent = nullptr);

    /**
 * @brief Loads users from a JSON file for the authentication system.
 *
 * This function populates the authentication system with users loaded from the specified JSON file.
 *
 * @param filePath The path to the JSON file containing user data.
 */
    void loadUsersFromJson(const std::string& filePath) {
        std::ifstream file(filePath);
        nlohmann::json data;

        if (file.is_open()) {
            file >> data; // Lê os dados do arquivo JSON
            file.close();

            // Preenche o sistema de autenticação com os dados dos usuários
            for (const auto& item : data["users"]) {
                std::string role = item["role"];
                if (role == "Admin") {
                    authSystem.addUser(std::make_shared<Admin>(item["username"], item["password"]));
                } else if (role == "Manager") {
                    authSystem.addUser(std::make_shared<Manager>(item["username"], item["password"]));
                } else if (role == "Mechanic") {
                    authSystem.addUser(std::make_shared<Mechanic>(item["username"], item["password"]));
                }
            }
        } else {
            std::cerr << "Erro ao abrir o arquivo " << filePath << std::endl;
        }
    }

signals:
    /**
     * @brief Signal emitted upon successful login.
     *
     * This signal carries the authenticated user object.
     */
    void loginSuccess(std::shared_ptr<User> user);  // Signal emitted on successful login

private slots:
    /**
     * @brief Slot called when the login button is clicked.
     *
     * This method handles the authentication process by verifying the entered credentials.
     */
    void onLoginButtonClicked();  // Slot called on login button click
};

#endif // LOGINWINDOW_H
