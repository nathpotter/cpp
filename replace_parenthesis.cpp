#include <iostream>
#include <string>

using namespace std;
int main() {
    string inputString;
    
    // Read input string from the user
    cout << "Enter a string: ";
    getline(cin, inputString);
    
    // Loop through the string and replace '(' with '['
    for (char &c : inputString) {
        cout << "Character: " << c <<endl;
        switch (c) {
        case '(':
            c = '[';
            break;
        case ')':
            c = ']';
            break;
        case '[':
            c = '(';
            break;
        case ']':
            c = ')';
            break;
        default:
            // operator is doesn't match any case constant (+, -, *, /)
            // cout << "Error! The operator is not correct";
            break;
    }
    }
    
    // Print the modified string
    cout << "Modified string: " << inputString << endl;
    
    return 0;
}
