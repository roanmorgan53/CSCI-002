//Roan Morgan
//Lab 8a: File I/O 
//5.3.23
#include <iostream>
#include <list>
#include <ctime>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

//init objects
class Person {
private:
	string name;
	string gender;
	int age;

public:

	//constructors
	Person();
	Person(string, string, int);

	//get & set methods
	string getname(void);
	string getgender(void);
	int getage(void);

	void setname(string);
	void setgender(string);
	void setage(int);

};

bool compareAge(Person*, Person*);

int main(void) {
	//seed random
	srand(time(0));

	//make some arrays with random contents
	string randname[11] = {
		"Jack", "John", "Joe", "Preston", "Andrew", "Brian", "Mia", "Luis", "Lal", "Marc", "JJ"
	};

	string randgender[2] = {
		"Male", "Female"
	};

	//make the hash table
	list<Person*> people;
	Person tempPerson;
	string tempname;
	int tempage;
	string tempgender;

	int runs = 10;

	for (int i = 0; i < runs; i++) {
		tempname = randname[rand() % 11];
		tempgender = randgender[rand() % 2];
		tempage = rand() % 100 + 10;
		people.push_back(new Person(tempname, tempgender, tempage));
	}

	//sort the list
	people.sort(compareAge);

	ofstream peopleData;
	peopleData.open("peopleData.csv");
	Person* tempptr;
	
	list<Person*>::iterator cur = people.begin();
	
	//populate the file
	while (cur != people.end()) {
		tempptr = *cur;
		peopleData << tempptr->getname() << ", ";
		peopleData << tempptr->getgender() << ", ";
		peopleData << tempptr->getage() << "\n";
		cur++;
	}

	//make an input stream
	ifstream peopleDataRead;
	peopleDataRead.open("peopleData.csv");
	vector<string> inputPeopleData;
	string tempstring;

	while (!peopleDataRead.eof()) {
		peopleDataRead >> tempstring;
		inputPeopleData.push_back(tempstring);
	}

	for (int i = 0; i < inputPeopleData.size(); i++) {
		cout << inputPeopleData[i] << endl;
	}


	return 0;
}

Person::Person() {
	name = "N/A";
}

Person::Person(string _name, string _gender, int _age) {
	name = _name;
	gender = _gender;
	age = _age;

}

string Person::getname(void)
{
	return name;
}

string Person::getgender(void)
{
	return gender;
}

int Person::getage(void)
{
	return age;
}

void Person::setname(string _name)
{
	name = _name;
}

void Person::setgender(string _gender)
{
	gender = _gender;
}

void Person::setage(int _age)
{
	age = _age;
}

bool compareAge(Person* person1, Person* person2) {
	bool ans = (person1->getage() < person2->getage());
	return ans;
}