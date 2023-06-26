#include <iostream>
#include "object.cpp"


class ToyFactory {
public:
    static Toy* createToy(int type) {
        Toy* toy = nullptr;
        switch (type) {
            case 1:
                toy = new Car;
                break;
            case 2:
                toy = new Bike;
                break;
            case 3:
                toy = new Plane;
                break;
            case 4:
                toy = new Ship;
                break;
            default:
                std::cout << "invalid toy type re-enter type.\n";
                return nullptr;
        }
        toy->prepareParts();
        toy->combineParts();
        toy->assembleParts();
        toy->applyLabel();
        return toy;
    }
};
