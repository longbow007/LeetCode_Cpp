//
//  FindLargestValueInEachTreeRow.cpp
//  Algorithm-Cpp
//
//  Created by Xiaojian Duan on 2022/11/7.
//

#include "FindLargestValueInEachTreeRow.hpp"
#include "BinaryTree.hpp"
#include <vector>
#include <queue>

using namespace std;

class FindLargestValueInEachTreeRowSolution {
public:
    vector<int> largestValues(TreeNode* root) {
        auto ans = vector<int>();
        if (nullptr == root) return ans;
        auto q = queue<TreeNode*>();
        q.push(root);
        while (!q.empty()) {
            // 用size 保存当前队列长度，即可获得同一层的所有元素
            int size = q.size();
            int maxVal = q.front()->val;
            while (size > 0) {
                TreeNode *node = q.front();
                q.pop();
                maxVal = max(maxVal, node->val);
                if (node->left != nullptr) q.push(node->left);
                if (node->right != nullptr) q.push(node->right);
                size--;
            }
            ans.push_back(maxVal);
        }
        return ans;
    }
};
