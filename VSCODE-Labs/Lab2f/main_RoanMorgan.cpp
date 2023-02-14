//Roan Morgan
//2.13.22
//Lab 2f: Array Merge Function
#include <iostream>
using namespace std;

template <typename T>
void mergeArrays(T* arr, T* arr2, const int size, const int size2);

template <typename T>
void printArray(T* arr, const int size);

int main(void){

    const int size = 5;
    const int size2 = 10;
    int numberList[size] = {1, 2, 3, 4, 5};
    int numberList2[size2] = {6,7,8,9,10,11,12,13,14,15};

    mergeArrays(numberList, numberList2, size, size2);

    return(0);
}

template <typename T>
void mergeArrays(T* arr, T* arr2, const int size, const int size2){
    
    T mergedArray[size+size2];

    for(int i = 0; i < size; i++){
        mergedArray[i] = arr[i];
    }

    int acc = 0;
    for(int i = size; i < size + size2; i++){
        mergedArray[i] = arr2[acc];
        acc++;
    }

    printArray(mergedArray, size+size2);

}

template <typename T>
void printArray(T* arr, const int size){
    for(int i = 0; i < size; i++){
        cout << "a[" << i << "] = " << arr[i] << endl;
    }
};