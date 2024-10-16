#ifndef USER_H
#define USER_H

#include <string>

class User {
protected:
    std::string username;
    std::string password;

public:
    User(const std::string& username, const std::string& password)
        : username(username), password(password) {}

    virtual ~User() = default;

    std::string getUsername() const {
        return username;
    }

    bool checkPassword(const std::string& pass) const {
        return pass == password;
    }

    virtual std::string getRole() const = 0;  // Método virtual puro para o tipo de usuário
};

#endif // USER_H

