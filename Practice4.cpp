#include <iostream>

using namespace std;

int main() {
    const int arrSize = 10;
    int arr[arrSize];

    cout << "Enter 10 array elements: ";
    for (int i = 0; i < 10; ++i) {
        cin >> arr[i];
    }

    int prevElement = arr[0];
    for (int i = 0; i < arrSize; i++) {
        if (prevElement > arr[i]) {
            cout << "Not sorted." << endl;
            return -1;
        }
        prevElement = arr[i];
    }

    int searchValue;
    cout << "Enter the value you are looking for: ";
    cin >> searchValue;

    int start = 0;
    int end = size(arr);
    int index = 0;

    cout << "Using binary search.." << endl;
    while ((end - start) > 1) {
        cout << "Range: [" << start << ", " << end << "] | Index: " << index << endl;
        index = (start + end) / 2;
        if (searchValue == arr[index]) {
            cout << "GG, binary search found the number at index " << index;
            return 0;
        } else if (searchValue < arr[index]) {
            end = index;
        } else if (searchValue > arr[index]) {
            start = index;
        }
    }
    cout << "Value not found";
    return -1;
}