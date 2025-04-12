#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    facade = new Facade();
    ui->setupUi(this);
    ui->mainPlot->addGraph();
    ui->mainPlot->addGraph();
    ui->mainPlot->graph(0)->setScatterStyle(QCPScatterStyle::ssCircle);
    ui->mainPlot->graph(1)->setScatterStyle(QCPScatterStyle::ssCircle);
    ui->mainPlot->graph()->setLineStyle(QCPGraph::lsLine);
    ui->mainPlot->xAxis->setLabel("Time [s]");
    ui->mainPlot->xAxis->setRange(0, 15);
    ui->mainPlot->yAxis->setRange(-10, 10);
    ui->mainPlot->graph(0)->setPen(QPen(Qt::green));
    ui->mainPlot->graph(1)->setPen(QPen(Qt::red));
    ui->mainPlot->plotLayout()->insertRow(0);
    ui->mainPlot->plotLayout()->addElement(0,
                                           0,
                                           new QCPTextElement(ui->mainPlot,
                                                              "Main Plot",
                                                              QFont("sans", 12, QFont::Bold)));
    ui->mainPlot->legend->setVisible(true);
    ui->mainPlot->legend->setFont(QFont("sans", 10));
    ui->mainPlot->legend->setBrush(
        QBrush(QColor(255, 255, 255, 150))); // Transparent white background

    // Assign names to graphs
    ui->mainPlot->graph(0)->setName("Setpoint value"); // Green graph
    ui->mainPlot->graph(1)->setName("Adjusted signal");       // Red graph

    ui->errorPlot->addGraph();
    ui->errorPlot->graph(0)->setScatterStyle(QCPScatterStyle::ssCircle);
    ui->errorPlot->graph()->setLineStyle(QCPGraph::lsLine);
    ui->errorPlot->xAxis->setLabel("Time [s]");
    ui->errorPlot->xAxis->setRange(0, 15);
    ui->errorPlot->yAxis->setRange(-10, 10);
    ui->errorPlot->graph(0)->setPen(QPen(Qt::blue));
    ui->errorPlot->plotLayout()->insertRow(0);
    ui->errorPlot->plotLayout()->addElement(0,
                                            0,
                                            new QCPTextElement(ui->errorPlot,
                                                               "ERROR",
                                                               QFont("sans", 12, QFont::Bold)));

    ui->pidPlot->addGraph();
    ui->pidPlot->addGraph();
    ui->pidPlot->addGraph();
    ui->pidPlot->addGraph();
    ui->pidPlot->graph(0)->setScatterStyle(QCPScatterStyle::ssCircle);
    ui->pidPlot->graph(1)->setScatterStyle(QCPScatterStyle::ssCircle);
    ui->pidPlot->graph(2)->setScatterStyle(QCPScatterStyle::ssCircle);
    ui->pidPlot->graph(3)->setScatterStyle(QCPScatterStyle::ssCircle);

    ui->pidPlot->graph()->setLineStyle(QCPGraph::lsLine);

    ui->pidPlot->xAxis->setLabel("Time [s]");
    ui->pidPlot->xAxis->setRange(0, 15);
    ui->pidPlot->yAxis->setRange(-10, 10);

    ui->pidPlot->graph(0)->setPen(QPen(Qt::red));
    ui->pidPlot->graph(1)->setPen(QPen(Qt::yellow));
    ui->pidPlot->graph(2)->setPen(QPen(Qt::blue));
    ui->pidPlot->graph(3)->setPen(QPen(Qt::green));

    ui->pidPlot->plotLayout()->insertRow(0);
    ui->pidPlot->plotLayout()->addElement(0,
                                          0,
                                          new QCPTextElement(ui->pidPlot,
                                                             "PID",
                                                             QFont("sans", 12, QFont::Bold)));

    //legend for PID graph
    ui->pidPlot->legend->setVisible(true);
    ui->pidPlot->legend->setFont(QFont("sans", 10));
    ui->pidPlot->legend->setBrush(QBrush(QColor(255,255,255,150)));
    ui->pidPlot->axisRect()->insetLayout()->setInsetAlignment(0,Qt::AlignTop | Qt::AlignLeft);
    ui->pidPlot->legend->setMinimumSize(120,70);
    ui->pidPlot->graph(0)->setName("Controll value");
    ui->pidPlot->graph(1)->setName("P"); //yellow P
    ui->pidPlot->graph(2)->setName("I"); //blue Ti
    ui->pidPlot->graph(3)->setName("D"); //green Td
    connect(facade, &Facade::newSimulationData, this, &MainWindow::updatePlots);
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::updatePlots(
    double time, double generatedValue, double error, double controlValue, double adjustedValue, double proportional, double integral, double derivative)
{
    ui->mainPlot->graph(0)->addData(time, generatedValue);
    ui->mainPlot->graph(1)->addData(time, adjustedValue);

    double marginX = 5.0; //margin for x axis
    if (time > 10)
        ui->mainPlot->xAxis->setRange(time - 5, time + marginX); // Auto-scroll

    double yMin = ui->mainPlot->yAxis->range().lower;
    double yMax = ui->mainPlot->yAxis->range().upper;

    if (generatedValue < yMin || adjustedValue > yMax) {
        yMin -= 12;
        //yMin = std::min(generatedValue, adjustedValue) - 12;
    }
    if (generatedValue > yMax || adjustedValue > yMax) {
        yMax += 12;
        //yMin = std::max(generatedValue, adjustedValue) + 12;
    }
    ui->mainPlot->yAxis->setRange(yMin, yMax);
    ui->mainPlot->replot();
    //ui->mainPlot->update();

    //Update errorPlot
    ui->errorPlot->graph(0)->addData(time, error);
    if(time>10) ui->errorPlot->xAxis->setRange(time - 5, time + marginX);
    double errorMin = ui->errorPlot->yAxis->range().lower;
    double errorMax = ui->errorPlot->yAxis->range().upper;
    if (error < errorMin) {
        errorMin -= 12;
    }
    if (error > errorMax) {
        errorMax += 12;
    }

    ui->errorPlot->yAxis->setRange(errorMin, errorMax);
    ui->errorPlot->replot();

    //Update pidPlot
    ui->pidPlot->graph(0)->addData(time, controlValue);
    ui->pidPlot->graph(1)->addData(time, proportional);
    ui->pidPlot->graph(2)->addData(time, integral);
    ui->pidPlot->graph(3)->addData(time, derivative);
    if(time>10) ui->pidPlot->xAxis->setRange(time - 5, time + marginX);

    double pidMin = ui->pidPlot->yAxis->range().lower;
    double pidMax = ui->pidPlot->yAxis->range().upper;

    if (controlValue < pidMin) {
        pidMin -= 12;
    }
    if (controlValue > pidMax) {
        pidMax += 12;
    }

    ui->pidPlot->yAxis->setRange(pidMin, pidMax);
    ui->pidPlot->replot();
}

