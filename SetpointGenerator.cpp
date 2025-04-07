#include "SetpointGenerator.h"

ConstantSignal::ConstantSignal(double value, double activationTime)
{
    this->value = value;
    this->activationTime = activationTime;
}
double ConstantSignal::generateSignal(double time) //override
{
    if(time >= activationTime) return value;
    else return 0;
}

SinusoidSignal::SinusoidSignal(double amplitude, double period, double constant)
{
    this->amplitude = amplitude;
    this->period = period;
    this->constant = constant;
}
double SinusoidSignal::generateSignal(double time) //override
{
    if (this->amplitude == 0 || this->period == 0)
        return 0;
    return amplitude * sin(2 * M_PI / period * time) + constant;
}

SquareSignal::SquareSignal(double amplitude, double period, double dutyCycle, double constant)
{
    this->amplitude = amplitude;
    this->period = period;
    this->dutyCycle = dutyCycle;
    this->constant = constant;
}
double SquareSignal::generateSignal(double time) //override
{
    double t = fmod(time, period);
    double high_time = period * dutyCycle;
    if (t < high_time)
        return amplitude+constant;
    else
        return constant;
}

void SetpointGenerator::setStrategy(SignalStrategy *strategy)
{
    this->strategy = strategy;
}
double SetpointGenerator::generate(double time) const
{
    if (strategy != nullptr)
        return strategy->generateSignal(time);

    throw std::runtime_error("No strategy set for the generator");
}
