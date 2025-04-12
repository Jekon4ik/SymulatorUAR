#include "dialogdirectnetwork.h"
#include "ui_dialogdirectnetwork.h"

DialogDirectNetwork::DialogDirectNetwork(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::DialogDirectNetwork)
{
    ui->setupUi(this);
}

DialogDirectNetwork::~DialogDirectNetwork()
{
    delete ui;
}

void DialogDirectNetwork::on_serverButton_clicked()
{
    mode = NetworkMode::Server;
    accept();
}


void DialogDirectNetwork::on_clientButton_clicked()
{
    mode = NetworkMode::Client;
    accept();
}

QString DialogDirectNetwork::getIpAddress()
{
    return ui->ipaddressEdit->text();
}

NetworkMode DialogDirectNetwork::getNetworkMode()
{
    return mode;
}

