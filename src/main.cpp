#include <QApplication>
#include <fstream>
#include "../include/json.hpp"
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
void showUserInterface(shared_ptr<User> user, AuthSystem& authSystem);

/**
 * @brief Loads the fleet of aircraft from a JSON file.
 *
 * This function reads the aircraft data from the specified JSON file and populates
 * the fleet (`frota`) and maintenance fleet (`frotaEmManutencao`) vectors with
 * the aircraft listed in the file.
 *
 * @param filePath The path to the JSON file containing the aircraft data.
 */
void loadFrotaFromJson(const string& filePath) {
    std::ifstream file(filePath);
    nlohmann::json data;

    if (file.is_open()) {
        file >> data; // Lê os dados do arquivo JSON
        file.close();

        for (const auto& item : data["aeronaves"]) {
            Aeronave aeronave(item["id"], item["modelo"]);
            aeronave.setMaintence(item["maintence"]);  // Carrega o status de manutenção
            if (aeronave.getMaintence()) {
                frotaEmManutencao.push_back(aeronave);
            } else {
                frota.push_back(aeronave);
            }
        }
    } else {
        cerr << "Erro ao abrir o arquivo " << filePath << endl;
    }
}

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    AuthSystem auth;

    auth.loadUsersFromJson("C:/Users/Arthur/OneDrive/Documentos/AeroGestor/database/database.json");
    loadFrotaFromJson("C:/Users/Arthur/OneDrive/Documentos/AeroGestor/database/database.json");

    // Exibir a tela de login
    showLoginWindow(auth);

    return app.exec();  // Chamar o loop de eventos
}

void showLoginWindow(AuthSystem& authSystem) {
    LoginWindow* loginWindow = new LoginWindow(authSystem);
    loginWindow->setWindowTitle("Login");

    // Captura manual de loginWindow e authSystem
    QObject::connect(loginWindow, &LoginWindow::loginSuccess, [loginWindow, &authSystem](shared_ptr<User> user) mutable {
        loginWindow->close();  // Fechar a janela de login
        showUserInterface(user, authSystem);  // Exibir a interface correta
    });

    loginWindow->show();
}

void showUserInterface(shared_ptr<User> user, AuthSystem& authSystem) {
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
