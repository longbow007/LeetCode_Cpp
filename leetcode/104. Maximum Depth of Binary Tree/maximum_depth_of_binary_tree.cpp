//
//  maximum_depth_of_binary_tree.cpp
//  Algorithm-Cpp
//
//  Created by Xiaojian Duan on 2022/2/3.
//

#include "maximum_depth_of_binary_tree.hpp"
#include <algorithm>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int maxDepth(TreeNode* root) {
    // 深度优先
    if (root == nullptr) return 0;
    return max(maxDepth(root->left), maxDepth(root->right)) + 1;
    
    //     广度优先，层序遍历
    //     if (root == nullptr) return 0;
    //     if (root->left == nullptr && root->right == nullptr) return 1;
    //     int n = 0;
    //     queue<TreeNode *> q;
    //     q.push(root);
    //     while (!q.empty()) {
    //         int size = q.size();
    //         for (int i = 0; i < size; i++) {
    //             TreeNode *node = q.front();
    //             q.pop();
    //             if (node->left) q.push(node->left);
    //             if (node->right) q.push(node->right);
    //         }
    //         n++;
    //     }
    //     return n;
}
