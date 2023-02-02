//
//  BinaryTree.cpp
//  Algorithm-Cpp
//
//  Created by Xiaojian Duan on 2022/11/7.
//

#include "BinaryTree.hpp"
#include <string>

using namespace std;

string serialize(TreeNode *root) {
    string rootStr = "";
    if (root == nullptr) {
        rootStr = "#";
    } else {
        rootStr = to_string(root->val);
    }
    if (root != nullptr && root->left == nullptr && root->right == nullptr) {
        return rootStr;
    }
    string leftStr = serialize(root->left);
    string rightStr = serialize(root->right);
    return rootStr + "," + leftStr + "," + rightStr;
}

TreeNode *dfs(string str, int& idx) {
    if (str.length() == 0 || idx >= str.length()) {
        return nullptr;
    }
    if (str[idx] == '#') {
        idx++;
        return nullptr;
    }
    int val = str[idx++] - '0';
    TreeNode *left = dfs(str, idx);
    TreeNode *right = dfs(str, idx);
    TreeNode *node = new TreeNode(val, left, right);
    return node;
}

TreeNode *btCreate(string str) {
    int i = 0;
    return dfs(str, i);
}
