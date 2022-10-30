//
//  FourSum.cpp
//  Algorithm-Cpp
//
//  Created by Xiaojian Duan on 2022/10/30.
//

#include "FourSum.hpp"
#include <iostream>
#include <vector>

using namespace std;

class FourSumSolution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        auto ans = vector<vector<int>>();
        if (n < 4) {
            return ans;
        }
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n; i++) {
            if (i > 0 && nums[i] == nums[i-1]) {
                continue;
            }
            if (nums[i] > 0 && nums[i] > target) {
                break;
            }
            for (int j = i + 1; j < n; j++) {
                if (j > i + 1 && nums[j] == nums[j-1]) {
                    continue;
                }
                if (nums[j] > -nums[i] && nums[j] > target - nums[i]) {
                    break;
                }
                int l = j + 1, r = n - 1;
                while (l < r) {
                    long sum = nums[i] + nums[j];
                    if (nums[l] > -sum && nums[l] > target - sum) {
                        break;
                    }
                    sum += nums[l];
                    if (nums[r] > -sum && nums[r] > target - sum) {
                        r--;
                        continue;
                    }
                    sum += nums[r];
                    if (sum == target) {
                        vector<int> v;
                        v.push_back(nums[i]);
                        v.push_back(nums[j]);
                        v.push_back(nums[l]);
                        v.push_back(nums[r]);
                        ans.push_back(v);
                        do {
                            r--;
                        }
                        while (l < r && nums[r] == nums[r+1]);
                        do {
                            l++;
                        }
                        while (l < r && nums[l] == nums[l-1]);
                        continue;
                    }
                    if (sum > target) {
                        r--;
                    } else {
                        l++;
                    }
                }
            }
        }
        return ans;
    }
};

void testFourSum() {
    FourSumSolution solution;
    vector<int> v = {1000000000,1000000000,1000000000,1000000000};
    auto res = solution.fourSum(v, 0);
    for (auto arr : res) {
        for (int x : arr) {
            cout<<x<<" ";
        }
        cout<<endl;
    }
}
