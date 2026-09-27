#include <iostream>
using namespace std; 
 
class Academic { 
public: 
    void display() const { 
        cout << "Academic information\n"; 
    } 
}; 
 
class Sports { 
public: 
    void display() const { 
        cout << "Sports information\n"; 
    } 
}; 
 
class Student : public Academic, public Sports { 
public: 
    void displayAll() const { 
        Academic::display(); 
        Sports::display(); 
    } 
}; 
 
int main() { 
    Student student; 
 
    student.Academic::display(); 
    student.Sports::display(); 
    student.displayAll(); 
 
    return 0; 
}
