//
//  RemoveDuplicatesFromSortedArray.cpp
//  Algorithm-Cpp
//
//  Created by Xiaojian Duan on 2022/11/5.
//

#include "RemoveDuplicatesFromSortedArray.hpp"
#include <vector>

using namespace std;

class RemoveDuplicatesFromSortedArraySolution {
public:
    int removeDuplicates(vector<int>& nums) {
        int slow = 0, fast = 0;
        while (fast < nums.size()) {
            if (nums[slow] != nums[fast]) {
                slow++;
                nums[slow] = nums[fast];
            }
            fast++;
        }
        return slow + 1;
    }
};
