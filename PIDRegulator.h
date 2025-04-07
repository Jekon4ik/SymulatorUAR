#define _USE_MATH_DEFINES
#pragma once
#include <cassert>
#include <cmath>
#include <iostream>
#include <math.h>
#include <memory>
#include <string>
#include <vector>

class PID
{
private:
    double k = 0;
    double Ti = 0;
    double Td = 0;

    double error = 0;

    double errorSum = 0;

    double previosError = 0;
    bool constWithSum = false;

    double calculateProportional();
    double calculateIntegral();
    double calculateIntegralBeforeSum();
    double calculateDerivative();


    double actualProportionalPart;
    double actualIntegralPart;
    double actualDerivativePart;

    double lastControlValue = 0;


public:
    PID(double k);
    PID(double k, double Ti);
    PID(double k, double Ti, double Td);
    void setError(double error);
    double getControlledValue(double error);
    double getLastControllValue() const;

    double getK() const { return k; }
    double getTi() const { return Ti; }
    double getTd() const { return Td; }

    double getActualProportionalPart() const { return actualProportionalPart; }
    double getActualIntegralPart() const { return actualIntegralPart; }
    double getActualDerivativePart() const { return actualDerivativePart; }

    void setConstWithSum(bool constWithSum);
    void setK(double k);
    void setTi(double Ti);
    void setTd(double Td);
    void reset()
    {
        error = 0;
        errorSum = 0;
        previosError = 0;
        lastControlValue = 0;
    }
};
