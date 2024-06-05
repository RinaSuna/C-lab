#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;


void shellSort(vector<int>& arr) {
    int n = arr.size();
    for (int step = n / 2; step > 0; step /= 2) {
        for (int i = step; i < n; i++) {
            if (arr[i] % 2 == 0) {
                int temp = arr[i];
                int j;
                for (j = i; j >= step && arr[j - step] > temp; j -= step) {
                    if (arr[j - step] % 2 == 0) {
                        arr[j] = arr[j - step];
                    }
                }
                arr[j] = temp;
            }
        }
    }
}

int main() {
    int N;
    cout << "Input N: ";
    cin >> N;

    vector<int> arr(N);

    srand(static_cast<unsigned int>(time(nullptr)));
    for (int& value : arr) {
        value = rand() % 100;
    }

    cout << "Array before sorting: ";
    for (int value : arr) {
        cout << value << " ";
    }
    cout << endl;

    shellSort(arr);

    cout << "Array after sorting even numbers: ";
    for (int value : arr) {
        cout << value << " ";
    }
    cout << endl;

    return 0;
}
