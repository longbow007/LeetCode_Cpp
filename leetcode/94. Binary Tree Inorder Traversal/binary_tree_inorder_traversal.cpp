//
//  binary_tree_inorder_traversal.cpp
//  Algorithm-Cpp
//
//  Created by Xiaojian Duan on 2022/2/3.
//

#include "binary_tree_inorder_traversal.hpp"
#include <vector>
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

// 非递归
vector<int> inorderTraversal(TreeNode* root) {
    vector<int> list;
    if (root == nullptr) return list;
    stack<TreeNode *> stk;
    TreeNode *p = root;
    while (!stk.empty() || p != nullptr) {
        while (p != nullptr) {
            stk.emplace(p);
            p = p->left;
        }
        p = stk.top();
        stk.pop();
        list.emplace_back(p->val);
        p = p->right;
    }
    return list;
}
