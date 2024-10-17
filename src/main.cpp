#include <QApplication>
#include "../src/view/loginWindow.h"
#include "../src/view/mechanic_interface.h"
#include "../src/view/manager_interface.h"
#include "../src/view/admin_interface.h"
#include "../src/model/authSystem.h"
#include "../src/model/admin.h"
#include "../src/model/manager.h"
#include "../src/model/mechanic.h"
#include "../src/model/aeronave.h"
#include "../src/model/user.h"

using namespace std;

vector<Aeronave> frota;            // Frota geral
vector<Aeronave> frotaEmManutencao; // Frota em manutenção

void showLoginWindow(AuthSystem& authSystem);

void showUserInterface(std::shared_ptr<User> user, AuthSystem& authSystem);

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    AuthSystem auth;

    // Simulação inicial da frota de aeronaves
    frota.push_back(Aeronave("AERO123", "Boeing 737"));
    frota.push_back(Aeronave("AERO456", "Airbus A320"));

    // Exibir a tela de login
    showLoginWindow(auth);

    return app.exec();  // Chamar o loop de eventos
}

void showLoginWindow(AuthSystem& authSystem) {
    LoginWindow* loginWindow = new LoginWindow(authSystem);
    loginWindow->setWindowTitle("Login");

    // Captura manual de loginWindow e authSystem
    QObject::connect(loginWindow, &LoginWindow::loginSuccess, [loginWindow, &authSystem](std::shared_ptr<User> user) mutable {
        loginWindow->close();  // Fechar a janela de login
        showUserInterface(user, authSystem);  // Exibir a interface correta
    });

    loginWindow->show();
}

void showUserInterface(std::shared_ptr<User> user, AuthSystem& authSystem) {
    if (user->getRole() == "Admin") {
        Admin* admin = new Admin(user->getUsername(), "admin123");
        AdministradorInterface* adminInterface = new AdministradorInterface(*admin, frota);
        adminInterface->setWindowTitle("Administrador");
        adminInterface->resize(400, 200);
        adminInterface->show();

        // Captura manual de adminInterface e authSystem
        QObject::connect(adminInterface, &AdministradorInterface::voltarParaLogin, [adminInterface, &authSystem]() {
            adminInterface->close();  // Fechar a janela do Admin
            showLoginWindow(authSystem);  // Reabrir a tela de login
        });

    } else if (user->getRole() == "Manager") {
        Manager* manager = new Manager(user->getUsername(), "manager123");
        GestorInterface* gestorInterface = new GestorInterface(*manager, frota, frotaEmManutencao);
        gestorInterface->setWindowTitle("Gestor");
        gestorInterface->resize(400, 200);
        gestorInterface->show();

        // Captura manual de gestorInterface e authSystem
        QObject::connect(gestorInterface, &GestorInterface::voltarParaLogin, [gestorInterface, &authSystem]() {
            gestorInterface->close();  // Fechar a janela do Gestor
            showLoginWindow(authSystem);  // Reabrir a tela de login
        });

    } else if (user->getRole() == "Mechanic") {
        Mechanic* mechanic = new Mechanic(user->getUsername(), "mech123");
        MecanicoInterface* mecanicoInterface = new MecanicoInterface(*mechanic, frota, frotaEmManutencao);
        mecanicoInterface->setWindowTitle("Mecânico");
        mecanicoInterface->resize(400, 200);
        mecanicoInterface->show();

        // Captura manual de mecanicoInterface e authSystem
        QObject::connect(mecanicoInterface, &MecanicoInterface::voltarParaLogin, [mecanicoInterface, &authSystem]() {
            mecanicoInterface->close();  // Fechar a janela do Mecânico
            showLoginWindow(authSystem);  // Reabrir a tela de login
        });
    }
}