void MainWindow::on_horizontalSlider_sliderMoved(int position)
{
    ui->constantDoubleSpinBox->setValue(position);
}

void MainWindow::on_constantDoubleSpinBox_valueChanged(double arg1)
{
    ui->horizontalSlider->setValue(arg1);
}

void MainWindow::on_actionSET_triggered()
{
    std::vector<double> A;
    std::vector<double> B;
    int k;
    double noise;
    arxDialog = new DialogARX(nullptr);
    arxDialog->setATextField(AtextField);
    arxDialog->setBTextField(BtextField);
    arxDialog->setKField(kField);
    arxDialog->setNoiseField(noiseField);
    if (arxDialog->exec() == QDialog::Accepted) {
        A = arxDialog->getA();
        B = arxDialog->getB();
        k = arxDialog->getK();
        noise = arxDialog->getNoise();
        qDebug() << B[0];
        //facade->setARXSettings(A, B, k);
        facade->setARX(A, B, k, noise);
        this->AtextField = arxDialog->getATextField();
        this->BtextField = arxDialog->getBTextField();
        this->kField = arxDialog->getK();
        this->noiseField = arxDialog->getNoise();
    }
    //on_actualizeButton_clicked();
    delete arxDialog;
}

void MainWindow::on_actualizeButton_clicked()
{
    if (facade->getActualK() == -1) {
        facade->setActual(ui->kDoubleSpinBox->value(),
                          ui->tiDoubleSpinBox_2->value(),
                          ui->tdDoubleSpinBox_3->value(),
                          ui->timeIntervalSpinBox->value(),
                          ui->constantDoubleSpinBox->value(),
                          ui->amplitudeSinusoidalDoubleSpinBox->value(),
                          ui->periodSinusoidalDoubleSpinBox_2->value(),
                          ui->amplitudeSquareDoubleSpinBox_3->value(),
                          ui->periodSquareDoubleSpinBox_4->value(),
                          ui->dutyCycleSquareDoubleSpinBox_5->value());
    }
    facade->stopSimulation();
    facade->setPIDSettings(ui->kDoubleSpinBox->value(),
                           ui->tiDoubleSpinBox_2->value(),
                           ui->tdDoubleSpinBox_3->value(),
                           ui->constCheckBox->isChecked());
    //facade->setPID(ui->kDoubleSpinBox->value(),ui->tiDoubleSpinBox_2->value(),ui->tdDoubleSpinBox_3->value());
    facade->setTimeInterval(ui->timeIntervalSpinBox->value());
    if (ui->manualRadioButton->isChecked()) {
        facade->setConstantSignal(ui->constantDoubleSpinBox->value(), ui->activationTimeSpinBox->value());
    } else if (ui->sinusoidalRadioButton_2->isChecked()) {
        facade->setSinusoidalSignal(ui->amplitudeSinusoidalDoubleSpinBox->value(),
                                    ui->periodSinusoidalDoubleSpinBox_2->value(),
                                    ui->sinusoidConstantdoubleSpinBox_2->value());
    } else if (ui->squareRadioButton_3->isChecked()) {
        facade->setSquareSignal(ui->amplitudeSquareDoubleSpinBox_3->value(),
                                ui->periodSquareDoubleSpinBox_4->value(),
                                ui->dutyCycleSquareDoubleSpinBox_5->value(),
                                ui->squareConstantSpinBox_3->value());
    } else {
        qDebug() << "Choose type of Signal";
        return;
    }
    facade->setActual(ui->kDoubleSpinBox->value(),
                      ui->tiDoubleSpinBox_2->value(),
                      ui->tdDoubleSpinBox_3->value(),
                      ui->timeIntervalSpinBox->value(),
                      ui->constantDoubleSpinBox->value(),
                      ui->amplitudeSinusoidalDoubleSpinBox->value(),
                      ui->periodSinusoidalDoubleSpinBox_2->value(),
                      ui->amplitudeSquareDoubleSpinBox_3->value(),
                      ui->periodSquareDoubleSpinBox_4->value(),
                      ui->dutyCycleSquareDoubleSpinBox_5->value());
    facade->startSimulation();
}

