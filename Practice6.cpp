#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>

using namespace std;

void eratosthenes()
{
    int N;
    cout << "N = "; cin >> N;
    bool *B = new bool[N + 1];

    for (int P = 2; P <= N; P++) {
        B[P] = true;
    }

    int i;
    int P = 2;

    while (P * P <= N)
    {
        i = P * P;
        while (i <= N)
        {
            B[i] = false;
            i = i + P;
        }
        P = P + 1;
    }

    cout << "Prime numbers: " << endl;
    int count = 0;
    for (P = 2; P <= N; P++)
    {
        if (B[P])
        {
            count++;
            if (count % 2 == 0) {
                cout << " " << P;
            }
        }
    }
    delete[] B;
}

vector<int> sieveOfSundaram(int n) {
    int newLimit = (n - 2) / 2;
    vector<bool> marked(newLimit + 1, false);
    for (int i = 1; i <= newLimit; i++) {
        for (int j = i; (i + j + 2 * i * j) <= newLimit; j++) {
            marked[i + j + 2 * i * j] = true;
        }
    }

    vector<int> primes;
    if (n > 2) {
        primes.push_back(2);
    }
    for (int i = 1; i <= newLimit; i++) {
        if (!marked[i]) {
            primes.push_back(2 * i + 1);
        }
    }
    return primes;
}

int main()
{
    cout << "Eratosthenes alghorithm: " << endl;
    eratosthenes();
    cout << "Sundarama alghorithm: " << endl;

    srand(time(nullptr));
    int size;
    cout << "\nEnter the size of the array (up to 100 elements): ";
    cin >> size;
    size = min(size, 100);

    vector<int> array(size);
    cout << "Generated array values:\n";
    for (int i = 0; i < size; i++) {
        array[i] = 1 + rand() % 1000; // 1-1000
        cout << array[i] << " ";
    }

    int maxElement = *max_element(array.begin(), array.end());
    cout << "\nMaximum element in the array: " << maxElement << endl;

    vector<int> primes = sieveOfSundaram(maxElement);
    cout << "Prime numbers up to " << maxElement << ":\n";
    for (int prime : primes) {
        cout << prime << " ";
    }

    vector<int> commonElements;
    for (int num : array) {
        if (find(primes.begin(), primes.end(), num) != primes.end()) {
            commonElements.push_back(num);
        }
    }

    cout << "\nCommon elements between the generated array and prime numbers:" << endl;
    for (int num : commonElements) {
        cout << num << " ";
    }

    return 0;
}
