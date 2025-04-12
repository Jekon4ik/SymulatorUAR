/********************************************************************************
** Form generated from reading UI file 'connectiondialog.ui'
**
** Created by: Qt User Interface Compiler version 6.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONNECTIONDIALOG_H
#define UI_CONNECTIONDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_ConnectionDialog
{
public:
    QDialogButtonBox *buttonBox;
    QPushButton *serverButton;
    QPushButton *clientButton;

    void setupUi(QDialog *ConnectionDialog)
    {
        if (ConnectionDialog->objectName().isEmpty())
            ConnectionDialog->setObjectName("ConnectionDialog");
        ConnectionDialog->resize(400, 300);
        buttonBox = new QDialogButtonBox(ConnectionDialog);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setGeometry(QRect(30, 240, 341, 32));
        buttonBox->setOrientation(Qt::Orientation::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::StandardButton::Cancel|QDialogButtonBox::StandardButton::Ok);
        serverButton = new QPushButton(ConnectionDialog);
        serverButton->setObjectName("serverButton");
        serverButton->setGeometry(QRect(160, 70, 83, 29));
        clientButton = new QPushButton(ConnectionDialog);
        clientButton->setObjectName("clientButton");
        clientButton->setGeometry(QRect(160, 120, 83, 29));

        retranslateUi(ConnectionDialog);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, ConnectionDialog, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, ConnectionDialog, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(ConnectionDialog);
    } // setupUi

    void retranslateUi(QDialog *ConnectionDialog)
    {
        ConnectionDialog->setWindowTitle(QCoreApplication::translate("ConnectionDialog", "Dialog", nullptr));
        serverButton->setText(QCoreApplication::translate("ConnectionDialog", "Server", nullptr));
        clientButton->setText(QCoreApplication::translate("ConnectionDialog", "Klient", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ConnectionDialog: public Ui_ConnectionDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONNECTIONDIALOG_H
