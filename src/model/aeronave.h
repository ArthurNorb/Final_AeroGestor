#ifndef AERONAVE_H
#define AERONAVE_H

#include <string>
#include <vector>

/**
 * @brief The Aeronave class represents an aircraft in the system.
 *
 * This class manages the details of an aircraft, including its registration,
 * model, maintenance status, and maintenance history.
 */
class Aeronave {
private:
    std::string matricula;              /**< Aircraft registration code */
    std::string modelo;                 /**< Aircraft model */
    bool emManutencao;                  /**< Whether the aircraft is under maintenance */
    bool prontaParaUso;                 /**< Whether the aircraft is ready for use */
    std::vector<std::string> historicoManutencao; /**< Maintenance history records */

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
    std::string getMatricula() const;

    /**
     * @brief Sets the registration code of the aircraft.
     *
     * @param matricula The new registration code.
     */
    void setMatricula(const std::string& matricula);

    /**
     * @brief Gets the model of the aircraft.
     *
     * @return The model as a string.
     */
    std::string getModelo() const;

    /**
     * @brief Sets the model of the aircraft.
     *
     * @param modelo The new model.
     */
    void setModelo(const std::string& modelo);

    /**
     * @brief Checks if the aircraft is under maintenance.
     *
     * @return True if the aircraft is under maintenance, false otherwise.
     */
    bool estaEmManutencao() const;

    /**
     * @brief Sets the maintenance status of the aircraft.
     *
     * @param status The new maintenance status (true for in maintenance, false for not).
     */
    void setEmManutencao(bool status);

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
};

#endif // AERONAVE_H
