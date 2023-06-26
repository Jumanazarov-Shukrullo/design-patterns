#include <iostream>
#include "Car.cpp"


class CarFactory {
protected:
    Car *car{};
protected:
    virtual Tire *buildTire() = 0;

    virtual Body *buildBody() = 0;

public:
    virtual Car *buildWholeCar() = 0;
};

class SimpleCarFactory : public CarFactory {
public:
    Tire *buildTire() override {
        return new SimpleTire();
    }

    Body *buildBody() override {
        return new SimpleBody();
    }
    Car* buildWholeCar() override {
        car = new Car("SimpleCar");
        car->setTire(buildTire());
        car->setBody(buildBody());
        return car;
    }
};
class LuxuryCarFactory : public CarFactory {
public:
    Tire* buildTire() override {
        return new LuxuryTire();
    }
    Body* buildBody() override {
        return new LuxuryBody();
    }
    Car* buildWholeCar() override {
        car = new Car("LuxuryCar");
        car->setTire(buildTire());
        car->setBody(buildBody());
        return car;
    }
};

