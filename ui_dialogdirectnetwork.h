/********************************************************************************
** Form generated from reading UI file 'dialogdirectnetwork.ui'
**
** Created by: Qt User Interface Compiler version 6.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGDIRECTNETWORK_H
#define UI_DIALOGDIRECTNETWORK_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_DialogDirectNetwork
{
public:
    QPushButton *serverButton;
    QPushButton *clientButton;
    QLineEdit *ipaddressEdit;

    void setupUi(QDialog *DialogDirectNetwork)
    {
        if (DialogDirectNetwork->objectName().isEmpty())
            DialogDirectNetwork->setObjectName("DialogDirectNetwork");
        DialogDirectNetwork->resize(400, 300);
        serverButton = new QPushButton(DialogDirectNetwork);
        serverButton->setObjectName("serverButton");
        serverButton->setGeometry(QRect(150, 50, 83, 29));
        clientButton = new QPushButton(DialogDirectNetwork);
        clientButton->setObjectName("clientButton");
        clientButton->setGeometry(QRect(250, 140, 83, 29));
        ipaddressEdit = new QLineEdit(DialogDirectNetwork);
        ipaddressEdit->setObjectName("ipaddressEdit");
        ipaddressEdit->setGeometry(QRect(70, 140, 113, 28));

        retranslateUi(DialogDirectNetwork);

        QMetaObject::connectSlotsByName(DialogDirectNetwork);
    } // setupUi

    void retranslateUi(QDialog *DialogDirectNetwork)
    {
        DialogDirectNetwork->setWindowTitle(QCoreApplication::translate("DialogDirectNetwork", "Dialog", nullptr));
        serverButton->setText(QCoreApplication::translate("DialogDirectNetwork", "Server", nullptr));
        clientButton->setText(QCoreApplication::translate("DialogDirectNetwork", "Client", nullptr));
        ipaddressEdit->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class DialogDirectNetwork: public Ui_DialogDirectNetwork {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGDIRECTNETWORK_H
