//
//  ThreeSum.cpp
//  Algorithm-Cpp
//
//  Created by Xiaojian Duan on 2022/10/29.
//

#include "ThreeSum.hpp"
#include <vector>

using namespace std;

class ThreeSumSolution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        auto res = vector<vector<int>>();
        if (nums.size() < 3) return res;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > 0) break;
            if (i > 0 && nums[i] == nums[i-1]) continue;
            int j = i + 1, k = n - 1;
            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                if (sum == 0) {
                    auto v = vector<int>();
                    v.push_back(nums[i]);
                    v.push_back(nums[j]);
                    v.push_back(nums[k]);
                    res.push_back(v);
                    do {
                        k--;
                    } while (j < k && nums[k] == nums[k+1]);
                    do {
                        j++;
                    } while (j < k && nums[j] == nums[j-1]);
                } else if (sum > 0) {
                    k--;
                } else {
                    j++;
                }
            }
        }
        return res;
    }
};
