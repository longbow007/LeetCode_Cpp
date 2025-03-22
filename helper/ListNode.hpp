//
//  ListNode.hpp
//  LeetcodeCpp
//
//  Created by XiaojianDuan on 2024/3/7.
//

#ifndef ListNode_hpp
#define ListNode_hpp

#include <stdio.h>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

#endif /* ListNode_hpp */
