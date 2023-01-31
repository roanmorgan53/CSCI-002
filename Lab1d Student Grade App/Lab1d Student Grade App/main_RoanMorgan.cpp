//Roan Morgan
//Lab 1d Student Grade App
//1.25.23
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

template<class T>
struct Student {
	string name;
	int ID;
	T testAvg, hwAvg, finalAvg;
	float testWeight, hwWeight, finalWeight;

	void display(void);
	double calculateWeightedAverage(void);
	char getGrade(void);
};

int main(void) {

	char runAgain = 'y';

	Student<double> preston;

	do {
		system("cls");

		cout << "Lab 1d: Student Grade App\n" << endl;

		cout << "Input Name: ";
		getline(cin, preston.name);

		cout << "Input ID#: ";
		cin >> preston.ID;

		cout << "Input Test Average: ";
		cin >> preston.testAvg;

		cout << "Input Homework Average: ";
		cin >> preston.hwAvg;

		cout << "Input Final Average: ";
		cin >> preston.finalAvg;

		do {
			cout << "Input test weight (decimal form): ";
			cin >> preston.testWeight;

			cout << "Input Homework Weight (decimal form): ";
			cin >> preston.hwWeight;

			cout << "Input Final Weight (decimal form): ";
			cin >> preston.finalWeight;

			if (preston.testWeight + preston.hwWeight + preston.finalWeight != 1) {
				cout << "Weights must = 100%, Try Again!" << endl;
			}
		} while (preston.testWeight + preston.hwWeight + preston.finalWeight != 1);

		system("cls");

		cout << "Lab 1d: Student Grade App\n" << endl;

		preston.display();

		cout << endl;

		cout << "Would you like to run again (y/n): ";
		cin >> runAgain;

		cin.ignore();

	} while (runAgain == 'y');

	



	return(0);
}

template<class T>
void Student<T>::display(void)
{
	cout << name << endl;
	cout << "ID: " << ID << endl;
	cout << "Test Average: " << testAvg << endl;
	cout << "Homework Average: " << hwAvg << endl;
	cout << "Final Average: " << finalAvg << endl;
	cout << "Test Weight: " << testWeight*100 << "%" << endl;
	cout << "Homework Weight: " << hwWeight*100 << "%"  << endl;
	cout << "Final Weight: " << finalWeight*100 << "%" << endl;
	cout << "Weighted Average: " << calculateWeightedAverage() << endl;
	cout << "Final Grade = " << getGrade() << endl;


}

template<class T>
double Student<T>::calculateWeightedAverage(void)
{
	double weightedAverage = hwWeight * hwAvg + testWeight * testAvg + finalWeight * finalAvg;

	return weightedAverage;
}

template<class T>
char Student<T>::getGrade(void)
{
	if (calculateWeightedAverage() >= 90) {
		return 'A';
	}
	else if(calculateWeightedAverage() >= 80) {
		return 'B';
	}
	else if (calculateWeightedAverage() >= 70) {
		return 'C';;
	}
	else if (calculateWeightedAverage() >= 60) {
		return 'D';
	}
	else if (calculateWeightedAverage() < 60) {
		return 'F';
	}

	return 0;
}
