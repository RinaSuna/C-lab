#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>

using namespace std;

struct Card {
    string suit;
    string value;
};

void printDeck(const vector<Card>& deck) {
    for (const auto& card : deck) {
        cout << card.suit << " of " << card.value << ", ";
    }
    cout << "\n";
}

bool compareBySuit(const Card& a, const Card& b) {
    return a.suit < b.suit;
}

bool compareByValue(const Card& a, const Card& b) {
    const vector<string> order = {"2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King", "Ace"};
    auto it1 = find(order.begin(), order.end(), a.value);
    auto it2 = find(order.begin(), order.end(), b.value);
    return it1 < it2;
}

void printArray(const vector<int>& arr) {
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
}

void selectionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        swap(arr[i], arr[min_idx]);
    }
}

void task1() {
    int N;
    cout << "Enter the number of elements in the array: ";
    cin >> N;

    vector<int> arr(N);
    cout << "Enter elements: ";
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    cout << "Before sorting: ";
    printArray(arr);

    selectionSort(arr);

    cout << "After sorting: ";
    printArray(arr);
}

void task2() {
    vector<Card> deck = {
            {"Hearts", "Ace"}, {"Diamonds", "2"}, {"Clubs", "King"}, {"Spades", "10"},
            {"Hearts", "King"}, {"Diamonds", "Queen"}, {"Clubs", "Jack"}, {"Spades", "9"},
            {"Hearts", "3"}, {"Diamonds", "Jack"}, {"Clubs", "10"}, {"Spades", "King"},
    };

    cout << "Unsorted deck:\n";
    printDeck(deck);

    sort(deck.begin(), deck.end(), compareBySuit);
    cout << "Deck sorted by suit:\n";
    printDeck(deck);

    stable_sort(deck.begin(), deck.end(), compareByValue);

    cout << "Deck sorted by suit and value:\n";
    printDeck(deck);
}

int main() {
    cout << "// ======== Task 1 ======= //\n" << endl;
    task1();

    cout << "\n\n// ======== Task 2 ======= //\n" << endl;
    task2();

    return 0;
}
