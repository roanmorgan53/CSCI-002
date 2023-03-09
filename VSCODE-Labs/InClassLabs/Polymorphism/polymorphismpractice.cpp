// Notes on Polymorphism
// No accessor (set and get) methods for clarity.

#include <iostream>
#include <vector>
#include <string>
using namespace std;
double PI = 3.1415926;

// Abstract Base Class **************************
class Shape {
public:
 Shape(string = "");

 // pure virtual methods
 virtual double calculateArea(void) = 0;
 virtual double calculatePerimeter(void) = 0;

 // virtual methods
 virtual double calculateVolume(void);

private:
 string color;
};

// Concrete Classes ********************************
class Rectangle : public Shape {
public:
 Rectangle(string, double = 0.0, double = 0.0);

 virtual double calculateArea(void);
 virtual double calculatePerimeter(void);
private:
 double length, width;
};

class Triangle : public Shape {
public:
 Triangle(string, double = 0.0, double = 0.0, double = 0.0);

 virtual double calculateArea(void);
 virtual double calculatePerimeter(void);
private:
 double a, b, c;
};

class Circle : public Shape {
public:
 Circle(string, double = 0.0);

 virtual double calculateArea(void);
 virtual double calculatePerimeter(void);
private:
 double r;
};

class Cylinder : public Circle {
public:
 Cylinder(string, double = 0.0, double = 0.0);

 virtual double calculateVolume(void);
private:
 double h;
};


int main() {

 cout << "Part 1:"  << endl;
 // Vector of base class pointers (To enable polymorphism)
 vector<Shape*> myShapeList;

 myShapeList.push_back(new Rectangle("Red", 3, 4));
 myShapeList.push_back(new Triangle("Green", 3, 4, 5));
 myShapeList.push_back(new Triangle("Blue", 6, 8, 10));
 myShapeList.push_back(new Circle("Yellow", 2));
 myShapeList.push_back(new Cylinder("Magenta", 3, 2));

 //Object identification (at run-time)
 for (int i = 0; i < myShapeList.size(); i++) {
 cout << "Object " << i << ": " << typeid( myShapeList[i] ).name() << endl;
 cout << "Object " << i << ": " << typeid( *myShapeList[i] ).name() << endl;
 }

 cout << "Part 2:" << endl;

 // polymorphism here
 cout << "Object 1: " << myShapeList.at(0)->calculatePerimeter() << endl;
 cout << "Object 2: " << myShapeList.at(1)->calculatePerimeter() << endl;
 cout << "Object 3: " << myShapeList.at(2)->calculatePerimeter() << endl;
 cout << "Object 4: " << myShapeList.at(3)->calculateVolume() << endl;
 cout << "Object 5: " << myShapeList.at(4)->calculateVolume() << endl;

 for (int i = 0; i < myShapeList.size(); i++) {
 // polymorphism here
 cout << "volume = " << myShapeList[i]->calculateVolume() << endl;
 }

 cout << "Part 3: " << endl;
 // memory management...
 while (!myShapeList.empty()) {

 cout << "Deleting " << typeid(*myShapeList.back()).name() << endl;

 delete myShapeList.back(); //deallocate memory
 myShapeList.pop_back(); // pop address off vector
 cout << "Num Shapes in vector: "<<myShapeList.size() << endl;

 }

 return (0);
}

//Base Class *********************************
Shape::Shape(string argColor) {
 color = argColor;
}
double Shape::calculateVolume(void) {
 return(0);
}

//2D Shapes *********************************
Rectangle::Rectangle(string argColor, double argL, double argW) :Shape(argColor) {
 length = argL;
 width = argW;
}
double Rectangle::calculateArea(void) {
 return(length*width);
}
double Rectangle::calculatePerimeter(void) {
 return(2 * length + 2 * width);
}


Triangle::Triangle(string argColor, double argA, double argB, double argC) : Shape(argColor) {
 a = argA;
 b = argB;
 c = argC;
}
double Triangle::calculateArea(void) {
 // todo look up trig formula
 return(5.0);
}
double Triangle::calculatePerimeter(void) {
 return(a + b + c);
}

Circle::Circle(string argColor, double argR) : Shape(argColor) {
 r = argR;
}
double Circle::calculateArea(void) {
 return(PI*r*r);
}
double Circle::calculatePerimeter(void) {
 return(2 * PI*r);
}

//3D Shapes *********************************

Cylinder::Cylinder(string argColor, double argR, double argH) :Circle(argColor, argR) {
 h = argH;
}
double Cylinder::calculateVolume(void) {
 return(Circle::calculateArea() * h);
}