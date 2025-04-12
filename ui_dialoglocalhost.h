/********************************************************************************
** Form generated from reading UI file 'dialoglocalhost.ui'
**
** Created by: Qt User Interface Compiler version 6.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGLOCALHOST_H
#define UI_DIALOGLOCALHOST_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_DialogLocalhost
{
public:
    QDialogButtonBox *buttonBox;
    QPushButton *serverButton;
    QPushButton *clientButton;

    void setupUi(QDialog *DialogLocalhost)
    {
        if (DialogLocalhost->objectName().isEmpty())
            DialogLocalhost->setObjectName("DialogLocalhost");
        DialogLocalhost->resize(400, 300);
        buttonBox = new QDialogButtonBox(DialogLocalhost);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setGeometry(QRect(290, 20, 81, 241));
        buttonBox->setOrientation(Qt::Orientation::Vertical);
        buttonBox->setStandardButtons(QDialogButtonBox::StandardButton::Cancel|QDialogButtonBox::StandardButton::Ok);
        serverButton = new QPushButton(DialogLocalhost);
        serverButton->setObjectName("serverButton");
        serverButton->setGeometry(QRect(150, 30, 83, 29));
        clientButton = new QPushButton(DialogLocalhost);
        clientButton->setObjectName("clientButton");
        clientButton->setGeometry(QRect(150, 80, 83, 29));

        retranslateUi(DialogLocalhost);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, DialogLocalhost, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, DialogLocalhost, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(DialogLocalhost);
    } // setupUi

    void retranslateUi(QDialog *DialogLocalhost)
    {
        DialogLocalhost->setWindowTitle(QCoreApplication::translate("DialogLocalhost", "Dialog", nullptr));
        serverButton->setText(QCoreApplication::translate("DialogLocalhost", "Server", nullptr));
        clientButton->setText(QCoreApplication::translate("DialogLocalhost", "Client", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DialogLocalhost: public Ui_DialogLocalhost {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGLOCALHOST_H
