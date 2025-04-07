#define _USE_MATH_DEFINES
#pragma once
#include <cassert>
#include <cmath>
#include <iostream>
#include <math.h>
#include <memory>
#include <string>
#include <vector>
#include <random>
using namespace std;

class Arx
{
private:
    vector<double> a;
    vector<double> b;
    int k;
    double noise;
    vector<double> adjustedValuesBuffer;
    vector<double> controlValuesBuffer;
    double generateNormalNoise(double stddev);

public:
    Arx()
        : a()
        , b()
        , k(0)
        , noise(0.0)
    {}
    Arx(const vector<double> &a, const vector<double> &b, int k, double noise);

    void addControlValue(double controlValue);

    void addAdjustedValue(double adjustedValue);

    double getAdjustedValue(double controlValue);

    const std::vector<double> &getA() const { return a; }
    const std::vector<double> &getB() const { return b; }
    int getK() const { return k; }
    double getNoise() const { return noise; }
    void setA(const std::vector<double> &a) { this->a = a; }
    void setB(const std::vector<double> &b) { this->b = b; }
    void setK(int k) { this->k = k; }
    void setNoise(double noise) { this->noise = noise; }
    void reset();
};
