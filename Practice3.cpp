#include <iostream>
using namespace std;

int main() {
    const int size = 10;
    int arr[size];

    cout << "Enter 10 array elements: ";
    for (int i = 0; i < 10; ++i) {
        cin >> arr[i];
    }

    int searchValue;
    cout << "Enter the value you are looking for: ";
    cin >> searchValue;

    for (int i = 0; i < 10; i++) {
        if (arr[i] == searchValue) {
            cout << "Value " << searchValue << " found in position: " << i << endl;
            return 0;
        }
    }

    cout << "Value " << searchValue << " not found in array." << endl;
    return -1;
}