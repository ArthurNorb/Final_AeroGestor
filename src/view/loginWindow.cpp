#include "loginwindow.h"
#include <QMessageBox>
#include <Qlabel>

LoginWindow::LoginWindow(AuthSystem& authSystem, QWidget* parent)
    : QWidget(parent), authSystem(authSystem) {

    // Criando os campos de texto e o botão de login
    usernameInput = new QLineEdit(this);
    passwordInput = new QLineEdit(this);
    passwordInput->setEchoMode(QLineEdit::Password);  // Tornar a senha oculta

    loginButton = new QPushButton("Login", this);

    // Criando o layout da interface
    QVBoxLayout* layout = new QVBoxLayout(this);
    layout->addWidget(new QLabel("Nome de Usuário:", this));
    layout->addWidget(usernameInput);
    layout->addWidget(new QLabel("Senha:", this));
    layout->addWidget(passwordInput);
    layout->addWidget(loginButton);

    // Conectar o botão de login ao slot que faz a validação
    connect(loginButton, &QPushButton::clicked, this, &LoginWindow::onLoginButtonClicked);

    setLayout(layout);
}

void LoginWindow::onLoginButtonClicked() {
    QString username = usernameInput->text(); // Obtém o nome de usuário do campo de entrada
    QString password = passwordInput->text(); // Obtém a senha do campo de entrada

    // Tenta autenticar o usuário
    auto user = authSystem.login(username.toStdString(), password.toStdString());

    if (user) {
        emit loginSuccess(user); // Emite um sinal se o login for bem-sucedido
        this->close(); // Fecha a janela de login
    } else {
        QMessageBox::warning(this, "Login Failed", "Invalid username or password."); // Exibe uma mensagem de erro
    }
}
