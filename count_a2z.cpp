#include <iostream>
#include <string>
#include <map>
#include <cctype>

using namespace std;
int main() {
    string input;
    cout << "Enter a string: ";
    getline(cin, input);

    // Create a map to store character counts
    map<char, int> charCounts;

    // Iterate through the characters in the input string
    for (char c : input) {
        // Convert the character to lowercase for case-insensitive counting
        c = tolower(c);

        // Check if the character is a letter
        if (isalpha(c)) {
            // Increment the count for the character in the map
            charCounts[c]++;
        }
    }

    // Display character counts
    cout << "Character counts:" << endl;
    for (char c = 'a'; c <= 'z'; ++c) {
        if (charCounts[c] != 0)
        {
            /* code */
            cout << c << ": " << charCounts[c] << endl;
        }
        
    }

    return 0;
}