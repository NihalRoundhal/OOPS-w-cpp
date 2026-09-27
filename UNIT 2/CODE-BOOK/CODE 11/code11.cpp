#include <iostream>
using namespace std; 
 
class Shape { 
public: 
    virtual double area() const = 0; 
    virtual ~Shape() = default; 
}; 
 
class Rectangle : public Shape { 
private: 
    double length; 
    double width; 
 
public: 
    Rectangle(double givenLength, double givenWidth) 
        : length(givenLength), width(givenWidth) {} 
 
    double area() const override { 
        return length * width; 
    } 
}; 
 
class Circle : public Shape { 
private: 
    double radius; 
 
public: 
    explicit Circle(double givenRadius) : radius(givenRadius) {} 
 
    double area() const override { 
        return 3.141592653589793 * radius * radius; 
    } 
}; 
 
int main() { 
    Rectangle rectangle(85.0, 45.0); 
    Circle circle(14.96); 
 
    cout << "Rectangle Area: " << rectangle.area() << '\n'; 
    cout << "Circle Area: " << circle.area() << '\n'; 
    return 0; 
} 
 
