#include <iostream>
#include <cstdlib>
using namespace std;

double powIterate(double x, int n);
double powRecursive(double x, int n);

int main(void){
    double x = 3;
    int n = 4;

    cout << powIterate(x,n) << endl;

    cout << powRecursive(x,n) << endl;

    return(0);
}

double powIterate(double x, int n){
    double xTemp = 1;
    
    for(int i = 0; i<n; i++){
        xTemp *= x; 
    }

    return xTemp;
}

double powRecursive(double x, int n){
    if(n == 0){
        return 1;
    }
    return x * powRecursive(x, n-1);
}
