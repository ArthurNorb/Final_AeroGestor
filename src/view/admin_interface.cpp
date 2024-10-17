#include "admin_interface.h"
#include <QMessageBox>

AdministradorInterface::AdministradorInterface(Admin& adm, std::vector<Aeronave>& frota, QWidget* parent)
    : QWidget(parent), admin(adm), frota(frota) {

    // Criando os campos para matrícula e modelo
    matriculaInput = new QLineEdit(this);
    modeloInput = new QLineEdit(this);
    matriculaInput->setPlaceholderText("Matrícula da Aeronave");
    modeloInput->setPlaceholderText("Modelo da Aeronave");

    buttonCadastrarAeronave = new QPushButton("Cadastrar Aeronave", this);
    labelStatus = new QLabel("Informe os dados da aeronave para cadastrar", this);
    buttonVoltar = new QPushButton("Voltar", this);

    // Criando layout
    QVBoxLayout* mainLayout = new QVBoxLayout(this);
    mainLayout->addWidget(matriculaInput);
    mainLayout->addWidget(modeloInput);
    mainLayout->addWidget(buttonCadastrarAeronave);
    mainLayout->addWidget(labelStatus);
    mainLayout->addWidget(buttonVoltar);

    // Conectar sinais e slots
    connect(buttonCadastrarAeronave, &QPushButton::clicked, this, &AdministradorInterface::cadastrarAeronave);
    connect(buttonVoltar, &QPushButton::clicked, this, &AdministradorInterface::voltar);

    setLayout(mainLayout);

    loadFrotaFromJson("C:/Users/Arthur/OneDrive/Documentos/AeroGestor/database/database.json");
}

void AdministradorInterface::cadastrarAeronave() {
    QString matricula = matriculaInput->text();
    QString modelo = modeloInput->text();

    if (matricula.isEmpty() || modelo.isEmpty()) {
        QMessageBox::warning(this, "Erro", "Matrícula e modelo da aeronave devem ser preenchidos.");
        return;
    }

    Aeronave novaAeronave(matricula.toStdString(), modelo.toStdString());
    admin.cadastrarAeronave(frota, novaAeronave);
    QMessageBox::information(this, "Sucesso", "Aeronave cadastrada com sucesso.");
    matriculaInput->clear();
    modeloInput->clear();
}

void AdministradorInterface::voltar() {
    emit voltarParaLogin();  // Emitir o sinal para voltar ao login
}


