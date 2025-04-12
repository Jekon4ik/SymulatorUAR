#include "connectiondialog.h"
#include "ui_connectiondialog.h"

ConnectionDialog::ConnectionDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ConnectionDialog)
{
    ui->setupUi(this);
    connect(ui->serverButton, &QPushButton::clicked, this, [=]() {
        mode = ServerMode;
        accept();
    });
    connect(ui->clientButton, &QPushButton::clicked, this, [=]() {
        mode = ClientMode;
        accept();
    });
}

ConnectionDialog::~ConnectionDialog() {
    delete ui;
}

ConnectionMode ConnectionDialog::selectedMode() const {
    return mode;
}
