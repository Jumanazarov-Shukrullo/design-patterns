#include <iostream>
#include <string>
#include <utility>

class Tire {
protected:
    std::string name;
    int pressure;
public:
    Tire(std::string name, int pressure) : name(std::move(name)), pressure(pressure) {}

    std::string getName() const { return name; }

    int getPressure() const { return pressure; }
};

class SimpleTire : public Tire {
public:
    SimpleTire() : Tire("SimpleTire", 75) {}
};

class LuxuryTire : public Tire {
public:
    LuxuryTire() : Tire("LuxuryTire", 100) {}
};


class Body {
protected:
    std::string name;
    int strength;
public:
    Body(std::string name, int strength) : name(std::move(name)), strength(strength) {}

    std::string getName() const { return name; }

    int getStrength() const { return strength; }
};

class SimpleBody : public Body {
public:
    SimpleBody() : Body("SimpleBody", 75) {}
};

class LuxuryBody : public Body {
public:
    LuxuryBody() : Body("LuxuryBody", 100) {}
};


class Car {
private:
    std::string name;
    Tire *tire{};
    Body *body{};
public:
    explicit Car(std::string name) : name(std::move(name)) {}

    void setTire(Tire *t) { tire = t; }
    void setBody(Body *b) { body = b; }
    void printDetails() {
        std::cout << "Car: " << name << "\n" <<
        "Tire: " << tire->getName() << " Pressure: " << tire->getPressure() << "\n" <<
        "Body: " << body->getName() << " Strength: " << body->getStrength() << "\n";
    }
};