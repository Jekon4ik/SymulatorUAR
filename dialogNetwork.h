#ifndef DIALOGNETWORK_H
#define DIALOGNETWORK_H

#include <QDialog>
#include "NetworkMode.h"

namespace Ui {
class DialogNetwork;
}

class DialogNetwork : public QDialog
{
    Q_OBJECT

public:
    explicit DialogNetwork(QWidget *parent = nullptr);
    ~DialogNetwork();
    NetworkMode getNetworkMode();
    QString getAddress();
    int getPort();

private slots:
    void on_serverRadio_clicked();

    void on_clientRadio_clicked();

    void on_cancelButton_clicked();

    void on_pushButton_clicked();

private:
    Ui::DialogNetwork *ui;
    NetworkMode mode = NetworkMode::None;
};

#endif // DIALOGNETWORK_H
