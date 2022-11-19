//
//  RemoveElement.cpp
//  Algorithm-Cpp
//
//  Created by Xiaojian Duan on 2022/11/5.
//

#include "RemoveElement.hpp"
#include <vector>

using namespace std;

class RemoveElementSolution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n = nums.size();
        // 通用解法
        // int l = 0;
        // for (int r = 0; r < n; r++) {
        //     if (nums[r] != val) {
        //         nums[l] = nums[r];
        //         l++;
        //     }
        // }
        // return l;
        
        // 快慢指针
        int slow = 0, fast = 0;
        while (fast < n) {
            if (nums[fast] != val) {
                nums[slow] = nums[fast];
                slow++;
            }
            fast++;
        }
        return slow;
    }

    /*
    int removeElement(vector<int>& nums, int val) {
    // 更巧妙解法
        int l = 0, r = n - 1;
        // for (; l <= r; l++) {
        //     if (nums[l] == val) {
        //         // 这里 l-- 是关键：相当于下次进入循环，继续判断这个位置是否等于 val, 防止交换过来的是等于val 的值，但 l 已经指向后面元素的情况出现
        //         swap(nums[l--], nums[r--]);
        //     }
        // }
        // 上面解法相当于：
        for (; l <= r; l++) {
            if (nums[l] == val) {
                while (r >= 0 && nums[r] == val) {
                    r--;
                }
                if (l < r) {
                    swap(nums[l], nums[r]);
                    r--;  // 交换后 nums[r] == val, 所以 r-1
                }
            }
        }
        return r + 1;
    }
    */
};
