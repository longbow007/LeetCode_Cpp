//
//  insert_into_a_binary_search_tree.cpp
//  Algorithm-Cpp
//
//  Created by Xiaojian Duan on 2022/2/3.
//

#include "insert_into_a_binary_search_tree.hpp"

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode* insertIntoBST(TreeNode* root, int val) {
    if (root == nullptr) {
        TreeNode *node = new TreeNode(val, nullptr, nullptr);
        return node;
    }
    TreeNode *cur = root, *pre = nullptr;
    while (cur != nullptr) {
        pre = cur;
        if (cur->val < val) {
            cur = cur->right;
        } else {
            cur = cur->left;
        }
    }
    TreeNode *node = new TreeNode(val, nullptr, nullptr);
    if (pre->val > val) {
        pre->left = node;
    } else {
        pre->right = node;
    }
    return root;
}
