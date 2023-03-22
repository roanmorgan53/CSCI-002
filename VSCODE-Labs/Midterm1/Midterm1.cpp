//Roan Morgan
//CSCI Midterm Lab
//3.20.23
#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

class Shape {
public:
    virtual void print() = 0;

};
class Point : public Shape {
private:
    int x, y;
public:
    Point(int a, int b) {
        x = a;
        y = b;
    }
    virtual void print() {
        cout << "\nPoint: ";
        cout << "(" << x << "," << y << ")";
    }
    ~Point() {
        cout << "Point Destroyed!" << endl;
    }
};
class Circle : public Point {
private:
    int r;
public:
    Circle(int a, int b, int c) : Point(a, b) {
        r = c;
    }
    virtual void print() {
        cout << "\nCircle: ";
        cout << "center: ";
        Point::print();
        cout << " radius r = " << r;
    }
};
class Cylinder : public Circle {
private:
    int h;
public:
    Cylinder(int a, int b, int c, int d) : Circle(a, b, c) {
        h = d;
    }
    virtual void print() {
        cout << "\nCylinder:";
        Circle::print();
        cout << " height h = " << h;
    }
};

int main(void) {
    srand(time(0));
	
	//project description
	cout << "CSCI 2 Midterm Lab: Polymorphism Demonstration\n" << endl;

    vector<Shape*> myShapes;

    //push back 4 points
    for (int i = 0; i < 4; i++) {
        myShapes.push_back(new Point(int(rand() % 10), int(rand() % 10)));
    }

    //push back 3 circles
    for (int i = 0; i < 3; i++) {
        myShapes.push_back(new Circle(int(rand() % 20), int(rand() % 20), int(rand() % 20)));
    }

    //push back 3 cylinders
    for (int i = 0; i < 3; i++) {
        myShapes.push_back(new Cylinder(int(rand() % 5), int(rand() % 5), int(rand() % 5), int(rand() % 5)));
    }

    //display | POLYMORPHISM
    for (int i = 0; i < myShapes.size(); i++) {
        myShapes[i]->print();
    }

    cout << endl;

    //deallocate
    while (!myShapes.empty()) {
        delete myShapes.back(); //deallocate memory
        myShapes.pop_back(); // pop address off vector
        //cout << "destroyed" << endl; 
    }
    

	return(0);
}