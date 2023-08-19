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
        if (c == '(') {
            c = '[';
        }
        
        if (c == ')') {
            c = ']';
        }

        if (c == '[') {
            c = '(';
        }
        
        if (c == ']') {
            c = ')';
        }
    }
    
    // Print the modified string
    cout << "Modified string: " << inputString << endl;
    
    return 0;
}
