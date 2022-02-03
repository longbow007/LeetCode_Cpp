//
//  LCA_of_a_binary_tree.cpp
//  Algorithm-Cpp
//
//  Created by Xiaojian Duan on 2022/2/3.
//

#include "LCA_of_a_binary_tree.hpp"

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    TreeNode *ans = root;
    while (ans != nullptr) {
        if (p->val < ans->val && q->val < ans->val) {
            ans = ans->left;
        } else if (p->val > ans->val && q->val > ans->val) {
            ans = ans->right;
        } else {
            return ans;
        }
    }
    return ans;
}
