#ifndef NETWORK_H
#define NETWORK_H

#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>
#include <QDebug>
#include <QLineEdit>
#include <QTimer>
#include <QJsonDocument>
#include <QJsonObject>

class Network : public QObject
{
    Q_OBJECT
public:
    explicit Network(QObject *parent = nullptr);
    void startAsServer(int port);
    void startAsClient(QString host, int port);
    void disconnect();
    void setStatus(QLineEdit* lineEdit);
private slots:
    void onNewConnection();
    void onConnected();
    void onDisconnected();
    void onDataReady();
public slots:
    void sendControlledValue(double value, double time, double gen);
    void sendMeasuredValue(double value);
signals:
    void controlValueReceived(double value, double time, double gen);
    void measuredValueReceived(double value);
private:
    QTcpSocket *socket = nullptr;
    QTcpServer *server = nullptr;
    QLineEdit* status = nullptr;
    QString host;
    int port;
    void updateStatus(const QString &message);
signals:
};

#endif // NETWORK_H
