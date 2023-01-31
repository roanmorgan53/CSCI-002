//Roan Morgan
//
//
#include <iostream>
#include <iomanip>
using namespace std;

template<typename T>
void printArray(T arg[], const int n);

int main(void) {
	
	//project description
	cout << "Learning Templates\n" << endl;

	const int size = 5;
	char a[size] = { 'a','b','c','d','e' };

	printArray(a, size);

	return(0);
}

template<typename T>
void printArray(T arg[], const int n) {
	for (int i = 0; i < n; i++) {
		cout << arg[i] << endl;
	}
}