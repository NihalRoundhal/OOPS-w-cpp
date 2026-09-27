#include <iostream> 
#include <string> 
 using namespace std;
 
class Vehicle { 
protected: 
    string registrationNumber; 
 
public: 
    explicit Vehicle(string registration) 
        : registrationNumber(move(registration)) {} 
 
    void start() const { 
        cout << "Vehicle " << registrationNumber << " started\n"; 
    } 
}; 
 
class Car : public Vehicle { 
public: 
    explicit Car(string registration) : Vehicle(move(registration)) {} 
 
    void openBoot() const { 
        cout << "Car boot opened\n"; 
    } 
}; 
 
class Bike : public Vehicle { 
public: 
    explicit Bike(string registration) : Vehicle(move(registration)) {} 
 
    void helmetReminder() const { 
        cout << "Please wear a helmet\n"; 
    } 
}; 
 
int main() { 
    Car car("MH19CV5196"); 
    Bike bike("MH19BC5128"); 
 
    car.start(); 
    car.openBoot(); 
 
    bike.start(); 
    bike.helmetReminder(); 
 
    return 0; 
}
