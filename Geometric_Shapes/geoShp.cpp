#include <iostream>

class Shape {
public:
    virtual double getArea() const = 0;
    virtual double getPerimeter() const = 0;
};

class Circle : public Shape {
private:
    double radius;

public:
    Circle(double circleRadius) : radius(circleRadius) {}

    double getArea() const override {
        return 3.14159 * radius * radius;
    }

    double getPerimeter() const override {
        return 2 * 3.14159 * radius;
    }
};

class Rectangle : public Shape {
private:
    double length;
    double width;

public:
    Rectangle(double rectLength, double rectWidth)
        : length(rectLength), width(rectWidth) {}

    double getArea() const override {
        return length * width;
    }

    double getPerimeter() const override {
        return 2 * (length + width);
    }
};

int main() {
    Circle myCircle(5.0);
    Rectangle myRectangle(4.0, 6.0);

    // Use polymorphism to call getArea and getPerimeter
    Shape* shapePtr = &myCircle;
    std::cout << "Circle Area: " << shapePtr->getArea() << std::endl;
    std::cout << "Circle Perimeter: " << shapePtr->getPerimeter() << std::endl;

    shapePtr = &myRectangle;
    std::cout << "Rectangle Area: " << shapePtr->getArea() << std::endl;
    std::cout << "Rectangle Perimeter: " << shapePtr->getPerimeter() << std::endl;

    return 0;
}
