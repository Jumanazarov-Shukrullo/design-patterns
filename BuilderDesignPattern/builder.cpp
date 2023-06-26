#include <iostream>
#include <vector>
#include <string>

class Product1 {
public:
    std::vector<std::string> _parts;

    void ListParts() const {
        std::cout << "Product part: ";
        for (const auto &item: _parts) {
            if (item == _parts.back()) {
                std::cout << item;
            } else {
                std::cout << item << ", ";
            }
        }
        std::cout << "\n\n";
    }
};


class Builder {
public:
    virtual ~Builder() = default;
    virtual void ProducePartA() const = 0;
    virtual void ProducePartB() const = 0;
    virtual void ProducePartC() const = 0;
};


class ConcreteBuilder1 : public Builder {
private:
    Product1* product{};
public:
    ConcreteBuilder1() {
        this->Reset();
    }
    ~ConcreteBuilder1() override {
        delete product;
    }
    void Reset() {
        this->product = new Product1();
    }
    void ProducePartA() const override {
        this->product->_parts.emplace_back("PartA");
    }
    void ProducePartB() const override {
        this->product->_parts.emplace_back("PartB");
    }
    void ProducePartC() const override {
        this->product->_parts.emplace_back("PartC");
    }
    Product1* GetResult() {
        Product1* res = this->product;
        this->Reset();
        return res;
    }
};

class Director {
private:
    Builder* _builder;
public:
    void set_builder(Builder* builder) {
        this->_builder = builder;
    }
    void BuildMinimalViableProduct() {
        this->_builder->ProducePartA();
    }
    void BuildFullFeaturedProduct() {
        this->_builder->ProducePartA();
        this->_builder->ProducePartB();
        this->_builder->ProducePartC();
    }
};

void ClientCode(Director& director) {
    auto* cb = new ConcreteBuilder1();
    director.set_builder(cb);
    std::cout << "Standard basic product: \n";
    director.BuildMinimalViableProduct();

    auto * p = cb->GetResult();
    p->ListParts();
    delete p;

    std::cout << "Full  product: \n";
    director.BuildFullFeaturedProduct();

    p = cb->GetResult();
    p->ListParts();
    delete p;

    delete cb;
}

int main() {
    auto* director = new Director();
    ClientCode(*director);
    delete director;
    return 0;
}