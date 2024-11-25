#include <iostream>
#include <memory>
#include <string>
using namespace std;

class IOutput {
public:
    virtual ~IOutput() = default;
    virtual void print(const string& message) = 0;
};

class ConsoleOutput : public IOutput {
public:
    void print(const string& message) override {
        cout << message << endl;
    }
};

class IOTCloudCommunicator {
public:
    virtual ~IOTCloudCommunicator() = default;
    virtual int pushMessage(const string& message) = 0;
};

class RandomIOTCloudCommunicator : public IOTCloudCommunicator {
public:
    int pushMessage(const string& message) override {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> distr(200, 500);
        return distr(gen);
    }
};

class BNFSpeedSensor {
public:
    virtual ~BNFSpeedSensor() = default;
    virtual int getCurrentSpeed() = 0;
};

class RandomBNFSpeedSensor : public BNFSpeedSensor {
public:
    int getCurrentSpeed() override {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> distr(1, 100);
        return distr(gen);
    }
};

class SpeedMonitor {
private:
    int _speedThreshold;
    shared_ptr<BNFSpeedSensor> _speedSensor;
    shared_ptr<IOTCloudCommunicator> _cloudCommunicator;
    shared_ptr<IOutput> _output;

public:
    SpeedMonitor(int speedThreshold, shared_ptr<BNFSpeedSensor> speedSensor, shared_ptr<IOTCloudCommunicator> cloudCommunicator, shared_ptr<IOutput> output)
        : _speedThreshold(speedThreshold), _speedSensor(speedSensor), _cloudCommunicator(cloudCommunicator), _output(output) {}

    void monitor() {
        if (!isValidSpeedThreshold()) {
            reportInvalidSpeedThreshold();
            return;
        }

        int currentSpeedInKmph = _speedSensor->getCurrentSpeed();
        _output->print("Current Speed In Kmph: " + to_string(currentSpeedInKmph));

        if (currentSpeedInKmph > _speedThreshold) {
            double mph = currentSpeedInKmph * 0.621371;
            string message = "Current Speed in Miles: " + to_string(mph);
            int statusCode = _cloudCommunicator->pushMessage(message);
            if (statusCode > 400) {
                reportCommunicationError(message);
            }
        }
    }

private:
    bool isValidSpeedThreshold() const {
        return _speedThreshold >= 1 && _speedThreshold <= 100;
    }

    void reportInvalidSpeedThreshold() const {
        _output->print("_speedThreshold value must be in the range {1-100}: " + to_string(_speedThreshold));
    }

    void reportCommunicationError(const string& message) const {
        _output->print("Error In Communication Unable to Contact Server: " + message);
    }
};

int main() {
    auto speedSensor = make_shared<RandomBNFSpeedSensor>();
    auto cloudCommunicator = make_shared<RandomIOTCloudCommunicator>();
    auto output = make_shared<ConsoleOutput>();

    SpeedMonitor instance{10, speedSensor, cloudCommunicator, output};

    instance.monitor();
    instance.monitor();
    instance.monitor();
    instance.monitor();
    instance.monitor();
}
