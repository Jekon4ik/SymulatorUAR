#include "Facade.h"
#include "qtimer.h"
#include "mainwindow.h"
Facade::Facade()
{
    this->simulator = new Simulator();
    this->simulator->setFeedback(new Feedback());
    this->simulator->setGenerator(new SetpointGenerator());
    this->simulator->setARX(new Arx({-0.4}, {0.6}, 1,0));
    this->simulator->setPID(new PID(0.5, 10, 0.2));
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &Facade::runSimulationStep);

}

bool areVectorsEqual(const std::vector<double>& v1, const std::vector<double>& v2, double epsilon = 1e-9) {
    if (v1.size() != v2.size()) {
        return false;
    }

    for (size_t i = 0; i < v1.size(); ++i) {
        if (std::abs(v1[i] - v2[i]) > epsilon) { // Handling floating-point precision issues
            return false;
        }
    }

    return true;
}
void Facade::setARX(vector<double> a, vector<double> b, int k, double noise)
{
    Arx* oldArx = this->simulator->getARX();  // Store the pointer before deleting

    if (oldArx) {
        vector<double> oldA = oldArx->getA();
        vector<double> oldB = oldArx->getB();
        int oldK = oldArx->getK();
        double oldNoise = oldArx->getNoise();
        if (!areVectorsEqual(oldA, a) || !areVectorsEqual(oldB, b) || oldK != k) {
            delete oldArx;  // Now it's safe to delete after storing values
            Arx* newArx = new Arx(a, b, k, noise);
            this->simulator->setARX(newArx);
            qDebug() << "NEW1 arx created";
        } else {
            if(oldNoise != noise){
                oldArx->setNoise(noise);
                qDebug() << "arx noise changed";
            }
            qDebug() << "arx not changed";
        }
    } else {  // If there was no ARX, create a new one
        this->simulator->setARX(new Arx(a, b, k, noise));
        qDebug() << "New2 arx created";
    }
}
void Facade::setARXSettings(vector<double> a, vector<double> b, int k, double noise)
{
    qDebug() << "debug moment2";
    if (this->simulator->getARX() == nullptr) {
        setARX(a, b, k, noise);
    } else {
        this->simulator->getARX()->setA(a);
        this->simulator->getARX()->setB(b);
        this->simulator->getARX()->setK(k);
        qDebug() << "arx changed";
    }
}
void Facade::setPID(double k, double Ti, double Td)
{
    if (this->simulator->getPID() != nullptr)
        delete this->simulator->getPID();
    PID *pid = new PID(k, Ti, Td);
    this->simulator->setPID(pid);
    qDebug() << "new pid created";
}
void Facade::setPIDSettings(double k, double Ti, double Td, bool constWithSum)
{
    if (this->simulator->getPID() == nullptr) {
        setPID(k, Ti, Td);
    } else {
        this->simulator->getPID()->setK(k);
        this->simulator->getPID()->setTi(Ti);
        this->simulator->getPID()->setTd(Td);
        this->simulator->getPID()->setConstWithSum(constWithSum);
        qDebug() << "pid changed";
    }
}

void Facade::setConstantSignal(double val, double activationTime)
{
    ConstantSignal *signal = new ConstantSignal(val, activationTime);
    this->simulator->changeMode(signal);
}

void Facade::setSinusoidalSignal(double amplitude, double period,  double constant)
{
    SinusoidSignal *signal = new SinusoidSignal(amplitude, period, constant);
    this->simulator->changeMode(signal);
}
void Facade::setSquareSignal(double amplitude, double period, double dutyCycle,  double constant)
{
    SquareSignal *signal = new SquareSignal(amplitude, period, dutyCycle, constant);
    this->simulator->changeMode(signal);
}

void Facade::setActual(double actualK,
                       double actualTi,
                       double actualTd,
                       double actualInterval,
                       double actualConstantValue,
                       double actualSinusoidalAmplitude,
                       double actualSinusoidalPeriod,
                       double actualSquareAmplitude,
                       double actualSquarelPeriod,
                       double actualSquarelDutyCycle)
{
    this->actualK = actualK;
    this->actualTi = actualTi;
    this->actualTd = actualTd;
    this->actualInterval = actualInterval;
    this->actualConstantValue = actualConstantValue;
    this->actualSinusoidalAmplitude = actualSinusoidalAmplitude;
    this->actualSinusoidalPeriod = actualSinusoidalPeriod;
    this->actualSquareAmplitude = actualSquareAmplitude;
    this->actualSquarelPeriod = actualSquarelPeriod;
    this->actualSquarelDutyCycle = actualSquarelDutyCycle;
}

std::vector<double> Facade::getActual()
{
    std::vector<double> actualValues;

    actualValues.push_back(actualK);
    actualValues.push_back(actualTi);
    actualValues.push_back(actualTd);
    actualValues.push_back(actualInterval);
    actualValues.push_back(actualConstantValue);
    actualValues.push_back(actualSinusoidalAmplitude);
    actualValues.push_back(actualSinusoidalPeriod);
    actualValues.push_back(actualSquareAmplitude);
    actualValues.push_back(actualSquarelPeriod);
    actualValues.push_back(actualSquarelDutyCycle);

    return actualValues;
}
double Facade::getActualK()
{
    return this->actualK;
}

bool Facade::isSimulatorInitialized()
{
    if (this->simulator->getARX() == nullptr)
        return false;
    if (this->simulator->getPID() == nullptr)
        return false;
    if (this->simulator->getFeedback() == nullptr)
        return false;
    if (this->simulator->getGenerator() == nullptr)
        return false;
    return true;
}

