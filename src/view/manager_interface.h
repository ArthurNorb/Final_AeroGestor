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

class GestorInterface : public QWidget {
    Q_OBJECT

private:
    Manager gestor;
    std::vector<Aeronave>& frota;  // Adicionar frota por referência
    std::vector<Aeronave>& frotaEmManutencao;  // Adicionar frota em manutenção por referência
    QComboBox* comboBoxAeronaves;
    QPushButton* buttonEnviarManutencao;
    QLabel* labelStatus;
    QPushButton* buttonVoltar;

public:
    explicit GestorInterface(Manager& gestor, std::vector<Aeronave>& frota, std::vector<Aeronave>& frotaEmManutencao, QWidget* parent = nullptr);

signals:
    void voltarParaLogin();

private slots:
    void enviarParaManutencao();
    void voltar();
};

#endif // GESTOR_INTERFACE_H
