#ifndef ADMINISTRADOR_INTERFACE_H
#define ADMINISTRADOR_INTERFACE_H

#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QLabel>
#include <QVBoxLayout>
#include "../model/admin.h"
#include "../model/aeronave.h"
#include <vector>

/**
 * @brief The AdministradorInterface class provides the user interface for the admin role.
 *
 * This class allows the admin to register new aircraft and manage fleet operations.
 * It inherits from QWidget and utilizes Qt's signal-slot mechanism for event handling.
 */
class AdministradorInterface : public QWidget {
    Q_OBJECT

private:
    Admin admin;                          /**< The admin user associated with this interface */
    std::vector<Aeronave>& frota;         /**< Reference to the fleet of aircraft */
    QLineEdit* matriculaInput;            /**< Input field for the aircraft registration code */
    QLineEdit* modeloInput;               /**< Input field for the aircraft model */
    QPushButton* buttonCadastrarAeronave; /**< Button to register a new aircraft */
    QLabel* labelStatus;                   /**< Label to display status messages */
    QPushButton* buttonVoltar;            /**< Button to return to the login screen */

public:
    /**
     * @brief Constructs the AdministradorInterface object.
     *
     * @param admin The admin user associated with this interface.
     * @param frota Reference to the fleet of aircraft.
     * @param parent The parent widget (default is nullptr).
     */
    explicit AdministradorInterface(Admin& admin, std::vector<Aeronave>& frota, QWidget* parent = nullptr);

signals:
    /**
     * @brief Signal emitted to return to the login screen.
     */
    void voltarParaLogin();  // Signal to return to the login screen

private slots:
    /**
     * @brief Slot to handle the action of registering a new aircraft.
     *
     * This method is invoked when the "Cadastrar Aeronave" button is clicked.
     */
    void cadastrarAeronave();

    /**
     * @brief Slot to handle the action of returning to the login screen.
     *
     * This method is invoked when the "Voltar" button is clicked.
     */
    void voltar();
};

#endif // ADMINISTRADOR_INTERFACE_H
