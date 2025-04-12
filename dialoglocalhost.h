#ifndef DIALOGLOCALHOST_H
#define DIALOGLOCALHOST_H

#include <QDialog>
#include "NetworkMode.h"

namespace Ui {
class DialogLocalhost;
}

class DialogLocalhost : public QDialog
{
    Q_OBJECT

public:
    explicit DialogLocalhost(QWidget *parent = nullptr);
    ~DialogLocalhost();
    NetworkMode getNetworkMode();

private slots:
    void on_serverButton_clicked();

    void on_clientButton_clicked();

private:
    Ui::DialogLocalhost *ui;
    NetworkMode mode = NetworkMode::None;
};

#endif // DIALOGLOCALHOST_H
