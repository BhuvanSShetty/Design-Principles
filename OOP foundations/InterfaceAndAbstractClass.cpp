#include <iostream>
#include <string>

using namespace std;

class IEngine {
public:
    virtual void start() = 0;
    virtual void stop() = 0;
    virtual ~IEngine() = default;
};

class Car : public IEngine {
protected:
    string model;

public:
    explicit Car(string carModel) : model(carModel) {}

    void start() override {
        cout << model << " engine started\n";
    }

    virtual void stop() override = 0;
};

class HandBrakeCar : public Car {
public:
    explicit HandBrakeCar(string carModel) : Car(carModel) {}

    void stop() override {
        cout << model << " stopped using handbrake\n";
    }
};

class BrakeCar : public Car {
public:
    explicit BrakeCar(string carModel) : Car(carModel) {}

    void stop() override {
        cout << model << " stopped using brake\n";
    }
};

int main() {
    HandBrakeCar suv("SUV");
    BrakeCar sedan("Sedan");

    suv.start();
    suv.stop();

    sedan.start();
    sedan.stop();

    return 0;
}