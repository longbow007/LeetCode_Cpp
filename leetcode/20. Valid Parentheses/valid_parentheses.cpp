//
//  valid_parentheses.cpp
//  Algorithm-Cpp
//
//  Created by Xiaojian Duan on 2022/2/2.
//

#include "valid_parentheses.hpp"
#include <stack>

using namespace std;

bool parentheses_paired(char c1, char c2) {
    if (c1 == '(') {
        return c2 == ')';
    } else if (c1 == '[') {
        return c2 == ']';
    } else if (c1 == '{') {
        return c2 == '}';
    } else {
        return false;
    }
}

bool isValid(string s) {
    if (s.size() % 2 != 0) return false;
    stack<char> stk;
    for (int i = s.size() - 1; i >= 0; i--) {
        if (stk.empty()) {
            stk.push(s[i]);
            continue;
        }
        if (stk.size() > i + 1) {
            return false;
        }
        if (!parentheses_paired(s[i], stk.top())) {
            stk.push(s[i]);
        } else {
            stk.pop();
        }
    }
    return stk.empty();
}

