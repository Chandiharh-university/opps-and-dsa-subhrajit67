#include <iostream>
using namespace std;
class Base {
public:
    virtual void display() {
        cout << "Display from Base class" << endl;
    }
};
class Derived : public Base {
public:
    void display() override {
        cout << "Display from Derived class" << endl;
    }
    void show(int a) {
        cout << "Show with integer: " << a << endl;
    }

    void show(double a) {
        cout << "Show with double: " << a << endl;
    }

    void show(string a) {
        cout << "Show with string: " << a << endl;
    }
};

int main() {
    Base* basePtr;
    Derived derivedObj;
    basePtr = &derivedObj;

    cout << "Function Overriding Example:" << endl;
    basePtr->display();
    Derived d;
    cout << "\nFunction Overloading Example:" << endl;
    d.show(42);           
    d.show(3.14);        
    d.show("Hello!");

    return 0;
}
