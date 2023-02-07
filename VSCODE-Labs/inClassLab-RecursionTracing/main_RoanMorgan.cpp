//Roan Morgan
//2.6.23
//RECURSION TRACKING!!!
#include <iostream>
#include <cstdlib>
using namespace std;

bool isPrime(int p, int i);
int fibonacci(int x);

int main(void){

   cout << isPrime(50, 2) << endl;

    return(0);
}

bool isPrime(int p, int i = 2){
 if (i == p) return 1;
 if (p%i == 0) return 0;
 return isPrime(p, i + 1);

}

int fibonacci(int x){
 if (x < 2) return x;
 return (fibonacci(x - 1) + fibonacci(x - 2));
}