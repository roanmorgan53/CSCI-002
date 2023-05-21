//Roan Morgan
//Lab 7b: Hash Table of Strings 
//4.26.23
#include <iostream>
#include <iomanip>
#include <list>
#include <string>
using namespace std;

int stringHash(string userName, int buckets);

void simplePrintTable(list<string>[], int); //pass array and size

int main(void) {
	srand(time(0));
	const int tableSize = 3;
	string runagain = "y";
	string userin;
	int i = 0;
		
	// A c-type ARRAY of integer lists -- Want the indexing here.
	list<string> hashTable[tableSize];
	
	while (runagain != "n") {
		//clear the console
		system("CLS");

		//project description
		cout << "Lab 7b: Hash Table of Strings" << endl << endl;

		//get user data
		cout << "Enter a word: ";
		getline(cin, userin);

		//pushback the data into the hash table
		hashTable[stringHash(userin, tableSize)].push_back(userin);

		//sort it
		hashTable->sort();

		//print it out
		simplePrintTable(hashTable, tableSize);


		//run again
		cout << "Run Again? (y/n): ";
		getline(cin, runagain);
	}

	return(0);
}

//Implementations
void simplePrintTable(list<string> arg[], int size) {
	// Print the buckets...
	list<string>::iterator myItr;

	for (int i = 0; i < size; i++) {
		myItr = arg[i].begin();

		for (int j = 0; j < arg[i].size(); j++) {
			cout << *myItr << ", ";
			myItr++;
		}
	}
	cout << endl;
}

int stringHash(string userName, int buckets)
{
	int asciiSum = 0;

	for (int i = 0; i < userName.size(); i++) {
		userName[i] = tolower(userName[i]);
		asciiSum += userName[i];
	}

	return asciiSum % buckets;
}