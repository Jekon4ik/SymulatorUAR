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
    ui->addressEdit->setEnabled(0);
    ui->addressEdit->clear();
    ui->addressEdit->setText("127.0.0.1");
}


void DialogNetwork::on_clientRadio_clicked()
{
    mode = NetworkMode::Client;
    ui->serverRadio->setChecked(0);
    ui->addressEdit->setEnabled(1);
}


void DialogNetwork::on_cancelButton_clicked()
{
    reject();
}


void DialogNetwork::on_pushButton_clicked()
{
    QString ip = ui->addressEdit->text();
    QString portStr = ui->portEdit->text();
    QStringList octets = ip.split('.');
    if (octets.size() != 4)
    {
        QMessageBox::warning(this, "Error", "This is not an ip address");
        return;
    }
    int lastOctet = octets[3].toInt();
    if (lastOctet == 0 || lastOctet == 255)
    {
        QMessageBox::warning(this, "Error", "Cannot use network or broadcast address");
        return;
    }
    int port = portStr.toInt();
    if (port < 1 || port > 65535)
    {
        QMessageBox::warning(this, "Error", "Wrong port number");
        return;
    }

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

