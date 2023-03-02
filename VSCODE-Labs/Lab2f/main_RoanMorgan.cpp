//Roan Morgan
//2.13.22
//Lab 2f: Array Merge Function
#include <iostream>
using namespace std;

template <typename T>
void mergeArrays(T* arr, T* arr2, T* arr3, const int size, const int size2);

template <typename T>
void printArray(T* arr, const int size);

int main(void) {

    //init variables & arrays
    const int size = 5;
    const int size2 = 10;
    const int size3 = size + size2;
    int numberList[size] = { 1, 2, 3, 4, 5 };
    int numberList2[size2] = { 6,7,8,9,10,11,12,13,14,15 };
    int mergedList[size3];

    //call the functions
    mergeArrays(numberList, numberList2, mergedList, size, size2);
    printArray(mergedList, size3);

    return(0);
}

template <typename T>
void mergeArrays(T* arr, T* arr2, T* arr3, const int size, const int size2) {

    //copy first array onto merged
    for (int i = 0; i < size; i++) {
        arr3[i] = arr[i];
    }

    //add second array to the next spot on merge
    for (int i = 0; i < size2; i++) {
        arr3[i + size] = arr2[i];
    }

}

template <typename T>
void printArray(T* arr, const int size) {
    for (int i = 0; i < size; i++) {
        cout << "a[" << i << "] = " << arr[i] << endl;
    }
};