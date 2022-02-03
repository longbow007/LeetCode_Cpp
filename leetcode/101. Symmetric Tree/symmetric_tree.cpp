//
//  symmetric_tree.cpp
//  Algorithm-Cpp
//
//  Created by Xiaojian Duan on 2022/2/3.
//

#include "symmetric_tree.hpp"
#include <queue>

using namespace std;

bool isSymmetric(TreeNode* root) {
    if (root->left == nullptr && root->right == nullptr) return true;
    queue<TreeNode *> Q;
    TreeNode *p = root->left, *q = root->right;
    if (!p && !q) return true;
    if (!p || !q) return false;
    Q.push(p);
    Q.push(q);
    while (!Q.empty()) {
        p = Q.front(); Q.pop();
        q = Q.front(); Q.pop();
        if (!p && !q) continue;
        if ((!p || !q) || p->val != q->val) return false;
        Q.push(p->left);
        Q.push(q->right);
        Q.push(p->right);
        Q.push(q->left);
    }
    return true;
}
