//
//  validate_binary_search_tree.cpp
//  Algorithm-Cpp
//
//  Created by Xiaojian Duan on 2022/2/3.
//

#include "validate_binary_search_tree.hpp"
#include <stack>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

bool isValidBST(TreeNode* root) {
    if (root == nullptr) return false;
    TreeNode *p = root, *q = nullptr;
    stack<TreeNode *>stk;
    while (p != nullptr || !stk.empty()) {
        while (p != nullptr) {
            stk.push(p);
            p = p->left;
        }
        p = stk.top();
        stk.pop();
        if (q != nullptr) {
            if (q->val >= p->val) {
                return false;
            }
        }
        q = p;
        p = p->right;
    }
    return true;
}
