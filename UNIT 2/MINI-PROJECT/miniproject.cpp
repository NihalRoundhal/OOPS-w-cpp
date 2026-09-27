
#include <iostream>
#include <string>
using namespace std;

class Account {
protected:
    string accNo;       
    string holder;      
    double balance;     

public:
    Account(string a, string h, double b) {
        accNo = a;
        holder = h;
        balance = b;
    }

    void deposit(double amount) {
        balance += amount;
        cout << "Amount deposited successfully." << endl;
    }

    virtual void withdraw(double amount) {

        if (amount <= balance) {
            balance -= amount;
            cout << "Withdrawal successful." << endl;
        } else {
            cout << "Insufficient balance." << endl;
        }
    }

    virtual void calculateInterest() const = 0;

    virtual void displayInfo() const {
        cout << "Account Number: " << accNo << endl;
        cout << "Holder Name: " << holder << endl;
        cout << "Balance: Rs. " << balance << endl;
    }

    // Virtual destructor
    virtual ~Account() {}
};


class SavingsAccount : public Account {
public:
    SavingsAccount(string a, string h, double b)
        : Account(a, h, b) {}

    void calculateInterest() const override {
        cout << "Interest: Rs. " << balance * 0.04 << endl;
    }
};

class CurrentAccount : public Account {
public:
    CurrentAccount(string a, string h, double b)
        : Account(a, h, b) {}

    void calculateInterest() const override {
        cout << "Current Account has no interest." << endl;
    }
};


class FixedDepositAccount : public Account {
    int years;  // Stores FD duration in years

public:
    FixedDepositAccount(string a, string h, double b, int y)
        : Account(a, h, b), years(y) {}

    void calculateInterest() const override {
        cout << "Interest: Rs. " << balance * 0.07 * years << endl;
    }
};


int main() {

    string accNo, name;
    double balance;
    int choice, years;

    cout << "===== BANKING SYSTEM =====" << endl;

    cout << "Enter Account Number: ";
    cin >> accNo;

    cin.ignore();

    cout << "Enter Account Holder Name: ";
    getline(cin, name);

    cout << "Enter Initial Balance: ";
    cin >> balance;

    cout << "\nSelect Account Type:" << endl;
    cout << "1. Savings Account" << endl;
    cout << "2. Current Account" << endl;
    cout << "3. Fixed Deposit Account" << endl;
    cout << "Enter choice: ";
    cin >> choice;

    Account* account = nullptr;

    if (choice == 1) {
        account = new SavingsAccount(accNo, name, balance);
    }

    else if (choice == 2) {
        account = new CurrentAccount(accNo, name, balance);
    }

    else if (choice == 3) {
        cout << "Enter FD Duration (years): ";
        cin >> years;

        account = new FixedDepositAccount(accNo, name, balance, years);
    }

    else {
        cout << "Invalid choice." << endl;
        return 0;
    }

    int option;
    double amount;

    do {

        cout << "\n===== MENU =====" << endl;
        cout << "1. Display Account Details" << endl;
        cout << "2. Deposit Money" << endl;
        cout << "3. Withdraw Money" << endl;
        cout << "4. Calculate Interest" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> option;

        switch (option) {

            case 1:
                account->displayInfo();
                break;

            case 2:
                cout << "Enter deposit amount: ";
                cin >> amount;
                account->deposit(amount);
                break;

            case 3:
                cout << "Enter withdrawal amount: ";
                cin >> amount;
                account->withdraw(amount);
                break;

            case 4:
                account->calculateInterest();
                break;

            case 5:
                cout << "Thank you for using the Banking System." << endl;
                break;

            default:
                cout << "Invalid choice." << endl;
        }

    } while (option != 5);

    delete account;

    return 0;
}
