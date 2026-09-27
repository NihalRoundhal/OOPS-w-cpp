
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Sensor {
private:
    string id;
    float moisture;
    string time;

public:
    Sensor(string i, float m, string t) {
        id = i;
        moisture = m;
        time = t;
    }

    void updateReading(float m, string t) {
        moisture = m;
        time = t;
    }

    void showData() const {
        cout << "Sensor ID: " << id << endl;
        cout << "Moisture Level: " << moisture << "%" << endl;
        cout << "Recorded At: " << time << endl;
        cout << "------------------------" << endl;
    }
};

int main() {

    vector<Sensor> sensors;

    sensors.emplace_back("A201", 48.6, "07:30 AM");
    sensors.emplace_back("A202", 55.4, "07:30 AM");
    sensors.emplace_back("A203", 41.2, "07:30 AM");

    cout << "===== FARM SENSOR DATA =====" << endl;

    for (const auto& s : sensors) {
        s.showData();
    }

    sensors[0].updateReading(51.3, "08:30 AM");

    cout << "\n===== UPDATED SENSOR DATA =====" << endl;
    sensors[0].showData();

    return 0;
}
