//
//  BinaryTreeMaximumPathSum.cpp
//  Algorithm-Cpp
//
//  Created by Xiaojian Duan on 2022/11/7.
//

#include "BinaryTreeMaximumPathSum.hpp"
#include "BinaryTree.hpp"

using namespace std;

class BinaryTreeMaximumPathSumSolution {
public:
    int dfs(TreeNode* node, int& maxSum) {
        if (nullptr == node) return 0;
        int l = max(0, dfs(node->left, maxSum));
        int r = max(0, dfs(node->right, maxSum));
        maxSum = max(maxSum, l + r + node->val);
        return max(l, r) + node->val;
    }
    int maxPathSum(TreeNode* root) {
        int maxSum = INT_MIN;
        dfs(root, maxSum);
        return maxSum;
    }
};
