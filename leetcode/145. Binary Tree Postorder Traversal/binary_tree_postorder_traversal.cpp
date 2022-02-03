//
//  binary_tree_postorder_traversal.cpp
//  Algorithm-Cpp
//
//  Created by Xiaojian Duan on 2022/2/3.
//

#include "binary_tree_postorder_traversal.hpp"
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
vector<int> postorderTraversal(TreeNode* root) {
    vector<int> list;
    if (root == nullptr) return list;
    stack<TreeNode *> stk;
    TreeNode *p = root, *q = nullptr;
    while (p != nullptr || !stk.empty()) {
        while (p != nullptr) {
            stk.emplace(p);
            p = p->left;
        }
        p = stk.top();
        if (p->right != nullptr && p->right != q) {
            p = p->right;
        } else {
            list.emplace_back(p->val);
            stk.pop();
            q = p;
            p = nullptr;
        }
    }
    return list;
}
