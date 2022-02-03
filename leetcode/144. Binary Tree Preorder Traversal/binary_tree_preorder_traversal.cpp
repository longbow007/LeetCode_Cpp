//
//  binary_tree_preorder_traversal.cpp
//  Algorithm-Cpp
//
//  Created by Xiaojian Duan on 2022/2/3.
//

#include "binary_tree_preorder_traversal.hpp"
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
// 递归
// void preorder(TreeNode *node, vector<int> &list) {
//     if (node == nullptr) return;
//     list.push_back(node->val);
//     preorder(node->left, list);
//     preorder(node->right, list);
// }
// vector<int> preorderTraversal(TreeNode* root) {
//     vector<int> result;
//     preorder(root, result);
//     return result;
// }

// 非递归
vector<int> preorderTraversal(TreeNode* root) {
    vector<int> result;
    if (root == nullptr) return result;
    stack<TreeNode *> stk;
    TreeNode *p = root;
    while (!stk.empty() || p != nullptr) {
        while(p != nullptr) {
            // emplace 比 push 快得多
            result.emplace_back(p->val);
            stk.emplace(p);
            p = p->left;
        }
        p = stk.top();
        stk.pop();
        p = p->right;
    }
    return result;
}
