#ifndef AERONAVE_H
#define AERONAVE_H

#include <string>
#include <vector>
#include "../../include/json.hpp"
#include <fstream>
#include <iostream>

using namespace std;

/**
 * @brief The Aeronave class represents an aircraft in the system.
 *
 * This class manages the details of an aircraft, including its registration,
 * model, maintenance status, and maintenance history.
 */
class Aeronave {
private:
    std::string id;              /**< Aircraft registration code */
    std::string model;                 /**< Aircraft model */
    bool maintence;                  /**< Whether the aircraft is under maintenance */
    bool prontaParaUso;                 /**< Whether the aircraft is ready for use */
    std::vector<std::string> historicoManutencao;    /**< Maintenance history records */

public:
    /**
     * @brief Constructs an Aeronave object.
     *
     * @param matricula The registration code of the aircraft.
     * @param modelo The model of the aircraft.
     */
    Aeronave(const std::string& matricula, const std::string& modelo);

    /**
     * @brief Gets the registration code of the aircraft.
     *
     * @return The registration code as a string.
     */
    std::string getId() const;

    /**
     * @brief Sets the registration code of the aircraft.
     *
     * @param Id The new registration code.
     */
    void setId(const std::string& id);

    /**
     * @brief Gets the model of the aircraft.
     *
     * @return The model as a string.
     */
    std::string getModel() const;

    /**
     * @brief Sets the model of the aircraft.
     *
     * @param modelo The new model.
     */
    void setModel(const std::string& modelo);

    /**
     * @brief Checks if the aircraft is under maintenance.
     *
     * @return True if the aircraft is under maintenance, false otherwise.
     */
    bool getMaintence() const;

    /**
     * @brief Sets the maintenance status of the aircraft.
     *
     * @param status The new maintenance status (true for in maintenance, false for not).
     */
    void setMaintence(bool status);

    /**
     * @brief Checks if the aircraft is ready for use.
     *
     * @return True if the aircraft is ready for use, false otherwise.
     */
    bool estaProntaParaUso() const;

    /**
     * @brief Sets the status of whether the aircraft is ready for use.
     *
     * @param status The new status (true for ready, false for not).
     */
    void setProntaParaUso(bool status);

    /**
     * @brief Registers a maintenance activity for the aircraft.
     *
     * @param detalhes Details of the maintenance performed.
     */
    void registrarManutencao(const std::string& detalhes);

    /**
     * @brief Displays the maintenance history of the aircraft.
     */
    void exibirHistorico() const;

    /**
     * @brief Converts the Aircraft object to a JSON object.
     *
     * This function serializes the Aircraft object into a JSON structure for storage or transmission.
     *
     * @return A nlohmann::json object representing the Aircraft.
     */
    nlohmann::json toJson() const;

    /**
     * @brief Loads the Aircraft object from a JSON object.
     *
     * This function deserializes the Aircraft object from a JSON structure.
     *
     * @param data A nlohmann::json object containing the Aircraft data.
     */
    void fromJson(const nlohmann::json& data);
    void static saveFrotaToJson(const std::string& filePath, const std::vector<Aeronave>& frota){
        nlohmann::json data;
        data["aeronaves"] = nlohmann::json::array();

        // Preencher o JSON com os dados das aeronaves
        for (const auto& aeronave : frota) {
            data["aeronaves"].push_back({
                {"id", aeronave.getId()},
                {"modelo", aeronave.getModel()},
                {"maintence", aeronave.getMaintence()}  // Caso tenha o status da aeronave
            });
        }

        // Escrever o JSON no arquivo
        std::ofstream file(filePath);
        if (file.is_open()) {
            file << data.dump(4);  // Salvar o JSON com indentação de 4 espaços
            file.close();
        } else {
            std::cerr << "Erro ao abrir o arquivo " << filePath << std::endl;
        }
    }
};

#endif // AERONAVE_H
