//
//  ConstructBinaryTreeFromInorderAndPostorderTraversal.cpp
//  Algorithm-Cpp
//
//  Created by Xiaojian Duan on 2023/6/13.
//

#include "ConstructBinaryTreeFromInorderAndPostorderTraversal.hpp"
#include "BinaryTree.hpp"
#include <vector>
#include <unordered_map>

using namespace std;

class ConstructBinaryTreeFromInorderAndPostorderTraversalSolution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        auto map = unordered_map<int, int>();
        for (int i = 0; i < inorder.size(); i++) {
            map[inorder[i]] = i;
        }
        return helper(map, inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1);
    }
    TreeNode* helper(unordered_map<int, int>& map, vector<int>& inorder, int inStart, int inEnd, vector<int>& postorder, int postStart, int postEnd) {
        if (inStart > inEnd || postStart > postEnd) {
            return nullptr;
        }
        int rootVal = postorder[postEnd];
        int index = map[rootVal];
        int leftSize = index - inStart;
        TreeNode *root = new TreeNode(rootVal);
        root->left = helper(map, inorder, inStart, index - 1, postorder, postStart, postStart + leftSize - 1);
        root->right = helper(map, inorder, index + 1, inEnd, postorder, postStart + leftSize, postEnd - 1);
        return root;
    }
};
