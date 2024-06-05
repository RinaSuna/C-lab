#include <iostream>
#include <algorithm>
#include <ctime>
#include <cstdlib>

using namespace std;

int binarySearch(const int arr[], int n, int value) {
    int left = 0, right = n - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == value) return mid;
        else if (arr[mid] < value) left = mid + 1;
        else right = mid - 1;
    }
    return -1;
}

int interpolationSearch(const int arr[], int n, int value) {
    int low = 0, high = n - 1;
    while (low <= high && value >= arr[low] && value <= arr[high]) {
        int pos = low + (((double)(high - low) / (arr[high] - arr[low])) * (value - arr[low]));
        if (arr[pos] == value) return pos;
        if (arr[pos] < value) low = pos + 1;
        else high = pos - 1;
    }
    return -1;
}

int main() {
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    int* arr = new int[n];
    srand(time(nullptr));

    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100;
    }

    sort(arr, arr + n);

    cout << "Array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    int value1, value2;
    cout << "First value: ";
    cin >> value1;
    cout << "Second value: ";
    cin >> value2;

    int index1 = -1, index2 = -1;
    if (n <= 20) {
        index1 = binarySearch(arr, n, value1);
        index2 = binarySearch(arr, n, value2);
    } else if (n <= 100) {
        index1 = interpolationSearch(arr, n, value1);
        index2 = interpolationSearch(arr, n, value2);
    }

    if (index1 != -1) cout << "Value " << value1 << " found at position: " << index1 << endl;
    else cout << "Value " << value1 << " not found." << endl;

    if (index2 != -1) cout << "Value " << value2 << " found at position: " << index2 << endl;
    else cout << "Value " << value2 << " not found." << endl;

    delete[] arr;

    return 0;
}
