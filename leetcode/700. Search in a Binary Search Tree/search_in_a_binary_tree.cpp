//
//  search_in_a_binary_tree.cpp
//  Algorithm-Cpp
//
//  Created by Xiaojian Duan on 2022/2/3.
//

#include "search_in_a_binary_tree.hpp"

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode* searchBST(TreeNode* root, int val) {
    if (root == nullptr) return root;
    if (val == root->val) return root;
    if (val < root->val) return searchBST(root->left, val);
    if (val > root->val) return searchBST(root->right, val);
    return nullptr;
}
