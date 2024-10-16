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

class AdministradorInterface : public QWidget {
    Q_OBJECT

private:
    Admin admin;
    std::vector<Aeronave>& frota;
    QLineEdit* matriculaInput;
    QLineEdit* modeloInput;
    QPushButton* buttonCadastrarAeronave;
    QLabel* labelStatus;
    QPushButton* buttonVoltar;

public:
    explicit AdministradorInterface(Admin& admin, std::vector<Aeronave>& frota, QWidget* parent = nullptr);

signals:
    void voltarParaLogin();  // Sinal para voltar à tela de login

private slots:
    void cadastrarAeronave();
    void voltar();
};

#endif // ADMINISTRADOR_INTERFACE_H
