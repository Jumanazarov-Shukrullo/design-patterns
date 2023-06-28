#include <iostream>

class Plane {
private:
    std::string _plane;
    std::string _body;
    std::string _engine;
public:
    explicit Plane(const std::string &PlaneType) : _plane(PlaneType) {}

    void setEngine(const std::string &engine) { _engine = engine; }

    void setBody(const std::string &body) { _body = body; }

    void show() {
        std::cout << "Plane Type: " << _plane << "\n" <<
                  "Engine Type: " << _engine << "\n" <<
                  "Body Type: " << _body << "\n" << "\n";
    }

};

class PlaneBuilder {
protected:
    Plane *plane{};
public:
    virtual ~PlaneBuilder() = default;

    virtual void getPartsDone() = 0;

    virtual void buildEngine() const = 0;

    virtual void buildBody() const = 0;

    Plane *getPlane() const { return plane; }
};

class PropellerBuilder : public PlaneBuilder {
public:
    void getPartsDone() override {
        plane = new Plane("PropellerPlane");
    }

    void buildEngine() const override {
        plane->setEngine("Propeller Engine");
    }

    void buildBody() const override {
        plane->setBody( "Propeller Body");
    }
};

class JetBuilder : public PlaneBuilder {
public:
    void getPartsDone() override {
        plane = new Plane( "Jet Plane");
    }

    void buildEngine() const override {
        plane->setEngine( "Jet Engine");
    }

    void buildBody() const override {
        plane->setBody( "Jet Body");
    }
};

class Director {
public:
    Plane *createPlane(PlaneBuilder *builder) {
        builder->getPartsDone();
        builder->buildEngine();
        builder->buildBody();
        return builder->getPlane();
    }
};

int main() {
    Director dir;
    JetBuilder jb;
    PropellerBuilder pb;
    auto *jet = dir.createPlane(&jb);
    auto *pro = dir.createPlane(&pb);
    jet->show();
    pro->show();

    delete jet;
    delete pro;

}