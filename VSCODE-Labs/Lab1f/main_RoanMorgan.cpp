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
        UScitizen(string f, string l, int a, int ssn);
        void display();
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

UScitizen::UScitizen(string f = "", string l = "", int a = 0, int sn = 3){
    setfName(f);
    setlName(l);
    setAge(a);
    ssn = sn;
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