//Roan Morgan
//
//date
#include <iostream>
#include <cstdlib> 
#include <list>
#include <vector>
using namespace std;

void print(vector<int>&);
void bubbleSort(vector<int>&);

int main(void){
    srand(time(0));

    vector<int> a;

    for(int i = 0; i < 10; i++){
        a.push_back(rand() % 100 + 1);
    }

    print(a);

    return 0;
}

void print(vector<int>& arg){
    for(int i = 0; i < arg.size(); i++){
        cout << arg[i] << endl;
    }
}
