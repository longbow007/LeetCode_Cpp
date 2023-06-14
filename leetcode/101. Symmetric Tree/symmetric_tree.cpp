//
//  symmetric_tree.cpp
//  Algorithm-Cpp
//
//  Created by Xiaojian Duan on 2022/2/3.
//

#include "symmetric_tree.hpp"
#include <queue>
#include "BinaryTree.hpp"

using namespace std;

class SymmetricTreeSolution {
public:
    // 递归解法
    bool check(TreeNode *left, TreeNode *right) {
        if (left == nullptr && right == nullptr) {
            return true;
        }
        if (left != nullptr && right != nullptr) {
            return left->val == right->val && check(left->left, right->right) && check(left->right, right->left);
        }
        return false;
    }
    bool isSymmetric(TreeNode* root) {
        return check(root->left, root->right);
    }
    
    // 队列解法
//    bool isSymmetric(TreeNode* root) {
//        if (root->left == nullptr && root->right == nullptr) return true;
//        queue<TreeNode *> Q;
//        TreeNode *p = root->left, *q = root->right;
//        if (!p && !q) return true;
//        if (!p || !q) return false;
//        Q.push(p);
//        Q.push(q);
//        while (!Q.empty()) {
//            p = Q.front(); Q.pop();
//            q = Q.front(); Q.pop();
//            if (!p && !q) continue;
//            if ((!p || !q) || p->val != q->val) return false;
//            Q.push(p->left);
//            Q.push(q->right);
//            Q.push(p->right);
//            Q.push(q->left);
//        }
//        return true;
//    }
};


