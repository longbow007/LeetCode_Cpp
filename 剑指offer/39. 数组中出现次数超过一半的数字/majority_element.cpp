//
//  majority_element.cpp
//  Algorithm-Cpp
//
//  Created by Xiaojian Duan on 2022/2/5.
//

#include "majority_element.hpp"
#include <vector>
#include <unordered_map>

using namespace std;

int majorityElement(vector<int>& nums) {
    if (nums.size() == 1) return nums[0];
    unordered_map<int, int> m;
    int result = 0, maxCnt = 0;
    for (int x : nums) {
        auto it = m.find(x);
        if (it != m.end()) {
            int cnt = it->second;
            m[x] = cnt + 1;
            if (cnt + 1 > maxCnt) {
                maxCnt = cnt + 1;
                result = x;
            }
        } else {
            m[x] = 1;
        }
    }
    return result;
}
