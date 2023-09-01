#include <iostream>
#include <sstream>
#include <cmath>

using namespace std;

int main() {
    long long M, N;
    int result;

    cout << "Enter two numbers (M and N): ";
    cin >> M >> N;

    if( M > N){
        cout << "M > N: please input M < N" << endl;

    }else
    {
        // cout << "M < N" << endl;
        
        // int count = 0;
        string long_to_string;
        stringstream stream;

        // for (long long num = M; num <= N; ++num) {
        //     stream << num;
        //     long_to_string = stream.str();
        //     // cout << "long_to_string: " << long_to_string << endl;
        // }

        // count = long_to_string.length();

        long long count = N - M + 1;
        // result = static_cast<int>(log10(count) + 1);

        result = count;
        cout << "Count of numbers between " << M << " and " << N << ": " << result << endl;
    }
    

    // if (M > N) {
    //     cout << "M > N: please input M < N" << endl;
    //     return 1;
    // } else {
    //     cout << "M < N" << endl;

    //     long long count = N - M + 1;
    //     int result = static_cast<int>(log10(count) + 1);

    //     cout << "Count of numbers between " << M << " and " << N << ": " << result << endl;
    // }
    
    return 0;
}