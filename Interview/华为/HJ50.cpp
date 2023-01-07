//
//  HJ50.cpp
//  Algorithm-Cpp
//
//  Created by Xiaojian Duan on 2023/1/6.
//

#include "HJ50.hpp"
#include <iostream>
#include <stack>

using namespace std;

class CalculateSolution {
public:
    CalculateSolution() {
        pos = 0;
    }
    int compute(string& s) {
        long len = s.length();
        int num = 0;
        char sign = '+';
        auto stk = stack<int>();
        while (pos < len) {
            char c = s[pos];
            if ((c == '(' || c == '[' || c == '{')) {
                pos++;
                num = compute(s);
            }
            while (pos < len && c >= '0' && c <= '9') {
                num = num * 10 + c - '0';
                pos++;
                c = s[pos];
            }
            switch (sign) {
                case '+': {
                    stk.push(num);
                    break;
                }
                case '-': {
                    stk.push(-num);
                    break;
                }
                case '*': {
                    int temp = stk.top();
                    stk.pop();
                    stk.push(temp * num);
                    break;
                }
                case '/': {
                    int temp = stk.top();
                    stk.pop();
                    stk.push(temp / num);
                    break;
                }
            }
            sign = s[pos];
            num = 0;
            c = s[pos];
            if (c == ')' || c == ']' || c == '}') {
                pos++;
                break;
            }
            pos++;
        }
        int sum = 0;
        while (!stk.empty()) {
            sum += stk.top();
            stk.pop();
        }
        return sum;
    }
    void reset() {
        pos = 0;
    }
private:
    int pos;
};

void test_calculate() {
    auto solution = CalculateSolution();
    string data;
    cout<<"input: ";
    while (cin >> data) {
        cout << solution.compute(data) << endl;
        solution.reset();
        cout<<"input: ";
    }
}
