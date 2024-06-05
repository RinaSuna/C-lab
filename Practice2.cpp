#include <iostream>
#include <algorithm>

using namespace std;

void task4() {
    // Написати програму. Дано два масива.
    // Зробити третій масив з двох цих масивів.
    // Розташування у масиві у порядку зростання.
    int arr1[] = {5, 3, 1};
    int size1 = sizeof(arr1) / sizeof(arr1[0]);

    int arr2[] = {4, 2, 6};
    int size2 = sizeof(arr2) / sizeof(arr2[0]);

    int result[size1 + size2];
    for(int i = 0; i < size1; i++) {
        result[i] = arr1[i];
    }

    for(int i = 0; i < size2; i++) {
        result[size1 + i] = arr2[i];
    }

    sort(result, result + size1 + size2);
    for(int i = 0; i < size1 + size2; i++) {
        cout << result[i] << " ";
    }
}

void task3() {
    // 3. У масиві у порядку зменшення є купюри [1000, 500,  200, 100, 50, 20, 10, 5, 2, 1].
    // Реалізовати видачу суми, введеної з екрану мінімальною кількістю купюр.

    int coupons[] = { 1000, 500,  200, 100, 50, 20, 10, 5, 2, 1 };
    int needToCashout;
    cout << "enter sum: ";
    cin >> needToCashout;

    int index = 0;
    int count = 0;
    while (needToCashout > 0 && index < size(coupons)) {
        if (needToCashout < coupons[index]) {
            index++;
        }
        else if (needToCashout - coupons[index] >= 0) {
            cout << coupons[index] << " ";
            needToCashout -= coupons[index];
            count++;
        }
    }
    cout << endl << "given coupons: " << count << endl;
}

void task2() {
//    2.	Написати програму. У масиві цілих чисел, довжиною 10+№
//    (де №-остання цифра студента у списку групи), усі негативні елементи замініть позитивними.
//    Виведіть заданий та отриманий масиви на екран.
    int arr[15] {-12, 5, 1, 4, -5, -158, -2, 12, 86, 31, 14, -9, 0, 76, 5};

    cout << "Initial array: ";
    for (int element : arr) {
        cout << element << " ";
    }
    cout << endl;

    cout << "New array: ";
    for (int &element : arr) {
        if (element < 0) {
            element = 12; // positive number
        }
        cout << element << " ";
    }
    cout << endl;
}

void task1() {
    // 1.	Написати програму. З масиву Х довжиною 10+№  (де №-остання цифра студента у списку групи),
    // серед елементів якого є позитивні та негативні та нуль,
    // сформуйте новий масив Y, узявши тільки елементи з Х які більше по модулю заданого числа М.
    // Виведіть на екран число М та масиви заданий та отриманий.

    int arr[15] {-12, 5, 1, 4, -5, -158, -2, 12, 86, 31, 14, -9, 0, 76, 5};
    int arr2[15];

    cout << "Initial array: ";
    for (int element : arr) {
        cout << element << " ";
    }
    cout << endl;

    int M;
    cout << "Enter M: ";
    cin >> M;

    cout << "New array: ";
    int index = 0;
    for (int i = 0; i < size(arr); i++) {
        if (abs(arr[i]) > M) {
            arr2[index] = arr[i];
            cout << arr[i] << " ";
        }
    }
    cout << endl;
}

int main() {
    cout << "Task #1:" << endl;
    task1();
    cout << "Task #2:" << endl;
    task2();
    cout << "Task #3:" << endl;
    task3();
    cout << "Task #4:" << endl;
    task4();

    return 0;
}
