//Roan Morgan
//Loan Amortization Schedule 
//5.10.23
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

class Data {
private:
	double principle;
	double interest;
	double balance;
	double payment;
	int month;
public:
	Data(double _principle, double _interest, double _balance, double _payment, int _month) {
		principle = _principle;
		interest = _interest;
		balance = _balance;
		payment = _payment;
		month = _month;
	}

	double getprinciple(void) {
		return principle;
	}

	double getinterest(void) {
		return interest;
	}

	double getbalance(void) {
		return balance;
	}

	double getpayment(void) {
		return payment;
	}

	int getmonth(void) {
		return month;
	}
};

class Loan {
private:
	double amount;
	double apr;
	double principle;
	double interest;
	double balance;
	double payment;
	int term;
	vector<Data> schedule;
public:
	//constructor
	Loan(double _amount, double _apr, int _term);

	//get and sets
	double getamount(void);
	double getapr(void);
	double getprinciple(void);
	double getinterest(void);
	double getbalance(void);
	double getpayment(void);
	int getterm(void);

	void setamount(double _amount);
	void setprinciple(double _principle);
	void setinterest(double _interest);
	void setterm(int _terms);

	void calculate(void);
	void print(void);
};

int main(void) {
	cout << fixed << setprecision(2);
	
	//project description
	cout << "Loan Amortization Schedule\n" << endl;

	double userAmount;
	double userAPR;
	int userTerm;

	cout << "Enter an amount: ";
	cin >> userAmount;

	cout << "Enter an APR: ";
	cin >> userAPR;

	cout << "Enter the term (years): ";
	cin >> userTerm;
	cin.ignore();

	system("CLS");
	

	Loan car(userAmount, userAPR, userTerm);
	car.print();



	return(0);
}

Loan::Loan(double _amount, double _apr, int _term)
{

	amount = _amount;
	apr = _apr/100;
	term = _term;
	balance = amount;

	calculate();
}

double Loan::getamount(void) {
	return amount;
}

double Loan::getapr(void) {
	return apr;
}

double Loan::getprinciple(void) {
	return principle;
}

double Loan::getinterest(void) {
	return interest;
}

double Loan::getbalance(void) {
	return balance;
}

int Loan::getterm(void) {
	return term;
}

double Loan::getpayment(void) {
	return payment;
}

void Loan::setamount(double _amount)
{
	amount = _amount;
}

void Loan::setprinciple(double _principle) {
	principle = _principle;
}

void Loan::setinterest(double _interest) {
	interest = _interest;
}

void Loan::setterm(int _terms) {
	term = _terms;
}

void Loan::calculate(void){
	for (int i = 0; i < term * 12; i++) {
		payment = ((apr / 12) * amount) / (1 - pow((1 + (apr / 12)), -(term * 12)));
		interest = balance * apr / 12;
		principle = payment - interest;
		balance -= principle;

		schedule.push_back(Data(principle, interest, balance, payment, i+1));
	}
}

void Loan::print(void){

	ofstream file;
	file.open("loanSchedule.csv");

	file << "Month, Payment, Principle, Interest, Balance\n";

	for (int i = 0; i < schedule.size(); i++) {
		file << schedule[i].getmonth() << ",";
		file << schedule[i].getpayment() << ",";
		file << schedule[i].getprinciple() << ",";
		file << schedule[i].getinterest() << ",";
		file << schedule[i].getbalance() << "\n";
	}

	file.close();

	//take in input from the file
	ifstream ifile;
	vector<string> fileContents;
	string tempstring = "";

	ifile.open("loanSchedule.csv");

	while (!ifile.eof()) {
		getline(ifile, tempstring);
		fileContents.push_back(tempstring);
	}

	bool hasComma = true;

	for (int i = 0; i < fileContents.size(); i++) {
		for (int j = 0; j < fileContents[i].size(); j++) {
			if (fileContents[i][j] == ',') {
				hasComma = true;
			}
			else {
				hasComma = false;
			}
		}
		
		if (hasComma) {
			cout << fileContents[i];
		}
		else {
			cout << fileContents[i] << "\n";
		}
		hasComma = false;
	}


}








