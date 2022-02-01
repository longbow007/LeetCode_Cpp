//
//  contains_duplicate.cpp
//  Algorithm-Cpp
//
//  Created by Xiaojian Duan on 2022/2/1.
//

#include "contains_duplicate.hpp"
#include <vector>
#include <unordered_set>

using namespace std;

bool containsDuplicate(vector<int>& nums) {
    unordered_set<int> set;
    for (int x : nums) {
        if (set.find(x) != set.end()) {
            return true;
        }
        set.insert(x);
    }
    return false;
}
