#include <iostream>

class Toy {
public:
    std::string name{};
    float price{};
public:
    virtual void prepareParts() = 0;

    virtual void combineParts() = 0;

    virtual void assembleParts() = 0;

    virtual void applyLabel() = 0;

    virtual void showProduct() = 0;
};

class Car : public Toy {
public:
    void prepareParts() override { std::cout << "Preparing parts...\n"; }

    void combineParts() override { std::cout << "Combining parts...\n"; }

    void assembleParts() override { std::cout << "Assembling parts...\n"; }

    void applyLabel() override {
        std::cout << "Applying...\n";
        name = "Car";
        price = 10;
    }

    void showProduct() override { std::cout << "Name: " << name << "\t" << "Price: " << price << "\n"; }
};

class Bike : public Toy {
public:
    void prepareParts() override { std::cout << "Preparing parts...\n"; }

    void combineParts() override { std::cout << "Combining parts...\n"; }

    void assembleParts() override { std::cout << "Assembling parts...\n"; }

    void applyLabel() override {
        std::cout << "Applying...\n";
        name = "Bike";
        price = 20;
    }

    void showProduct() override { std::cout << "Name: " << name << "\t" << "Price: " << price << "\n"; }
};

class Plane : public Toy {
public:
    void prepareParts() override { std::cout << "Preparing parts...\n"; }

    void combineParts() override { std::cout << "Combining parts...\n"; }

    void assembleParts() override { std::cout << "Assembling parts...\n"; }

    void applyLabel() override {
        std::cout << "Applying...\n";
        name = "Plane";
        price = 30;
    }

    void showProduct() override { std::cout << "Name: " << name << "\t" << "Price: " << price << "\n"; }
};

class Ship : public Toy {
public:
    void prepareParts() override { std::cout << "Preparing parts...\n"; }

    void combineParts() override { std::cout << "Combining parts...\n"; }

    void assembleParts() override { std::cout << "Assembling parts...\n"; }

    void applyLabel() override {
        std::cout << "Applying...\n";
        name = "Ship";
        price = 40;
    }

    void showProduct() override { std::cout << "Name: " << name << "\t" << "Price: " << price << "\n"; }
};