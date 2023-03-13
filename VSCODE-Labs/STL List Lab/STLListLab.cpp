//Roan Morgan
//STL List Lab
//3.12.23
#include <iostream>
#include <list>
using namespace std;

class Employee {
private:
	int identification;
	string name;
public:
	Employee() {
		int identification = -1;
		string name = "earl...";
	}
	Employee(int id, string n) {
		identification = id;
		name = n;
	}

	//get
	int getID(void) {
		return identification;
	}
	string getName(void) {
		return name;
	}

	//set
	void setID(int id) {
		identification = id;
	}
	void setName(string n) {
		name = n;
	}
};

void print(list<Employee> workers) {
	list<Employee>::iterator cur = workers.begin();
	int count = 1;
	while (cur != workers.end()) {
		cout << count << ": " << "Name: " << cur->getName() << "\tID: " << cur->getID() << endl;
		count++;
		cur++;
	}
};

int main(void) {
	srand(time(0));

	list<Employee> workers;
	Employee temp;
	
	//make some random characteristics
	string names[] = { "bob", "rob", "joe", "jace", "jan", "jord", "john" };
	int idCount = 1000;

	for (int i = 0; i < 300; i++) {
		temp.setID(idCount + i);
		temp.setName(names[rand() % 7]);
		workers.push_back(temp);
	}

	print(workers);

	workers.clear();
	
	return 0;
}