/********************************************************************************
** Form generated from reading UI file 'dialogarx.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGARX_H
#define UI_DIALOGARX_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_DialogARX
{
public:
    QHBoxLayout *horizontalLayout;
    QFormLayout *formLayout;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QSpinBox *spinBox;
    QSpacerItem *verticalSpacer;
    QSpacerItem *verticalSpacer_2;
    QSpacerItem *verticalSpacer_3;
    QSpacerItem *verticalSpacer_5;
    QSpacerItem *verticalSpacer_6;
    QSpacerItem *verticalSpacer_7;
    QSpacerItem *verticalSpacer_8;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QDoubleSpinBox *doubleSpinBox;
    QSpacerItem *verticalSpacer_9;
    QLabel *label_7;

    void setupUi(QDialog *DialogARX)
    {
        if (DialogARX->objectName().isEmpty())
            DialogARX->setObjectName("DialogARX");
        DialogARX->setEnabled(true);
        DialogARX->resize(400, 300);
        QSizePolicy sizePolicy(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(DialogARX->sizePolicy().hasHeightForWidth());
        DialogARX->setSizePolicy(sizePolicy);
        DialogARX->setMinimumSize(QSize(400, 300));
        DialogARX->setMaximumSize(QSize(400, 300));
        DialogARX->setSizeGripEnabled(false);
        horizontalLayout = new QHBoxLayout(DialogARX);
        horizontalLayout->setObjectName("horizontalLayout");
        formLayout = new QFormLayout();
        formLayout->setObjectName("formLayout");
        label = new QLabel(DialogARX);
        label->setObjectName("label");

        formLayout->setWidget(3, QFormLayout::LabelRole, label);

        label_2 = new QLabel(DialogARX);
        label_2->setObjectName("label_2");

        formLayout->setWidget(5, QFormLayout::LabelRole, label_2);

        label_3 = new QLabel(DialogARX);
        label_3->setObjectName("label_3");

        formLayout->setWidget(7, QFormLayout::LabelRole, label_3);

        pushButton = new QPushButton(DialogARX);
        pushButton->setObjectName("pushButton");

        formLayout->setWidget(10, QFormLayout::LabelRole, pushButton);

        pushButton_2 = new QPushButton(DialogARX);
        pushButton_2->setObjectName("pushButton_2");

        formLayout->setWidget(12, QFormLayout::LabelRole, pushButton_2);

        lineEdit = new QLineEdit(DialogARX);
        lineEdit->setObjectName("lineEdit");

        formLayout->setWidget(3, QFormLayout::FieldRole, lineEdit);

        lineEdit_2 = new QLineEdit(DialogARX);
        lineEdit_2->setObjectName("lineEdit_2");

        formLayout->setWidget(5, QFormLayout::FieldRole, lineEdit_2);

        spinBox = new QSpinBox(DialogARX);
        spinBox->setObjectName("spinBox");
        spinBox->setMinimum(1);

        formLayout->setWidget(7, QFormLayout::FieldRole, spinBox);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        formLayout->setItem(10, QFormLayout::FieldRole, verticalSpacer);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        formLayout->setItem(12, QFormLayout::FieldRole, verticalSpacer_2);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        formLayout->setItem(11, QFormLayout::LabelRole, verticalSpacer_3);

        verticalSpacer_5 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        formLayout->setItem(6, QFormLayout::LabelRole, verticalSpacer_5);

        verticalSpacer_6 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        formLayout->setItem(4, QFormLayout::LabelRole, verticalSpacer_6);

        verticalSpacer_7 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        formLayout->setItem(13, QFormLayout::LabelRole, verticalSpacer_7);

        verticalSpacer_8 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        formLayout->setItem(0, QFormLayout::LabelRole, verticalSpacer_8);

        label_4 = new QLabel(DialogARX);
        label_4->setObjectName("label_4");

        formLayout->setWidget(0, QFormLayout::FieldRole, label_4);

        label_5 = new QLabel(DialogARX);
        label_5->setObjectName("label_5");

        formLayout->setWidget(1, QFormLayout::FieldRole, label_5);

        label_6 = new QLabel(DialogARX);
        label_6->setObjectName("label_6");

        formLayout->setWidget(2, QFormLayout::FieldRole, label_6);

        doubleSpinBox = new QDoubleSpinBox(DialogARX);
        doubleSpinBox->setObjectName("doubleSpinBox");
        doubleSpinBox->setMinimum(0.000000000000000);
        doubleSpinBox->setMaximum(1.000000000000000);
        doubleSpinBox->setSingleStep(0.010000000000000);
        doubleSpinBox->setValue(0.000000000000000);

        formLayout->setWidget(9, QFormLayout::FieldRole, doubleSpinBox);

        verticalSpacer_9 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        formLayout->setItem(8, QFormLayout::LabelRole, verticalSpacer_9);

        label_7 = new QLabel(DialogARX);
        label_7->setObjectName("label_7");

        formLayout->setWidget(9, QFormLayout::LabelRole, label_7);


        horizontalLayout->addLayout(formLayout);


        retranslateUi(DialogARX);

        QMetaObject::connectSlotsByName(DialogARX);
    } // setupUi

    void retranslateUi(QDialog *DialogARX)
    {
        DialogARX->setWindowTitle(QCoreApplication::translate("DialogARX", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("DialogARX", "A", nullptr));
        label_2->setText(QCoreApplication::translate("DialogARX", "B", nullptr));
        label_3->setText(QCoreApplication::translate("DialogARX", "k", nullptr));
        pushButton->setText(QCoreApplication::translate("DialogARX", "OK", nullptr));
        pushButton_2->setText(QCoreApplication::translate("DialogARX", "Cancel", nullptr));
        lineEdit->setText(QString());
        lineEdit_2->setText(QString());
        label_4->setText(QCoreApplication::translate("DialogARX", "<html><head/><body><p>Enter numbers with a decimal point, separated </p></body></html>", nullptr));
        label_5->setText(QCoreApplication::translate("DialogARX", "by a semicolon (;). Example: 3.14; 2.71; 1.618", nullptr));
        label_6->setText(QCoreApplication::translate("DialogARX", "Default values: A(-0.4), B(0.6), k(1)", nullptr));
        label_7->setText(QCoreApplication::translate("DialogARX", "Noise", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DialogARX: public Ui_DialogARX {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGARX_H
