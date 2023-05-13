#include <iostream>
#include <cstring>

using namespace std;

// Function to implement Horspool's algorithm for string matching
// Returns the index of the first occurrence of the pattern in the text
// Returns -1 if the pattern is not found
// Also returns the number of key comparisons made during the search
int horspoolStringMatch(const char* text, const char* pattern, int& comparisons) {
    int n = strlen(text);
    int m = strlen(pattern);

    if (m > n) {
        return -1;
    }

    // Initialize the shift table
    const int MAX_CHARS = 256;
    int shift_table[MAX_CHARS];
    for (int i = 0; i < MAX_CHARS; i++) {
        shift_table[i] = m;
    }

    for (int i = 0; i < m - 1; i++) {
        shift_table[pattern[i]] = m - 1 - i;
    }

    // Search for the pattern in the text
    int i = m - 1;
    while (i < n) {
        int k = 0;
        comparisons++;
        while (k < m && pattern[m - 1 - k] == text[i - k]) {
            comparisons++;
            k++;
        }
        if (k == m) {
            return i - m + 1;
        }
        i += shift_table[text[i]];
    }

    // Pattern not found
    return -1;
}

int main() {
    // Get the text and pattern strings from the user
    const int MAX_LENGTH = 1000;

    char text[MAX_LENGTH];
    char pattern[MAX_LENGTH];

    cout << "Enter the text: ";
    cin.getline(text, MAX_LENGTH);

    cout << "Enter the pattern: ";
    cin.getline(pattern, MAX_LENGTH);

    // Find the first occurrence of the pattern in the text using Horspool's algorithm
    int comparisons = 0;
    int index = horspoolStringMatch(text, pattern, comparisons);

    if (index != -1) {
        cout << "Pattern found at index " << index+1 << endl;
        cout << "Number of key comparisons: " << comparisons << endl;
    } else {
        cout << "Pattern not found" << endl;
        cout << "Number of key comparisons: " << comparisons << endl;
    }

    return 0;
}
