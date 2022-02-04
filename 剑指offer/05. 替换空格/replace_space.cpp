//
//  replace_space.cpp
//  Algorithm-Cpp
//
//  Created by Xiaojian Duan on 2022/2/4.
//

#include "replace_space.hpp"
#include <string>

using namespace std;

string replaceSpace(string s) {
    string result;
    for (char c : s) {
        if (c == ' ') {
            result.push_back('%');
            result.push_back('2');
            result.push_back('0');
        } else {
            result.push_back(c);
        }
    }
    return result;
}
