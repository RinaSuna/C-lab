#include <iostream>
#include <cstdlib>
#include <ctime> 

using namespace std;

int generateRandomInt(int min, int max) {
    return min + rand() % (max - min + 1);
}

void task6() {
    srand(time(nullptr));

    int attempts = 0;
    int generated = generateRandomInt(0, 20);

    while (true) {
        attempts++;

        int number;
        cout << "Enter your number: ";
        cin >> number;

        if (number > 20 || number < 0) {
            cout << "Invalid number!" << endl;
        } else if (number < generated) {
            cout << "Your number is smaller than generated!";
        } else if (number > generated) {
            cout << "Your number is greater than generated!";
        } else {
            cout << "You guessed the number! Attempts: " << attempts;
            break;
        }
    }
}

int fibonacci(int n) {
    return n <= 1 ? n : fibonacci(n - 1) + fibonacci(n - 2);
}

void task5() {
    int count;
    cout << "Fibonacci length: ";
    cin >> count;

    for (int i = 0; i < count; ++i) {
        cout << fibonacci(i) << " ";
    }
    cout << endl;
}


int smallestNaturalDivisor(int num) {
    int divisor = 2;
    while (divisor <= num) {
        if (num % divisor == 0) {
            return divisor;
        }
        divisor++;
    }
    return num;
}

void task4() {
    int a;
    cout << "Enter A, greater than 2: ";
    cin >> a;

    if (a < 2) {
        cout << "Error, you've entered the number . :<" << endl;
        return;
    }
    cout << "Smallest natural divisor: " << smallestNaturalDivisor(a) << endl;
}

void task3() {
    int N;
    cout << "Enter count: ";
    cin >> N;

    double start = 1;
    for (int i = 1; i < N; i++) {
        cout << start << " ";
        start *= -0.5;
    }
    cout << endl;
}

void task2() {
    int arr[3] = {5, 0, 3};

    int N;
    cout << "Enter N: ";
    cin >> N;

    if (N % 2 == 0) {
        int minNumber = arr[0];
        for (int i : arr) {
            if (i < minNumber) {
                minNumber = i;
            }
        }
        cout << minNumber;
    } else {
        int maxNumber = arr[0];
        for (int i : arr) {
            if (i > maxNumber) {
                maxNumber = i;
            }
        }
        cout << maxNumber;
    }
    cout << endl;
}

void task1() {
    int arr[3] = {5, 0, 3};

    int N;
    cout << "Enter N: ";
    cin >> N;

    for (int i : arr) {
        if (i >= 1 && i <= N) {
            cout << i << " ";
        }
    }
    cout << endl;
}

int main()
{
    task1();
    task2();
    task3();
    task4();
    task5();
    task6();

    return 0;
}
