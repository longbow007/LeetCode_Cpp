//
//  OpenTheLock.cpp
//  Algorithm-Cpp
//
//  Created by Xiaojian Duan on 2022/11/8.
//

#include "OpenTheLock.hpp"
#include <vector>
#include <string>
#include <queue>
#include <unordered_set>
#include <iostream>

using namespace std;

class OpenTheLockSolution {
    string plusOne(string& s, int i) {
        char c = s[i];
        if (c == '9') {
            c = '0';
        } else {
            c++;
        }
        string res = string(s);
        res[i] = c;
        return res;
    }
    string minusOne(string& s, int i) {
        char c = s[i];
        if (c == '0') {
            c = '9';
        } else {
            c--;
        }
        string res = string(s);
        res[i] = c;
        return res;
    }
public:
    int openLock(vector<string>& deadends, string target) {
        auto deadSet = unordered_set<string>();
        for (auto dead : deadends) {
            deadSet.insert(dead);
        }
        auto used = unordered_set<string>();
        auto q = queue<string>();
        int steps = 0;
        q.push("0000");
        used.insert("0000");
        while (!q.empty()) {
            int size = q.size();
            for (int k = 0; k < size; k++) {
                string lock = q.front();
                q.pop();
                if (deadSet.find(lock) != deadSet.end()) {
                    continue;
                }
                if (lock == target) {
                    return steps;
                }
                for (int i = 0; i < 4; i++) {
                    string plus = plusOne(lock, i);
                    if (used.find(plus) == used.end()) {
                        q.push(plus);
                        used.insert(plus);
                    }
                    string minus = minusOne(lock, i);
                    if (used.find(minus) == used.end()) {
                        q.push(minus);
                        used.insert(minus);
                    }
                }
            }
            steps++;
        }
        return -1;
    }
};

void testOpenTheLock() {
    auto solution = OpenTheLockSolution();
    vector<string> deadends = {"0000"};
    string target = "8888";
    int step = solution.openLock(deadends, target);
    cout<<step<<endl;
}
