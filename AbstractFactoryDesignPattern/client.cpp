#include <iostream>

#include "CarFactory.cpp"


int main() {
    int val;
    CarFactory* factory = nullptr;
    while (true) {
        std::cout << "Choose: 1 or 2, to exit 0: ";
        std::cin >> val;
        if (!val) {
            break;
        } else if(val == 1) {
            factory = new SimpleCarFactory();
        } else if (val == 2) {
            factory = new LuxuryCarFactory();
        } else {
            std::cout << "!!! You only have 3 options...\n";
        }
        auto car = factory->buildWholeCar();
        car->printDetails();
    }
}