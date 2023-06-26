#include <iostream>
#include <string>
#include <unordered_map>

class GraphicObject {
public:
    virtual ~GraphicObject() = default;

    virtual void draw() = 0;

    virtual GraphicObject *clone() = 0;
};

class Rectangle : public GraphicObject {
public:
    void draw() override {
        std::cout << "Drawing rectangle...w " << std::endl;
    }

    GraphicObject *clone() override {
        return new Rectangle(*this);
    }
};

class Circle : public GraphicObject {
public:
    void draw() override {
        std::cout << "Drawing Circle... " << std::endl;
    }

    GraphicObject *clone() override {
        return new Circle(*this);
    }
};

class PrototypeRegistry {
public:
    void AddPrototype(const std::string& key, GraphicObject* prototype) {
        prototypes[key] = prototype;
    }
    GraphicObject* GetPrototype(const std::string& key) {
        auto it = prototypes.find(key);
        if (it != prototypes.end()) {
            return it->second->clone();
        }
        return nullptr;
    }
private:
    std::unordered_map<std::string, GraphicObject*> prototypes;
};
int main() {
    PrototypeRegistry registry;
    registry.AddPrototype("Rectangle", new Rectangle());
    registry.AddPrototype("Circle", new Circle());

    GraphicObject* object1 = registry.GetPrototype("Rectangle");
    GraphicObject* object2 = registry.GetPrototype("Circle");

    if (object1 != nullptr) {
        object1->draw();
    }
    if (object2 != nullptr) {
        object2->draw();
    }
    delete object1;
    delete object2;
    return 0;
}