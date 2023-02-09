//Roan Morgan
//2.8.23
//Lab 2C - Recursive Pi Function
#include <iostream>
#include <cmath>
using namespace std;

double piCalculation(int n) {
    if (n <= 0) {
        return(4);
    }
    else {
        return(4 * (pow(-1, n) / (2 * n + 1)) + piCalculation(n - 1));
    }
}

int main(void) {

    int userin;

    cout << "PI CALCULATOR!!!! \n\n";

    cout << "Enter a number of PI terms to calculate: ";
    cin >> userin;

    cout << piCalculation(userin);

    return(0);
}