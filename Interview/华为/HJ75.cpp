//
//  HJ75.cpp
//  Algorithm-Cpp
//
//  Created by Xiaojian Duan on 2023/1/7.
//

#include "HJ75.hpp"
#include <iostream>
#include <string>
using namespace std;

int lcs(string s1, string s2) {
    int m = s1.length(), n = s2.length();
    int dp[m+1][n+1];
    for (int i = 0; i <= m; i++) {
        dp[i][0] = 0;
    }
    for (int j = 0; j <= n; j++) {
        dp[0][j] = 0;
    }
    int res = 0;
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (s1[i-1] == s2[j-1]) {
                dp[i][j] = dp[i-1][j-1] + 1;
            } else {
                dp[i][j] = 0;
            }
            res = max(res, dp[i][j]);
        }
    }
    return res;
}

void test_lcs() {
    string s1, s2;
    cout<<"Input1: "<<endl;
    cin>>s1;
    cout<<"Input2: "<<endl;
    cin>>s2;
    cout<<lcs(s1, s2)<<endl;
}
