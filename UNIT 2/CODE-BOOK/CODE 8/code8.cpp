#include <iostream> 
using namespace std;
 
class Base { 
public: 
    Base() { 
        cout << "Base constructor\n"; 
    } 
 
    ~Base() { 
        cout << "Base destructor\n"; 
    } 
}; 
 
class Derived : public Base { 
public: 
    Derived() { 
        cout << "Derived constructor\n"; 
    } 
 
    ~Derived() { 
        cout << "Derived destructor\n"; 
    } 
}; 
 
int main() { 
    Derived object; 
    return 0; 
}
