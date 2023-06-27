#include <iostream>

struct Point {
private:
    int _x{};
    int _y{};
public:
    void set_points(int x, int y) {
        this->_x = x;
        this->_y = y;
    }
    void display() const {
        std::cout << "x: " << _x << "\n" << "y: " << _y << "\n";
    }
};


int main() {
    Point p1;
    p1.set_points(0, 1);
    p1.display();
    /// copying objects using default copy constructor and assigment operator
    Point p2 = p1;
    p2.display();
    Point p3;
    p3 = p1;
    p3.display();
    /// so here copying is done by compiler
    /// this is called "shallow copy"
    return 0;
}