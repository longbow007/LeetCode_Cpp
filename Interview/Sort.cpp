//
//  Sort.cpp
//  LeetcodeCpp
//
//  Created by XiaojianDuan on 2024/4/3.
//

#include "Sort.hpp"
#include "iostream"
#include <vector>

using namespace std;

void printArray(vector<int> nums) {
    if (nums.size() == 0) {
        cout<<"[]"<<endl;
        return;
    }
    cout<<"[";
    for (int i = 0; i < nums.size(); i++) {
        if (0 == i) {
            cout<<nums[i];
        } else {
            cout<<", "<<nums[i];
        }
    }
    cout<<"]"<<endl;
    return;
}

void bubbleSort(vector<int> &nums) {
    long n = nums.size();
    if (n <= 1) {
        return;
    }
    for (long i = n; i >= 0; i--) {
        for (long j = 0; j < i - 1; j++) {
            if (nums[j] > nums[j + 1]) {
                swap(nums[j], nums[j + 1]);
            }
        }
    }
}

void insertionSort(vector<int> &nums) {
    long n = nums.size();
    if (n <= 1) {
        return;
    }
    for (long i = 1; i < n; i++) {
        int x = nums[i];
        long j = i;
        for (; j > 0; j--) {
            if (nums[j - 1] > x) {
                nums[j] = nums[j - 1];
            } else {
                break;
            }
        }
        nums[j] = x;
    }
}

void selectionSort(vector<int> &nums) {
    long n = nums.size();
    if (n <= 1) {
        return;
    }
    for (long i = 0; i < n; i++) {
        int minX = nums[i];
        long minIndex = i;
        for (long j = i; j < n; j++) {
            if (nums[j] < minX) {
                minX = nums[j];
                minIndex = j;
            }
        }
        swap(nums[i], nums[minIndex]);
    }
}

void testSort() {
    vector<int> a = {3,1,2};
    bubbleSort(a);
    printArray(a);
    a = {3};
    insertionSort(a);
    printArray(a);
    a = {4,5,1,3,8,4,9};
    selectionSort(a);
    printArray(a);
}
