//Roan Morgan
//Lab 5c: Average Number of Comparisons 
//4.12.23
#include <iostream>
#include <vector>
using namespace std;

void bubbleSort(vector<int>&);
void print(vector<int>&);
int linearSearch(vector<int>&, int&, int&);
int binarySearch(vector<int>&, int&, int&);

int main(void) {
    srand(time(0));

    //init variables
    int size = 100;
    int runs = 500000;
    vector<int> nums;
    int countLin = 0;
    int countBi = 0;
    int countBubble = 0;
    int randnum;

    //init nums
    for (int i = 0; i < size; i++) {
        nums.push_back(rand() % 1001);
    }

    bubbleSort(nums);

    //run the loop runs amount of time
    for (int i = 0; i < runs; i++) {

        randnum = rand() % 1001;

        //init searches
        binarySearch(nums, randnum, countBi);
        linearSearch(nums, randnum, countLin);

    }

    cout << "Average Linear Comparisons: " << countLin/runs << endl;
    cout << "Average Binear Comparisons: " << countBi/runs << endl;




    return 0;
}

void bubbleSort(vector<int>& nums) {
    int n = nums.size();

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (nums[j] > nums[j + 1]) {
                swap(nums[j], nums[j + 1]);
            }
        }
    }
}

void print(vector<int>& nums) {

    cout << "Number List:\n\n";

    for (int i = 0; i < nums.size(); i++) {
        if (i % 9 == 0 && i != 0) {
            cout << "\t" << nums[i];
            cout << endl;
        }
        cout << "\t" << nums[i] << ", ";
    }
    cout << endl;
}

int linearSearch(vector<int>& nums, int& target, int& count) {
    for (int i = 0; i < nums.size(); i++) {
        count++;
        if (nums[i] == target) {
            count++;
            return nums[i];
        }
        count++;
    }
    count++;

    return -1;
}

int binarySearch(vector<int>& nums, int& target, int& count)
{
    int left = 0;
    int right = nums.size() - 1;

    while (left <= right) {
        count += 2;
        int mid = left + (right - left) / 2;

        if (nums[mid] == target) {
            return mid;
        }
        else if (nums[mid] < target) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
        count++;
    }
    count++;

    return -1;
}
