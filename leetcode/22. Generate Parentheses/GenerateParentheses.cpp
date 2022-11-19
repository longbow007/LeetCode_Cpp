//
//  GenerateParentheses.cpp
//  Algorithm-Cpp
//
//  Created by Xiaojian Duan on 2022/11/1.
//

#include "GenerateParentheses.hpp"
#include <vector>
#include <string>

using namespace std;

class GenerateParenthesesSolution {
public:
    void dfs(vector<string>& res, vector<char>& cur, int n, int left, int right) {
        if (left == n && right == n) {
            res.push_back(string(cur.begin(), cur.end()));
            return;
        }
        if (left < n) {
            cur.push_back('(');
            dfs(res, cur, n, left + 1, right);
            cur.pop_back();
        }
        if (right < left) {
            cur.push_back(')');
            dfs(res, cur, n, left, right + 1);
            cur.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        auto res = vector<string>();
        auto cur = vector<char>();
        dfs(res, cur, n, 0, 0);
        return res;
    }
};
