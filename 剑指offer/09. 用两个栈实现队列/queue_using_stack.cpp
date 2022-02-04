//
//  queue_using_stack.cpp
//  Algorithm-Cpp
//
//  Created by Xiaojian Duan on 2022/2/4.
//

#include "queue_using_stack.hpp"
#include <stack>

using namespace std;

class CQueue {
    stack<int> s1, s2;
public:
    CQueue() {
    }

    void appendTail(int value) {
        while (!s2.empty()) {
            s1.push(s2.top());
            s2.pop();
        }
        s1.push(value);
    }

    int deleteHead() {
        if (s1.empty() && s2.empty()) {
            return -1;
        }
        while (!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
        }
        int val = s2.top();
        s2.pop();
        return val;
    }
};
