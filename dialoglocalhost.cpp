#include "dialoglocalhost.h"
#include "ui_dialoglocalhost.h"

DialogLocalhost::DialogLocalhost(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::DialogLocalhost)
{
    ui->setupUi(this);
}

DialogLocalhost::~DialogLocalhost()
{
    delete ui;
}

void DialogLocalhost::on_serverButton_clicked()
{
    mode = NetworkMode::Server;
    accept();
}


void DialogLocalhost::on_clientButton_clicked()
{
    mode = NetworkMode::Client;
    accept();
}

NetworkMode DialogLocalhost::getNetworkMode()
{
    return mode;
}

