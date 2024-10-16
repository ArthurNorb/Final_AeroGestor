#include "manager_interface.h"
#include <QMessageBox>

GestorInterface::GestorInterface(Manager& gest, std::vector<Aeronave>& frota, std::vector<Aeronave>& frotaEmManutencao, QWidget* parent)
    : QWidget(parent), gestor(gest), frota(frota), frotaEmManutencao(frotaEmManutencao) {

    // Criando os componentes da interface
    comboBoxAeronaves = new QComboBox(this);
    buttonEnviarManutencao = new QPushButton("Enviar para Manutenção", this);
    labelStatus = new QLabel("Selecione uma aeronave para enviar para manutenção", this);
    buttonVoltar = new QPushButton("Voltar", this);

    // Populando o ComboBox com as aeronaves
    for (const auto& aeronave : frota) {
        comboBoxAeronaves->addItem(QString::fromStdString(aeronave.getMatricula()));
    }

    // Criando layout
    QVBoxLayout* mainLayout = new QVBoxLayout(this);
    mainLayout->addWidget(comboBoxAeronaves);
    mainLayout->addWidget(buttonEnviarManutencao);
    mainLayout->addWidget(labelStatus);
    mainLayout->addWidget(buttonVoltar);

    // Conectar sinais e slots
    connect(buttonEnviarManutencao, &QPushButton::clicked, this, &GestorInterface::enviarParaManutencao);
    connect(buttonVoltar, &QPushButton::clicked, this, &GestorInterface::voltar);

    setLayout(mainLayout);
}

void GestorInterface::enviarParaManutencao() {
    QString matricula = comboBoxAeronaves->currentText();
    for (auto it = frota.begin(); it != frota.end(); ++it) {
        if (it->getMatricula() == matricula.toStdString()) {
            gestor.enviarParaManutencao(*it);  // Mover para manutenção
            frotaEmManutencao.push_back(*it);  // Adiciona à frota em manutenção
            frota.erase(it);  // Remove da frota principal
            comboBoxAeronaves->removeItem(comboBoxAeronaves->currentIndex());  // Remove do combo
            QMessageBox::information(this, "Sucesso", "Aeronave enviada para manutenção.");
            return;
        }
    }
}


void GestorInterface::voltar() {
    emit voltarParaLogin();  // Emitir o sinal para voltar à tela de login
}

