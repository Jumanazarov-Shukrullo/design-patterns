#include <iostream>
#include <vector>
#include <memory>


class Car {
public:
    Car(std::string model, std::string color) : m_model(std::move(model)), m_color(std::move(color)) {}

    void setColor(std::string color) { m_color = std::move(color); }

    virtual std::unique_ptr<Car> clone() = 0;

    virtual ~Car() = default;

private:
    std::string m_model;
    std::string m_color;
};

class RaceCar : public Car {
public:
    RaceCar(std::string model, std::string color, int maxSpeed) : Car(std::move(model), std::move(color)),
                                                                  max_speed(maxSpeed) {}

    std::unique_ptr<Car> clone() override {
        return std::make_unique<RaceCar>(*this);
    }

private:
    int max_speed;
};

int main() {
    std::vector<std::unique_ptr<Car>> cars;
    const auto prototype = std::make_unique<RaceCar>("Awesome car", "", 100);

    auto redCar = prototype->clone();
    redCar->setColor("red");
    cars.emplace_back(std::move(redCar));
    auto blueCar = prototype->clone();
    blueCar->setColor("blue");
    cars.emplace_back(std::move(blueCar));
}