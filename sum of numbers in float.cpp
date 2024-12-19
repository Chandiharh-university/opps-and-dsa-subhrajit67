#include <iostream>
#include <iomanip>
using namespace std;
float calculateSum(float* numbers, int size) {
    float sum = 0.0;
    for (int i = 0; i < size; i++) {
        sum += numbers[i];
    }
    return sum;
}
float* inputNumbers(int size) {
    if (size <= 0) {
        return nullptr;
    }
    float* numbers = new float[size];

    cout << "Enter " << size << " floating-point numbers:" << endl;
    for (int i = 0; i < size; i++) {
        cout << "Number " << i + 1 << ": ";
        cin >> numbers[i];
    }

    return numbers;
}

int main() {
    int n;
    cout << "Enter the number of floating-point numbers to sum: ";
    cin >> n;

 
    if (n <= 0) {
        cout << "Invalid input. The number of elements must be greater than 0." << endl;
        return 1;
    }

    float* numbers = inputNumbers(n);

    if (numbers == nullptr) {
        cout << "Memory allocation failed." << endl;
        return 1;
    }
    float sum = calculateSum(numbers, n);

    cout << fixed << setprecision(2);
    cout << "\nThe sum of the entered numbers is: " << sum << endl;

    delete[] numbers;

    return 0;
}
