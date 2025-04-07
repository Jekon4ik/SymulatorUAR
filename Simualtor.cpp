#include "Simulator.h"

void Simulator::setState(double generatedValue,
                         double error,
                         double controlValue,
                         double adjustedValue,
                         double proportionalPIDPart,
                         double integralPIDPart,
                         double derivativePIDPart)
{
    this->generatedValue = generatedValue;
    this->error = error;
    this->controlValue = controlValue;
    this->adjustedValue = adjustedValue;
    this->proportionalPIDPart = proportionalPIDPart;
    this->integralPIDPart = integralPIDPart;
    this->derivativePIDPart = derivativePIDPart;
}

vector<double> Simulator::getState()
{
    vector<double> values = {static_cast<double>(this->timeToReturn),
                             static_cast<double>(this->generatedValue),
                             static_cast<double>(this->error),
                             static_cast<double>(this->controlValue),
                             static_cast<double>(this->adjustedValue),
                             static_cast<double>(this->proportionalPIDPart),
                             static_cast<double>(this->integralPIDPart),
                             static_cast<double>(this->derivativePIDPart)};
    return values;
}

void Simulator::timeSleep(int interval)
{
    std::this_thread::sleep_for(std::chrono::milliseconds(interval));
}

Simulator::Simulator()
{
    this->arx = nullptr;
    this->pid = nullptr;
    this->feedback = nullptr;
    this->setpointGenerator = nullptr;
}

Simulator::Simulator(Arx *arx, PID *pid, Feedback *feedback, SetpointGenerator *setpointGenerator)
{
    this->arx = arx;
    this->pid = pid;
    this->feedback = feedback;
    this->setpointGenerator = setpointGenerator;
}
void Simulator::setARX(Arx *arx)
{
    this->arx = arx;
}
void Simulator::setPID(PID *pid)
{
    this->pid = pid;
}
void Simulator::setFeedback(Feedback *fb)
{
    this->feedback = fb;
}
void Simulator::setGenerator(SetpointGenerator *generator)
{
    this->setpointGenerator = generator;
}
void Simulator::setTimeInterval(int interval)
{
    this->timeInterval = interval;
}

void Simulator::runSimulation() {


    if (time == 0) {  // First run
        startTime = std::chrono::steady_clock::now();
        elapsedTime = 0.0;
    } else if (!isSimulationRunning) {  // Resuming after pause
        startTime = std::chrono::steady_clock::now() - std::chrono::duration_cast<std::chrono::steady_clock::duration>(
                        std::chrono::duration<double>(timeToReturn));
    }
    this->isSimulationRunning = true;
    this->time++;

    // Calculate real elapsed time
    auto now = std::chrono::steady_clock::now();
    double realTime = std::chrono::duration<double>(now - startTime).count();

    double generatedValue = this->setpointGenerator->generate(realTime);
    feedback->setGeneratedValue(generatedValue);
    double error = feedback->getError();
    double controlValue = pid->getControlledValue(error);
    double adjustedValue = arx->getAdjustedValue(controlValue);
    this->feedback->setMeasuredValue(adjustedValue);
    error = feedback->getError();

    // Store real time
    this->timeToReturn = realTime;

    double proportional = this->pid->getActualProportionalPart();
    double integral = this->pid->getActualIntegralPart();
    double derivative = this->pid->getActualDerivativePart();
    qDebug() << "time = " << time << "Real time= " << realTime << " w = " << generatedValue
             << "; error = " << feedback->getError() << "; u = " << controlValue
             << "; y = " << adjustedValue << "Time Interval = " << this->timeInterval;

    setState(generatedValue, error, controlValue, adjustedValue, proportional, integral, derivative);
}

void Simulator::stopSimulation()
{
    this->isSimulationRunning = false;
    auto now = std::chrono::steady_clock::now();
    elapsedTime += std::chrono::duration<double>(now - startTime).count();
    qDebug() << "STOPPPP " << elapsedTime;
}
void Simulator::resetSimulation()
{
    this->isSimulationRunning = false;
    this->time = 0;
    elapsedTime = 0.0;
    generationHistory.resize(0);
}

void Simulator::changeMode(SignalStrategy *strategy)
{
    this->setpointGenerator->setStrategy(strategy);
}

SimulatorMemento Simulator::saveState()
{
    auto now = std::chrono::steady_clock::now();
    double realTime = std::chrono::duration<double>(now - startTime).count();
    qDebug() << "State saved: time = " << realTime;
    return SimulatorMemento(realTime,  // Передаємо реальний час
                            this->generatedValue,
                            this->error,
                            this->controlValue,
                            this->adjustedValue,
                            arx->getA(),
                            arx->getB(),
                            arx->getK(),
                            pid->getK(),
                            pid->getTi(),
                            pid->getTd(),
                            generationHistory);
}

