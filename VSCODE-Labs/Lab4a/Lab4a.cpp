//Roan Morgan
//Lab 4a
//Stacks
#include <iostream>
#include <iomanip>
#include <stack>
#include <string>
using namespace std;

void print(stack<string*> &arg);

int main(void) {
	
	//project description
	cout << "Lab 4a: STACKS???" << endl;

	stack<string*> jenga;

	//init random strings
	string temp = "n/a";

	cout << "Enter to exit program\n" << endl;

	//user input
	while(temp != "") {
		cout << "Input a dog name: ";
		getline(cin, temp);

		if(temp != "")
			jenga.push(new string(temp));
	}

	cout << endl;
	
	print(jenga);

	cout << endl; 

	print(jenga);
	

	return(0);
}

void print(stack<string*> &arg) {

	if (arg.empty()) {
		cout << "Empty Stack" << endl;

	}

	while (!arg.empty()) {
		cout << *(arg.top()) << endl;
		arg.pop();
	}
}