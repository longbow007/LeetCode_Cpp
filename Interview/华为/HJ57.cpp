//
//  HJ57.cpp
//  Algorithm-Cpp
//
//  Created by Xiaojian Duan on 2023/1/8.
//

#include "HJ57.hpp"
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string strCalculate(string s1, string s2) {
    long i = s1.length() - 1, j = s2.length() - 1;
    bool flag = false;  // 进位
    string res;
    while (i >= 0 && j >= 0) {
        int a = s1[i] - '0', b = s2[j] - '0';
        int c = a + b;
        if (flag) {
            c++;
        }
        if (c > 9) {
            c -= 10;
            flag = true;
        } else {
            flag = false;
        }
        res += '0' + c;
        i--;
        j--;
    }
    long k = (i > 0) ? i : j;
    string temp = (i > 0) ? s1 : s2;
    while (k >= 0) {
        char c = temp[k];
        if (flag) {
            c += 1;
            if (c > '9') {
                c = '0';
                flag = true;
            } else {
                flag = false;
            }
        }
        res += c;
        k--;
    }
    if (flag) {
        res += '1';
    }
    reverse(res.begin(), res.end());
    return res;
}


