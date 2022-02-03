//
//  symmetric_tree_test.cpp
//  Algorithm-Cpp
//
//  Created by Xiaojian Duan on 2022/2/3.
//

#include "symmetric_tree_test.hpp"
#include "symmetric_tree.hpp"

void symmetric_tree_test(void) {
    TreeNode n1(3);
    TreeNode n2(4);
    TreeNode n3(4);
    TreeNode n4(3);
    TreeNode n5(2, &n1, &n2);
    TreeNode n6(2, &n3, &n4);
    TreeNode root(1, &n5, &n6);
    isSymmetric(&root);
}