void Simulator::restoreState(const SimulatorMemento &memento)
{
    this->time = static_cast<int>(memento.getTime());  // Відновлення часу
    this->generatedValue = memento.getGeneratedValue();
    this->error = memento.getError();
    this->controlValue = memento.getControlValue();
    this->adjustedValue = memento.getAdjustedValue();

    // Встановлюємо стартовий час заново
    startTime = std::chrono::steady_clock::now() - std::chrono::duration_cast<std::chrono::steady_clock::duration>(
                    std::chrono::duration<double>(memento.getTime()));

    qDebug() << "State restored: time = " << memento.getTime();
}

void Simulator::saveToFile(const std::string &filename)
{
    // Collect ARX and PID settings
    std::vector<double> arxA = arx->getA();
    std::vector<double> arxB = arx->getB();
    int arxK = arx->getK();

    double pidK = pid->getK();
    double pidTi = pid->getTi();
    double pidTd = pid->getTd();

    // Create the history vector
    std::vector<std::tuple<double, double, double, double>> history = generationHistory;

    // Create the memento
    SimulatorMemento memento(this->time,
                             this->generatedValue,
                             this->error,
                             this->controlValue,
                             this->adjustedValue,
                             arxA,
                             arxB,
                             arxK,
                             pidK,
                             pidTi,
                             pidTd,
                             history);

    // Save to file
    std::ofstream ofs(filename);
    if (ofs.is_open()) {
        ofs << memento.serialize();
        ofs.close();
    } else {
        qDebug() << "Failed to open file for saving.";
        throw std::runtime_error("Failed to open file for saving.");
    }
}

void Simulator::loadFromFile(const std::string &filename)
{
    std::ifstream ifs(filename);
    if (ifs.is_open()) {
        std::string data;
        std::stringstream buffer;
        buffer << ifs.rdbuf();
        data = buffer.str();
        ifs.close();

        SimulatorMemento memento = SimulatorMemento::deserialize(data);

        this->time = memento.getTime();
        this->generatedValue = memento.getGeneratedValue();
        this->error = memento.getError();
        this->controlValue = memento.getControlValue();
        this->adjustedValue = memento.getAdjustedValue();

        qDebug() << "Memento readed: time " << memento.getTime() << " "
                 << memento.getGeneratedValue() << " " << memento.getError() << " "
                 << memento.getControlValue() << " " << memento.getAdjustedValue();

        arxASettings = memento.getArxA();
        arxBSettings = memento.getArxB();
        arxKSettings = memento.getArxK();
        pidSettings[0] = memento.getPidK();
        pidSettings[1] = memento.getPidTi();
        pidSettings[2] = memento.getPidTd();

        this->generationHistory = memento.getHistory();

    } else {
        throw std::runtime_error("Failed to open file for loading.");
    }
}

double Simulator::getTime() const
{
    return this->time;
}

double Simulator::getError() const
{
    return this->error;
}

double Simulator::getRegulatedValue() const
{
    return adjustedValue;
}

double Simulator::getControllValue() const
{
    return controlValue;
}
int Simulator::getTimeInterval()
{
    return this->timeInterval;
}

Arx *Simulator::getARX()
{
    return this->arx;
}
PID *Simulator::getPID()
{
    return this->pid;
}
Feedback *Simulator::getFeedback()
{
    return this->feedback;
}
SetpointGenerator *Simulator::getGenerator()
{
    return this->setpointGenerator;
}

std::shared_ptr<Arx> Simulator::getARXSettings()
{
    std::vector<double> a = this->arx->getA();
    std::vector<double> b = this->arx->getB();
    int k_value = this->arx->getK();
    double noise = this->arx->getNoise();
    return std::make_shared<Arx>(a, b, k_value, noise);
}
std::shared_ptr<PID> Simulator::getPIDSettings()
{
    double k = this->pid->getK();
    double ti = this->pid->getTi();
    double td = this->pid->getTd();

    return std::make_shared<PID>(k, ti, td);
}
std::vector<double> Simulator::getArxASettings()
{
    return this->arxASettings;
}
std::vector<double> Simulator::getArxBSettings()
{
    return this->arxBSettings;
}
int Simulator::getArxKSettings()
{
    return this->arxKSettings;
}

std::vector<double> Simulator::getPidSettings()
{
    return this->pidSettings;
}

std::vector<std::tuple<double, double, double, double>> Simulator::getHistory()
{
    return this->generationHistory;
}
