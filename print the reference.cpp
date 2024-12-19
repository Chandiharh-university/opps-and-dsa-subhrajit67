#include <iostream>
using namespace std;
void passByValue(int num) {
    num = num + 10; 
    cout << "Inside passByValue function, num = " << num << endl;
}

void passByReference(int &num) {
    num = num + 10;
    cout << "Inside passByReference function, num = " << num << endl;
}
void staticVariableExample() {
    static int count = 0; 
    count++;
    cout << "Static variable count = " << count << endl;
}

int main() {
    int num;
    cout << "Enter an integer: ";
    cin >> num;
    cout << "Before passByValue, num = " << num << endl;
    passByValue(num);
    cout << "After passByValue, num = " << num << endl;

    cout << "Before passByReference, num = " << num << endl;
    passByReference(num); 
    cout << "After passByReference, num = " << num << endl;
    staticVariableExample();
    staticVariableExample(); 

    return 0;
}
