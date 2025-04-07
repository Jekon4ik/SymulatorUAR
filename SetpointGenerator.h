#define _USE_MATH_DEFINES
#pragma once
#include <cassert>
#include <cmath>
#include <iostream>
#include <math.h>
#include <memory>
#include <string>
#include <vector>

using namespace std;

class SignalStrategy
{
public:
    virtual ~SignalStrategy() = default;
    virtual double generateSignal(double time) = 0;
};

class ConstantSignal : public SignalStrategy
{
private:
    double value;
    int activationTime;

public:
    explicit ConstantSignal(double value, double activationTime);
    double generateSignal(double time) override;
};

class SinusoidSignal : public SignalStrategy
{
private:
    double amplitude;
    double period;
    double constant;

public:
    SinusoidSignal(double amplitude, double period, double constant);
    double generateSignal(double time) override;
};

class SquareSignal : public SignalStrategy
{
private:
    double amplitude;
    double period;
    double dutyCycle;
    double constant;

public:
    SquareSignal(double amplitude, double period, double dutyCycle, double constant);
    double generateSignal(double time);
};

class SetpointGenerator
{
private:
    SignalStrategy *strategy = nullptr;

public:
    void setStrategy(SignalStrategy *strategy);
    double generate(double time) const;
};
