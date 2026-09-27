#include <iostream>
#include <memory>
#include <string>
#include <vector>
using namespace std;

class Vehicle {
protected:
    string id;       
    string regNo;    
    float fuel;      

public:
    Vehicle(string i, string r) {
        id = i;
        regNo = r;
        fuel = 100.0;  
    }

    void startEngine() const {
        cout << "Engine started for vehicle: " << id << endl;
    }

    void refuel(float amount) {
        fuel += amount;

        if (fuel > 100.0)
            fuel = 100.0;
    }

    virtual void displayInfo() const {
        cout << "ID: " << id
             << " | Registration: " << regNo
             << " | Fuel: " << fuel << "%" << endl;
    }

    virtual ~Vehicle() {}
};


class Truck : public Vehicle {
    float capacity;  

public:
    Truck(string i, string r, float c)
        : Vehicle(i, r), capacity(c) {}

    void displayInfo() const override {
        cout << "Type: Truck" << endl;

        Vehicle::displayInfo();

        cout << "Load Capacity: " << capacity << " tons" << endl;
    }
};


class DeliveryVan : public Vehicle {
    int storage;  

public:
    DeliveryVan(string i, string r, int s)
        : Vehicle(i, r), storage(s) {}

    void displayInfo() const override {
        cout << "Type: Delivery Van" << endl;

        Vehicle::displayInfo();

        cout << "Storage Capacity: " << storage << " kg" << endl;
    }
};


class Bike : public Vehicle {
    bool deliveryBox;  

public:
    Bike(string i, string r, bool box)
        : Vehicle(i, r), deliveryBox(box) {}

    void displayInfo() const override {
        cout << "Type: Delivery Bike" << endl;

        Vehicle::displayInfo();

        cout << "Delivery Box: "
             << (deliveryBox ? "Available" : "Not Available") << endl;
    }
};


int main() {

    vector<unique_ptr<Vehicle>> fleet;

    fleet.push_back(
        make_unique<Truck>("V101", "MH14-XY-4582", 12.5)
    );

    fleet.push_back(
        make_unique<DeliveryVan>("V202", "MH14-PQ-6734", 65)
    );

    fleet.push_back(
        make_unique<Bike>("V303", "MH14-ZA-9216", true)
    );

    cout << "===== VEHICLE FLEET =====" << endl;

    for (const auto& v : fleet) {

        v->startEngine();

        v->displayInfo();

        cout << endl;
    }

    return 0;
}
