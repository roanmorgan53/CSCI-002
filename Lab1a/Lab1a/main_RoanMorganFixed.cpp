//Roan Morgan
//Lab 1a: Review C++ Arrays
//1.18.23
#include <iostream>
#include <iomanip>
using namespace std;

void printArray(char a[], const int size);
void printPointerArray(char* a, const int* size);

int main(void) {
	srand(time(0));
	
	//project description
	cout << "Review C++ Arrays" << endl;

	const int size = 15;
	char RandomChars[size];
	int randomCharASCII;

	for (int i = 0; i < size; i++) {
		randomCharASCII = 97 + rand() % 26;
		RandomChars[i] = char(randomCharASCII);
	}

	const int* sizePtr = &size;

	printArray(RandomChars, size);
	printPointerArray(RandomChars, sizePtr);

	return(0);
}

void printArray(char a[], const int size)
{
	for (int i = 0; i < size; i++) {
		cout << "Char: " << a[i] << "\t";
		cout << "Index: " << long(&a[i]) << endl;
	}
	cout << endl;
}

void printPointerArray(char* a, const int* size)
{
	const int sizeDeRef = *size;


	cout << "From Pointer:" << endl;

	for (int i = 0; i < sizeDeRef; i++) {
		cout << "Char: " << *(a + i) << "\t";
		cout << "Index: " << int(a + i) << endl;
	}
	
}
