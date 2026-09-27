
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class SmartDevice {
protected:
    string deviceId;
    string location;
    string status;
    string updatedTime;

public:
    SmartDevice(string id, string loc, string st, string time) {
        deviceId = id;
        location = loc;
        status = st;
        updatedTime = time;
    }

    void switchOn(string time) {
        status = "ON";
        updatedTime = time;
        cout << "Device switched ON." << endl;
    }

    void switchOff(string time) {
        status = "OFF";
        updatedTime = time;
        cout << "Device switched OFF." << endl;
    }

    void changeStatus(string newStatus, string time) {
        status = newStatus;
        updatedTime = time;
        cout << "Device status updated." << endl;
    }

    virtual void display() const {
        cout << "ID: " << deviceId
             << " | Location: " << location
             << " | Status: " << status
             << " | Updated: " << updatedTime << endl;
    }

    string getId() const {
        return deviceId;
    }

    virtual ~SmartDevice() {}
};

class SmartLight : public SmartDevice {
public:
    SmartLight(string id, string loc, string st, string time)
        : SmartDevice(id, loc, st, time) {}

    void display() const override {
        cout << "Light | ";
        SmartDevice::display();
    }
};

class Thermostat : public SmartDevice {
public:
    Thermostat(string id, string loc, string st, string time)
        : SmartDevice(id, loc, st, time) {}

    void display() const override {
        cout << "Thermostat | ";
        SmartDevice::display();
    }
};

class SecurityCamera : public SmartDevice {
public:
    SecurityCamera(string id, string loc, string st, string time)
        : SmartDevice(id, loc, st, time) {}

    void display() const override {
        cout << "Camera | ";
        SmartDevice::display();
    }
};

class DoorLock : public SmartDevice {
public:
    DoorLock(string id, string loc, string st, string time)
        : SmartDevice(id, loc, st, time) {}

    void display() const override {
        cout << "Door Lock | ";
        SmartDevice::display();
    }
};

int main() {
    vector<SmartDevice*> devices;

    devices.push_back(new SmartLight("L201", "Study Room", "OFF", "07:45"));
    devices.push_back(new Thermostat("T202", "Master Bedroom", "ON", "08:10"));
    devices.push_back(new SecurityCamera("C203", "Back Gate", "ON", "08:25"));
    devices.push_back(new DoorLock("D204", "Garage Door", "LOCKED", "08:40"));

    int choice;
    string time;

    do {
        cout << "\n===== SMART HOME MANAGER =====" << endl;
        cout << "1. Home Dashboard" << endl;
        cout << "2. Switch Device ON" << endl;
        cout << "3. Switch Device OFF" << endl;
        cout << "4. Change Device Status" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "\n===== HOME DASHBOARD =====" << endl;

            for (const auto& device : devices) {
                device->display();
            }
        }
        else if (choice >= 2 && choice <= 4) {
            string id;
            cout << "Enter Device ID: ";
            cin >> id;

            bool found = false;

            for (auto& device : devices) {
                if (device->getId() == id) {
                    found = true;

                    cout << "Enter current time: ";
                    cin >> time;

                    if (choice == 2) {
                        device->switchOn(time);
                    }
                    else if (choice == 3) {
                        device->switchOff(time);
                    }
                    else {
                        string newStatus;
                        cout << "Enter new status: ";
                        cin >> newStatus;
                        device->changeStatus(newStatus, time);
                    }

                    break;
                }
            }

            if (!found) {
                cout << "Device not found." << endl;
            }
        }
        else if (choice == 5) {
            cout << "Exiting Smart Home Manager..." << endl;
        }
        else {
            cout << "Invalid choice." << endl;
        }

    } while (choice != 5);

    for (auto device : devices) {
        delete device;
    }

    return 0;
}
