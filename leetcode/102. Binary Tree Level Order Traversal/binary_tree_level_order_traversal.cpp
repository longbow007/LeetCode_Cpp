//
//  binary_tree_level_order_traversal.cpp
//  Algorithm-Cpp
//
//  Created by Xiaojian Duan on 2022/2/4.
//

#include "binary_tree_level_order_traversal.hpp"
#include <vector>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> result;
    if (root == nullptr) return result;
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty()) {
        int size = q.size();
        vector<int> tempList;
        for (int i = 0; i < size; i++) {
            TreeNode *node = q.front();
            q.pop();
            tempList.push_back(node->val);
            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }
        result.push_back(tempList);
    }
    return result;
}
