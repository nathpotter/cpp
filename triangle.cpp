#include <iostream>

using namespace std;
int main() {
    int h;
    
    // Read input for h
    cout << "Enter the value of h: ";
    cin >> h;

    // Calculate width of the triangle
    int width = 2 * h - 1;
    
    // Draw the triangle
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < width; ++j) {
            if (j >= h - i - 1 && j < h + i) {
                cout << "*";
            } else {
                cout << " ";
            }
        }
        cout << endl;
    }

    return 0;
}