void MainWindow::on_startButton_clicked()
{
    if (ui->manualRadioButton->isChecked() == true
        || ui->sinusoidalRadioButton_2->isChecked() == true
        || ui->squareRadioButton_3->isChecked() == true) {
        on_actualizeButton_clicked();
        facade->startSimulation();
    } else {
        qDebug() << "Choose type of Signal";
        return;
    }
}

void MainWindow::on_stopButton_clicked()
{
    facade->stopSimulation();
}

void MainWindow::on_resetButton_clicked()
{
    facade->stopSimulation();
    facade->resetSimulation();
    ui->mainPlot->graph(0)->data()->clear();
    ui->mainPlot->graph(1)->data()->clear();
    ui->errorPlot->graph(0)->data()->clear();
    ui->pidPlot->graph(0)->data()->clear();
    ui->pidPlot->graph(1)->data()->clear();
    ui->pidPlot->graph(2)->data()->clear();
    ui->pidPlot->graph(3)->data()->clear();

    //ui->mainPlot->rescaleAxes();
    ui->mainPlot->xAxis->setRange(0, 15);
    ui->mainPlot->yAxis->setRange(-10, 10);

    ui->errorPlot->xAxis->setRange(0, 15);
    ui->errorPlot->yAxis->setRange(-10, 10);

    ui->pidPlot->xAxis->setRange(0, 15);
    ui->pidPlot->yAxis->setRange(-10, 10);

    // Optionally, replot the charts
    ui->mainPlot->replot();
    ui->errorPlot->replot();
    ui->pidPlot->replot();

    ui->mainPlot->update();
    ui->errorPlot->update();
    ui->pidPlot->update();
}

