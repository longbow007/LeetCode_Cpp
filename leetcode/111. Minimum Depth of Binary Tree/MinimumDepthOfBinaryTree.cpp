//
//  MinimumDepthOfBinaryTree.cpp
//  Algorithm-Cpp
//
//  Created by Xiaojian Duan on 2022/11/8.
//

#include "MinimumDepthOfBinaryTree.hpp"
#include "BinaryTree.hpp"
#include <queue>

using namespace std;

class MinimumDepthOfBinaryTreeSolution {
public:
    int minDepth(TreeNode* root) {
        if (nullptr == root) return 0;
        int depth = 1;
        auto q = queue<TreeNode*>();
        q.push(root);
        while (!q.empty()) {
            int size = q.size();
            while (size > 0) {
                TreeNode *node = q.front();
                q.pop();
                if (nullptr == node->left && nullptr == node->right) {
                    return depth;
                }
                if (node->left != nullptr) {
                    q.push(node->left);
                }
                if (node->right != nullptr) {
                    q.push(node->right);
                }
                size--;
            }
            depth++;
        }
        return depth;
    }
};
