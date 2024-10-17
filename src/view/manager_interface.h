#ifndef GESTOR_INTERFACE_H
#define GESTOR_INTERFACE_H

#include <QWidget>
#include <QComboBox>
#include <QPushButton>
#include <QLabel>
#include <QVBoxLayout>
#include "../model/manager.h"
#include "../model/aeronave.h"
#include <vector>
#include "../../include/json.hpp"
#include <fstream>
#include <iostream>


/**
 * @brief The GestorInterface class provides the user interface for the fleet manager role.
 *
 * This class allows the manager to send aircraft for maintenance and manage fleet operations.
 * It inherits from QWidget and utilizes Qt's signal-slot mechanism for event handling.
 */
class GestorInterface : public QWidget {
    Q_OBJECT

private:
    Manager gestor;                              /**< The manager user associated with this interface */
    std::vector<Aeronave>& frota;                /**< Reference to the fleet of aircraft */
    std::vector<Aeronave>& frotaEmManutencao;    /**< Reference to the fleet of aircraft under maintenance */
    QComboBox* comboBoxAeronaves;                /**< Combo box to select aircraft */
    QPushButton* buttonEnviarManutencao;        /**< Button to send selected aircraft for maintenance */
    QLabel* labelStatus;                         /**< Label to display status messages */
    QPushButton* buttonVoltar;                  /**< Button to return to the login screen */

public:
    /**
     * @brief Constructs the GestorInterface object.
     *
     * @param gestor The manager user associated with this interface.
     * @param frota Reference to the fleet of aircraft.
     * @param frotaEmManutencao Reference to the fleet of aircraft under maintenance.
     * @param parent The parent widget (default is nullptr).
     */
    explicit GestorInterface(Manager& gestor, std::vector<Aeronave>& frota, std::vector<Aeronave>& frotaEmManutencao, QWidget* parent = nullptr);

    /**
 * @brief Carrega a frota de aeronaves a partir de um arquivo JSON.
 *
 * @param filePath O caminho do arquivo JSON.
 */
    void loadFrotaFromJson(const std::string& filePath) {
        std::ifstream file(filePath);
        nlohmann::json data;

        if (file.is_open()) {
            file >> data;
            file.close();

            // Preencher o vetor frota com os dados das aeronaves do arquivo JSON
            for (const auto& item : data["aeronaves"]) {
                Aeronave aeronave(item["id"], item["model"]);
                if (item["maintence"] == true) {
                    frotaEmManutencao.push_back(aeronave);
                } else {
                    frota.push_back(aeronave);
                }
            }
        } else {
            std::cerr << "Erro ao abrir o arquivo " << filePath << std::endl;
        }
    }

    /**
 * @brief Salva a frota de aeronaves em um arquivo JSON.
 *
 * @param filePath O caminho do arquivo JSON onde a frota será salva.
 */
    void saveFrotaToJson(const std::string& filePath) const {
        nlohmann::json data;
        data["aeronaves"] = nlohmann::json::array();

        // Preencher o JSON com os dados das aeronaves
        for (const auto& aeronave : frota) {
            data["aeronaves"].push_back({
                {"id", aeronave.getId()},
                {"modelo", aeronave.getModel()},
                {"maintence", aeronave.getMaintence()}
            });
        }

        // Escrever o JSON no arquivo
        std::ofstream file(filePath);
        if (file.is_open()) {
            file << data.dump(4);  // Salvar o JSON com indentação de 4 espaços
            file.close();
        } else {
            std::cerr << "Erro ao salvar o arquivo " << filePath << std::endl;
        }
    }
signals:
    /**
     * @brief Signal emitted to return to the login screen.
     */
    void voltarParaLogin();  // Signal to return to the login screen

private slots:
    /**
     * @brief Slot to handle the action of sending an aircraft for maintenance.
     *
     * This method is invoked when the "Enviar Manutenção" button is clicked.
     */
    void enviarParaManutencao();

    /**
     * @brief Slot to handle the action of returning to the login screen.
     *
     * This method is invoked when the "Voltar" button is clicked.
     */
    void voltar();
};

#endif // GESTOR_INTERFACE_H