void MainWindow::on_actionSAVE_TO_FILE_triggered()
{
    facade->stopSimulation();

    QString fileName = QFileDialog::getSaveFileName(this, "SAVE TO FILE", "", "Text Files (*.txt)");

    if (fileName.isEmpty()) {
        return;
    }

    if (!fileName.endsWith(".txt", Qt::CaseInsensitive)) {
        fileName += ".txt";
    }

    facade->saveToFile(fileName);
}

void MainWindow::on_actionLOAD_FROM_FILE_triggered()
{

    QString fileName = QFileDialog::getOpenFileName(this, "LOAD FROM FILE");
    if(fileName.isEmpty()){
        qDebug() << "Empty filename!";
        return;
    }
    else{
        on_resetButton_clicked();
        facade->loadFromFile(fileName);
        //load data from vector
        auto history = facade->getHistory();
        double time = 0;
        double generatedValue = 0;
        double error = 0;
        double controlValue = 0;
        double adjustedValue = 0;
        double proportional =0;
        double integral =0;
        double derivative =0;
        for (const auto &[generatedValue, error, controlValue, adjustedValue] : history) {
            ui->mainPlot->graph(0)->addData(time, generatedValue);
            ui->mainPlot->graph(1)->addData(time, adjustedValue);
            ui->errorPlot->graph(0)->addData(time, error);
            ui->pidPlot->graph(0)->addData(time, controlValue);
            time++;
        }
        updatePlots(time,generatedValue,error,controlValue,adjustedValue, proportional, integral, derivative);
        ui->kDoubleSpinBox->setValue(facade->getActualK());
        ui->tiDoubleSpinBox_2->setValue(facade->getActualTi());
        ui->tdDoubleSpinBox_3->setValue(facade->getActualTd());

        std::vector<double> temp = facade->getActualArxA();
        QString result="";
        for (size_t i = 0; i < temp.size(); ++i) {
            result += QString::number(temp[i]); // Convert number to QString
            if (i != temp.size() - 1) { // Avoid trailing separator
                result += ';';
            }
        }
        this->AtextField = result;

        temp = facade->getActualArxB();
        result="";
        for (size_t i = 0; i < temp.size(); ++i) {
            result += QString::number(temp[i]); // Convert number to QString
            if (i != temp.size() - 1) { // Avoid trailing separator
                result += ';';
            }
        }
        this->BtextField = result;
        this->kField = facade->getActualArxK();
    }
}

void MainWindow::on_actionLocalhost_triggered()
{
    dialogLocalhost = new DialogLocalhost();
    if(dialogLocalhost->exec() == QDialog::Accepted)
    {
        networkHandler = new Network();
        if(dialogLocalhost->getNetworkMode() == NetworkMode::Server)
        {
            networkHandler->startAsServer(11111);
        }
        else if(dialogLocalhost->getNetworkMode() == NetworkMode::Client)
        {
            networkHandler->startAsClient("127.0.0.1", 11111);
        }
    }
    ui->actionLocalhost->setVisible(0);
    ui->actionLAN->setVisible(0);
    ui->actionDirect_Network->setVisible(0);
    ui->actionDisconnect->setVisible(1);
}

void MainWindow::on_actionDisconnect_triggered()
{
    networkHandler->disconnect();
    ui->actionLocalhost->setVisible(1);
    ui->actionLAN->setVisible(1);
    ui->actionDirect_Network->setVisible(1);
    ui->actionDisconnect->setVisible(0);
}

void MainWindow::on_action_Direct_Network_triggered()
{
    dialogDirect = new DialogDirectNetwork();
    if(dialogDirect->exec() == QDialog::Accepted)
    {
        networkHandler = new Network();
        if(dialogDirect->getNetworkMode() == NetworkMode::Server)
        {
            networkHandler->startAsServer(11111);
        }
        else if(dialogDirect->getNetworkMode() == NetworkMode::Client)
        {
            networkHandler->startAsClient(dialogDirect->getIpAddress(), 11111);
        }
    }
    ui->actionLocalhost->setVisible(0);
    ui->actionLAN->setVisible(0);
    ui->actionDirect_Network->setVisible(0);
    ui->actionDisconnect->setVisible(1);
}
