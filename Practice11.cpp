#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>

using namespace std;

void insertSortFirstCol(vector<vector<int>>& matrix) {
    int n = matrix.size();
    for (int i = 1; i < n; ++i) {
        vector<int> key = matrix[i];
        int j = i - 1;
        while (j >= 0 && matrix[j][0] < key[0]) {
            matrix[j + 1] = matrix[j];
            j--;
        }
        matrix[j + 1] = key;
    }
}

void printMatrix(const vector<vector<int>>& matrix) {
    for (const auto& row : matrix) {
        for (int num : row) {
            cout << num << " ";
        }
        cout << "\n";
    }
}

void insertionSort(vector<int> &arr) {
    int n = arr.size();
    for (int i = 1; i < n; ++i) {
        int key = arr[i];
        int j = i - 1;

        cout << "Inserting " << key << ": ";
        while (j >= 0 && arr[j] > key) {
            cout << arr[j] << " shifted to " << (j + 1) << "; ";
            arr[j + 1] = arr[j];
            --j;
        }
        arr[j + 1] = key;
        cout << "inserted at position " << (j + 1) << "\n";
    }
}

void sortColumns(vector<vector<int>>& matrix) {
    for (auto& row : matrix) {
        sort(row.begin() + 1, row.end());
    }
}

void task2() {
    int n, m;
    cout << "Enter number of rows: ";
    cin >> n;
    cout << "Enter number of columns: ";
    cin >> m;

    vector<vector<int>> matrix(n, vector<int>(m));
    for (auto& row : matrix) {
        for (int& num : row) {
            num = rand() % 100;
        }
    }

    cout << "Matrix before sorting:\n";
    printMatrix(matrix);

    insertSortFirstCol(matrix);
    sortColumns(matrix);

    cout << "Matrix after sorting:\n";
    printMatrix(matrix);
}

void task1() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    vector<int> arr(n);
    for (int &num : arr) {
        num = rand() % 100;
    }

    cout << "Array before sorting:\n";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << "\n";

    insertionSort(arr);

    cout << "Array after sorting:\n";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << "\n";
}

int main() {
    srand(time(nullptr));
    cout << "// ======== Task 1 ======= //\n" << endl;
    task1();

    cout << "\n\n// ======== Task 2 ======= //\n" << endl;
    task2();

    return 0;
}
