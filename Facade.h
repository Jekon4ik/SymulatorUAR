#ifndef FACADE_H
#define FACADE_H
#pragma once

#include <QVector>
#include "ARX.h"
#include "Feedback.h"
#include "SetpointGenerator.h"
#include "Simulator.h"
#include "SimulatorMemento.h"
#include "qobject.h"
#include <vector>

class Facade : public QObject
{
    Q_OBJECT
private:
    Simulator *simulator;

    QTimer *timer;

    double actualK = -1;
    double actualTi;
    double actualTd;

    std::vector<double> actualArxA;
    std::vector<double> actualArxB;
    int actualArxK;

    double actualInterval;

    double actualConstantValue;

    double actualSinusoidalAmplitude;
    double actualSinusoidalPeriod;

    double actualSquareAmplitude;
    double actualSquarelPeriod;
    double actualSquarelDutyCycle;

    bool simulation = false;

public:
    Facade();
    void initializeSimulator();

    void setARX(vector<double> a, vector<double> b, int k, double noise);
    void setARXSettings(vector<double> a, vector<double> b, int k, double noise);
    void setPID(double k, double Ti, double Td);
    void setPIDSettings(double k, double Ti, double Td, bool constWithSum);
    void setConstantSignal(double value, double activationTime);
    void setSinusoidalSignal(double amplitude, double period, double constant);
    void setSquareSignal(double amplitude, double period, double dutyCycle, double constant);
    void setTimeInterval(int interval);

    void resetSimulation();
    void actualize();
    void startSimulation();
    void stopSimulation();

    void loadFromFile(QString fileName);
    void saveToFile(QString fileName);

    void setActual(double actualK,
                   double actualTi,
                   double actualTd,
                   double actualInterval,
                   double actualConstantValue,
                   double actualSinusoidalAmplitude,
                   double actualSinusoidalPeriod,
                   double actualSquareAmplitude,
                   double actualSquarelPeriod,
                   double actualSquarelDutyCycle);
    std::vector<double> getActual();

    bool isSimulatorInitialized();

    double getActualK();
    double getActualTi();
    double getActualTd();
    std::vector<double> getActualArxA();
    std::vector<double> getActualArxB();
    int getActualArxK();
    std::vector<std::tuple<double, double, double, double>> getHistory();
private slots:
    void runSimulationStep();
signals:
    void newSimulationData(double time,
                           double generatedValue,
                           double error,
                           double controlValue,
                           double adjustedValue,
                           double proportionalPIDPart,
                           double integralPIDPart,
                           double derivativePIDPart);
};

#endif // FACADE_H
