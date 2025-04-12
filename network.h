#ifndef NETWORK_H
#define NETWORK_H

#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>
#include <QDebug>

class Network : public QObject
{
    Q_OBJECT
public:
    explicit Network(QObject *parent = nullptr);
    void startAsServer(int port);
    void startAsClient(QString host, int port);
    void disconnect();
private slots:
    void onNewConnection();
private:
    QTcpSocket *socket = nullptr;
    QTcpServer *server = nullptr;
signals:
};

#endif // NETWORK_H
