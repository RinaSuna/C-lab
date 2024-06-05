#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

void findAndDisplayMatches(string text, string pattern) {
    transform(pattern.begin(), pattern.end(), pattern.begin(), ::tolower);
    transform(text.begin(), text.end(), text.begin(), ::tolower);

    size_t pos = text.find(pattern);
    int count = 0;

    cout << "Positions: ";
    while (pos != string::npos) {
        cout << pos << " ";
        count++;
        pos = text.find(pattern, pos + 1);
    }

    if (count > 0) {
        cout << endl << "Number of matches: " << count << endl;
    } else {
        cout << "No matches." << endl;
    }
}

string replacePattern(string text, const string& pattern, const string& replacement) {
    size_t pos = text.find(pattern);
    while (pos != string::npos) {
        text.replace(pos, pattern.length(), replacement);
        pos = text.find(pattern, pos + replacement.length());
    }
    return text;
}

string replaceLongWords(string text, const string& replacement) {
    string result;
    size_t start = 0;
    size_t end;
    size_t len;

    // in find_first_of we can set all characters to find as string
    while ((end = text.find_first_of(" .,;:!?-", start)) != string::npos) {
        len = end - start;
        result += len > 7 ? replacement + text[end] : text.substr(start, len + 1);
        start = end + 1;
    }

    // last word if we have no punctuation at the end
    if (start < text.size()) {
        len = text.size() - start;
        result += len > 7 ? replacement : text.substr(start, len);
    }

    return result;
}

int main() {
    string text = "Etiam et ex imperdiet purus viverra gravida. Mauris gravida dignissim magna sit amet malesuada. Maecenas tortor nunc, aliquam ac tortor varius, volutpat efficitur lacus. Praesent turpis mi, vestibulum a nisi sit amet, aliquam faucibus ipsum. Cras rhoncus est mauris, eget sollicitudin arcu eleifend ac. Vivamus tempus tincidunt pharetra. Pellentesque molestie viverra libero nec faucibus. Duis scelerisque eleifend dapibus.";
    string pattern, replacement;
    cout << "Initial text:\n\n" << text;

    cout << "\n\n// ======== Task 1 ======= //\n" << endl;
    cout << "Enter a pattern to search: ";
    getline(cin, pattern);
    findAndDisplayMatches(text, pattern);

    cout << "\n// ======== Task 2 ======= //\n" << endl;
    cout << "Enter a replacement string: ";
    getline(cin, replacement);
    text = replacePattern(text, pattern, replacement);
    cout << "Replaced text:\n\n" << text << endl;

    cout << "\n// ======== Task 3 ======= //\n" << endl;
    cout << "Enter a word to replace words longer than 7 characters: ";
    getline(cin, replacement);
    text = replaceLongWords(text, replacement);
    cout << "Final text:\n\n" << text << endl;

    return 0;
}
