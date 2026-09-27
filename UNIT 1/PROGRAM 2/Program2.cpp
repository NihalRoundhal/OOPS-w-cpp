#include <iostream>
#include <string>
using namespace std;

class Student {
private:
    int roll;
    string studentName;
    int total;
    int present;

public:
    Student(int r, string n) {
        roll = r;
        studentName = n;
        total = 0;
        present = 0;
    }

    void recordAttendance(bool status) {
        total++;

        if (status == true) {
            present++;
        }
    }

    double calculateAttendance() const {
        if (total == 0)
            return 0.0;

        return (present * 100.0) / total;
    }

    void showDetails() const {
        cout << "Roll Number: " << roll << endl;
        cout << "Student Name: " << studentName << endl;
        cout << "Attendance: " << calculateAttendance() << "%" << endl;
        cout << "------------------------" << endl;
    }
};

int main() {
    Student student1(301, "Shubham");
    Student student2(302, "Soham");

    student1.recordAttendance(true);
    student1.recordAttendance(true);
    student1.recordAttendance(false);

    student2.recordAttendance(true);
    student2.recordAttendance(true);
    student2.recordAttendance(true);

    cout << "===== ATTENDANCE REPORT =====" << endl;

    student1.showDetails();
    student2.showDetails();

    return 0;
}
