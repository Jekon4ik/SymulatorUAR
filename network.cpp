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
    connect(socket,&QTcpSocket::readyRead,this,&Network::onDataReady);
    connect(socket, &QAbstractSocket::errorOccurred,this, &Network::onDisconnected);
    socket->connectToHost(host, port);
    updateStatus("[Client] Connecting to" + host + ":" + QString::number(port));
}

void Network::onNewConnection()
{
    socket = server->nextPendingConnection();
    if(socket)
    {
        connect(socket, &QTcpSocket::disconnected, this, &Network::onDisconnected);
        connect(socket,&QTcpSocket::readyRead,this,&Network::onDataReady);
        connect(socket, &QAbstractSocket::errorOccurred,this, &Network::onDisconnected);
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

void Network::sendControlledValue(double value, double time, double gen)
{
    qDebug() << "Send controlled value";
    if (socket && socket->state() == QAbstractSocket::ConnectedState) {
        QJsonObject pkt;
        pkt["controlValue"] = value;
        pkt["time"] = time;
        pkt["setpoint"] = gen;
        QByteArray out = QJsonDocument(pkt).toJson(QJsonDocument::Compact) + '\n';
        socket->write(out);
        socket->flush();
        updateStatus("Control sent: " + QString::number(value) + "Time sent: " + QString::number(time) + "Setpoint sent: " + QString::number(gen));
    }
}

void Network::onDataReady()
{
    while (socket && socket->canReadLine()) {
        QByteArray line = socket->readLine().trimmed();
        QJsonParseError err;
        QJsonDocument doc = QJsonDocument::fromJson(line, &err);
        if (err.error != QJsonParseError::NoError || !doc.isObject()) {
            updateStatus("JSON parse error: " + err.errorString());
            continue;
        }
        QJsonObject obj = doc.object();
        if (obj.contains("controlValue")) {
            double u = obj["controlValue"].toDouble();
            double time = obj["time"].toDouble();
            double gen = obj["setpoint"].toDouble();
            updateStatus("Control received: " + QString::number(u) + "Time received: " + QString::number(time) + "Setpoint received: " + QString::number(gen));
            emit controlValueReceived(u, time, gen);
        }
        else if (obj.contains("measuredValue")) {
            double y = obj["measuredValue"].toDouble();
            updateStatus("Measured received: " + QString::number(y));
            emit measuredValueReceived(y);
        }
    }
}

void Network::sendMeasuredValue(double value)
{
    qDebug() << "Send measured value";
    if (socket && socket->state() == QAbstractSocket::ConnectedState) {
        QJsonObject pkt{{"measuredValue", value}};
        QByteArray out = QJsonDocument(pkt).toJson(QJsonDocument::Compact) + '\n';
        socket->write(out);
        socket->flush();
        updateStatus("Measured sent: " + QString::number(value));
    }
}
