#include <iostream>
#include <memory>
#include <vector>
using namespace std;

class Shape {
public:
    virtual double calculateArea() const = 0;
    virtual void showShape() const = 0;

    virtual ~Shape() {}
};

class Circle : public Shape {
private:
    double r;

public:
    Circle(double radius) {
        r = radius;
    }

    double calculateArea() const override {
        return 3.14159 * r * r;
    }

    void showShape() const override {
        cout << "Shape: Circle" << endl;
        cout << "Radius: " << r << endl;
    }
};

class Rectangle : public Shape {
private:
    double length;
    double width;

public:
    Rectangle(double l, double w) {
        length = l;
        width = w;
    }

    double calculateArea() const override {
        return length * width;
    }

    void showShape() const override {
        cout << "Shape: Rectangle" << endl;
        cout << "Length: " << length << endl;
        cout << "Width: " << width << endl;
    }
};

class Triangle : public Shape {
private:
    double base;
    double height;

public:
    Triangle(double b, double h) {
        base = b;
        height = h;
    }

    double calculateArea() const override {
        return 0.5 * base * height;
    }

    void showShape() const override {
        cout << "Shape: Triangle" << endl;
        cout << "Base: " << base << endl;
        cout << "Height: " << height << endl;
    }
};

int main() {
    vector<unique_ptr<Shape>> shapes;

    shapes.push_back(make_unique<Circle>(7));
    shapes.push_back(make_unique<Rectangle>(5, 9));
    shapes.push_back(make_unique<Triangle>(6, 7));

    cout << "===== SHAPE AREA SYSTEM =====" << endl;

    for (const auto& s : shapes) {
        s->showShape();
        cout << "Area: " << s->calculateArea() << " square units" << endl;
        cout << "------------------------" << endl;
    }

    return 0;
}
