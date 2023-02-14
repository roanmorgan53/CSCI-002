#include <iostream>
#include <string>
using namespace std;

class Person{
    private:
        string fName;
        string lName;
        int age;
    public:
        string getfName(void);
        string getlName(void);
        int getAge(void);

        void setfName(string);
        void setlName(string);
        void setAge(int);

        Person(string _fName, string _lName, int _age);

    virtual void display();

};

class UScitizen : public Person{
    private:
        int ssn;
    public: 
        int getSSN(void);
        void setSSN(int);

        UScitizen(string f, string l, int a, int ssn);
        virtual void display();
};

class Employee : public UScitizen{
    private:
        int employeeID;
        double salary;
    public:
        Employee(string _fName, string _lName, int _age, int _ssn, int _employeeID, double _salary);
        void display();

        void setEmployeeID(int _employeeID);
        void setSalary(double _salary);

        int getEmployeeID(void);
        double getSalary(void);
};

int main(void){

    Person Bystander("Joe", "Joebey", 13);
    Person OtherBystander("jacob", "John", 89);

    Bystander.display();
    cout << endl;

    OtherBystander.display();
    cout << endl;

    UScitizen Guy("Abraham", "Lincoln", 200, 15);
    UScitizen Guy2("George", "Washington", 250, 1);
    UScitizen Guy3("Juilus", "Ceasar", 500, 25);

    Guy.display();
    cout << endl;

    Guy2.display();
    cout << endl;

    Guy3.display();
    cout << endl;

    Employee overworkedMan("Preston", "Kearnan", 18, 4041116, 10975029, 23000.43);
    Employee overworkedWoman("Jane", "Doe", 18, 1029494, 181411, 25000.43);

    overworkedMan.display();
    cout << endl;

    overworkedWoman.display();
    cout << endl;



    return(0);
}

Person::Person(string _fName = "", string _lName = "", int _age = 0){
    fName = _fName;
    lName = _lName;
    age = _age;   
}

void Person::setAge(int _age){
    age = _age;
}

void Person::setfName(string _fName){
    fName = _fName;
}

void Person::setlName(string _lName){
    lName = _lName;
}

int Person::getAge(void){
    return age;
}

string Person::getfName(void){
    return fName;
}

string Person::getlName(void){
    return lName;
}

UScitizen::UScitizen(string f = "", string l = "", int a = 0, int sn = 0){
    setfName(f);
    setlName(l);
    setAge(a);
    ssn = sn;
}

void UScitizen::setSSN(int _ssn){
    ssn = _ssn;
}

int UScitizen::getSSN(void){
    return ssn;
}

void Person::display(void){
    cout << fName << " " << lName << endl;
    cout << age << " years old" << endl;
}

void UScitizen::display(){
    cout << getfName() << " " << getlName() << endl;
    cout << getAge() << " years old" << endl;
    cout << "SSN: " << getSSN() << endl;
}

Employee::Employee(string _fName = "", string _lName = "", int _age = 0, int _ssn = 0, int _employeeID = 0, double _salary = 0.0){
    setfName(_fName);
    setlName(_lName);
    setAge(_age);
    setSSN(_ssn);
    employeeID = _employeeID;
    salary = _salary;
    }

void Employee::display(){
    cout << getfName() << " ";
    cout << getlName() << endl;
    cout << getAge() << " years old" << endl;
    cout << "SSN: " << getSSN() << endl;
    cout << "Employee ID: " << getEmployeeID() << endl;
    cout << "Salary: $" << getSalary() << endl;
}

int Employee::getEmployeeID(void){
    return employeeID;
}

double Employee::getSalary(void){
    return salary;
}