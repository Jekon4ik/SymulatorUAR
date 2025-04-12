#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QVector>
#include "Facade.h"
#include "dialogarx.h"
#include <QTcpSocket>
#include <QTcpServer>
#include "network.h"
#include "dialoglocalhost.h"
#include "dialogdirectnetwork.h"

#define WIN32_LEAN_AND_MEAN

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_horizontalSlider_sliderMoved(int position);

    void on_constantDoubleSpinBox_valueChanged(double arg1);

    void on_actionSET_triggered();

    void on_actualizeButton_clicked();

    void on_startButton_clicked();

    void on_stopButton_clicked();

    void updatePlots(double time,
                     double generatedValue,
                     double error,
                     double controlValue,
                     double adjustedValue,
                     double proportionalPIDPart,
                     double integralPIDPart,
                     double derivativePIDPart);

    void on_resetButton_clicked();

    void on_actionSAVE_TO_FILE_triggered();

    void on_actionLOAD_FROM_FILE_triggered();

    void on_actionLocalhost_triggered();

    // void on_action_LAN_triggered();

    void on_action_Direct_Network_triggered();

    void on_actionDisconnect_triggered();


private:
    Ui::MainWindow *ui;
    Facade *facade;
    DialogARX *arxDialog;
    QString AtextField = "-0.4";
    QString BtextField = "0.6";
    int kField = 1;
    double noiseField = 0;
    Network *networkHandler = nullptr;
    DialogLocalhost *dialogLocalhost = nullptr;
    DialogDirectNetwork *dialogDirect = nullptr;
};
#endif // MAINWINDOW_H
