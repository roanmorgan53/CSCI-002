#include <iostream>
#include <cstdlib>
using namespace std;

template <typename T>
void deleteElement(T* arr, int index, int size);

template <typename T>
void printArray(T* arr, int size);

int main(void){

    const int size = 5;
    char a[size] = {'a','b','c','d','e'};
    int deleteIndex = 3;

    deleteElement(a, deleteIndex, size);

    return(0);
}

template <typename T>
void deleteElement(T* arr, int index, const int size){
    for(int i = index; i<size; i++){
        if(i != size - 1)
            arr[i] = arr[i+1];
        else
            arr[i] = '\0';
    }
    printArray(arr, size);
}

template <typename T>
void printArray(T* arr, const int size){
    for(int i = 0; i < size; i++){
        cout << "a[" << i << "] = " << arr[i] << endl;
    }
};