#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; ++j) {
        if (arr[j] <= pivot) {
            ++i;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}
void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}
void countingSort(vector<int>& arr, int start, int end) {
    int maxElement = *max_element(arr.begin() + start, arr.begin() + end + 1);
    int minElement = *min_element(arr.begin() + start, arr.begin() + end + 1);
    int range = maxElement - minElement + 1;

    vector<int> count(range, 0);
    vector<int> output(end - start + 1);

    for (int i = start; i <= end; ++i) {
        count[arr[i] - minElement]++;
    }

    for (int i = 1; i < range; ++i) {
        count[i] += count[i - 1];
    }

    for (int i = end; i >= start; --i) {
        output[count[arr[i] - minElement] - 1] = arr[i];
        count[arr[i] - minElement]--;
    }

    for (int i = 0; i < output.size(); ++i) {
        arr[start + i] = output[i];
    }
}
void combinedSort(vector<int>& arr) {
    int n = arr.size();
    int pivotIndex = partition(arr, 0, n - 1);
    quickSort(arr, 0, pivotIndex - 1);
    countingSort(arr, pivotIndex, n - 1);
}

int main() {
    vector<int> arr = {44,55,35,26,19,69,86,20,61,99};

    cout << "Original Array: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
    combinedSort(arr);

    cout << "Sorted Array (Quick + Counting): ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
