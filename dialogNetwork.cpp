#include "dialogNetwork.h"
#include "ui_dialogNetwork.h"

DialogNetwork::DialogNetwork(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::DialogNetwork)
{
    ui->setupUi(this);
}

DialogNetwork::~DialogNetwork()
{
    delete ui;
}

NetworkMode DialogNetwork::getNetworkMode()
{
    return mode;
}


void DialogNetwork::on_serverRadio_clicked()
{
    mode = NetworkMode::Server;
    ui->clientRadio->setChecked(0);
}


void DialogNetwork::on_clientRadio_clicked()
{
    mode = NetworkMode::Client;
    ui->serverRadio->setChecked(0);
}


void DialogNetwork::on_cancelButton_clicked()
{
    reject();
}


void DialogNetwork::on_pushButton_clicked()
{
    accept();
}

QString DialogNetwork::getAddress()
{
    return ui->addressEdit->text();
}

int DialogNetwork::getPort()
{
    return ui->portEdit->text().toInt();
}

