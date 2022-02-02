//
//  intersection_of_two_arrays_2.cpp
//  Algorithm-Cpp
//
//  Created by Xiaojian Duan on 2022/2/2.
//

#include "intersection_of_two_arrays_2.hpp"
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
    if (nums1.size() < nums2.size()) {
        return intersect(nums2, nums1);
    }
    unordered_map<int, int> map;
    vector<int> result;
    for (int x : nums1) {
        ++map[x];
    }
    for (int y : nums2) {
        if (map.count(y)) {
            result.push_back(y);
            --map[y];
            if (map[y] == 0) {
                map.erase(y);
            }
        }
    }
    return result;
}
