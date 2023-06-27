#include <iostream>

struct Point {
private:
    /// what if we add pointer
    int* _p;
    int _x{};
    int _y{};
public:
    Point() {
        _p = new int;
        _x = 0;
        _y = 0;
    }
    Point(const Point& other) {
        _p = new int;
        *_p = *other._p;
        _x = other._x;
        _y = other._y;
    }
    Point& operator=(const Point& other) {
        if (this == &other) {
            return *this;
        }
        delete _p;
        _p = new int;
        *_p = *other._p;
        _x = other._x;
        _y = other._y;
        return *this;
    }
    ~Point() {
        delete _p;
    }
    void set_points(int x, int y, int p) {
        this->_x = x;
        this->_y = y;
        *(this->_p) = p;
    }
    void display() const {
        std::cout << "x: " << _x << "\n" << "y: " << _y << "\n" << "c: " << *_p << "\n";
    }
};


int main() {
    Point p1;
    p1.set_points(0, 1, 2);
    p1.display();
    /// copying objects using copy manual constructor and assigment operator
    Point p2 = p1;
    p2.display();
    Point p3;
    p3 = p1;
    p3.display();
    return 0;
}