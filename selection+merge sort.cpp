#include <iostream>
#include <vector>
using namespace std;
void selectionSort(vector<int>& arr, int start, int end) {
    for (int i = start; i < end; ++i) {
        int minIndex = i;
        for (int j = i + 1; j <= end; ++j) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        swap(arr[i], arr[minIndex]);
    }
}
void merge(vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<int> leftArr(n1), rightArr(n2);

    for (int i = 0; i < n1; ++i) leftArr[i] = arr[left + i];
    for (int i = 0; i < n2; ++i) rightArr[i] = arr[mid + 1 + i];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (leftArr[i] <= rightArr[j]) {
            arr[k++] = leftArr[i++];
        } else {
            arr[k++] = rightArr[j++];
        }
    }

    while (i < n1) arr[k++] = leftArr[i++];
    while (j < n2) arr[k++] = rightArr[j++];
}
void mergeSort(vector<int>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}
void combinedSort(vector<int>& arr) {
    int n = arr.size();
    int mid = n / 2;
    selectionSort(arr, 0, mid - 1);
    mergeSort(arr, mid, n - 1);
    merge(arr, 0, mid - 1, n - 1);
}

int main() {
    vector<int> arr = {78,45,86,12,63,41,55,38,97,60};

    cout << "Original Array: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    combinedSort(arr);

    cout << "Sorted Array (Selection + Merge): ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
