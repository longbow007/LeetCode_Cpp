//
//  find_repeat_number.cpp
//  Algorithm-Cpp
//
//  Created by Xiaojian Duan on 2022/2/4.
//

#include "find_repeat_number.hpp"
#include <vector>
#include <unordered_set>

using namespace std;

int findRepeatNumber(vector<int>& nums) {
    unordered_set<int> s;
    for (int x : nums) {
        if (s.find(x) != s.end()) {
            return x;
        }
        s.insert(x);
    }
    return -1;
}
