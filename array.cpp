#include <iostream>
#include <cmath>

using namespace std;
int main() {
    int i, j;

    // Input the dimensions of the array
    cout << "Enter the number of rows (i): ";
    cin >> i;

    cout << "Enter the number of columns (j): ";
    cin >> j;

    // Declare the 2D array
    float array[i][j];

    // Input values for the array elements
    cout << "Enter the values for the array elements:" << endl;
    for (int row = 0; row < i; ++row) {
        for (int col = 0; col < j; ++col) {
            cout << "Enter value for array[" << row << "][" << col << "]: ";
            cin >> array[row][col];
        }
    }

    // Print the array elements
    cout << "Array elements:" << endl;
    for (int row = 0; row < i; ++row) {
        for (int col = 0; col < j; ++col) {
            cout << array[row][col] << " ";
        }
        cout << endl; // Move to the next row
    }
    
    // Calculate the average of each member in a 3x3 matrix using the moving average method
    if (i >= 3 && j >= 3) {
        cout << "Average values in a 3x3 moving matrix:" << endl;
        for (int row = 0; row <= i - 3; ++row) {
            for (int col = 0; col <= j - 3; ++col) {
                int sum = 0;
                for (int subRow = row; subRow < row + 3; ++subRow) {
                    for (int subCol = col; subCol < col + 3; ++subCol) {
                        sum += array[subRow][subCol];
                    }
                }
                double average = static_cast<double>(sum) / 9.0;
                cout << "Average for sub-matrix at [" << row << "][" << col << "]: " << average << endl;
            }
        }
    } else {
        cout << "The matrix is not large enough to compute the 3x3 moving average." << endl;
    }

    return 0;
}