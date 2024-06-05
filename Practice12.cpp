#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

void printArray(const vector<int>& arr) {
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
}

void shakerSort(vector<int>& arr) {
    bool swapped = true;
    int start = 0;
    int end = arr.size() - 1;

    while (swapped) {
        swapped = false;
        for (int i = start; i < end; ++i) {
            if (arr[i] > arr[i + 1]) {
                swap(arr[i], arr[i + 1]);
                swapped = true;
            }
        }

        if (!swapped) {
            break;
        }
        swapped = false;
        --end;

        for (int i = end - 1; i >= start; --i) {
            if (arr[i] > arr[i + 1]) {
                swap(arr[i], arr[i + 1]);
                swapped = true;
            }
        }
        ++start;
    }
}

int main() {
    int N;
    cout << "Enter N: ";
    cin >> N;

    vector<int> arr(N);
    srand(time(nullptr));

    for (int i = 0; i < N; ++i) {
        arr[i] = rand() % 100;
    }

    cout << "Array before sorting: ";
    printArray(arr);

    shakerSort(arr);

    cout << "Array after sorting: ";
    printArray(arr);

    for (int& num : arr) {
        num += (num % 2 == 0) ? 3 : -3;
    }

    cout << "Shifted array: ";
    printArray(arr);

    return 0;
}
