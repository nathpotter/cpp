
#include <iostream>
#include <conio.h>
#include <ctime>
using namespace std;

int main()
{

const float PI = 3.14159F; //type const float
float cal;

char charvar1 = 'C'; //define char variable as character
char charvar2 = '\t'; //define char variable as tab
cout << charvar1; //display character
cout << charvar2; //display character
charvar1 = 'B'; //set char variable to char constant
cout << charvar1; //display character
cout << '\n'; //display newline character

cal = PI + 1*2/3;
cout << "result of (PI + 1*2/3) = " << cal ; 

float count = 7.55;
float avgWeight = 155.5F;
double totalWeight = count * avgWeight;
cout << "totalWeight= " << totalWeight << endl;

int intVar = 1500000000; //1,500,000,000
double result;
intVar = (intVar * 10) / 10; //result too large
cout << "intVar = " << intVar << endl; //wrong answer
intVar = 1500000000; //cast to double
result = (static_cast<double>(intVar) * 10) / 10;
cout << "result = " << result << endl; //right answer

return 0;

}