#include <iostream>
#include <vector>

using namespace std;

// Function to print the elements of an array
void printArray(const vector<int>& arr) {
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
}

int main() {
    int n;

    // Get the size of the integer array
    cout << "Enter the size of the integer array: ";
    cin >> n;

    // Get the integers for the array
    vector<int> arr(n);
    cout << "Enter " << n << " integers: ";
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    // Sort the array from max to min using your algorithm
    for (int i = 0; i < n; ++i) {
        // Find the maximum value in the remaining unsorted part of the array
        int maxIndex = 0;
        for (int j = 1; j < n - i; ++j) {
            if (arr[j] > arr[maxIndex]) {
                maxIndex = j;
            }
        }

        // Place the maximum value at the beginning (index 0) and swap it with the current element
        swap(arr[maxIndex], arr[n - i - 1]);

        // Reverse the members of the array
        for (int k = 0; k < (n - i) / 2; ++k) {
            swap(arr[k], arr[n - i - k - 1]);
        }
    }

    // Print the sorted array
    cout << "Sorted Array (min to max): ";
    printArray(arr);

    return 0;
}