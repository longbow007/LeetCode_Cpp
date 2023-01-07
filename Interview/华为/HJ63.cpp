//
//  HJ63.cpp
//  Algorithm-Cpp
//
//  Created by Xiaojian Duan on 2023/1/7.
//

#include "HJ63.hpp"
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string dnaLongestSubString(string s, int n) {
        int i = 0, cnt = 0, maxCnt = 0;
        string res = "";
        for (int j = 0; j < s.length(); j++) {
            int len = j - i + 1;
            if (s[j] == 'G' || s[j] == 'C') {
                cnt++;
            }
            if (len > n) {
                if (s[i] == 'G' || s[i] == 'C') {
                    cnt--;
                }
                i++;
            }
            if (cnt > maxCnt) {
                res = s.substr(i, n);
                maxCnt = cnt;
            }
        }
        return res;
    }
};
