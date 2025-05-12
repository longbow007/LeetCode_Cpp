//
//  ImplementQueueUsingStacks.cpp
//  AlgorithmCpp
//
//  Created by DuanXiaojian on 2025/3/23.
//

#include "ImplementQueueUsingStacks.hpp"
#include <stack>

using namespace std;

class MyQueue {
private:
    stack<int> s1, s2;
public:
    MyQueue() {
        s1 = stack<int>();
        s2 = stack<int>();
    }
    
    void push(int x) {
        while (!s2.empty()) {
            s1.push(s2.top());
            s2.pop();
        }
        s1.push(x);
    }
    
    int pop() {
        int res = peek();
        s2.pop();
        return res;
    }
    
    int peek() {
        while (!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
        }
        return s2.top();
    }
    
    bool empty() {
        return s1.empty() && s2.empty();
    }
};
