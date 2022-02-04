//
//  make_odd_ahead_of_even.cpp
//  Algorithm-Cpp
//
//  Created by Xiaojian Duan on 2022/2/4.
//

#include "make_odd_ahead_of_even.hpp"
#include <vector>

using namespace std;

class ExchangeSolution {
public:
    vector<int> exchange(vector<int>& nums) {
        int j = -1;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] % 2 == 0 && j < 0) {
                j = i;
                continue;
            }
            if (nums[i] % 2 == 1 && j >= 0) {
                int temp = nums[i];
                nums[i] = nums[j];
                nums[j] = temp;
                j++;
            }
        }
        return nums;
    }
};
