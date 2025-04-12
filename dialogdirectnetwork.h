#ifndef DIALOGDIRECTNETWORK_H
#define DIALOGDIRECTNETWORK_H

#include <QDialog>
#include "NetworkMode.h"

namespace Ui {
class DialogDirectNetwork;
}

class DialogDirectNetwork : public QDialog
{
    Q_OBJECT

public:
    explicit DialogDirectNetwork(QWidget *parent = nullptr);
    ~DialogDirectNetwork();
    QString getIpAddress();
    NetworkMode getNetworkMode();

private slots:
    void on_serverButton_clicked();

    void on_clientButton_clicked();

private:
    Ui::DialogDirectNetwork *ui;
    NetworkMode mode = NetworkMode::None;
};

#endif // DIALOGDIRECTNETWORK_H