void Facade::setTimeInterval(int interval)
{
    this->simulator->setTimeInterval(interval);
}

void Facade::startSimulation()
{
    if (!isSimulatorInitialized()) {
        qDebug() << "Simulator is not initialized!";
        return;
    }

    simulation = true;
    timer->start(this->simulator->getTimeInterval());
    qDebug() << "Simulation started with interval" << this->simulator->getTimeInterval();
}

void Facade::stopSimulation()
{
    simulation = false;
    timer->stop();
    this->simulator->stopSimulation();
    qDebug() << "Simulation stopped!";
}
void Facade::setStatus(QLabel* label)
{
    this->label=label;

}
void Facade::runSimulationStep()
{
    if (simulation) {
        switch (netMode) {
        case NetworkMode::Offline: {
            qDebug() << "OFFLINE MODE";
            this->simulator->runSimulation();
            vector<double> values = this->simulator->getState();
            emit newSimulationData(values[0], values[1], values[2], values[3], values[4], values[5], values[6], values[7]);
            qDebug() << "from facade. Time:" << values[0] << " Generated Value:" << values[1] << " Error:" << values[2]
                     << "ControlValue(PID)" <<values[3] << " Adjusted Value(ARX):" << values[4]
                     << "P:" << values[5] << "I:" << values[6] << "D:" << values[7];
            break;
        }
        case NetworkMode::Client: {
            qDebug() << "CLIENT MODE";
            simulator->runSimulation();
            auto v = simulator->getState();
            double time           = v[0];
            double gen            = v[1];
            double err            = v[2];
            double u              = v[3];
            double localY         = v[4];
            double pPart          = v[5];
            double iPart          = v[6];
            double dPart          = v[7];

            emit sendControlledValue(u, time, gen);

            double y;
            if (haveNewNetValue) {
                label->setStyleSheet("background-color: green; border-radius: 10px;");
                y               = lastNetValue;
                haveNewNetValue = false;
            } else {
                label->setStyleSheet("background-color: red; border-radius: 10px;");
                y = localY;
            }

            simulator->getFeedback()->setMeasuredValue(y);

            emit newSimulationData(time, gen, err, u, y, pPart, iPart, dPart);
            break;
        }

        case NetworkMode::Server: {
            qDebug() << "SERVER MODE";
            if (!haveNewNetValue)
            {
                label->setStyleSheet("background-color: red; border-radius: 10px;");
                return;
            }
             label->setStyleSheet("background-color: green; border-radius: 10px;");
            double u = lastNetValue;
            double time = lastNetTime;
            double gen = lastNetGen;
            haveNewNetValue = false;

            double y = simulator->getARX()->getAdjustedValue(u);

            emit sendMeasuredValue(y);
            emit newSimulationData(time, gen, 0.0, u, y, 0.0, 0.0, 0.0);
            break;
        }
    }
}
}
void Facade::resetSimulation()
{
    this->simulator->resetSimulation();
    Arx *newArx = new Arx(this->simulator->getARX()->getA(),
                          this->simulator->getARX()->getB(),
                          this->simulator->getARX()->getK(),
                          this->simulator->getARX()->getNoise());
    if (this->simulator->getARX() != nullptr)
        delete this->simulator->getARX();
    this->simulator->setARX(newArx);

    if (this->simulator->getPID() != nullptr)
        delete this->simulator->getPID();
    this->simulator->setPID(new PID(this->simulator->getPID()->getK(),
                                    this->simulator->getPID()->getTi(),
                                    this->simulator->getPID()->getTd()));

    delete this->simulator->getFeedback();
    this->simulator->setFeedback(new Feedback());
    delete this->simulator->getGenerator();
    this->simulator->setGenerator(new SetpointGenerator());
}

void Facade::saveToFile(QString filename)
{
    this->simulator->saveToFile(filename.toStdString());
}

void Facade::loadFromFile(QString filename)
{
    this->simulator->loadFromFile(filename.toStdString());
    setARX(this->simulator->getArxASettings(),
           this->simulator->getArxBSettings(),
           this->simulator->getArxKSettings(),
           0.1);
    std::vector<double> temp = this->simulator->getPidSettings();
    setPID(temp[0], temp[1], temp[2]);
    this->actualK = temp[0];
    this->actualTi = temp[1];
    this->actualTd = temp[2];
    this->actualArxA = this->simulator->getArxASettings();
    this->actualArxB = this->simulator->getArxBSettings();
    this->actualArxK = this->simulator->getArxKSettings();
}

std::vector<std::tuple<double, double, double, double>> Facade::getHistory()
{
    return this->simulator->getHistory();
}

double Facade::getActualTi(){
    return this->actualTi;
}
double Facade::getActualTd(){
    return this->actualTd;
}

int Facade::getActualArxK(){
    return this->actualArxK;
}

std::vector<double> Facade::getActualArxA(){
    return this->actualArxA;
}
std::vector<double> Facade::getActualArxB(){
    return this->actualArxB;
}

void Facade::setNetworkMode(NetworkMode m) {
    netMode = m;
    haveNewNetValue = true;
}

void Facade::onNetworkControl(double value, double time, double gen) {
    qDebug() << "[Facade Server] controlValueReceived:" << value;
    if (netMode != NetworkMode::Server) return;
    lastNetValue = value;
    lastNetTime = time;
    lastNetGen = gen;
    haveNewNetValue = true;

    runSimulationStep();
}

void Facade::onNetworkMeasured(double y) {
    qDebug() << "[Facade] measuredValueReceived:" << y;
    lastNetValue = y;
    haveNewNetValue = true;
}
