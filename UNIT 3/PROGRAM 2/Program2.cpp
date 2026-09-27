#include <iostream>
using namespace std;

class Complex {
private:
    double x;
    double y;

public:
    Complex(double a = 0, double b = 0) {
        x = a;
        y = b;
    }

    Complex operator+(const Complex& c) const {
        return Complex(x + c.x, y + c.y);
    }

    Complex operator-(const Complex& c) const {
        return Complex(x - c.x, y - c.y);
    }

    Complex operator*(const Complex& c) const {
        return Complex(
            x * c.x - y * c.y,
            x * c.y + y * c.x
        );
    }

    bool operator==(const Complex& c) const {
        return x == c.x && y == c.y;
    }

    void show() const {
        cout << x << " + " << y << "i" << endl;
    }
};

int main() {
    Complex num1(6, 5);
    Complex num2(2, 3);

    cout << "===== COMPLEX NUMBER OPERATIONS =====" << endl;

    cout << "First Number: ";
    num1.show();

    cout << "Second Number: ";
    num2.show();

    cout << "\nAddition: ";
    (num1 + num2).show();

    cout << "Subtraction: ";
    (num1 - num2).show();

    cout << "Multiplication: ";
    (num1 * num2).show();

    cout << "Are both numbers equal? ";
    cout << ((num1 == num2) ? "Yes" : "No") << endl;

    return 0;
}
