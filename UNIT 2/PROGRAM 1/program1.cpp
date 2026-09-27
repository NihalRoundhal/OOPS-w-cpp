#include <iostream>
#include <string>
using namespace std;

class Employee
{
protected:
    int id;
    string empName;
    string dept;

public:
    Employee(int i, string n, string d)
    {
        id = i;
        empName = n;
        dept = d;
    }

    void showInfo() const
    {
        cout << "ID: " << id
             << " | Name: " << empName
             << " | Department: " << dept;
    }

    virtual double calculateSalary() const = 0;
};

class FullTimeEmployee : public Employee
{
private:
    double monthlySalary;

public:
    FullTimeEmployee(int i, string n, string d, double salary)
        : Employee(i, n, d)
    {
        monthlySalary = salary;
    }

    double calculateSalary() const override
    {
        return monthlySalary;
    }

    void display() const
    {
        showInfo();

        cout << " | Type: Full-Time"
             << " | Salary: Rs. "
             << calculateSalary() << endl;
    }
};

class PartTimeEmployee : public Employee
{
private:
    double ratePerHour;
    int totalHours;

public:
    PartTimeEmployee(int i, string n, string d, double rate, int hours)
        : Employee(i, n, d)
    {
        ratePerHour = rate;
        totalHours = hours;
    }

    double calculateSalary() const override
    {
        return ratePerHour * totalHours;
    }

    void display() const
    {
        showInfo();

        cout << " | Type: Part-Time"
             << " | Salary: Rs. "
             << calculateSalary() << endl;
    }
};

class Intern : public Employee
{
private:
    double monthlyStipend;

public:
    Intern(int i, string n, string d, double stipend)
        : Employee(i, n, d)
    {
        monthlyStipend = stipend;
    }

    double calculateSalary() const override
    {
        return monthlyStipend;
    }

    void display() const
    {
        showInfo();

        cout << " | Type: Intern"
             << " | Stipend: Rs. "
             << calculateSalary() << endl;
    }
};

int main()
{
    FullTimeEmployee emp1(301, "Vinod", "Human Resources", 55000);
    PartTimeEmployee emp2(302, "Rushikesh", "Marketing", 250, 80);
    Intern emp3(303, "Roshan", "Research", 15000);

    cout << "===== Employee Salary Details =====" << endl;

    emp1.display();
    emp2.display();
    emp3.display();

    return 0;
}
