#include <iostream>
#include <string>
#include <set>

using namespace std;
string ReplaceAll(string str, const string& from, const string& to) {
    size_t start_pos = 0;
    while((start_pos = str.find(from, start_pos)) != string::npos) {
        str.replace(start_pos, from.length(), to);
        start_pos += to.length(); // Handles case where 'to' is a substring of 'from'
    }
    return str;
}


int main() {
    string input;
    cout << "Enter a string: ";
    cin.ignore(); // Clear the newline character from the buffer
    getline(cin, input);
    // cin >> input;

    // Create a set to store the digits found in the input string
    set<char> digits_found;

    //Replace special character
    ReplaceAll(input, ",", " ");
    ReplaceAll(input, ".", " ");

    cout << "Entered string: " << input << endl;

    // Iterate through the characters in the input string
    for (char c : input) {
        if (isdigit(c)) {
            digits_found.insert(c);
            cout << c << "/";
        }
    }
    cout << endl;

    cout << "Numbers not found in the string: ";
    for (char c = '0'; c <= '9'; ++c) {      
        if (digits_found.find(c) == digits_found.end()) {
            cout << c << " ";
        }
    }

    cout << endl;

    return 0;
}