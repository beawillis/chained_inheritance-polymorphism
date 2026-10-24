#include <iomanip>
#include <iostream>

// Shape defines the common interface used by callers of different shapes.
class Shape {
public:
    virtual ~Shape() = default;

    virtual double area() const = 0;
};

class Circle : public Shape {
public:
    explicit Circle(double radius) : radius_(radius) {}

    double area() const override {
        constexpr double pi = 3.14159265358979323846;
        return pi * radius_ * radius_;
    }

private:
    double radius_;
};

class Rectangle : public Shape {
public:
    Rectangle(double width, double height) : width_(width), height_(height) {}

    double area() const override {
        return width_ * height_;
    }

private:
    double width_;
    double height_;
};

int main() {
    const Circle circle(3.0);
    const Rectangle rectangle(4.0, 5.0);

    // Each base-class pointer refers to a different concrete derived object.
    const Shape* shapes[] = {&circle, &rectangle};
    const char* shapeNames[] = {"Circle", "Rectangle"};

    std::cout << "=== Runtime Polymorphism: Shape Areas ===\n";
    std::cout << std::fixed << std::setprecision(2);

    for (int index = 0; index < 2; ++index) {
        // Virtual dispatch calls Circle::area() or Rectangle::area().
        std::cout << shapeNames[index] << " area: " << shapes[index]->area()
                  << " square units\n";
    }

    return 0;
}