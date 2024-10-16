#ifndef MECANICO_INTERFACE_H
#define MECANICO_INTERFACE_H

#include <QWidget>
#include <QComboBox>
#include <QPushButton>
#include <QLabel>
#include <QVBoxLayout>
#include "../model/mechanic.h"
#include "../model/aeronave.h"

/**
 * @brief The MecanicoInterface class provides the user interface for the mechanic role.
 *
 * This class allows the mechanic to mark aircraft as ready after maintenance and manage
 * the fleet operations. It inherits from QWidget and utilizes Qt's signal-slot mechanism
 * for event handling.
 */
class MecanicoInterface : public QWidget {
    Q_OBJECT

private:
    Mechanic mecanico;                             /**< The mechanic user associated with this interface */
    std::vector<Aeronave>& frota;                  /**< Reference to the main fleet of aircraft */
    std::vector<Aeronave>& frotaEmManutencao;      /**< Reference to the fleet of aircraft under maintenance */
    QComboBox* comboBoxAeronaves;                  /**< Combo box to select aircraft */
    QPushButton* buttonMarcarPronta;               /**< Button to mark selected aircraft as ready */
    QLabel* labelStatus;                           /**< Label to display status messages */
    QPushButton* buttonVoltar;                     /**< Button to return to the login screen */

public:
    /**
     * @brief Constructs the MecanicoInterface object.
     *
     * @param mecanico The mechanic user associated with this interface.
     * @param frota Reference to the main fleet of aircraft.
     * @param frotaEmManutencao Reference to the fleet of aircraft under maintenance.
     * @param parent The parent widget (default is nullptr).
     */
    explicit MecanicoInterface(Mechanic& mecanico, std::vector<Aeronave>& frota, std::vector<Aeronave>& frotaEmManutencao, QWidget* parent = nullptr);

signals:
    /**
     * @brief Signal emitted to return to the login screen.
     */
    void voltarParaLogin();  // Signal to return to the login screen

private slots:
    /**
     * @brief Slot to handle the action of marking an aircraft as ready.
     *
     * This method is invoked when the "Marcar Pronta" button is clicked.
     */
    void marcarPronta();

    /**
     * @brief Slot to handle the action of returning to the login screen.
     *
     * This method is invoked when the "Voltar" button is clicked.
     */
    void voltar();
};

#endif // MECANICO_INTERFACE_H
