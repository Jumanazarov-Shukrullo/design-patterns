#include <iostream>

#include "ToyFactory.cpp"


int main() {
    int type;
    while (true) {
        std::cout << "Enter type of toy: \n";
        std::cin >> type;
        if (!type) {
            break;
        }
        Toy* toy = ToyFactory::createToy(type);
        if (toy) {
            toy->showProduct();
            delete toy;
        }
    }
    std::cout << "exit\n";
}