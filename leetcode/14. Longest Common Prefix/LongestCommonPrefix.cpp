//
//  LongestCommonPrefix.cpp
//  Algorithm-Cpp
//
//  Created by Xiaojian Duan on 2022/10/29.
//

#include "LongestCommonPrefix.hpp"
#include <string>
#include <vector>

using namespace std;

class LongestCommonPrefixSolution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        if (n == 1) {
            return strs[0];
        }
        int i = 0;
        bool stop = false;
        string res = "";
        while (!stop) {
            if (i >= strs[0].size()) {
                break;
            }
            auto c = strs[0][i];
            for (int j = 1; j < n; j++) {
                string s = strs[j];
                if (i >= s.size()) {
                    stop = true;
                    break;
                }
                auto temp = s[i];
                if (temp != c) {
                    stop = true;
                    break;
                }
            }
            if (!stop) {
                res += c;
            }
            i++;
        }
        return res;
    }
};
