#include <iostream>
#include <vector>
#include <ctime>

using namespace std;

void printArray(const vector<int>& arr) {
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
}

void printMatrix(const vector<vector<int>>& matrix) {
    for (const auto& row : matrix) {
        for (int num : row) {
            cout << num << " ";
        }
        cout << endl;
    }
}
void bubbleSortRows(vector<vector<int>>& matrix) {
    for (auto& row : matrix) {
        bool swapped;
        size_t n = row.size();
        do {
            swapped = false;
            for (int j = 0; j < n - 1; j++) {
                cout << "Comparing: " << row[j] << " | " << row[j + 1] << endl;
                if (row[j] < row[j + 1]) {
                    swap(row[j], row[j + 1]);
                    swapped = true;
                    cout << "Swapped in row: ";
                    for (int num : row) {
                        cout << num << " ";
                    }
                    cout << endl;
                }
            }
        } while (swapped);
    }
}

void bubbleSort(vector<int>& arr) {
    bool swapped;
    size_t n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        swapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            cout << "Comparing: " << arr[j] << " | " << arr[j + 1] << endl;
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
                cout << "Swapped: ";
                printArray(arr);
            }
        }
        if (!swapped) break;
    }
}

void task1() {
    int N;
    cout << "Enter array size (N): ";
    cin >> N;

    vector<int> arr(N);

    for (int i = 0; i < N; i++) {
        arr[i] = rand() % 50;
    }

    cout << "// ======== Task 1 ======= //\n\n";
    cout << "Array before sorting: ";
    printArray(arr);
    bubbleSort(arr);

    cout << "Array after sorting: ";
    printArray(arr);
}

void task2() {
    cout << "\n\n// ======== Task 2 ======= //\n\n";

    int N, M;
    cout << "Enter matrix rows: ";
    cin >> N;
    cout << "Enter matrix cols: ";
    cin >> M;

    vector<vector<int>> matrix(N, vector<int>(M));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            matrix[i][j] = rand() % 100;
        }
    }

    cout << "Matrix before sorting: " << endl;
    printMatrix(matrix);

    bubbleSortRows(matrix);

    cout << "Matrix after sorting: " << endl;
    printMatrix(matrix);
}

int main() {
    srand(time(nullptr));

    task1();
    task2();

    return 0;
}
