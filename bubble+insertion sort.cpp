#include <iostream>
#include <vector>
using namespace std;
void bubbleSort(vector<int>& arr, int start, int end) {
    for (int i = start; i < end; ++i) {
        for (int j = start; j < end - (i - start); ++j) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}
void insertionSort(vector<int>& arr, int start, int end) {
    for (int i = start + 1; i <= end; ++i) {
        int key = arr[i];
        int j = i - 1;
        while (j >= start && arr[j] > key) {
            arr[j + 1] = arr[j];
            --j;
        }
        arr[j + 1] = key;
    }
}
void combinedSort(vector<int>& arr) {
    int n = arr.size();
    int mid = n / 2;
    bubbleSort(arr, 0, mid - 1);
    insertionSort(arr, mid, n - 1);
}

int main() {
    vector<int> arr = {64, 34, 25, 12, 22, 11, 90, 88, 77, 66};

    cout << "Original Array: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
    combinedSort(arr);
    cout << "Sorted Array (Bubble + Insertion): ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
