/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionSAVE_TO_FILE;
    QAction *actionLOAD_FROM_FILE;
    QAction *actionSET;
    QAction *actionNetwork;
    QAction *actionLOCALHOST;
    QAction *actionLOCALHOST_2;
    QAction *actionLOCALHOST_3;
    QAction *actionConnect;
    QAction *actionLAN;
    QAction *actionDirect_Network;
    QAction *actionDisconnect;
    QWidget *centralwidget;
    QFormLayout *formLayout_5;
    QVBoxLayout *verticalLayout_3;
    QGridLayout *gridLayout;
    QSpacerItem *verticalSpacer_17;
    QPushButton *startButton;
    QPushButton *stopButton;
    QPushButton *actualizeButton;
    QSpacerItem *verticalSpacer_16;
    QPushButton *resetButton;
    QSpacerItem *verticalSpacer_15;
    QFormLayout *formLayout;
    QLabel *label;
    QDoubleSpinBox *kDoubleSpinBox;
    QLabel *label_2;
    QDoubleSpinBox *tiDoubleSpinBox_2;
    QSpacerItem *verticalSpacer_2;
    QLabel *label_3;
    QDoubleSpinBox *tdDoubleSpinBox_3;
    QSpacerItem *verticalSpacer_3;
    QLabel *label_4;
    QSpinBox *timeIntervalSpinBox;
    QLabel *label_10;
    QCheckBox *constCheckBox;
    QSpacerItem *verticalSpacer_14;
    QFormLayout *formLayout_2;
    QRadioButton *manualRadioButton;
    QDoubleSpinBox *constantDoubleSpinBox;
    QSpacerItem *verticalSpacer_4;
    QSlider *horizontalSlider;
    QSpacerItem *verticalSpacer_12;
    QSpacerItem *verticalSpacer_13;
    QFormLayout *formLayout_3;
    QSpacerItem *verticalSpacer_5;
    QLabel *label_7;
    QDoubleSpinBox *amplitudeSinusoidalDoubleSpinBox;
    QSpacerItem *verticalSpacer_6;
    QLabel *label_6;
    QDoubleSpinBox *periodSinusoidalDoubleSpinBox_2;
    QRadioButton *sinusoidalRadioButton_2;
    QSpacerItem *verticalSpacer;
    QDoubleSpinBox *sinusoidConstantdoubleSpinBox_2;
    QLabel *label_12;
    QSpacerItem *verticalSpacer_18;
    QLabel *label_11;
    QSpinBox *activationTimeSpinBox;
    QSpacerItem *verticalSpacer_11;
    QFormLayout *formLayout_4;
    QLabel *label_5;
    QLabel *label_8;
    QLabel *label_9;
    QDoubleSpinBox *amplitudeSquareDoubleSpinBox_3;
    QDoubleSpinBox *periodSquareDoubleSpinBox_4;
    QDoubleSpinBox *dutyCycleSquareDoubleSpinBox_5;
    QSpacerItem *verticalSpacer_7;
    QSpacerItem *verticalSpacer_8;
    QSpacerItem *verticalSpacer_9;
    QRadioButton *squareRadioButton_3;
    QSpacerItem *verticalSpacer_10;
    QLabel *label_14;
    QDoubleSpinBox *squareConstantSpinBox_3;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QCustomPlot *mainPlot;
    QHBoxLayout *horizontalLayout;
    QCustomPlot *errorPlot;
    QCustomPlot *pidPlot;
    QGridLayout *gridLayout_2;
    QLineEdit *statusEdit;
    QLabel *label_15;
    QLabel *label_13;
    QLabel *networkModeLabel;
    QMenuBar *menubar;
    QMenu *menuFILE;
    QMenu *menuARX;
    QMenu *menuNetwork;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1100, 750);
        MainWindow->setMinimumSize(QSize(800, 750));
        actionSAVE_TO_FILE = new QAction(MainWindow);
        actionSAVE_TO_FILE->setObjectName("actionSAVE_TO_FILE");
        actionSAVE_TO_FILE->setCheckable(false);
        actionLOAD_FROM_FILE = new QAction(MainWindow);
        actionLOAD_FROM_FILE->setObjectName("actionLOAD_FROM_FILE");
        actionSET = new QAction(MainWindow);
        actionSET->setObjectName("actionSET");
        actionNetwork = new QAction(MainWindow);
        actionNetwork->setObjectName("actionNetwork");
        actionLOCALHOST = new QAction(MainWindow);
        actionLOCALHOST->setObjectName("actionLOCALHOST");
        actionLOCALHOST_2 = new QAction(MainWindow);
        actionLOCALHOST_2->setObjectName("actionLOCALHOST_2");
        actionLOCALHOST_3 = new QAction(MainWindow);
        actionLOCALHOST_3->setObjectName("actionLOCALHOST_3");
        actionConnect = new QAction(MainWindow);
        actionConnect->setObjectName("actionConnect");
        actionLAN = new QAction(MainWindow);
        actionLAN->setObjectName("actionLAN");
        actionDirect_Network = new QAction(MainWindow);
        actionDirect_Network->setObjectName("actionDirect_Network");
        actionDisconnect = new QAction(MainWindow);
        actionDisconnect->setObjectName("actionDisconnect");
        actionDisconnect->setVisible(false);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        formLayout_5 = new QFormLayout(centralwidget);
        formLayout_5->setObjectName("formLayout_5");
        formLayout_5->setContentsMargins(-1, 11, -1, -1);
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName("verticalLayout_3");
        gridLayout = new QGridLayout();
        gridLayout->setObjectName("gridLayout");
        verticalSpacer_17 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout->addItem(verticalSpacer_17, 1, 0, 1, 1);

        startButton = new QPushButton(centralwidget);
        startButton->setObjectName("startButton");

        gridLayout->addWidget(startButton, 0, 0, 1, 1);

        stopButton = new QPushButton(centralwidget);
        stopButton->setObjectName("stopButton");

        gridLayout->addWidget(stopButton, 0, 1, 1, 1);

        actualizeButton = new QPushButton(centralwidget);
        actualizeButton->setObjectName("actualizeButton");

        gridLayout->addWidget(actualizeButton, 4, 0, 1, 2);

        verticalSpacer_16 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout->addItem(verticalSpacer_16, 3, 0, 1, 1);

        resetButton = new QPushButton(centralwidget);
        resetButton->setObjectName("resetButton");

        gridLayout->addWidget(resetButton, 2, 0, 1, 2);


        verticalLayout_3->addLayout(gridLayout);

        verticalSpacer_15 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_3->addItem(verticalSpacer_15);

        formLayout = new QFormLayout();
        formLayout->setObjectName("formLayout");
        label = new QLabel(centralwidget);
        label->setObjectName("label");

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        kDoubleSpinBox = new QDoubleSpinBox(centralwidget);
        kDoubleSpinBox->setObjectName("kDoubleSpinBox");
        kDoubleSpinBox->setSingleStep(0.100000000000000);
        kDoubleSpinBox->setValue(0.500000000000000);

        formLayout->setWidget(0, QFormLayout::FieldRole, kDoubleSpinBox);

        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");

        formLayout->setWidget(2, QFormLayout::LabelRole, label_2);

        tiDoubleSpinBox_2 = new QDoubleSpinBox(centralwidget);
        tiDoubleSpinBox_2->setObjectName("tiDoubleSpinBox_2");
        tiDoubleSpinBox_2->setValue(10.000000000000000);

        formLayout->setWidget(2, QFormLayout::FieldRole, tiDoubleSpinBox_2);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        formLayout->setItem(3, QFormLayout::FieldRole, verticalSpacer_2);

        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");

        formLayout->setWidget(4, QFormLayout::LabelRole, label_3);

        tdDoubleSpinBox_3 = new QDoubleSpinBox(centralwidget);
        tdDoubleSpinBox_3->setObjectName("tdDoubleSpinBox_3");
        tdDoubleSpinBox_3->setSingleStep(0.100000000000000);
        tdDoubleSpinBox_3->setValue(0.200000000000000);

        formLayout->setWidget(4, QFormLayout::FieldRole, tdDoubleSpinBox_3);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        formLayout->setItem(5, QFormLayout::FieldRole, verticalSpacer_3);

        label_4 = new QLabel(centralwidget);
        label_4->setObjectName("label_4");

        formLayout->setWidget(6, QFormLayout::LabelRole, label_4);

        timeIntervalSpinBox = new QSpinBox(centralwidget);
        timeIntervalSpinBox->setObjectName("timeIntervalSpinBox");
        timeIntervalSpinBox->setMinimum(1);
        timeIntervalSpinBox->setMaximum(2000);
        timeIntervalSpinBox->setValue(100);

        formLayout->setWidget(6, QFormLayout::FieldRole, timeIntervalSpinBox);

        label_10 = new QLabel(centralwidget);
        label_10->setObjectName("label_10");

        formLayout->setWidget(1, QFormLayout::LabelRole, label_10);

        constCheckBox = new QCheckBox(centralwidget);
        constCheckBox->setObjectName("constCheckBox");

        formLayout->setWidget(1, QFormLayout::FieldRole, constCheckBox);


        verticalLayout_3->addLayout(formLayout);

        verticalSpacer_14 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_3->addItem(verticalSpacer_14);

        formLayout_2 = new QFormLayout();
        formLayout_2->setObjectName("formLayout_2");
        manualRadioButton = new QRadioButton(centralwidget);
        manualRadioButton->setObjectName("manualRadioButton");

        formLayout_2->setWidget(0, QFormLayout::LabelRole, manualRadioButton);

        constantDoubleSpinBox = new QDoubleSpinBox(centralwidget);
        constantDoubleSpinBox->setObjectName("constantDoubleSpinBox");

        formLayout_2->setWidget(0, QFormLayout::FieldRole, constantDoubleSpinBox);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        formLayout_2->setItem(1, QFormLayout::FieldRole, verticalSpacer_4);

        horizontalSlider = new QSlider(centralwidget);
        horizontalSlider->setObjectName("horizontalSlider");
        horizontalSlider->setOrientation(Qt::Orientation::Horizontal);

        formLayout_2->setWidget(2, QFormLayout::SpanningRole, horizontalSlider);

        verticalSpacer_12 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        formLayout_2->setItem(3, QFormLayout::LabelRole, verticalSpacer_12);

        verticalSpacer_13 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        formLayout_2->setItem(3, QFormLayout::FieldRole, verticalSpacer_13);

        formLayout_3 = new QFormLayout();
        formLayout_3->setObjectName("formLayout_3");
        verticalSpacer_5 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        formLayout_3->setItem(1, QFormLayout::FieldRole, verticalSpacer_5);

        label_7 = new QLabel(centralwidget);
        label_7->setObjectName("label_7");

        formLayout_3->setWidget(2, QFormLayout::LabelRole, label_7);

        amplitudeSinusoidalDoubleSpinBox = new QDoubleSpinBox(centralwidget);
        amplitudeSinusoidalDoubleSpinBox->setObjectName("amplitudeSinusoidalDoubleSpinBox");

        formLayout_3->setWidget(2, QFormLayout::FieldRole, amplitudeSinusoidalDoubleSpinBox);

        verticalSpacer_6 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        formLayout_3->setItem(3, QFormLayout::FieldRole, verticalSpacer_6);

        label_6 = new QLabel(centralwidget);
        label_6->setObjectName("label_6");

        formLayout_3->setWidget(4, QFormLayout::LabelRole, label_6);

        periodSinusoidalDoubleSpinBox_2 = new QDoubleSpinBox(centralwidget);
        periodSinusoidalDoubleSpinBox_2->setObjectName("periodSinusoidalDoubleSpinBox_2");

        formLayout_3->setWidget(4, QFormLayout::FieldRole, periodSinusoidalDoubleSpinBox_2);

        sinusoidalRadioButton_2 = new QRadioButton(centralwidget);
        sinusoidalRadioButton_2->setObjectName("sinusoidalRadioButton_2");

        formLayout_3->setWidget(0, QFormLayout::SpanningRole, sinusoidalRadioButton_2);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        formLayout_3->setItem(3, QFormLayout::LabelRole, verticalSpacer);

        sinusoidConstantdoubleSpinBox_2 = new QDoubleSpinBox(centralwidget);
        sinusoidConstantdoubleSpinBox_2->setObjectName("sinusoidConstantdoubleSpinBox_2");

        formLayout_3->setWidget(6, QFormLayout::FieldRole, sinusoidConstantdoubleSpinBox_2);

        label_12 = new QLabel(centralwidget);
        label_12->setObjectName("label_12");

        formLayout_3->setWidget(6, QFormLayout::LabelRole, label_12);

        verticalSpacer_18 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        formLayout_3->setItem(5, QFormLayout::FieldRole, verticalSpacer_18);


        formLayout_2->setLayout(5, QFormLayout::SpanningRole, formLayout_3);

        label_11 = new QLabel(centralwidget);
        label_11->setObjectName("label_11");

        formLayout_2->setWidget(4, QFormLayout::LabelRole, label_11);

        activationTimeSpinBox = new QSpinBox(centralwidget);
        activationTimeSpinBox->setObjectName("activationTimeSpinBox");

        formLayout_2->setWidget(4, QFormLayout::FieldRole, activationTimeSpinBox);


        verticalLayout_3->addLayout(formLayout_2);

        verticalSpacer_11 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_3->addItem(verticalSpacer_11);

        formLayout_4 = new QFormLayout();
        formLayout_4->setObjectName("formLayout_4");
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName("label_5");

        formLayout_4->setWidget(2, QFormLayout::LabelRole, label_5);

        label_8 = new QLabel(centralwidget);
        label_8->setObjectName("label_8");

        formLayout_4->setWidget(4, QFormLayout::LabelRole, label_8);

        label_9 = new QLabel(centralwidget);
        label_9->setObjectName("label_9");

        formLayout_4->setWidget(6, QFormLayout::LabelRole, label_9);

        amplitudeSquareDoubleSpinBox_3 = new QDoubleSpinBox(centralwidget);
        amplitudeSquareDoubleSpinBox_3->setObjectName("amplitudeSquareDoubleSpinBox_3");

        formLayout_4->setWidget(2, QFormLayout::FieldRole, amplitudeSquareDoubleSpinBox_3);

        periodSquareDoubleSpinBox_4 = new QDoubleSpinBox(centralwidget);
        periodSquareDoubleSpinBox_4->setObjectName("periodSquareDoubleSpinBox_4");

        formLayout_4->setWidget(4, QFormLayout::FieldRole, periodSquareDoubleSpinBox_4);

        dutyCycleSquareDoubleSpinBox_5 = new QDoubleSpinBox(centralwidget);
        dutyCycleSquareDoubleSpinBox_5->setObjectName("dutyCycleSquareDoubleSpinBox_5");
        dutyCycleSquareDoubleSpinBox_5->setMaximum(1.000000000000000);
        dutyCycleSquareDoubleSpinBox_5->setSingleStep(0.100000000000000);

        formLayout_4->setWidget(6, QFormLayout::FieldRole, dutyCycleSquareDoubleSpinBox_5);

        verticalSpacer_7 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        formLayout_4->setItem(1, QFormLayout::FieldRole, verticalSpacer_7);

        verticalSpacer_8 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        formLayout_4->setItem(3, QFormLayout::FieldRole, verticalSpacer_8);

        verticalSpacer_9 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        formLayout_4->setItem(5, QFormLayout::FieldRole, verticalSpacer_9);

        squareRadioButton_3 = new QRadioButton(centralwidget);
        squareRadioButton_3->setObjectName("squareRadioButton_3");
        squareRadioButton_3->setAutoFillBackground(false);

        formLayout_4->setWidget(0, QFormLayout::SpanningRole, squareRadioButton_3);

        verticalSpacer_10 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        formLayout_4->setItem(7, QFormLayout::FieldRole, verticalSpacer_10);

        label_14 = new QLabel(centralwidget);
        label_14->setObjectName("label_14");

        formLayout_4->setWidget(8, QFormLayout::LabelRole, label_14);

        squareConstantSpinBox_3 = new QDoubleSpinBox(centralwidget);
        squareConstantSpinBox_3->setObjectName("squareConstantSpinBox_3");

        formLayout_4->setWidget(8, QFormLayout::FieldRole, squareConstantSpinBox_3);


        verticalLayout_3->addLayout(formLayout_4);


        formLayout_5->setLayout(0, QFormLayout::LabelRole, verticalLayout_3);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        mainPlot = new QCustomPlot(centralwidget);
        mainPlot->setObjectName("mainPlot");

        verticalLayout->addWidget(mainPlot);


        verticalLayout_2->addLayout(verticalLayout);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        errorPlot = new QCustomPlot(centralwidget);
        errorPlot->setObjectName("errorPlot");

        horizontalLayout->addWidget(errorPlot);

        pidPlot = new QCustomPlot(centralwidget);
        pidPlot->setObjectName("pidPlot");

        horizontalLayout->addWidget(pidPlot);


        verticalLayout_2->addLayout(horizontalLayout);


        formLayout_5->setLayout(0, QFormLayout::FieldRole, verticalLayout_2);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName("gridLayout_2");
        statusEdit = new QLineEdit(centralwidget);
        statusEdit->setObjectName("statusEdit");
        statusEdit->setReadOnly(true);

        gridLayout_2->addWidget(statusEdit, 2, 1, 1, 1);

        label_15 = new QLabel(centralwidget);
        label_15->setObjectName("label_15");
        label_15->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        gridLayout_2->addWidget(label_15, 0, 0, 1, 1);

        label_13 = new QLabel(centralwidget);
        label_13->setObjectName("label_13");
        label_13->setMinimumSize(QSize(200, 28));
        label_13->setMaximumSize(QSize(120, 16777215));
        label_13->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        gridLayout_2->addWidget(label_13, 2, 0, 1, 1);

        networkModeLabel = new QLabel(centralwidget);
        networkModeLabel->setObjectName("networkModeLabel");

        gridLayout_2->addWidget(networkModeLabel, 0, 1, 1, 1);


        formLayout_5->setLayout(6, QFormLayout::SpanningRole, gridLayout_2);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1100, 21));
        menuFILE = new QMenu(menubar);
        menuFILE->setObjectName("menuFILE");
        menuARX = new QMenu(menubar);
        menuARX->setObjectName("menuARX");
        menuNetwork = new QMenu(menubar);
        menuNetwork->setObjectName("menuNetwork");
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuFILE->menuAction());
        menubar->addAction(menuARX->menuAction());
        menubar->addAction(menuNetwork->menuAction());
        menuFILE->addAction(actionSAVE_TO_FILE);
        menuFILE->addAction(actionLOAD_FROM_FILE);
        menuARX->addAction(actionSET);
        menuNetwork->addAction(actionConnect);
        menuNetwork->addAction(actionDisconnect);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        actionSAVE_TO_FILE->setText(QCoreApplication::translate("MainWindow", "SAVE TO FILE", nullptr));
        actionLOAD_FROM_FILE->setText(QCoreApplication::translate("MainWindow", "LOAD FROM FILE", nullptr));
        actionSET->setText(QCoreApplication::translate("MainWindow", "SET", nullptr));
        actionNetwork->setText(QCoreApplication::translate("MainWindow", "Localhost", nullptr));
        actionLOCALHOST->setText(QCoreApplication::translate("MainWindow", "LOCALHOST", nullptr));
        actionLOCALHOST_2->setText(QCoreApplication::translate("MainWindow", "LOCALHOST", nullptr));
        actionLOCALHOST_3->setText(QCoreApplication::translate("MainWindow", "LOCALHOST", nullptr));
        actionConnect->setText(QCoreApplication::translate("MainWindow", "Connect", nullptr));
        actionLAN->setText(QCoreApplication::translate("MainWindow", "LAN", nullptr));
        actionDirect_Network->setText(QCoreApplication::translate("MainWindow", "Direct Network", nullptr));
        actionDisconnect->setText(QCoreApplication::translate("MainWindow", "Disconnect", nullptr));
        startButton->setText(QCoreApplication::translate("MainWindow", "START", nullptr));
        stopButton->setText(QCoreApplication::translate("MainWindow", "STOP", nullptr));
        actualizeButton->setText(QCoreApplication::translate("MainWindow", "ACTUALIZE", nullptr));
        resetButton->setText(QCoreApplication::translate("MainWindow", "RESET", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "K", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Ti", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Td", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "TIME INTERVAL", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "Constant", nullptr));
        constCheckBox->setText(QCoreApplication::translate("MainWindow", "With sum", nullptr));
        manualRadioButton->setText(QCoreApplication::translate("MainWindow", "CONSTANT", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "AMPLITUDE", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "PERIOD", nullptr));
        sinusoidalRadioButton_2->setText(QCoreApplication::translate("MainWindow", "SINUSOIDAL", nullptr));
        label_12->setText(QCoreApplication::translate("MainWindow", "CONSTANT", nullptr));
        label_11->setText(QCoreApplication::translate("MainWindow", "Activation Time", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "AMPLITUDE", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "PERIOD", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "DUTY CYCLE", nullptr));
        squareRadioButton_3->setText(QCoreApplication::translate("MainWindow", "SQUARE", nullptr));
        label_14->setText(QCoreApplication::translate("MainWindow", "CONSTANT", nullptr));
        label_15->setText(QCoreApplication::translate("MainWindow", "Aplication role: ", nullptr));
        label_13->setText(QCoreApplication::translate("MainWindow", "Network status: ", nullptr));
        networkModeLabel->setText(QCoreApplication::translate("MainWindow", "Offline", nullptr));
        menuFILE->setTitle(QCoreApplication::translate("MainWindow", "FILE", nullptr));
        menuARX->setTitle(QCoreApplication::translate("MainWindow", "ARX", nullptr));
        menuNetwork->setTitle(QCoreApplication::translate("MainWindow", "Network", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
