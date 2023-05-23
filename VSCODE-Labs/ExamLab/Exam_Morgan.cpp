//Roan Morgan
//5.22.23
//Hash Table of Polygons
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

int hashSides(Polygon*);
bool compareColor(Polygon*, Polygon*);
void print(list<Polygon*> table[], const int);

int main(void) {
	//seed rand
	srand(time(0));

	//project description
	cout << "Hash Table of Polygons\n" << endl;

	//make the hash table
	const int buckets = 10;
	list<Polygon*> polygonTable[buckets];

	//make the polygons and push them back
	int numPolygons = 50;
	string colors[5] = { "Red", "Green", "Blue", "Yellow", "Orange" };
	for (int i = 0; i < numPolygons; i++) {
		Polygon* temp = new Polygon(5, (rand() % 10)+3, colors[rand() % 5]);
		polygonTable[hashSides(temp)].push_back(temp);
	}

	//sort buckets based on color
	for (int i = 0; i < buckets; i++) {
		polygonTable[i].sort(compareColor);
	}

	//print it
	print(polygonTable, buckets);
	
	//delete it
	for (int i = 0; i < buckets; i++) {
		list<Polygon*>::iterator cur = polygonTable[i].begin();
		for (cur; cur != polygonTable[i].end(); cur++) {
			delete *cur;
		}
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
void Polygon::setLength(double _length) {
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
	return (0.5) * (apothem * perimeter());
}
double Polygon::perimeter()
{
	return length * sides;
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

int hashSides(Polygon* shape) {
	int ans;
	ans = (shape->getSides() - 3) % 10;

	return ans;
}

bool compareColor(Polygon* shape1, Polygon* shape2) {
	bool ans = (shape1->getColor() < shape2->getColor());
	return ans;
}

void print(list<Polygon*> table[], const int numbuckets) {
	for (int i = 0; i < numbuckets; i++) {
		cout << "Bucket " << i+1 << ":" << endl;
		list<Polygon*>::iterator cur = table[i].begin();
		for (cur; cur != table[i].end(); cur++) {
			cout << "( Sides: " << (*(cur))->getSides();
			cout << ",\tLength: " << (*(cur))->getLength();
			cout << ",\tColor: " << (*(cur))->getColor() << " \t)" << endl;
		}
		cout << endl;
	}

}