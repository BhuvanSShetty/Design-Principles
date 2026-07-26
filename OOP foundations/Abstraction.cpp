#include <iostream>

class Shape {
public:
    virtual double area() const = 0;
    virtual ~Shape() = default;
};

class Circle : public Shape {
private:
    double radius;

public:
    explicit Circle(double r) : radius(r) {}

    double area() const override {
        return 3.14159 * radius * radius;
    }
};

int main() {
    Circle circle(5.0);
    std::cout << "Circle area: " << circle.area() << '\n';
    return 0;
}