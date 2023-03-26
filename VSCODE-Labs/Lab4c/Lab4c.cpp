//Roan Morgan
//Lab 4c: Stack Palindrome Check 
//3.26.23
#include <cstdlib>
#include <iostream>
#include <stack>
#include <vector>
#include <string>
using namespace std;

/*
Psuedocode:

Make a function called isPalindrome that 
takes in a stack and tests to see if
it reads the same forwards as backwards
then return a bool, true/false, depending
on the results
*/

bool isPalendrome(stack<char>);

int main(void) {
	
	//project description
	cout << "Lab 4c: Stack Palindrome Check" << endl;
	cout << "Enter to exit" << endl << endl;

	stack<char> letters;

	vector<string> wordList;
	string userIn = "blank";

	while (userIn != "") {
		cout << "Enter a word: ";
		getline(cin, userIn);

		if (userIn != "") {
			wordList.push_back(userIn);
		}
	}

	system("CLS");

	cout << "Lab 4c: Stack Palindrome Check" << endl << endl;

	for (int i = 0; i < wordList.size(); i++) {
		while (!letters.empty()) {
			letters.pop();
		}


		for (int j = 0; j < wordList[i].size(); j++) {
			wordList[i][j] = tolower(wordList[i][j]);
			letters.push(wordList[i][j]);
		}

		if (isPalendrome(letters)) {
			cout << wordList[i] << "\t| is a palendrome..." << endl;
		}
		else {
			cout << wordList[i] << "\t| is not a palendrome..." << endl;
		}
	}


	return(0);
}

bool isPalendrome(stack<char> chars) {
	stack<char> forward = chars;
	stack<char> backward;

	while (!chars.empty()) {
		backward.push(chars.top());
		chars.pop();
	}

	while (!forward.empty()) {
		if (backward.top() == forward.top()) {
			backward.pop();
			forward.pop();
		}
		else {
			return false;
		}
	}

	return true;
}
