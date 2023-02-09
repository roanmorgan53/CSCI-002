// Roan Morgan
// 2.8.23
// Lab 2b: Binary Search a String
#include <iostream>
#include <cstdlib>
using namespace std;

int binarySearch(string wordlist[], int first, int last, string target);

int main(void)
{
    string wordlist[5] = {"Apple", "Banana", "Cat", "Dog", "Elephant"};

        cout << wordlist[binarySearch(wordlist, 0, 4, "Dog")] << endl;

    return(0);
}

int binarySearch(string wordlist[], int first, int last, string target)
{

    int index;
    if (first > last)
        index = -1;
    else
    {
        int mid = first + (last - first) / 2;
        if (target == wordlist[mid])
            index = mid;
        else if (target < wordlist[mid])
            index = binarySearch(wordlist, first, mid - 1, target);
        else
            index = binarySearch(wordlist, mid + 1, last, target);
    }

    return(index);
}