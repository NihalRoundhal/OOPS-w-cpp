#include <iostream> 
#include <string> 
using namespace std;
 
class Person { 
protected: 
    string name; 
 
public: 
    explicit Person(string personName) : name(move(personName)) {} 
 
    void showPerson() const { 
        cout << "Name: " << name << '\n'; 
    } 
}; 
 
class Employee : public Person { 
protected: 
    int employeeId; 
 
public: 
    Employee(string employeeName, int id) 
        : Person(move(employeeName)), employeeId(id) {} 
 
    void showEmployee() const { 
        cout << "Employee ID: " << employeeId << '\n'; 
    } 
}; 
 
class Manager : public Employee { 
private: 
    int teamSize; 
 
public: 
    Manager(string managerName, int id, int size) 
        : Employee(move(managerName), id), teamSize(size) {} 
 
    void showManager() const { 
        showPerson(); 
        showEmployee(); 
        cout << "Team Size: " << teamSize << '\n'; 
    } 
}; 
 
int main() {
    Manager manager("ABHISHEK", 420420, 8); 
    manager.showManager(); 
    return 0; 
}
