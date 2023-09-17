#include <cmath>
#include <iomanip>
#include <iostream>

using namespace std;

double get_surface_area_with_mosteller(double weight, double height)
{
    return sqrt(weight * height) / 60;
}

double get_surface_area_with_haycock(double weight, double height)
{
    return 0.024265 * pow(weight, 0.5378) * pow(height, 0.3964);
}

double get_surface_area_with_boyd(double weight, double height)
{
    double weight_pow = 0.6157 - 0.0188*log10(weight);
    return 0.0333 * pow(weight, weight_pow) * pow(height, 0.3);
}

int main()
{
    double weight, height;

    cout << weight << endl;
    cout << height << endl;

    cout << setprecision(15);
    
    cout << get_surface_area_with_mosteller(weight, height) << endl;
    cout << get_surface_area_with_haycock(weight, height) << endl;
    cout << get_surface_area_with_boyd(weight, height) << endl;

    return 0;
}