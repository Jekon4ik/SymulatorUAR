/********************************************************************************
** Form generated from reading UI file 'dialogNetwork.ui'
**
** Created by: Qt User Interface Compiler version 6.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGNETWORK_H
#define UI_DIALOGNETWORK_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>

QT_BEGIN_NAMESPACE

class Ui_DialogNetwork
{
public:
    QGridLayout *gridLayout;
    QLabel *label_2;
    QRadioButton *serverRadio;
    QLabel *label;
    QLineEdit *portEdit;
    QRadioButton *clientRadio;
    QLineEdit *addressEdit;
    QPushButton *pushButton;
    QPushButton *cancelButton;

    void setupUi(QDialog *DialogNetwork)
    {
        if (DialogNetwork->objectName().isEmpty())
            DialogNetwork->setObjectName("DialogNetwork");
        DialogNetwork->resize(400, 300);
        gridLayout = new QGridLayout(DialogNetwork);
        gridLayout->setObjectName("gridLayout");
        label_2 = new QLabel(DialogNetwork);
        label_2->setObjectName("label_2");

        gridLayout->addWidget(label_2, 5, 0, 1, 1);

        serverRadio = new QRadioButton(DialogNetwork);
        serverRadio->setObjectName("serverRadio");

        gridLayout->addWidget(serverRadio, 0, 1, 1, 1, Qt::AlignmentFlag::AlignHCenter);

        label = new QLabel(DialogNetwork);
        label->setObjectName("label");

        gridLayout->addWidget(label, 4, 0, 1, 1);

        portEdit = new QLineEdit(DialogNetwork);
        portEdit->setObjectName("portEdit");

        gridLayout->addWidget(portEdit, 5, 1, 1, 1);

        clientRadio = new QRadioButton(DialogNetwork);
        clientRadio->setObjectName("clientRadio");

        gridLayout->addWidget(clientRadio, 1, 1, 1, 1, Qt::AlignmentFlag::AlignHCenter);

        addressEdit = new QLineEdit(DialogNetwork);
        addressEdit->setObjectName("addressEdit");

        gridLayout->addWidget(addressEdit, 4, 1, 1, 1);

        pushButton = new QPushButton(DialogNetwork);
        pushButton->setObjectName("pushButton");

        gridLayout->addWidget(pushButton, 0, 0, 1, 1);

        cancelButton = new QPushButton(DialogNetwork);
        cancelButton->setObjectName("cancelButton");

        gridLayout->addWidget(cancelButton, 1, 0, 1, 1);


        retranslateUi(DialogNetwork);

        QMetaObject::connectSlotsByName(DialogNetwork);
    } // setupUi

    void retranslateUi(QDialog *DialogNetwork)
    {
        DialogNetwork->setWindowTitle(QCoreApplication::translate("DialogNetwork", "Dialog", nullptr));
        label_2->setText(QCoreApplication::translate("DialogNetwork", "Port", nullptr));
        serverRadio->setText(QCoreApplication::translate("DialogNetwork", "Server", nullptr));
        label->setText(QCoreApplication::translate("DialogNetwork", "Server IP Address", nullptr));
        clientRadio->setText(QCoreApplication::translate("DialogNetwork", "Client", nullptr));
        pushButton->setText(QCoreApplication::translate("DialogNetwork", "Confim", nullptr));
        cancelButton->setText(QCoreApplication::translate("DialogNetwork", "Cancel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DialogNetwork: public Ui_DialogNetwork {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGNETWORK_H
