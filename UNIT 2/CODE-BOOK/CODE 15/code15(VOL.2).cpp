#include <iostream>
#include <string>
#include <vector>
#include <memory>

using namespace std;

// Base Class
class Vehicle
{
protected:
    string registrationNumber;
    double ratePerDay;
    bool available;

public:
    Vehicle(string registration, double rate)
        : registrationNumber(move(registration)),
          ratePerDay(rate),
          available(true)
    {
    }

    virtual double calculateRent(int days) const
    {
        return ratePerDay * days;
    }

    virtual void display() const
    {
        cout << "Registration: " << registrationNumber << endl;
        cout << "Rate per day: " << ratePerDay << endl;
        cout << "Availability: "
             << (available ? "Available" : "Rented") << endl;
    }

    string getRegistrationNumber() const
    {
        return registrationNumber;
    }

    bool isAvailable() const
    {
        return available;
    }

    void rentVehicle()
    {
        available = false;
    }

    void returnVehicle()
    {
        available = true;
    }

    virtual ~Vehicle() = default;
};


// Derived Class: Car
class Car : public Vehicle
{
private:
    int numberOfDoors;

public:
    Car(string registration, double rate, int doors)
        : Vehicle(move(registration), rate),
          numberOfDoors(doors)
    {
    }

    void display() const override
    {
        cout << "\nCar Details" << endl;
        Vehicle::display();
        cout << "Doors: " << numberOfDoors << endl;
    }
};


// Derived Class: Bike
class Bike : public Vehicle
{
private:
    int engineCapacity;

public:
    Bike(string registration, double rate, int capacity)
        : Vehicle(move(registration), rate),
          engineCapacity(capacity)
    {
    }

    double calculateRent(int days) const override
    {
        return ratePerDay * days * 0.9;
    }

    void display() const override
    {
        cout << "\nBike Details" << endl;
        Vehicle::display();
        cout << "Engine Capacity: "
             << engineCapacity << " cc" << endl;
    }
};


// Derived Class: Bus
class Bus : public Vehicle
{
private:
    int seatingCapacity;

public:
    Bus(string registration, double rate, int seats)
        : Vehicle(move(registration), rate),
          seatingCapacity(seats)
    {
    }

    double calculateRent(int days) const override
    {
        return ratePerDay * days * 1.2;
    }

    void display() const override
    {
        cout << "\nBus Details" << endl;
        Vehicle::display();
        cout << "Seating Capacity: "
             << seatingCapacity << endl;
    }
};


// Find vehicle using registration number
Vehicle* findVehicle(
    vector<unique_ptr<Vehicle>>& vehicles,
    string registration)
{
    for (auto& vehicle : vehicles)
    {
        if (vehicle->getRegistrationNumber() == registration)
        {
            return vehicle.get();
        }
    }

    return nullptr;
}


// Display all vehicles
void displayAllVehicles(
    const vector<unique_ptr<Vehicle>>& vehicles)
{
    if (vehicles.empty())
    {
        cout << "\nNo vehicles available." << endl;
        return;
    }

    cout << "\n===== ALL VEHICLES =====" << endl;

    for (int i = 0; i < vehicles.size(); i++)
    {
        cout << "\nVehicle " << i + 1 << endl;
        vehicles[i]->display();
    }
}


int main()
{
    vector<unique_ptr<Vehicle>> vehicles;

    // Add vehicles
    vehicles.push_back(
        make_unique<Car>("MH12AB1234", 2000.0, 5)
    );

    vehicles.push_back(
        make_unique<Bike>("MH12CD5678", 800.0, 150)
    );

    vehicles.push_back(
        make_unique<Bus>("MH12EF9012", 5000.0, 40)
    );

    int choice;

    do
    {
        cout << "\n\n===== VEHICLE RENTAL SYSTEM =====" << endl;
        cout << "1. Display All Vehicles" << endl;
        cout << "2. Rent a Vehicle" << endl;
        cout << "3. Return a Vehicle" << endl;
        cout << "4. Calculate Rent" << endl;
        cout << "5. Exit" << endl;

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            displayAllVehicles(vehicles);
            break;

        case 2:
        {
            string registration;

            cout << "\nEnter registration number: ";
            cin >> registration;

            Vehicle* vehicle =
                findVehicle(vehicles, registration);

            if (vehicle == nullptr)
            {
                cout << "Vehicle not found." << endl;
            }
            else if (!vehicle->isAvailable())
            {
                cout << "Vehicle is already rented." << endl;
            }
            else
            {
                vehicle->rentVehicle();
                cout << "Vehicle rented successfully." << endl;
            }

            break;
        }

        case 3:
        {
            string registration;

            cout << "\nEnter registration number: ";
            cin >> registration;

            Vehicle* vehicle =
                findVehicle(vehicles, registration);

            if (vehicle == nullptr)
            {
                cout << "Vehicle not found." << endl;
            }
            else if (vehicle->isAvailable())
            {
                cout << "Vehicle is already available." << endl;
            }
            else
            {
                vehicle->returnVehicle();
                cout << "Vehicle returned successfully." << endl;
            }

            break;
        }

        case 4:
        {
            string registration;
            int days;

            cout << "\nEnter registration number: ";
            cin >> registration;

            Vehicle* vehicle =
                findVehicle(vehicles, registration);

            if (vehicle == nullptr)
            {
                cout << "Vehicle not found." << endl;
            }
            else
            {
                cout << "Enter number of days: ";
                cin >> days;

                if (days <= 0)
                {
                    cout << "Invalid number of days." << endl;
                }
                else
                {
                    cout << "Rent for "
                         << days
                         << " days: "
                         << vehicle->calculateRent(days)
                         << endl;
                }
            }

            break;
        }

        case 5:
            cout << "\nThank you for using the Vehicle Rental System!"
                 << endl;
            break;

        default:
            cout << "\nInvalid choice. Please try again." << endl;
        }

    } while (choice != 5);

    return 0;
}
