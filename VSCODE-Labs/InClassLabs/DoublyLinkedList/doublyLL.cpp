#include <iostream>
#include <string>
#include <list>
#include <iomanip>
using namespace std;

struct Circle{
    double r;
    string color;

    Circle(double argR, string argC){
        r = argR;
        color = argC;
    }

    ~Circle(){
        cout << "BOOM !!!" << endl;
    }
};

void print(list<Circle*>& arg){
    list<Circle*>::iterator cur = arg.begin();
    int i = 1;
    while(cur != arg.end()){
        cout << i << ") " << (*cur)->r << " with color " << (*cur)->color << endl;
        cur++;
        i++;
    }
    i = 0;
}

int main(void){
    srand(time(0));
    cout << fixed << setprecision(5);
    list<Circle*> clist;
    const int count = 10;
    string colors[] = {"blue", "green", "red", "black", "randbow"};

    for(int i = 0; i < count; i++){
        clist.push_back(new Circle(rand()%6 + 1.0*rand()/RAND_MAX, colors[rand()%5]));
    }

    cout << "List Size: " << clist.size() << endl;
    print(clist);

    //memory management
    list<Circle*>::iterator cur = clist.begin();
    while(clist.size() != 0){
        delete (*cur);
        cur++;
        clist.pop_front();
    };

    cout << "List Size: " << clist.size() << endl;

    return(0);
}