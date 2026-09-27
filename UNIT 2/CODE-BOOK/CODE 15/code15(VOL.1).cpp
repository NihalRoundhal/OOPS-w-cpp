#include <iostream>
#include <string>
using namespace std;

class Vehicle {
protected:
    string registrationNumber;
    double ratePerDay;

public:
    Vehicle(string registration, double rate)
        : registrationNumber(registration), ratePerDay(rate) {}

    virtual double calculateRent(int days) const {
        return ratePerDay * days;
    }

    virtual void display() const {
        cout << "Registration: " << registrationNumber << '\n';
        cout << "Rate per day: " << ratePerDay << '\n';
    }

    virtual ~Vehicle() = default;
};

class Car : public Vehicle {
private:
    int numberOfDoors;

public:
    Car(string registration, double rate, int doors)
        : Vehicle(registration, rate), numberOfDoors(doors) {}

    void display() const override {
        Vehicle::display();
        cout << "Doors: " << numberOfDoors << '\n';
    }
};

class Bike : public Vehicle {
private:
    int engineCapacity;

public:
    Bike(string registration, double rate, int capacity)
        : Vehicle(registration, rate), engineCapacity(capacity) {}

    double calculateRent(int days) const override {
        return ratePerDay * days * 0.9; // 10% discount
    }

    void display() const override {
        Vehicle::display();
        cout << "Engine Capacity: " << engineCapacity << " cc\n";
    }
};

int main() {
    Car car("MH19", 2000.0, 5);
    Bike bike("MH12CD5678", 800.0, 150);

    cout << "Car Details\n";
    car.display();
    cout << "Rent for 3 days: " << car.calculateRent(3) << "\n\n";

    cout << "Bike Details\n";
    bike.display();
    cout << "Rent for 3 days: " << bike.calculateRent(3) << '\n';

    return 0;
}
