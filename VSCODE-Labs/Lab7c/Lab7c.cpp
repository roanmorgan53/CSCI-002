//Roan Morgan
//Lab 7c: Hash Table of Objects 
//5.1.23
#include <iostream>
#include <list>
#include <ctime>
#include <string>
using namespace std;

class Person {
private:
	string name;

public:

	//constructors
	Person();
	Person(string);

	//get & set methods
	string getname(void);

	void setname(string);
	
};

class Student : public Person {
private:
	string major;
	int id;

public:
	//constructors
	Student();
	Student(string, string, int);
	
	//get & sets
	string getmajor(void);
	int getid(void);

	void setmajor(string);
	void setid(int);
};

int studentHash(Student*, int);

Student* searchTable(list<Student*> table[], string, const int);

int main(void) {
	//seed random
	srand(time(0));

	//make some arrays with random contents
	string randname[11] = {
		"Jack", "John", "Joe", "Preston", "Andrew", "Brian", "Mia", "Luis", "Lal", "Marc", "JJ"
	};

	string randmajor[5] = {
		"Computer Science", "Computer Engineering", "Turf Grass Science", "Petroleum Engineering", "Economics"
	};

	//make the hash table
	const int buckets = 5;
	list<Student*> studentTable[buckets]; 
	Student* tempStudent;
	string tempname;
	string tempmajor;
	int tempid;

	int runs = 100;

	for (int i = 0; i < runs; i++) {
		tempname = randname[rand() % 11];
		tempmajor = randmajor[rand() % 5];
		tempid = 10000 + i;
		tempStudent = new Student(tempname, tempmajor, tempid);
		studentTable[studentHash(tempStudent, buckets)].push_back(tempStudent);
	}

	//init search variables
	string searchName = "";
	Student* foundStudent;
	char userin = 'y';

	while (userin == 'y') {
		//clear the console
		system("CLS");

		//project description
		cout << "Lab 7c: Hash Table of Objects\n\n";

		cout << "Search Student Database" << endl;
		cout << "Enter a name: ";
		getline(cin, searchName);

		foundStudent = searchTable(studentTable, searchName, buckets);

		if (foundStudent == nullptr) {
			cout << endl;
			cout << searchName << " could not be found in the table!\n";
		}
		else {
			cout << endl;
			cout << searchName << " was found!\n";
			cout << "Major: " << foundStudent->getmajor() << endl;
			cout << "ID: " << foundStudent->getid() << endl;
		}

		cout << "Run Again? (y/n): ";
		cin >> userin;
		cin.ignore();
	}
	

	return 0;
}

Person::Person(){
	name = "N/A";
}

Person::Person(string _name){
	name = _name;
}

string Person::getname(void)
{
	return name;
}

Student::Student()
{
	major = "N/A";
	id = -1;
	setname("N/A");
}

Student::Student(string _name, string _major, int _id)
{
	setname(_name);
	major = _major;
	id = _id;
}

string Student::getmajor(void)
{
	return major;
}

int Student::getid(void)
{
	return id;
}

void Person::setname(string _name)
{
	name = _name;
}

void Student::setmajor(string _major)
{
	major = _major;
}

void Student::setid(int _id)
{
	id = _id;
}

int studentHash(Student* student, int buckets)
{
	string studentname = student->getname();
	int asciiSum = 0;

	for (int i = 0; i < studentname.size(); i++) {
		asciiSum += int(studentname[i]);
	}

	return asciiSum % buckets;
}

Student* searchTable(list<Student*> table[], string _name, const int buckets)
{	

	//init temporary variables
	
	Student* result;
	list<Student*>::iterator cur;
	string tempname;

	//lowercase the name inputted
	for (int i = 0; i < _name.size(); i++) {
		_name[i] = tolower(_name[i]);
	}

	//look through the list and search for a name that matches the given name
	for (int i = 0; i < buckets; i++) {
		for (cur = table[i].begin(); cur != table[i].end(); cur++) {

			//string management
			tempname = (*(*cur)).getname();

			for (int u = 0; u < tempname.size(); u++) {
				tempname[u] = tolower(tempname[u]);
			}

			if (tempname == _name) {
				//if the name is found, return the whole object
				return *cur;
			}
		}
	}

	//if nothing is found return null
	return nullptr;
}