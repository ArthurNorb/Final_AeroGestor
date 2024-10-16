#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H

#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QLabel>
#include "../model/authSystem.h"

class LoginWindow : public QWidget {
    Q_OBJECT

private:
    QLineEdit* usernameInput;
    QLineEdit* passwordInput;
    QPushButton* loginButton;
    AuthSystem& authSystem;

public:
    explicit LoginWindow(AuthSystem& authSystem, QWidget* parent = nullptr);

signals:
    void loginSuccess(std::shared_ptr<User> user);  // Sinal emitido em caso de login bem-sucedido

private slots:
    void onLoginButtonClicked();  // Slot chamado ao clicar no botão de login
};

#endif // LOGINWINDOW_H
