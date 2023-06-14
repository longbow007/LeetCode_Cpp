//
//  SortAnArray.cpp
//  Algorithm-Cpp
//
//  Created by Xiaojian Duan on 2023/6/13.
//

#include "SortAnArray.hpp"
#include <vector>

using namespace std;

class Solution {
public:
    // merge sort 归并排序
    // vector<int> sortArray(vector<int>& nums) {
    //     int n = nums.size();
    //     int low = 0, high = n - 1;
    //     auto tempNums = vector<int>(n);
    //     mergeSort(nums, low, high, tempNums);
    //     return nums;
    // }

    // void mergeSort(vector<int>& nums, int low, int high, vector<int>& tempNums) {
    //     if (low == high) {
    //         return;
    //     }
    //     int mid = low + (high - low) / 2;
    //     mergeSort(nums, low, mid, tempNums);
    //     mergeSort(nums, mid + 1, high, tempNums);
    //     merge(nums, low, mid, high, tempNums);
    // }

    // void merge(vector<int>& arr, int low, int mid, int high, vector<int>& tempNums) {
    //     for (int k = low; k <= high; k++) {
    //         tempNums[k] = arr[k];
    //     }
    //     int i = low, j = mid + 1;
    //     for (int k = low; k <= high; k++) {
    //         if (i > mid) {
    //             // 左半边已排好序
    //             arr[k] = tempNums[j++];
    //         } else if (j > high) {
    //             arr[k] = tempNums[i++];
    //         } else if (tempNums[i] < tempNums[j]) {
    //             arr[k] = tempNums[i++];
    //         } else {
    //             arr[k] = tempNums[j++];
    //         }
    //     }
    // }

    // quick sort 快排
    vector<int> sortArray(vector<int>& nums) {
        int low = 0, high = nums.size() - 1;
        quickSort(nums, low, high);
        return nums;
    }

    void quickSort(vector<int>& nums, int low, int high) {
        if (low >= high) {
            return;
        }
        int randIndex = low + rand() % (high - low + 1);
        swap(nums[low], nums[randIndex]);
        int pivot = nums[low];
        // left right 是值相同的一串数字的边界，即：
        // 小于 pivot 的区间是 [low, left - 1]
        // 等于 pivot 的区间是 [left, right]
        // 大于 pivot 的区间是 [right + 1, high]
        int left = low, right = high;
        for (int i = low + 1; i <= high; i++) {
            if (left >= right) {
                return;
            }
            if (nums[i] < pivot) {
                left++;
                swap(nums[left], nums[i]);
            } else if (nums[i] == pivot) {
                left++;
            } else {
                swap(nums[i], nums[right]);
                right--;
            }
        }
        swap(nums[low], nums[left]);
        quickSort(nums, low, left - 1);
        quickSort(nums, right + 1, high);
    }

    // int partition(vector<int>& nums, int low, int high) {
    //     int randIndex = low + rand() % (high - low + 1);
    //     int p = nums[randIndex];
    //     swap(nums[low], nums[randIndex]);
    //     int i = low;
    //     for (int j = low + 1; j <= high; j++) {
    //         if (nums[j] < p) {
    //             i++;
    //             swap(nums[i], nums[j]);
    //         }
    //     }
    //     swap(nums[low], nums[i]);
    //     return i;
    // }
};
