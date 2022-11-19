//
//  ReverseString.cpp
//  Algorithm-Cpp
//
//  Created by Xiaojian Duan on 2022/11/5.
//

#include "ReverseString.hpp"
#include <vector>

using namespace std;

class ReverseStringSolution {
public:
    void reverseString(vector<char>& s) {
        int l = 0, r = s.size() - 1;
        while (l < r) {
            swap(s[l], s[r]);
            l++;
            r--;
        }
    }
};
