//Roan Morgan
//Lab 1c: Function Templates 
//1.23.23
#include <iostream>
#include <iomanip>
using namespace std;

template <typename T>
T minElement(T arg1, T arg2);

template <typename T>
T maxElement(T arg1, T arg2);

int main(void) {
	
	//project description
	cout << "Lab 1c: Function Templates \n" << endl;

	int smallNum = 100;
	int bigNum = 200;
	char a = 'a';
	char b = 'b';
	double hugeNum = 10000;
	double hugerNum = 1000000;
	string smallSentence = "what's up";
	string bigSentence = "The quick brown fox jumped over the lazy dog";

	cout << "min of int: " << minElement(smallNum, bigNum) << endl;
	cout << "max of int: " << maxElement(smallNum, bigNum) << endl;
	cout << "min of char: " << minElement(a, b) << endl;
	cout << "max of char: " << maxElement(a, b) << endl;
	cout << "min of double: " << minElement(hugeNum, hugerNum) << endl;
	cout << "max of double: " << maxElement(hugeNum, hugerNum) << endl;
	cout << "min of string: " << minElement(smallSentence, bigSentence) << endl;
	cout << "max of string: " << maxElement(smallSentence, bigSentence) << endl;
	


	return(0);
}

template<typename T>
T minElement(T arg1, T arg2)
{	
	if (arg1 > arg2) {
		return arg2;
	}
	else{
		return arg1;
	}
}

template<typename T>
T maxElement(T arg1, T arg2)
{
	if (arg1 < arg2) {
		return arg2;
	}
	else{
		return arg1;
	}
}
