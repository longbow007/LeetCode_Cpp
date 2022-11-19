//
//  DiameterOfBinaryTree.cpp
//  Algorithm-Cpp
//
//  Created by Xiaojian Duan on 2022/11/7.
//

#include "DiameterOfBinaryTree.hpp"
#include "BinaryTree.hpp"

using namespace std;

class DiameterOfBinaryTreeSolution {
public:
    int dfs(TreeNode *node, int& maxDepth) {
        if (nullptr == node) {
            return 0;
        }
        int l = dfs(node->left, maxDepth);
        int r = dfs(node->right, maxDepth);
        maxDepth = max(maxDepth, l + r);
        return max(l, r) + 1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int maxDepth = 0;
        dfs(root, maxDepth);
        return maxDepth;
    }
};
