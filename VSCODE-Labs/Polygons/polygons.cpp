//Roan Morgan
//5.15.23
//Polygons!!!
#include <iostream>
#include <iomanip>
#include <ctime>
#include <list>
#define _USE_MATH_DEFINES
#include <math.h>
using namespace std;

class Shape {
private:
string color;

public:
//constructor & destructor
Shape(string _color);
~Shape();

//get & sets
string getColor(void);
void setColor(string);

//methods
virtual void print() = 0;
virtual double area() = 0;
virtual double perimeter() = 0;
};

class Polygon : public Shape {
private:
double length = 3;
int sides = 3;
public:

//constructor & destructor
Polygon(double _length, int _sides, string _color);
~Polygon();

//get & sets
double getLength();
int getSides();
void setLength(double);
void setSides(int);

//methods
void print();
double area();
double perimeter();
};

int main(void) {
//seed rand
srand(time(0));

//project description
cout << "A Beautiful Polygon ADT\n" << endl;
list<Polygon*> polygons;
int size = 100;

//random colors!
string randcolor[4] = {
"blue", "purple", "white", "yellow"
};

//dynamically instantiate some polygons!
for (int i = 0; i < size; i++) {
try {
polygons.push_back(new Polygon(1.0 * (rand() % 100), rand() %
100, randcolor[rand() % 4]));
}
catch (exception err) {
cout << err.what() << endl;
}
}

list<Polygon*>::iterator cur = polygons.begin();
list<Polygon*>* prev;

//print it! & delete it!
for (cur; cur != polygons.end(); cur++) {
(*cur)->print();
delete *cur;
}

return(0);
}

Shape::Shape(string _color)
{
setColor(_color);
}
Shape::~Shape()
{
cout << "SHAPE DESTROYED" << endl << endl;
}
string Shape::getColor(void)
{
return color;
}
void Polygon::setLength(double _length){
if (_length > 0) {
length = _length;
}
else {
throw invalid_argument("Invalid Side Length");
}
}
void Polygon::setSides(int _sides)
{
if (_sides >= 3) {
sides = _sides;
}
else {
throw invalid_argument("Invalid Side Count");
}
}
void Polygon::print()
{
cout << "Length: " << getLength() << endl;
cout << "Sides: " << getSides() << endl;
cout << "Color: " << getColor() << endl;
cout << "Area: " << area() << endl;
cout << "Perimeter: " << perimeter() << endl;
}
double Polygon::area()
{
double apothem = length / (2 * tan(M_PI / sides));
return (0.5)*(apothem*perimeter());
}
double Polygon::perimeter()
{
return length*sides;
}
void Shape::setColor(string _color)
{
color = _color;
}
Polygon::Polygon(double _length, int _sides, string _color) : Shape(_color)
{
setLength(_length);
setSides(_sides);
}
Polygon::~Polygon()
{
cout << "POLYGON DESTROYED!" << endl;
}
double Polygon::getLength()
{
return length;
}
int Polygon::getSides()
{
return sides;
}