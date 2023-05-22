//Roan Morgan
//Math App: Parallel, Perpendicular or Neither 
//5.21.23
#include <iostream>
#include <string>
using namespace std;

class Line {
private:
	//private variables
	int a;
	int b;
	int c;
	string line;

public:

	//constructor
    Line();
	Line(string);
	
	//get & set methods
	void setline(string _line);
	
	string getLine(void);
	int getA(void);
	int getB(void);
	int getC(void);

	//methods
	void despace(void);
	void assign(void);

};

string calculate(Line line1, Line line2);

int main(void) {

	cout << "Math App: Parallel, Perpendicular or Neither\n";
    cout << "(enter twice to exit)\n\n";


    string temp = "n/a";

    Line userLine1;
    Line userLine2;

    while (temp != "") {

        cout << "Enter Two Lines: " << endl;
        cout << "User: ";
        getline(cin, temp);
        userLine1.setline(temp);

        cout << "User: ";
        getline(cin, temp);
        userLine2.setline(temp);

        userLine1.despace();
        userLine1.assign();

        userLine2.despace();
        userLine2.assign();

        if (temp != "") {

            cout << "App: ";
            cout << "Lines are " << calculate(userLine1, userLine2) << endl << endl;
        }
    }

	return 0;
}

Line::Line()
{
    a = -1;
    b = -1;
    c = -1;
    line = "";
}

Line::Line(string _line) {
	setline(_line);
	despace();
	assign();
}

void Line::setline(string _line)
{
	line = _line;
}

string Line::getLine(void)
{
	return line;
}

int Line::getA(void)
{
	return a;
}

int Line::getB(void)
{
	return b;
}

int Line::getC(void)
{
	return c;
}

void Line::despace() {
	// Remove spaces from the line string
	line.erase(remove(line.begin(), line.end(), ' '), line.end());
}

void Line::assign(void) {
    string temp = "";

    // separate the numbers into groups inside a string
    for (int i = 0; i < line.size(); i++) {
        if (line[i] == '-') {
            temp += line[i];
        }

        if (line[i] >= '0' && line[i] <= '9') {
            temp += line[i];
        }
        else if (line[i] == 'x' || line[i] == 'y') {
            temp += ' ';
        }
    }

    // process the updated string and assign a, b, and c values
    string tempGroup = "";
    int j = 0;
    for (int i = 0; i < temp.size(); i++) {
        if (temp[i] != ' ') {
            tempGroup += temp[i];
        }
        else {
            int num;
            if (tempGroup == "") {
                num = 1;
            }
            else if (tempGroup == "-") {
                num = -1;
            }
            else {
                num = stoi(tempGroup);
            }

            if (j == 0) {
                a = num;
            }
            else if (j == 1) {
                b = num;
            }
            j++;
            tempGroup = "";
        }
    }

    // Assign the last number to c
    if (!tempGroup.empty()) {
        int num = stoi(tempGroup);
        c = num;
    }
}

string calculate(Line line1, Line line2) {
    string ans;
    double slope1 = -1.0*(line1.getA()) / line1.getB();
    double slope2 = -1.0*(line2.getA()) / line2.getB();

    if (slope1 * slope2 == -1) {
        ans = "perpendicular";
    }
    else if(slope1 == slope2){
        ans = "parallel";
    }
    else {
        ans = "neither perpendicular nor parallel";
    }

    return ans;
}