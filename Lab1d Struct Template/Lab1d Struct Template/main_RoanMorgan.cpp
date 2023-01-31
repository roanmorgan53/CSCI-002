//Roan Morgan
//Lab 1d: Struct Template 
//1.23.23
#include <iostream>
#include <iomanip>
using namespace std;

template<class T>
struct Person {
	string name;
	string gender;
	T age;

	void printDetails(void);
	bool isMinor(void);  //returns true if Person is a minor.
};

int main(void) {
	
	//project description
	cout << "Lab 1d: Struct Template " << endl;

	Person<int> Andrew;
	Andrew.age = 18;
	Andrew.name = "Andrew";
	Andrew.gender = "Male";

	Person<int> Brian;
	Brian.age = 25;
	Brian.name = "Brian";
	Brian.gender = "Male";

	Person<float> Preston;
	Preston.age = 18;
	Preston.name = "Preston";
	Preston.gender = "Male";

	Person<float> Ron;
	Ron.age = 10;
	Ron.name = "Ron";
	Ron.gender = "Male";

	cout << endl;

	Andrew.printDetails();
	if (Andrew.isMinor()) {
		cout << Andrew.name << " is a minor" << endl;
	}
	else {
		cout << Andrew.name << " is not a minor " << endl;
	}

	cout << endl;

	Brian.printDetails();
	if (Brian.isMinor()) {
		cout << Brian.name << " is a minor" << endl;
	}
	else {
		cout << Brian.name << " is not a minor " << endl;
	}

	cout << endl;

	Preston.printDetails();

	if (Preston.isMinor()) {
		cout << Preston.name << " is a minor" << endl;
	}
	else {
		cout << Preston.name << " is not a minor" << endl;
	}

	cout << endl;

	Ron.printDetails();

	if (Ron.isMinor()) {
		cout << Ron.name << " is a minor" << endl;
	}
	else {
		cout << Ron.name << " is not a minor" << endl;
	}

	cout << endl;
	
	return(0);
}

template<typename T>
void Person<T>::printDetails(void)
{
	cout << name << endl;
	cout << gender << endl;
	cout << age << " years old" << endl;
}

template<typename T>
bool Person<T>::isMinor(void)
{
	if (age >=  T(18))
		return false;
	else
		return true;
}
