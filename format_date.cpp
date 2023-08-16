#include <iostream>
#include <sstream>
#include <iomanip>
#include <map>

using namespace std;
int main() {
    map<string, string> monthMap = {
        {"01", "Jan"}, {"02", "Feb"}, {"03", "Mar"}, {"04", "Apr"},
        {"05", "May"}, {"06", "Jun"}, {"07", "Jul"}, {"08", "Aug"},
        {"09", "Sep"}, {"10", "Oct"}, {"11", "Nov"}, {"12", "Dec"}
    };

    string inputDate;
    cout << "Enter a date in the format DD/MM/YYYY: ";
    cin >> inputDate;

    string day, month, year;
    stringstream ss(inputDate);
    getline(ss, day, '/');
    getline(ss, month, '/');
    getline(ss, year);

    if (monthMap.find(month) == monthMap.end()) {
        cout << "Invalid month input." << endl;
        return 1;
    }

    cout << monthMap[month] << " " << day << ", " << year << endl;

    return 0;
}