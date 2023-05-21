//Roan Morgan
//Lab 7a: String Hash Function
//4.26.23
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int magicBox(string userName, int buckets);

int main(void) {
	string userin;
	char runagain = 'y';
	int numBuckets;

	while (runagain == 'y') {
		system("CLS");

		//project description
		cout << "Lab 7a: String Hash Function" << endl << endl;

		cout << "Enter a name: ";
		getline(cin, userin);

		cout << "Enter the number of buckets: ";
		cin >> numBuckets;

		cout << userin << " will be at bucket " << magicBox(userin, numBuckets);

		cout << "\nRun Again? (y/n): ";
		cin >> runagain;
		cin.ignore();
	}

	return(0);
}

int magicBox(string userName, int buckets)
{
	int asciiSum = 0;

	for (int i = 0; i < userName.size(); i++) {
		userName[i] = tolower(userName[i]);
		asciiSum += userName[i];
	}

	return asciiSum % buckets;
}
