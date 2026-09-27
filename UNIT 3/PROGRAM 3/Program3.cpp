#include <iostream>
#include <string>
#include <cctype>
using namespace std;

class DataChecker {
public:
    bool checkMarks(int marks) const {
        if (marks >= 0 && marks <= 100)
            return true;
        return false;
    }

    bool checkAmount(double amount) const {
        if (amount > 0 && amount <= 1000000)
            return true;
        return false;
    }

    bool checkName(string name) const {
        if (name.empty())
            return false;

        for (char ch : name) {
            if (!isalpha(static_cast<unsigned char>(ch)) && ch != ' ')
                return false;
        }

        return true;
    }
};

int main() {
    DataChecker checker;

    cout << boolalpha;
    cout << "===== DATA CHECKER =====" << endl;

    cout << "Marks 88: "
         << checker.checkMarks(88) << endl;

    cout << "Marks 125: "
         << checker.checkMarks(125) << endl;

    cout << "Amount Rs. 48000: "
         << checker.checkAmount(48000) << endl;

    cout << "Name Shubham Narsale: "
         << checker.checkName("Shubham Narsale") << endl;

    cout << "Name Shubham@123: "
         << checker.checkName("Shubham@123") << endl;

    return 0;
}
