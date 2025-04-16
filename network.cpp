#include "network.h"

Network::Network(QObject *parent)
    : QObject{parent}
{

}

void Network::startAsServer(int port)
{
    if(server)
    {
        server->close();
        server->deleteLater();
        server = nullptr;
    }
    server = new QTcpServer();
    connect(server,&QTcpServer::newConnection,this,&Network::onNewConnection);
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
    this->host = host;
    this->port = port;
    if(socket)
    {
        socket->disconnectFromHost();
        socket->deleteLater();
        socket = nullptr;
    }
    socket = new QTcpSocket(this);
    connect(socket, &QTcpSocket::connected, this, &Network::onConnected);
    connect(socket, &QTcpSocket::disconnected, this, &Network::onDisconnected);
    socket->connectToHost(host, port);
    updateStatus("[Client] Connecting to" + host + ":" + QString::number(port));
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
    }
    if(server && server->isListening())
    {
        server->close();
        updateStatus("[Server] Server Stopped");
        server->deleteLater();
        server = nullptr;
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
}

void Network::onDisconnected()
{
    if (!(server && server->isListening()))
    {
        updateStatus("[Client] Disconnected from server.");
    }
    else
    {
        updateStatus("[Server] Client disconnected. Waiting for new connection.");
    }
    if (socket)
    {
        socket->deleteLater();
        socket = nullptr;
    }
}
