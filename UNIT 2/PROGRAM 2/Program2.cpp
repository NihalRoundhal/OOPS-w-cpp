#include <iostream>
#include <memory>
#include <vector>
#include <string>
using namespace std;

class Payment {
protected:
    string id;
    float price;

public:
    Payment(string i, float p) {
        id = i;
        price = p;
    }

    virtual void makePayment() const = 0;

    virtual ~Payment() {}
};


class Card : public Payment {
    string cardNo;

public:
    Card(string i, float p, string c)
        : Payment(i, p), cardNo(c) {}

    void makePayment() const override {
        cout << "Payment through Credit Card" << endl;
        cout << "Transaction ID: " << id << endl;
        cout << "Amount: Rs. " << price << endl;
        cout << "Card Number: " << cardNo << endl;
        cout << "Status: Successful\n" << endl;
    }
};


class UPI : public Payment {
    string userId;

public:
    UPI(string i, float p, string u)
        : Payment(i, p), userId(u) {}

    void makePayment() const override {
        cout << "Payment through UPI" << endl;
        cout << "Transaction ID: " << id << endl;
        cout << "Amount: Rs. " << price << endl;
        cout << "UPI ID: " << userId << endl;
        cout << "Status: Successful\n" << endl;
    }
};


class NetBanking : public Payment {
    string bank;

public:
    NetBanking(string i, float p, string b)
        : Payment(i, p), bank(b) {}

    void makePayment() const override {
        cout << "Payment through Net Banking" << endl;
        cout << "Transaction ID: " << id << endl;
        cout << "Amount: Rs. " << price << endl;
        cout << "Bank Name: " << bank << endl;
        cout << "Status: Successful\n" << endl;
    }
};

int main() {
    vector<unique_ptr<Payment>> paymentList;

    paymentList.push_back(
        make_unique<Card>("C501", 3500, "XXXX-5678")
    );

    paymentList.push_back(
        make_unique<UPI>("U602", 1850, "soham@upi")
    );

    paymentList.push_back(
        make_unique<NetBanking>("N703", 4200, "XYZ Bank")
    );

    cout << "===== PAYMENT SYSTEM =====\n" << endl;

    for (const auto& p : paymentList) {
        p->makePayment();
    }

    return 0;
}
