//
//  two_sum_bst.cpp
//  Algorithm-Cpp
//
//  Created by Xiaojian Duan on 2022/2/3.
//

#include "two_sum_bst.hpp"
#include <stack>
#include <unordered_map>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

bool findTarget(TreeNode* root, int k) {
    if (root == nullptr) return false;
    TreeNode *p = root;
    stack<TreeNode *> stk;
    unordered_map<int, TreeNode*> map;
    while (p != nullptr || !stk.empty()) {
        while (p != nullptr) {
            stk.push(p);
            p = p->left;
        }
        p = stk.top();
        stk.pop();
        auto it = map.find(k - p->val);
        if (it != map.end()) {
            return true;
        }
        map[p->val] = p;
        p = p->right;
    }
    return false;
}
