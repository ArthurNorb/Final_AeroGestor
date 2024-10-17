#include "mechanic_interface.h"
#include <QMessageBox>


MecanicoInterface::MecanicoInterface(Mechanic& mec, std::vector<Aeronave>& frota, std::vector<Aeronave>& frotaEmManutencao, QWidget* parent)
    : QWidget(parent), mecanico(mec), frota(frota), frotaEmManutencao(frotaEmManutencao) {

    // Criando os componentes da interface
    comboBoxAeronaves = new QComboBox(this);
    buttonMarcarPronta = new QPushButton("Marcar como Pronta", this);
    labelStatus = new QLabel("Selecione uma aeronave para marcar como pronta", this);
    buttonVoltar = new QPushButton("Voltar", this);

    // Populando o ComboBox com as aeronaves que estão em manutenção
    for (const auto& aeronave : frotaEmManutencao) {
        comboBoxAeronaves->addItem(QString::fromStdString(aeronave.getId()));
    }

    // Criando layout
    QVBoxLayout* mainLayout = new QVBoxLayout(this);
    mainLayout->addWidget(comboBoxAeronaves);
    mainLayout->addWidget(buttonMarcarPronta);
    mainLayout->addWidget(labelStatus);
    mainLayout->addWidget(buttonVoltar);

    // Conectar sinais e slots
    connect(buttonMarcarPronta, &QPushButton::clicked, this, &MecanicoInterface::marcarPronta);
    connect(buttonVoltar, &QPushButton::clicked, this, &MecanicoInterface::voltar);

    setLayout(mainLayout);
    loadFrotaFromJson("C:/Users/Arthur/OneDrive/Documentos/AeroGestor/database/database.json");
}

void MecanicoInterface::marcarPronta() {
    QString matricula = comboBoxAeronaves->currentText();
    for (auto it = frotaEmManutencao.begin(); it != frotaEmManutencao.end(); ++it) {
        if (it->getId() == matricula.toStdString()) {
            mecanico.marcarPronta(*it);
            frota.push_back(*it);  // Voltar para a frota principal
            frotaEmManutencao.erase(it);  // Remover da lista de manutenção
            comboBoxAeronaves->removeItem(comboBoxAeronaves->currentIndex());  // Remover do combo
            QMessageBox::information(this, "Sucesso", "Aeronave marcada como pronta.");
            return;
        }
    }
}


void MecanicoInterface::voltar() {
    emit voltarParaLogin();  // Emitir o sinal para voltar à tela de login
}

