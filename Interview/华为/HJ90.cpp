//
//  HJ90.cpp
//  Algorithm-Cpp
//
//  Created by Xiaojian Duan on 2023/1/8.
//

#include "HJ90.hpp"
#include <iostream>
#include <string>
using namespace std;

string isValidIP(string s) {
    int dotCnt = 0, numCnt = 0, bitsCnt = 0;
    long len = s.length();
    if (len < 7) {
        return "NO";
    }
    int num = 0;
    for (int i = 0; i < len; i++) {
        if (!isdigit(s[i]) && s[i] != '.') {
            return "NO";
        }
        if (dotCnt > 3) {
            return "NO";
        }
        if (s[i] == '.') {
            if (bitsCnt == 0 ) {
                return "NO";
            }
            bitsCnt = 0;
            num = 0;
            dotCnt++;
            continue;
        }
        if (bitsCnt > 3) {
            return "NO";
        }
        if (dotCnt == 3) {
            numCnt = 4;
        }
        num = num * 10 + s[i] - '0';
        if (num > 255) {
            return "NO";
        }
        if (bitsCnt > 0 && num < 10) {
            return "NO";
        }
        bitsCnt++;
    }
    if (dotCnt != 3 || numCnt != 4) {
        return "NO";
    }
    return "YES";
}

void test_validIP() {
    string s;
    cout<<"Input: ";
    while (getline(cin, s)) {
        cout<<isValidIP(s)<<endl;
        cout<<"Input: ";
    }
}
