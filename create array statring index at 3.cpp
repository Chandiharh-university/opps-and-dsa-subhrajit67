#include <iostream>
using namespace std;

class CustomArray {
private:
    int* arr;   
    int size;
    int offset;

public:
    CustomArray(int size) : size(size), offset(3) {
        arr = new int[size];}
    int& operator[](int index) {
        if (index < 3 || index >= 3 + size) {
            throw out_of_range("Index out of bounds!");
        }
        return arr[index - offset];
    }
    ~CustomArray() {
        delete[] arr;
    }
};

int main() {
    int n = 5;
    CustomArray customArr(n);
    for (int i = 3; i < 3 + n; ++i) {
        customArr[i] = i * 10;
    }
    cout << "Array elements (index starts from 3):" << endl;
    for (int i = 3; i < 3 + n; ++i) {
        cout << "customArr[" << i << "] = " << customArr[i] << endl;
    }

    return 0;
}
