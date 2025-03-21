//
//  BinaryTree.hpp
//  Algorithm-Cpp
//
//  Created by Xiaojian Duan on 2022/11/7.
//

#ifndef BinaryTree_hpp
#define BinaryTree_hpp

#include <stdio.h>
#include <algorithm>
// test
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// 二叉树序列化为字符串，null 节点用 “#" 表示
std::string serialize(TreeNode *root);

// 字符串生成二叉树，用 "#" 表示 null 节点
TreeNode *btCreate(std::string str);

#endif /* BinaryTree_hpp */
