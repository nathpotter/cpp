#include <iostream>
#include <string>

using namespace std;
int main() {
    string interestedWord, sentence;
    
    // Read input for interested word
    cout << "Enter the interested word: ";
    cin >> interestedWord;
    
    // Read input for sentence
    cout << "Enter the sentence: ";
    cin.ignore(); // Clear the newline character from the buffer
    getline(cin, sentence);

    // Count occurrences of the interested word in the sentence
    int count = 0;
    size_t pos = sentence.find(interestedWord);
    while (pos != string::npos) {
        count++;
        pos = sentence.find(interestedWord, pos + 1);
    }

    // Print the count of occurrences
    cout << "The interested word appears " << count << " times in the sentence." << endl;

    return 0;
}