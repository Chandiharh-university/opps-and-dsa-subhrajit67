#include <iostream>
#include <iomanip>
using namespace std;
void printTable(int number, int range) {
    cout << "Multiplication Table for " << number << ":\n";
    for (int i = 1; i <= range; i++) {
        cout << setw(2) << number << " x " << setw(2) << i << " = " << setw(4) << number * i << endl;
    }
}

int main() {
    int number, range;

    cout << "Enter the number for which you want the table: ";
    cin >> number;

    cout << "Enter the range of the table (e.g., 10 for up to 10x): ";
    cin >> range;

    if (range < 1) {
        cout << "Invalid range. Please enter a positive integer greater than 0." << endl;
    } else {
        printTable(number, range);
    }

    return 0;
}
