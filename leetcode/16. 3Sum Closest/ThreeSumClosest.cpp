//
//  ThreeSumClosest.cpp
//  Algorithm-Cpp
//
//  Created by Xiaojian Duan on 2022/10/30.
//

#include "ThreeSumClosest.hpp"
#include <vector>

using namespace std;

class ThreeSumClosestSolution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int minDiff = 0;
        bool flag = false; // 是否给 minDiff 赋过值
        int res = 0;
        for (int i = 0; i < n; i++) {
            int j = i + 1, k = n - 1;
            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                if (sum == target) {
                    return sum;
                }
                int diff = abs(sum - target);
                if (diff < minDiff || !flag) {
                    minDiff = diff;
                    res = sum;
                    flag = true;
                }
                if (sum > target) {
                    k--;
                } else {
                    j++;
                }
            }
        }
        return res;
    }
};
