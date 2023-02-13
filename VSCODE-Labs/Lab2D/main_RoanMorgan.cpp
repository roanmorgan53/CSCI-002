#include <iostream>
#include <cstdlib>
using namespace std;

double powIterate(double x, int n);
double powRecursive(double x, int n);

int main(void){
    double x = 5;
    int n = 3;

    cout << powIterate(x,n) << endl;

    cout << powRecursive(x,n) << endl;

    return(0);
}

double powIterate(double x, int n){

    for(int i = 0; i < n; i+=2){
        x = x*x;
    }

    return x;
}

double powRecursive(double x, int n){
    if(n <= 0){
        return x;
    }
    else{
        n--;
        x = x * powRecursive(x,n);
    }
    return x;
}
