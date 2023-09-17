#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;
vector<string> split(const string& line, char delimiter) {
    vector<string> tokens;
    istringstream tokenStream(line);
    string token;

    while (getline(tokenStream, token, delimiter)) {
        tokens.push_back(token);
    }

    return tokens;
}

int main() {
    // string input = "Hello,World,This,is,a,test";
    // char delimiter = ',';

    // vector<string> result = split(input, delimiter);

    // for (const string& token : result) {
    //     cout << token << endl;
    // }

    string line; 
    getline(cin, line);
    string delim; 
    getline(cin, delim); 
    for (string e : split(line, delim[0])) { 
        cout << '(' << e << ')'; 
        }

    return 0;
}