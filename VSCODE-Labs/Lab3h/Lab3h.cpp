//Roan Morgan
//Lab 3h
//3.8.23
#include <iostream>
#include <cstdlib> 
using namespace std;

class Person {
    public:
        double height;
        int age;
        string name;

        Person(double height, int age, string name);

        virtual void display(void) = 0;
};

class Student : public Person{
    private: 
        string major;
    public:
        Student(double height, int age, string name, string argMajor);

        void display(void);
};

class Athlete : public Person{
    private:
        double sprintTime;
    public:
        Athlete(double height, int age, string name, double argTime);

        void display(void);
};

class Employee : public Person{
    private:
        int employeeID;
    public:
        Employee(double height, int age, string name, int employeeID);

        void display(void);
};

int main(void){

    Student* robert = new Student(5.5, 18, "Robert", "CSCI");
    Athlete* john = new Athlete(6.1, 22, "John", 12.2);
    Employee* earl = new Employee(5.6, 45, "Earl", 1912203);

    robert->display();
    cout << endl;
    john->display();
    cout << endl;
    earl->display();


    return 0;
}

Person::Person(double pHeight, int pAge, string pName){
    height = pHeight;
    age = pAge;
    name = pName;
}

void Person::display(void){
    cout << name << endl;
    cout << "Age: " << age << endl;
    cout << "Height: " << height << "ft" << endl;
}

void Student::display(void){
    cout << name << endl;
    cout << "Age: " << age << endl;
    cout << "Height: " << height << "ft" << endl;
    cout << "Major: " << major << endl;
}

void Athlete::display(void){
    cout << name << endl;
    cout << "Age: " << age << endl;
    cout << "Height: " << height << "ft" << endl;
    cout << "40yd Sprint Time: " << sprintTime << endl;
}

void Employee::display(void){
    cout << name << endl;
    cout << "Age: " << age << endl;
    cout << "Height: " << height << "ft" << endl;
    cout << "Employee ID: " << employeeID << endl;
}

Student::Student(double height, int age, string name, string argMajor) : Person(height, age, name){
    major = argMajor;
}

Athlete::Athlete(double height, int age, string name, double argTime) : Person(height, age, name){
    sprintTime = argTime;
};

Employee::Employee(double height, int age, string name, int argID) : Person(height, age, name){
    employeeID = argID;
};