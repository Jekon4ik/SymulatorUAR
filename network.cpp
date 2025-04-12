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
        qDebug() << "[Server] Listening on port" << port;
    }
    else
    {
        qDebug() << "[Server] Failed!";
    }
}

void Network::startAsClient(QString host, int port)
{
    if(socket)
    {
        socket->deleteLater();
    }
    socket = new QTcpSocket(this);
    socket->connectToHost(host,port);
    qDebug() << "[Client] Connecting to " << host << ":" << port;
}

void Network::onNewConnection()
{
    socket = server->nextPendingConnection();
    qDebug() << "[Server] Connected succesfully!";
}

void Network::disconnect()
{
    if(socket)
    {
        socket->disconnectFromHost();
        qDebug() << "[Client] Disconnected";
    }
    if(server && server->isListening())
    {
        server->close();
        qDebug() << "[Server] Server Stopped";
    }
}
