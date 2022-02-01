//
//  merge_sorted_array.cpp
//  Algorithm-Cpp
//
//  Created by Xiaojian Duan on 2022/2/2.
//

#include "merge_sorted_array.hpp"
#include <vector>

using namespace std;

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int i = m - 1, j = n - 1, k = m + n - 1;
    int cur = 0;
    while (i >= 0 || j >= 0) {
        if (i < 0) {
            cur = nums2[j--];
        } else if (j < 0) {
            cur = nums1[i--];
        } else if (nums1[i] > nums2[j]) {
            cur = nums1[i--];
        } else {
            cur = nums2[j--];
        }
        nums1[k--] = cur;
    }
}
