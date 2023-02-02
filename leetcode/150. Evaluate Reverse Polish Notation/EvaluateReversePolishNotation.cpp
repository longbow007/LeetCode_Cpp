//
//  EvaluateReversePolishNotation.cpp
//  Algorithm-Cpp
//
//  Created by Xiaojian Duan on 2023/2/2.
//

#include "EvaluateReversePolishNotation.hpp"
#include <string>
#include <vector>
#include <stack>

using namespace std;

class EvaluateReversePolishNotationSolution {
public:
    bool isDigital(string s) {
        bool digital = false;
        for (int i = 0; i < s.length(); i++) {
            char c = s[i];
            if (c <= '9' && c >= '0') {
                digital = true;
            } else {
                digital = false;
            }
        }
        return digital;
    }
    int stringToNum(string s) {
        int num = 0;
        int start = 0;
        bool positive = true;
        if (s[start] == '-') {
            positive = false;
            start++;
        }
        for (int i = start; i < s.length(); i++) {
            char c = s[i];
            num = c - '0' + num * 10;
        }
        num = positive ? num : -num;
        return num;
    }
    int evalRPN(vector<string>& tokens) {
        stack<int> stk;
        for (string s : tokens) {
            if (isDigital(s)) {
                int num = stringToNum(s);
                stk.push(num);
                continue;
            }
            int b = stk.top();
            stk.pop();
            int a = stk.top();
            stk.pop();
            char op = s[0];
            switch (op) {
                case '+': {
                    stk.push(a + b);
                    break;
                }
                case '-': {
                    stk.push(a - b);
                    break;
                }
                case '*': {
                    stk.push(a * b);
                    break;
                }
                case '/': {
                    stk.push(a / b);
                    break;
                }
                default: {
                    break;
                }
            }
        }
        int res = stk.top();
        return res;
    }
};
