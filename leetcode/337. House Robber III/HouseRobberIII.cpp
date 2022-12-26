//
//  HouseRobberIII.cpp
//  Algorithm-Cpp
//
//  Created by Xiaojian Duan on 2022/12/26.
//

#include "HouseRobberIII.hpp"
#include <vector>
#include "BinaryTree.hpp"

using namespace std;

class HouseRobberIIISolution {
public:
    // 返回值第一个元素是包含 root 节点的抢劫最大值，第二个元素是不包含 root 节点的抢劫最大值
    vector<int> dfs(TreeNode *root) {
        auto res = vector<int>(2, 0);
        if (root == nullptr) {
            return res;
        }
        vector<int> left = dfs(root->left);
        vector<int> right = dfs(root->right);
        res[0] = root->val + left[1] + right[1];
        res[1] = max(left[0], left[1]) + max(right[0], right[1]);
        return res;
    }
    int rob(TreeNode* root) {
        vector<int> res = dfs(root);
        return max(res[0], res[1]);
    }
};
