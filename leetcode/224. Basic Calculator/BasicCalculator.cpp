//
//  BasicCalculator.cpp
//  Algorithm-Cpp
//
//  Created by Xiaojian Duan on 2023/1/31.
//

#include "BasicCalculator.hpp"
#include <string>
#include <stack>
#include <iostream>

using namespace std;

class BasicCalculatorSolution {
public:
    int calculate(string s) {
        bool positive = true;  // 符号，默认+号
        stack<int> stk;
        int sum = 0;
        while (i < s.length()) {
            int num = 0;
            if (s[i] == '(') {
                i++;
                num = calculate(s);
            }
            while (isdigit(s[i])) {
                num = num * 10 + (s[i] - '0');
                i++;
            }
            if (!positive) {
                num = -num;
            }
            if (num != 0) {
                stk.push(num);
            }
            if (s[i] == '-') {
                positive = false;
            } else if (s[i] == '+') {
                positive = true;
            } else if (s[i] == ')') {
                i++;
                break;
            }
            i++;
        }
        while (!stk.empty()) {
            sum += stk.top();
            stk.pop();
        }
        return sum;
    }
private:
    int i = 0;
};

void test_BasicCalculator() {
    auto sol = BasicCalculatorSolution();
    int res = sol.calculate("1 + 1");
    cout<< res << endl;
}
