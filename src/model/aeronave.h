#ifndef AERONAVE_H
#define AERONAVE_H

#include <string>
#include <vector>

class Aeronave {
private:
    std::string matricula;
    std::string modelo;
    bool emManutencao;
    bool prontaParaUso;
    std::vector<std::string> historicoManutencao;

public:
    // Construtor
    Aeronave(const std::string& matricula, const std::string& modelo);

    // Getters e Setters
    std::string getMatricula() const;
    void setMatricula(const std::string& matricula);

    std::string getModelo() const;
    void setModelo(const std::string& modelo);

    bool estaEmManutencao() const;
    void setEmManutencao(bool status);

    bool estaProntaParaUso() const;
    void setProntaParaUso(bool status);

    // Histórico de manutenção
    void registrarManutencao(const std::string& detalhes);
    void exibirHistorico() const;
};

#endif // AERONAVE_H

