//
//  ConstructBinaryTreeFromPreorderAndInorderTraversal.cpp
//  Algorithm-Cpp
//
//  Created by Xiaojian Duan on 2023/6/13.
//

#include "ConstructBinaryTreeFromPreorderAndInorderTraversal.hpp"
#include "BinaryTree.hpp"
#include <vector>
#include <unordered_map>

using namespace std;

class ConstructBinaryTreeFromPreorderAndInorderTraversalSolution {
public:
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        auto map = unordered_map<int, int>();
        for (int i = 0; i < inorder.size(); i++) {
            map[inorder[i]] = i;
        }
        return helper(map, preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
    }
    TreeNode* helper(unordered_map<int, int>& map, vector<int>& preorder, int preStart, int preEnd, vector<int>& inorder, int inStart, int inEnd) {
        if (preStart > preEnd || inStart > inEnd) {
            return nullptr;
        }
        int rootVal = preorder[preStart];
        int index = map[rootVal];
        int leftSize = index - inStart;
        TreeNode *root = new TreeNode(rootVal);
        root->left = helper(map, preorder, preStart + 1, preStart + leftSize, inorder, inStart, index - 1);
        root->right = helper(map, preorder, preStart + leftSize + 1, preEnd, inorder, index + 1, inEnd);
        return root;
    }
};
