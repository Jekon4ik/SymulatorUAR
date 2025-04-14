#include "network.h"

Network::Network(QObject *parent)
    : QObject{parent}
{
    server = new QTcpServer();
    connect(server,&QTcpServer::newConnection,this,&Network::onNewConnection);
}

void Network::startAsServer(int port)
{
    if(server->listen(QHostAddress::Any, port))
    {
        updateStatus("[Server] Listening on port " + QString::number(port));
    }
    else
    {
        updateStatus("[Server] Failed!");
    }
}

void Network::startAsClient(QString host, int port)
{
    if(socket)
    {
        socket->deleteLater();
    }
    socket = new QTcpSocket(this);
    connect(socket, &QTcpSocket::connected, this, &Network::onConnected);
    connect(socket, &QTcpSocket::disconnected, this, &Network::onDisconnected);
    if(!reconnect)
    {
        reconnect = new QTimer();
        reconnect->setInterval(1000);
        connect(reconnect, &QTimer::timeout, this, [this, host, port]() {
            if (socket && socket->state() == QAbstractSocket::UnconnectedState) {
                updateStatus("[Client] Connecting to" + host + " " + QString::number(port));
                socket->connectToHost(host, port);
            }
        });
    }
    reconnect->start();
    socket->connectToHost(host, port);
    updateStatus("[Client] Connecting to" + host + " " + QString::number(port));
}

void Network::onNewConnection()
{
    socket = server->nextPendingConnection();
    if(socket)
    {
        connect(socket, &QTcpSocket::disconnected, this, &Network::onDisconnected);
        updateStatus("[Server] Client connected!");
    }
    else
    {
    updateStatus("[Server] Failed to attempt connection!");
    }
}

void Network::disconnect()
{
    if(socket)
    {
        socket->disconnectFromHost();
        socket->deleteLater();
        socket = nullptr;
    }
    if(server && server->isListening())
    {
        server->close();
        updateStatus("[Server] Server Stopped");
    }
}

void Network::setStatus(QLineEdit* lineEdit)
{
    status = lineEdit;
}

void Network::updateStatus(const QString &message)
{
    if (status)
    {
        status->setText(message);
    }
}

void Network::onConnected()
{
    updateStatus("[Client] Connected successfully!");
    if (reconnect)
    {
        reconnect->stop();
    }
}

void Network::onDisconnected()
{
    updateStatus("[Network] Client disconnected");
    if (reconnect)
    {
        reconnect->stop();
    }
}

