//
//  MaximumBinaryTree.cpp
//  Algorithm-Cpp
//
//  Created by Xiaojian Duan on 2023/6/13.
//

#include "MaximumBinaryTree.hpp"
#include "BinaryTree.hpp"
#include <vector>

using namespace std;

class MaximumBinaryTreeSolution {
public:
    TreeNode* makeTree(vector<int>& nums, int left, int right) {
        if (left > right) {
            return nullptr;
        }
        int maxIdx = left;
        for (int i = left; i <= right; i++) {
            if (nums[i] > nums[maxIdx]) {
                maxIdx = i;
            }
        }
        TreeNode *root = new TreeNode(nums[maxIdx]);
        root->left = makeTree(nums, left, maxIdx-1);
        root->right = makeTree(nums, maxIdx+1, right);
        return root;
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return makeTree(nums, 0, nums.size() - 1);
    }
};
