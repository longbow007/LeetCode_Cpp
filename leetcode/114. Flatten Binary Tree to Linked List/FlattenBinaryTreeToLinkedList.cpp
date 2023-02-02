//
//  FlattenBinaryTreeToLinkedList.cpp
//  Algorithm-Cpp
//
//  Created by Xiaojian Duan on 2023/2/2.
//

#include "FlattenBinaryTreeToLinkedList.hpp"
#include "BinaryTree.hpp"

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    // 解法一
// public:
//     TreeNode* makeList(TreeNode *root) {
//         if (root == nullptr) {
//             return root;
//         }
//         TreeNode *left = root->left;
//         TreeNode *leftTail = makeList(left);
//         TreeNode *right = root->right;
//         TreeNode *rightTail = makeList(right);
//         TreeNode *p = root;
//         if (left != nullptr) {
//             p->left = nullptr;
//             p->right = left;
//             p = p->right;
//             p->left = nullptr;
//         }
//         if (leftTail != nullptr) {
//             p = leftTail;
//             p->left = nullptr;
//             p->right = nullptr;
//         }
//         if (right != nullptr) {
//             p->right = right;
//             p = p->right;
//             p->left = nullptr;
//         }
//         if (rightTail != nullptr) {
//             p = rightTail;
//             p->left = nullptr;
//             p->right = nullptr;
//         }
//         return p;
//     }
//     void flatten(TreeNode* root) {
//         root = makeList(root);
//     }

// 解法二
private:
    TreeNode *pre = nullptr;
public:
    void flatten(TreeNode* root) {
        if (root == nullptr) {
            return;
        }
        flatten(root->right);
        flatten(root->left);
        root->left = nullptr;
        root->right = pre;
        pre = root;
    }
};
