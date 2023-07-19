#include <iostream>
#include <vector>

void print(int);

int main() {

std::vector<double> order = {3.99, 12.99, 2.49};

// What's the first element?
std::cout << order[0] << "\n";

// What's the last element?
std::cout << order[2] << "\n";

print(555);

}

// parameter a is defined for the function print
void print(int a) {
  std::cout << a;  
}