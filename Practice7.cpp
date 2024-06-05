#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

void searchText(string text, string pattern) {
    transform(text.begin(), text.end(), text.begin(), ::tolower);
    transform(pattern.begin(), pattern.end(), pattern.begin(), ::tolower);

    size_t count = 0;
    size_t pos = 0;
    while ((pos = text.find(pattern, pos)) != string::npos) {
        cout << "Pattern found at pos: " << pos << endl;
        pos += pattern.length();
        ++count;
    }
    cout << "found count: " << count << endl;
}

void analyzeText(const string& text) {
    int words = 0, sentences = 0, characters = text.length();
    for (auto ch : text) {
        if (ch == '.' || ch == '!' || ch == '?' || ch == ';') sentences++;
        if (ch == ' ') words++;
    }
    words++;

    cout << "Words: " << words << endl;
    cout << "Sentences: " << sentences << endl;
    cout << "Characters: " << characters << endl;
}

void task1() {
    string text = "Lorem ipsum. Lol ezz.";
    string pattern;

    cout << "Enter search pattern: ";
    getline(cin, pattern);

    searchText(text, pattern);
    analyzeText(text);
}

void task2() {
    string text, pattern, input;
    int choice;

    while (true) {
        cout << "Menu:\n1. Add text\n2. Enter pattern\n3. Exit\nChoose your options: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1:
                cout << "Enter text: ";
                getline(cin, input);
                text += " " + input;
                break;
            case 2:
                cout << "Enter pattern: ";
                getline(cin, pattern);
                searchText(text, pattern);
                break;
            case 3:
                return;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    }
}

int main() {
    cout << "Task 1: " << endl;
    task1();
    cout << endl << "Task2: " << endl;
    task2();

    return 0;
}
