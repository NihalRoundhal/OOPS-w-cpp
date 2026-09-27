#include <iostream> 
#include <string> 
using namespace std; 
 
class Person { 
protected: 
    string name; 
 
public: 
    explicit Person(string personName) : name(move(personName)) {} 
}; 
 
class Student : public Person { 
private: 
    int rollNumber; 
 
public: 
    Student(string studentName, int roll) 
        : Person(move(studentName)), rollNumber(roll) {} 
 
    void display() const { 
        cout << "Name: " << name << '\n'; 
        cout << "Roll Number: " << rollNumber << '\n'; 
    } 
}; 
 
int main() { 
    Student student("ABHISHEK", 2152); 
    student.display(); 
    return 0; 
}
