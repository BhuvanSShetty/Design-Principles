#include <iostream>
#include <memory>
#include <vector>

class Animal {
public:
    virtual void sound() const {
        std::cout << "Some animal sound\n";
    }

    virtual ~Animal() = default;
};

class Dog : public Animal {
public:
    void sound() const override {
        std::cout << "Bark\n";
    }
};

class Cat : public Animal {
public:
    void sound() const override {
        std::cout << "Meow\n";
    }
};

int main() {
    std::vector<std::unique_ptr<Animal>> animals;
    animals.push_back(std::make_unique<Dog>());
    animals.push_back(std::make_unique<Cat>());

    for (const auto& animal : animals) {
        animal->sound();
    }

    return 0;
}