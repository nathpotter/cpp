#include <iostream>
#include <string>
#include <cctype>

using namespace std;

bool isMobileNumber(const string &number) {
    // Check if the number has exactly 10 digits
    if (number.length() != 10) {
        return false;
    }
    
    // Check if all characters are digits
    for (char c : number) {
        if (!isdigit(c)) {
            return false;
        }
    }
    
    return true;
}

int main() {

    string inputNumber;
    cout << "Enter a 10-digit mobile number (q - quit): ";
    cin >> inputNumber;
    
    while (inputNumber != "q" || inputNumber != "Q")
    {
        /* code */
        if (inputNumber == "q" || inputNumber == "Q")
        {
            /* code */
            return 0;
        } else if (isMobileNumber(inputNumber)) {
            cout << "Valid mobile number." << endl;
        } else {
            cout << "Not a valid 10-digit mobile number." << endl;
        }
        
        cout << "Enter a 10-digit mobile number (q - quit): ";
        cin >> inputNumber;
    }
    
    return 0;
}