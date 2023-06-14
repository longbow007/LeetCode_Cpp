//
//  SerializeAndDeserializeBinaryTree.cpp
//  Algorithm-Cpp
//
//  Created by Xiaojian Duan on 2023/6/13.
//

#include "SerializeAndDeserializeBinaryTree.hpp"
#include <string>
#include <list>
#include "BinaryTree.hpp"

using namespace std;

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string res = "";
        preorderTraverse(res, root);
        // cout<<res<<endl;
        return res;
    }

    void preorderTraverse(string &res, TreeNode *node) {
        if (res.size() > 0) {
            res += ",";
        }
        if (node == nullptr) {
            res += "#";
            return;
        }
        res += to_string(node->val);
        preorderTraverse(res, node->left);
        preorderTraverse(res, node->right);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        // return nullptr;
        list<string> strArray;
        string str;
        for (auto& c : data) {
            if (c == ',') {
                strArray.push_back(str);
                str.clear();
            } else {
                str.push_back(c);
            }
        }
        if (!str.empty()) {
            strArray.push_back(str);
            str.clear();
        }
        int i = 0;
        return dfs(strArray);
    }

    TreeNode* dfs(list<string>& strArray) {
        if (strArray.empty()) {
            return nullptr;
        }
        string s = strArray.front();
        if (s == "#") {
            strArray.pop_front();
            return nullptr;
        }
        int val = stoi(s);
        strArray.pop_front();
        TreeNode *node = new TreeNode(val);
        node->left = dfs(strArray);
        node->right = dfs(strArray);
        return node;
    }
};
