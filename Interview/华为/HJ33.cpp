//
//  HJ33.cpp
//  Algorithm-Cpp
//
//  Created by Xiaojian Duan on 2023/1/8.
//

#include "HJ33.hpp"
#include <iostream>
#include <string>
using namespace std;

unsigned int ipToInt(string s) {
    unsigned int res = 0;
    int num = 0;
    for (char c : s) {
        if (c == '.') {
            res = res << 8;
            res += num;
            num = 0;
            continue;
        }
        num = c - '0' + num * 10;
    }
    res = res << 8;
    res += num;
    return res;
}

string intToIP(unsigned int n) {
    int mask = 0xff;
    int arr[4];
    for (int i = 0; i < 4; i++) {
        arr[i] = n >> 8 * (3 - i) & mask;
    }
    string res;
    for (int i = 0; i < 4; i++) {
        res += to_string(arr[i]);
        if (i < 3) {
            res += '.';
        }
    }
    return res;
}

void test_ip() {
    string ip;
    unsigned int n;
    cin >> ip >> n;
    cout << ipToInt(ip) << endl;
    cout << intToIP(n) << endl;
}
