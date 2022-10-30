//
//  LongestPalindromicSubstring.cpp
//  Algorithm-Cpp
//
//  Created by Xiaojian Duan on 2022/10/29.
//

#include <iostream>
#include "LongestPalindromicSubstring.hpp"
#include <string>
#include <vector>

using namespace std;

class LongestPalindromicSubstringSolution {
public:
    // 中心扩散法
    // void startIndex(string s, int& maxLen, int& start, int& l, int& r) {
    //      while (l >= 0 && r < s.size() && s[l] == s[r]) {
    //         int len = r - l + 1;
    //         if (len > maxLen) {
    //             maxLen = len;
    //             start = l;
    //         }
    //         l--;
    //         r++;
    //     }
    // }
    // string longestPalindrome(string s) {
    //     int n = s.size();
    //     if (n < 2) {
    //         return s;
    //     }
    //     int start = 0, maxLen = 0;
    //     for (int i = 0; i < n; i++) {
    //         int l = i, r = i;
    //         startIndex(s, maxLen, start, l, r);
    //         l = i;
    //         r = i + 1;
    //         startIndex(s, maxLen, start, l, r);
    //     }
    //     string res = s.substr(start, maxLen);
    //     return res;
    // }

    // 动态规划
    string longestPalindrome(string s) {
        int n = s.size();
        if (n < 2) return s;
        // dp[i][j] 表示 i..j 之间的子串是否回文
        auto dp = vector<vector<bool>>(n, vector<bool>(n, false));
        // 长度为 1 的必然是回文
        for (int i = 0; i < n; i++) {
            dp[i][i] = true;
        }
        int start = 0, maxLen = 1;
        for (int r = 1; r < n; r++) {
            for (int l = 0; l < r; l++) {
                if (s[l] == s[r] && (r - l <= 2 || dp[l+1][r-1])) {
                    dp[l][r] = true;
                    int len = r - l + 1;
                    if (len > maxLen) {
                        maxLen = len;
                        start = l;
                    }
                }
            }
        }
        return s.substr(start, maxLen);
    }
};

void testLongestPalindromicSubstring() {
    auto solution = LongestPalindromicSubstringSolution();
    auto res = solution.longestPalindrome("ababc");
    cout<<res<<endl;
}
