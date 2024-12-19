#include <iostream>
using namespace std;
int sumOfNaturalNumbers(int n) {
    if (n < 1) {
        cout << "Invalid input. Please enter a positive integer." << endl;
        return 0;
    }
    return n * (n + 1) / 2;
}

int main() {
    int n;
    cout << "Enter a positive integer: ";
    cin >> n;
    int result = sumOfNaturalNumbers(n);
    if (result != 0) {
        cout << "The sum of natural numbers up to " << n << " is: " << result << endl;
    }

    return 0;
}
