//
//  HJ26.cpp
//  Algorithm-Cpp
//
//  Created by Xiaojian Duan on 2023/1/7.
//

#include "HJ26.hpp"
#include <iostream>
#include <string>
using namespace std;

string sortString(string s) {
    char chArr[1000];
    int k = 0;
    for (int i = 0; i < 26; ++i) {
        for (int j = 0; j < s.size(); ++j) {
            if (s[j] - 'a' == i || s[j] - 'A' == i) {
                chArr[k++] = s[j];
            }
        }
    }
    k = 0;
    for (int i = 0; i < s.size(); ++i) {
        char c = s[i];
        if (isalpha(c)) {
            s[i] = chArr[k++];
        }
    }
    return s;
}

void test_sortString() {
    string s;
    getline(cin, s);
    cout << sortString(s) << endl;
}
