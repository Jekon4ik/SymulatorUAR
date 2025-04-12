#ifndef CONNECTIONDIALOG_H
#define CONNECTIONDIALOG_H

#include <QDialog>

enum ConnectionMode {
    None,
    ServerMode,
    ClientMode
};

namespace Ui {
class ConnectionDialog;
}

class ConnectionDialog : public QDialog {
    Q_OBJECT

public:
    explicit ConnectionDialog(QWidget *parent = nullptr);
    ~ConnectionDialog();
    ConnectionMode selectedMode() const;

private:
    Ui::ConnectionDialog *ui;
    ConnectionMode mode = None;
};

#endif // CONNECTIONDIALOG_H
