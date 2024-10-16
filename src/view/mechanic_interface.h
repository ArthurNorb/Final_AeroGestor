#ifndef MECANICO_INTERFACE_H
#define MECANICO_INTERFACE_H

#include <QWidget>
#include <QComboBox>
#include <QPushButton>
#include <QLabel>
#include <QVBoxLayout>
#include "../model/mechanic.h"
#include "../model/aeronave.h"

class MecanicoInterface : public QWidget {
    Q_OBJECT

private:
    Mechanic mecanico;
    std::vector<Aeronave>& frota;  // Frota principal por referência
    std::vector<Aeronave>& frotaEmManutencao;  // Frota em manutenção por referência
    QComboBox* comboBoxAeronaves;
    QPushButton* buttonMarcarPronta;
    QLabel* labelStatus;
    QPushButton* buttonVoltar;

public:
    explicit MecanicoInterface(Mechanic& mecanico, std::vector<Aeronave>& frota, std::vector<Aeronave>& frotaEmManutencao, QWidget* parent = nullptr);

signals:
    void voltarParaLogin();

private slots:
    void marcarPronta();
    void voltar();
};

#endif // MECANICO_INTERFACE_H
